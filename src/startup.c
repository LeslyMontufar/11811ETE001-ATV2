#include <stdint.h>

#define SRAM_START 0x20000000U                  /* Inicio da SRAM CORTEX-M */
#define SRAM_SIZE (20U * 1024U)                 /* Tam. SRAM STM32F103 20K */
#define SRAM_END ((SRAM_START) + (SRAM_SIZE))   /* Final da SRAM STM32F103 */
#define STACK_START SRAM_END                    /* Inicio da Stack */

int main(void);

void reset_handler      (void);
void nmi_handler        (void) __attribute__ ((weak, alias("default_handler")));
void hardfault_handler  (void) __attribute__ ((weak, alias("default_handler")));
void memmanage_handler  (void) __attribute__ ((weak, alias("default_handler")));
void busfault_handler   (void) __attribute__ ((weak, alias("default_handler")));
void usagefault_handler (void) __attribute__ ((weak, alias("default_handler")));
void svc_handler        (void) __attribute__ ((weak, alias("default_handler")));
void debugmon_handler   (void) __attribute__ ((weak, alias("default_handler")));
void pendsv_handler     (void) __attribute__ ((weak, alias("default_handler")));
void systick_handler    (void) __attribute__ ((weak, alias("default_handler")));

void wwdg_irqhandler               (void) __attribute__ ((weak, alias("default_handler")));
void pvd_irqhandler                (void) __attribute__ ((weak, alias("default_handler")));
void tamp_irqhandler               (void) __attribute__ ((weak, alias("default_handler")));
void rtc_irqhandler                (void) __attribute__ ((weak, alias("default_handler")));
void flash_irqhandler              (void) __attribute__ ((weak, alias("default_handler")));
void rcc_irqhandler                (void) __attribute__ ((weak, alias("default_handler")));
void exti0_irqhandler              (void) __attribute__ ((weak, alias("default_handler")));
void exti1_irqhandler              (void) __attribute__ ((weak, alias("default_handler")));
void exti2_irqhandler              (void) __attribute__ ((weak, alias("default_handler")));
void exti3_irqhandler              (void) __attribute__ ((weak, alias("default_handler")));
void exti4_irqhandler              (void) __attribute__ ((weak, alias("default_handler")));
void dma1_channel0_irqhandler       (void) __attribute__ ((weak, alias("default_handler")));
void dma1_channel1_irqhandler       (void) __attribute__ ((weak, alias("default_handler")));
void dma1_channel2_irqhandler       (void) __attribute__ ((weak, alias("default_handler")));
void dma1_channel3_irqhandler       (void) __attribute__ ((weak, alias("default_handler")));
void dma1_channel4_irqhandler       (void) __attribute__ ((weak, alias("default_handler")));
void dma1_channel5_irqhandler       (void) __attribute__ ((weak, alias("default_handler")));
void dma1_channel6_irqhandler       (void) __attribute__ ((weak, alias("default_handler")));
void dma1_channel7_irqhandler       (void) __attribute__ ((weak, alias("default_handler")));
void adc1_irqhandler                (void) __attribute__ ((weak, alias("default_handler")));
void usb_hp_can_tx_irqhandler       (void) __attribute__ ((weak, alias("default_handler")));
void usb_hp_can_rx0_irqhandler      (void) __attribute__ ((weak, alias("default_handler")));
void can_rx1_irqhandler             (void) __attribute__ ((weak, alias("default_handler")));
void can_sce_irqhandler             (void) __attribute__ ((weak, alias("default_handler")));
void exti9_5_irqhandler             (void) __attribute__ ((weak, alias("default_handler")));
void tim1_brk_irqhandler            (void) __attribute__ ((weak, alias("default_handler")));
void tim1_up_irqhandler             (void) __attribute__ ((weak, alias("default_handler")));
void tim1_trg_com_irqhandler        (void) __attribute__ ((weak, alias("default_handler")));
void tim1_cc_irqhandler             (void) __attribute__ ((weak, alias("default_handler")));
void tim2_irqhandler               (void) __attribute__ ((weak, alias("default_handler")));
void tim3_irqhandler               (void) __attribute__ ((weak, alias("default_handler")));
void tim4_irqhandler               (void) __attribute__ ((weak, alias("default_handler")));
void i2c1_ev_irqhandler            (void) __attribute__ ((weak, alias("default_handler")));
void i2c1_er_irqhandler            (void) __attribute__ ((weak, alias("default_handler")));
void i2c2_ev_irqhandler            (void) __attribute__ ((weak, alias("default_handler")));
void i2c2_er_irqhandler            (void) __attribute__ ((weak, alias("default_handler")));
void spi1_irqhandler               (void) __attribute__ ((weak, alias("default_handler")));
void spi2_irqhandler               (void) __attribute__ ((weak, alias("default_handler")));
void usart1_irqhandler             (void) __attribute__ ((weak, alias("default_handler")));
void usart2_irqhandler             (void) __attribute__ ((weak, alias("default_handler")));
void usart3_irqhandler             (void) __attribute__ ((weak, alias("default_handler")));
void exti15_10_irqhandler          (void) __attribute__ ((weak, alias("default_handler")));
void rtc_alarm_irqhandler          (void) __attribute__ ((weak, alias("default_handler")));
void usbwakeup_irqhandler          (void) __attribute__ ((weak, alias("default_handler")));
void tim8_brk_irqhandler           (void) __attribute__ ((weak, alias("default_handler")));
void tim8_up_irqhandler            (void) __attribute__ ((weak, alias("default_handler")));
void tim8_trg_com_irqhandler       (void) __attribute__ ((weak, alias("default_handler")));
void tim8_cc_irqhandler            (void) __attribute__ ((weak, alias("default_handler")));
void adc3_irqhandler               (void) __attribute__ ((weak, alias("default_handler")));
void fsmc_irqhandler               (void) __attribute__ ((weak, alias("default_handler")));
void sdio_irqhandler               (void) __attribute__ ((weak, alias("default_handler")));
void tim5_irqhandler               (void) __attribute__ ((weak, alias("default_handler")));
void spi3_irqhandler               (void) __attribute__ ((weak, alias("default_handler")));
void uart4_irqhandler              (void) __attribute__ ((weak, alias("default_handler")));
void uart5_irqhandler              (void) __attribute__ ((weak, alias("default_handler")));
void tim6_irqhandler               (void) __attribute__ ((weak, alias("default_handler")));
void tim7_irqhandler               (void) __attribute__ ((weak, alias("default_handler")));
void dma2_channel1_irqhandler      (void) __attribute__ ((weak, alias("default_handler")));
void dma2_channel2_irqhandler      (void) __attribute__ ((weak, alias("default_handler")));
void dma2_channel3_irqhandler      (void) __attribute__ ((weak, alias("default_handler")));
void dma2_channel4_5_irqhandler    (void) __attribute__ ((weak, alias("default_handler")));


/* Variaveis exportadas pelo linker script */

extern uint32_t _sdata;     /* Inicio da secao .data */
extern uint32_t _edata;     /* Fim da secao .data */
extern uint32_t _la_data;   /* Endereco de carga na RAM da secao .data */

extern uint32_t _sbss;      /* Inicio da secao .bss */
extern uint32_t _ebss;      /* Fim da secao .bss */

// extern uint32_t _etext;     /* Fim da secao .text */


uint32_t vectors[] __attribute__((section(".isr_vectors"))) =
{
    STACK_START,                    /* 0x0000 0000 */
    (uint32_t)reset_handler,        /* 0x0000 0004 */
    (uint32_t)nmi_handler,          /* 0x0000 0008 */
    (uint32_t)hardfault_handler,    /* 0x0000 000c */
    (uint32_t)memmanage_handler,    /* 0x0000 0010 */
    (uint32_t)busfault_handler,     /* 0x0000 0014 */
    (uint32_t)usagefault_handler,   /* 0x0000 0018 */
    0,                              /* 0x0000 001c */
    0,                              /* 0x0000 0020 */
    0,                              /* 0x0000 0024 */
    0,                              /* 0x0000 0028 */
    (uint32_t)svc_handler,          /* 0x0000 002c */
    (uint32_t)debugmon_handler,     /* 0x0000 0030 */
    0,                              /* 0x0000 0034 */
    (uint32_t)pendsv_handler,       /* 0x0000 0038 */
    (uint32_t)systick_handler,      /* 0x0000 003c */
    (uint32_t)wwdg_irqhandler,
    (uint32_t)pvd_irqhandler,
    (uint32_t)tamp_irqhandler,
    (uint32_t)rtc_irqhandler,
    (uint32_t)flash_irqhandler,
    (uint32_t)rcc_irqhandler,
    (uint32_t)exti0_irqhandler,
    (uint32_t)exti1_irqhandler,
    (uint32_t)exti2_irqhandler,
    (uint32_t)exti3_irqhandler,
    (uint32_t)exti4_irqhandler,
    (uint32_t)dma1_channel0_irqhandler,
    (uint32_t)dma1_channel1_irqhandler,
    (uint32_t)dma1_channel2_irqhandler,
    (uint32_t)dma1_channel3_irqhandler,
    (uint32_t)dma1_channel4_irqhandler,
    (uint32_t)dma1_channel5_irqhandler,
    (uint32_t)dma1_channel6_irqhandler,
    (uint32_t)dma1_channel7_irqhandler,
    (uint32_t)adc1_irqhandler,
    (uint32_t)usb_hp_can_tx_irqhandler,
    (uint32_t)usb_hp_can_rx0_irqhandler,
    (uint32_t)can_rx1_irqhandler,
    (uint32_t)can_sce_irqhandler,
    (uint32_t)exti9_5_irqhandler,
    (uint32_t)tim1_brk_irqhandler,
    (uint32_t)tim1_up_irqhandler,
    (uint32_t)tim1_trg_com_irqhandler,
    (uint32_t)tim1_cc_irqhandler,
    (uint32_t)tim2_irqhandler,
    (uint32_t)tim3_irqhandler,
    (uint32_t)tim4_irqhandler,
    (uint32_t)i2c1_ev_irqhandler,
    (uint32_t)i2c1_er_irqhandler,
    (uint32_t)i2c2_ev_irqhandler,
    (uint32_t)i2c2_er_irqhandler,
    (uint32_t)spi1_irqhandler,
    (uint32_t)spi2_irqhandler,
    (uint32_t)usart1_irqhandler,
    (uint32_t)usart2_irqhandler,
    (uint32_t)usart3_irqhandler,
    (uint32_t)exti15_10_irqhandler,
    (uint32_t)rtc_alarm_irqhandler,
    (uint32_t)usbwakeup_irqhandler,
    (uint32_t)tim8_brk_irqhandler,
    (uint32_t)tim8_up_irqhandler,
    (uint32_t)tim8_trg_com_irqhandler,
    (uint32_t)tim8_cc_irqhandler,
    (uint32_t)adc3_irqhandler,
    (uint32_t)fsmc_irqhandler,
    (uint32_t)sdio_irqhandler,
    (uint32_t)tim5_irqhandler,
    (uint32_t)spi3_irqhandler,
    (uint32_t)uart4_irqhandler,
    (uint32_t)uart5_irqhandler,
    (uint32_t)tim6_irqhandler,
    (uint32_t)tim7_irqhandler,
    (uint32_t)dma2_channel1_irqhandler,
    (uint32_t)dma2_channel2_irqhandler,
    (uint32_t)dma2_channel3_irqhandler,
    (uint32_t)dma2_channel4_5_irqhandler
};

void reset_handler()
{
    uint32_t i;

    /* Copia a secao .data para a RAM */
    uint32_t size = (uint32_t)&_edata - (uint32_t)&_sdata;
    uint8_t *pDst = (uint8_t*)&_sdata; /* SRAM */
    uint8_t *pSrc = (uint8_t*)&_la_data; /* FLASH */

    for(i = 0; i < size; i++)
    {
        *pDst++ = *pSrc++;
    }

    /* Preenche a secao .bss com zero */
    size = (uint32_t)&_ebss - (uint32_t)&_sbss;
    pDst = (uint8_t*)&_sbss;
    for(i = 0 ; i < size; i++)
    {
        *pDst++ = 0;
    }

    /* Chama a funcao main() */
    main();
}

void default_handler(void)
{
    while(1){};
}