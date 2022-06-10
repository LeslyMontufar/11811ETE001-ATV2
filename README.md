# Uso de pino de entrada no ambiente bare metal ![Language grade: C](https://img.shields.io/badge/language-C-blue)

Autora: Lesly Montúfar

Trata-se de uma modificação do ambiente bare metal criado no repositório da ATV1, em que se utiliza um pino de entrada.

## Índice 

* [Descrição](#descrição)
* [Desenvolvimento](#desenvolvimento)

## Descrição

Sem o auxílio de IDE, foram seguidos os passos:

1. Configure a placa para ter um pino de entrada adicional. Usuários da black pill podem usar o pino PA0, ligado em uma tactile switch presente na placa. Caso a sua placa não possua isso, use outro pino e um jumper para te ajudar na tarefa. Configure um resistor de pull up nesse pino, assim você irá ter certeza de que quando o valor do pino estiver em zero ele foi pressionado.
2. A frequência de piscada do led agora irá mudar, a depender do estado desse pino de entrada. Em nível baixo ele deverá piscar o led mais lentamente e em nível alto em frequência mais alta.


## Desenvolvimento

As modificações ocorreram no arquivo [`main.c`](https://github.com/LeslyMontufar/11811ETE001-ATV2/blob/f150678863eb0e6dac431010522855a3d0465be3/src/main.c) .

1. Decidi utilizar o pino A0 como "botão" para quando pressionado o led piscar com maior frequência. 
2. Para isso, é preciso configurar a porta GPIO A como input do tipo pull up.
3. Verificando no Manual de Referência da placa STM32F103xx, posso encontrar o endereço dos registros que precisarei modificar na memória e com quais valores setá-los:

```
#define STM32_GPIOA_BASE                0x40010800      /* 0x40010800 - 0x40010bff: GPIO Port A */

#define STM32_GPIO_IDR_OFFSET           0x0008          /* Port input data register */

#define STM32_GPIOA_CRL                 (STM32_GPIOA_BASE+STM32_GPIO_CRL_OFFSET)
#define STM32_GPIOA_CRH                 (STM32_GPIOA_BASE+STM32_GPIO_CRH_OFFSET)
#define STM32_GPIOA_IDR                 (STM32_GPIOA_BASE+STM32_GPIO_IDR_OFFSET)

```

