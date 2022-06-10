# Uso de pino de entrada no ambiente bare metal ![Language grade: C](https://img.shields.io/badge/language-C-blue)

Autora: Lesly Montúfar

Trata-se de uma modificação do ambiente bare metal criado no repositório da ATV1, em que se utiliza um pino de entrada.

## Índice 

* [Descrição](#descrição)
* [Desenvolvimento](#desenvolvimento)
* [Gravando o código no STM32F103](#gravando-o-código-no-stm32f103)

## Descrição

Sem o auxílio de IDE, foram seguidos os passos:

1. Configure a placa para ter um pino de entrada adicional. Usuários da black pill podem usar o pino PA0, ligado em uma tactile switch presente na placa. Caso a sua placa não possua isso, use outro pino e um jumper para te ajudar na tarefa. Configure um resistor de pull up nesse pino, assim você irá ter certeza de que quando o valor do pino estiver em zero ele foi pressionado.
2. A frequência de piscada do led agora irá mudar, a depender do estado desse pino de entrada. Em nível baixo ele deverá piscar o led mais lentamente e em nível alto em frequência mais alta.


## Desenvolvimento

As modificações ocorreram no arquivo [`main.c`](https://github.com/LeslyMontufar/11811ETE001-ATV2/blob/f150678863eb0e6dac431010522855a3d0465be3/src/main.c) .

1. Decidi utilizar o pino A0 como "botão" para quando pressionado o led piscar com maior frequência. 
2. Para isso, é preciso configurar a porta GPIO A como input do tipo pull up.
3. Verificando no [Manual de Referência da placa STM32F103xx](https://www.st.com/resource/en/reference_manual/cd00171190-stm32f101xx-stm32f102xx-stm32f103xx-stm32f105xx-and-stm32f107xx-advanced-arm-based-32-bit-mcus-stmicroelectronics.pdf), posso encontrar o endereço dos registros que precisarei modificar na memória e com quais valores setá-los:

```
/* APB2 Base Addresses ******************************************************/

#define STM32_GPIOA_BASE                0x40010800      /* 0x40010800 - 0x40010bff: GPIO Port A */

/* Register Offsets *********************************************************/

#define STM32_GPIO_IDR_OFFSET           0x0008          /* Port input data register */

/* Register Addresses *******************************************************/

#define STM32_GPIOA_CRL                 (STM32_GPIOA_BASE+STM32_GPIO_CRL_OFFSET)
#define STM32_GPIOA_CRH                 (STM32_GPIOA_BASE+STM32_GPIO_CRH_OFFSET)
#define STM32_GPIOA_IDR                 (STM32_GPIOA_BASE+STM32_GPIO_IDR_OFFSET)

/* APB2 Peripheral Clock ENable Register (RCC_APB2ENR) */

#define RCC_APB2ENR_IOPAEN              (1 << 2)        /* Bit 2 IOPAEN: IO port A clock enable */

/* Functions */

uint32_t set_GPIO(uint32_t, int, int, int);
uint32_t piscaLed(uint32_t, int, bool,int);
bool button_pressed(uint32_t,int);

```

4. Adicionei ponteiros para os registradores do GPIO A
```
uint32_t *pGPIOA_CRL    = (uint32_t *)STM32_GPIOA_CRL;
uint32_t *pGPIOA_CRH    = (uint32_t *)STM32_GPIOA_CRH;
uint32_t *pGPIOA_IDR    = (uint32_t *)STM32_GPIOA_IDR;
```

5. Habilitei o clock do GPIO A, junto com o GPIO C (>> Não sei se precisava)
```
reg  = *pRCC_APB2ENR;
reg |= RCC_APB2ENR_IOPCEN;
reg |= RCC_APB2ENR_IOPAEN;
*pRCC_APB2ENR = reg;
```

6. Configurei a porta A0 como `GPIO_CNF_I_PULL_UP_DOWN` e `GPIO_MODE_INPUT`.
```
if(BUTTON_PIN < 8) *pGPIOA_CRL = set_GPIO((uint32_t)*pGPIOA_CRL,BUTTON_PIN,GPIO_CNF_I_PULL_UP_DOWN,GPIO_MODE_INPUT); 
else *pGPIOA_CRH = set_GPIO((uint32_t)*pGPIOA_CRH,BUTTON_PIN,GPIO_CNF_I_PULL_UP_DOWN,GPIO_MODE_INPUT);
```

7. Para mudar a velocidade em que o led do pino PC13 pisca criei funções para verificar se o pino A0 está em nível alto, e em caso afirmativo, o led pisca 3x mais rápido.
```
while(1)
{
    *pGPIOC_BSRR = piscaLed((uint32_t)*pGPIOC_BSRR, LED_PIN, led_status,delay);
    led_status = !led_status;

    pressed = button_pressed((uint32_t)*pGPIOA_IDR, BUTTON_PIN);
    if(pressed) delay = LED_DELAY; // rápido
    else delay = 3*LED_DELAY; // lento

}
```

```
uint32_t set_GPIO(uint32_t reg, int led_pin, int cnf, int mode){ 

    reg &= ~GPIO_CNF_MASK(led_pin);
    reg |= (cnf << GPIO_CNF_SHIFT(led_pin));

    reg &= ~GPIO_MODE_MASK(led_pin);
    reg |= (mode << GPIO_MODE_SHIFT(led_pin));

    return reg;
}

uint32_t piscaLed(uint32_t reg, int led_pin, bool led_status, int delay){
    
    if(led_status) reg = GPIO_BSRR_SET(led_pin);
    else reg = GPIO_BSRR_RST(led_pin);
    for(int i = 0; i < delay; i++);

    return reg;
}

bool button_pressed(uint32_t reg, int b_pin){
    reg &= (1 << b_pin);
    return (reg >= 1);
}
```

## Gravando o código no STM32F103

1. Para conectar o gravador ST-LINK no WSL2, seguir os passos descritos no [roteiro](https://github.com/LeslyMontufar/11811ETE001-ATV2/blob/main/asset/03-Roteiro%20ATV1%20b%201.pdf).
2. Com o STLink conectado usar o comando no terminal do Ubuntu 20.04:
```
openocd -f interface/stlink.cfg -f target/stm32f1x.cfg -c init -c "reset halt" -c "flash write_image erase blinky.bin 0x08000000"
```

3. Quando o gravador informar que está ouvindo e não der nenhum erro, pressionar `Ctrl+C`.
```
Listening ...
```

4. No STM32F103 pressionar e soltar o botão de `reset`. Pronto, o código foi gravado no microcontrolador.

