/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v7.0
processor: MKL25Z128xxx4
package_id: MKL25Z128VLK4
mcu_data: ksdk2_0
processor_version: 7.0.1
board: FRDM-KL25Z
pin_labels:
- {pin_num: '13', pin_signal: ADC0_DP0/ADC0_SE0/PTE20/TPM1_CH0/UART0_TX, label: 'J10[1]', identifier: SUR_VERDE}
- {pin_num: '14', pin_signal: ADC0_DM0/ADC0_SE4a/PTE21/TPM1_CH1/UART0_RX, label: 'J10[3]', identifier: SUR_AMARILLO}
- {pin_num: '15', pin_signal: ADC0_DP3/ADC0_SE3/PTE22/TPM2_CH0/UART2_TX, label: 'J10[5]', identifier: SUR_ROJO}
- {pin_num: '16', pin_signal: ADC0_DM3/ADC0_SE7a/PTE23/TPM2_CH1/UART2_RX, label: 'J10[7]', identifier: SUR_VUELTA}
- {pin_num: '21', pin_signal: CMP0_IN5/ADC0_SE4b/PTE29/TPM0_CH2/TPM_CLKIN0, label: 'J10[9]', identifier: SUR_SENSOR}
- {pin_num: '27', pin_signal: TSI0_CH2/PTA1/UART0_RX/TPM2_CH0, label: 'J1[2]/D0/UART0_RX', identifier: DEBUG_UART_RX;OESTE_SENSOR}
- {pin_num: '28', pin_signal: TSI0_CH3/PTA2/UART0_TX/TPM2_CH1, label: 'J1[4]/D1/UART0_TX', identifier: DEBUG_UART_TX;OESTE_VUELTA}
- {pin_num: '30', pin_signal: TSI0_CH5/PTA4/I2C1_SDA/TPM0_CH1/NMI_b, label: 'J1[10]/D4', identifier: OESTE_VERDE}
- {pin_num: '32', pin_signal: PTA12/TPM1_CH0, label: 'J1[8]/D3', identifier: OESTE_AMARILLO}
- {pin_num: '43', pin_signal: ADC0_SE8/TSI0_CH0/PTB0/LLWU_P5/I2C0_SCL/TPM1_CH0, label: 'J1[2]/D0/UART0_RX', identifier: NORTEVERDE;NORTE_VERDE}
- {pin_num: '44', pin_signal: ADC0_SE9/TSI0_CH6/PTB1/I2C0_SDA/TPM1_CH1, label: 'J10[4]/A1', identifier: NORTE_AMARILLO}
- {pin_num: '45', pin_signal: ADC0_SE12/TSI0_CH7/PTB2/I2C0_SCL/TPM2_CH0, label: 'J10[6]/A2', identifier: NORTE_ROJO}
- {pin_num: '46', pin_signal: ADC0_SE13/TSI0_CH8/PTB3/I2C0_SDA/TPM2_CH1, label: 'J10[8]/A3', identifier: NORTE_VUELTA}
- {pin_num: '55', pin_signal: ADC0_SE14/TSI0_CH13/PTC0/EXTRG_IN/CMP0_OUT, label: 'J1[3]', identifier: ESTE_VUELTA}
- {pin_num: '57', pin_signal: ADC0_SE11/TSI0_CH15/PTC2/I2C1_SDA/TPM0_CH1, label: 'J10[10]/A4', identifier: NORTE_SENSOR}
- {pin_num: '58', pin_signal: PTC3/LLWU_P7/UART1_RX/TPM0_CH2/CLKOUTa, label: 'J1[5]', identifier: ESTE_ROJO}
- {pin_num: '61', pin_signal: PTC4/LLWU_P8/SPI0_PCS0/UART1_TX/TPM0_CH3, label: 'J1[7]', identifier: ESTE_AMARILLO}
- {pin_num: '62', pin_signal: PTC5/LLWU_P9/SPI0_SCK/LPTMR0_ALT2/CMP0_OUT, label: 'J1[9]', identifier: ESTE_VERDE}
- {pin_num: '64', pin_signal: CMP0_IN1/PTC7/SPI0_MISO/SPI0_MOSI, label: 'J1[1]', identifier: ESTE_SENSOR}
- {pin_num: '77', pin_signal: PTD4/LLWU_P14/SPI1_PCS0/UART2_RX/TPM0_CH4, label: 'J1[6]/D2', identifier: OESTE_ROJO}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

#include "fsl_common.h"
#include "fsl_port.h"
#include "fsl_gpio.h"
#include "pin_mux.h"

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitBootPins
 * Description   : Calls initialization functions.
 *
 * END ****************************************************************************************************************/
void BOARD_InitBootPins(void)
{
    BOARD_InitPins();
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '43', peripheral: GPIOB, signal: 'GPIO, 0', pin_signal: ADC0_SE8/TSI0_CH0/PTB0/LLWU_P5/I2C0_SCL/TPM1_CH0, identifier: NORTE_VERDE, direction: OUTPUT}
  - {pin_num: '44', peripheral: GPIOB, signal: 'GPIO, 1', pin_signal: ADC0_SE9/TSI0_CH6/PTB1/I2C0_SDA/TPM1_CH1, direction: OUTPUT}
  - {pin_num: '45', peripheral: GPIOB, signal: 'GPIO, 2', pin_signal: ADC0_SE12/TSI0_CH7/PTB2/I2C0_SCL/TPM2_CH0, direction: OUTPUT}
  - {pin_num: '46', peripheral: GPIOB, signal: 'GPIO, 3', pin_signal: ADC0_SE13/TSI0_CH8/PTB3/I2C0_SDA/TPM2_CH1, direction: OUTPUT}
  - {pin_num: '57', peripheral: GPIOC, signal: 'GPIO, 2', pin_signal: ADC0_SE11/TSI0_CH15/PTC2/I2C1_SDA/TPM0_CH1, direction: INPUT, pull_enable: enable}
  - {pin_num: '13', peripheral: GPIOE, signal: 'GPIO, 20', pin_signal: ADC0_DP0/ADC0_SE0/PTE20/TPM1_CH0/UART0_TX, direction: OUTPUT}
  - {pin_num: '14', peripheral: GPIOE, signal: 'GPIO, 21', pin_signal: ADC0_DM0/ADC0_SE4a/PTE21/TPM1_CH1/UART0_RX, direction: OUTPUT}
  - {pin_num: '15', peripheral: GPIOE, signal: 'GPIO, 22', pin_signal: ADC0_DP3/ADC0_SE3/PTE22/TPM2_CH0/UART2_TX, direction: OUTPUT}
  - {pin_num: '16', peripheral: GPIOE, signal: 'GPIO, 23', pin_signal: ADC0_DM3/ADC0_SE7a/PTE23/TPM2_CH1/UART2_RX, direction: OUTPUT}
  - {pin_num: '21', peripheral: GPIOE, signal: 'GPIO, 29', pin_signal: CMP0_IN5/ADC0_SE4b/PTE29/TPM0_CH2/TPM_CLKIN0, direction: INPUT, pull_enable: enable}
  - {pin_num: '62', peripheral: GPIOC, signal: 'GPIO, 5', pin_signal: PTC5/LLWU_P9/SPI0_SCK/LPTMR0_ALT2/CMP0_OUT, direction: OUTPUT}
  - {pin_num: '61', peripheral: GPIOC, signal: 'GPIO, 4', pin_signal: PTC4/LLWU_P8/SPI0_PCS0/UART1_TX/TPM0_CH3, direction: OUTPUT}
  - {pin_num: '58', peripheral: GPIOC, signal: 'GPIO, 3', pin_signal: PTC3/LLWU_P7/UART1_RX/TPM0_CH2/CLKOUTa, direction: OUTPUT}
  - {pin_num: '55', peripheral: GPIOC, signal: 'GPIO, 0', pin_signal: ADC0_SE14/TSI0_CH13/PTC0/EXTRG_IN/CMP0_OUT, direction: OUTPUT}
  - {pin_num: '64', peripheral: GPIOC, signal: 'GPIO, 7', pin_signal: CMP0_IN1/PTC7/SPI0_MISO/SPI0_MOSI, direction: INPUT, pull_enable: enable}
  - {pin_num: '30', peripheral: GPIOA, signal: 'GPIO, 4', pin_signal: TSI0_CH5/PTA4/I2C1_SDA/TPM0_CH1/NMI_b, direction: OUTPUT}
  - {pin_num: '32', peripheral: GPIOA, signal: 'GPIO, 12', pin_signal: PTA12/TPM1_CH0, direction: OUTPUT}
  - {pin_num: '77', peripheral: GPIOD, signal: 'GPIO, 4', pin_signal: PTD4/LLWU_P14/SPI1_PCS0/UART2_RX/TPM0_CH4, direction: OUTPUT}
  - {pin_num: '28', peripheral: GPIOA, signal: 'GPIO, 2', pin_signal: TSI0_CH3/PTA2/UART0_TX/TPM2_CH1, identifier: OESTE_VUELTA, direction: OUTPUT}
  - {pin_num: '27', peripheral: GPIOA, signal: 'GPIO, 1', pin_signal: TSI0_CH2/PTA1/UART0_RX/TPM2_CH0, identifier: OESTE_SENSOR, direction: INPUT, pull_enable: enable}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitPins(void)
{
    /* Port A Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortA);
    /* Port B Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortB);
    /* Port C Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortC);
    /* Port D Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortD);
    /* Port E Clock Gate Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortE);

    gpio_pin_config_t OESTE_SENSOR_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTA1 (pin 27)  */
    GPIO_PinInit(BOARD_INITPINS_OESTE_SENSOR_GPIO, BOARD_INITPINS_OESTE_SENSOR_PIN, &OESTE_SENSOR_config);

    gpio_pin_config_t OESTE_VUELTA_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTA2 (pin 28)  */
    GPIO_PinInit(BOARD_INITPINS_OESTE_VUELTA_GPIO, BOARD_INITPINS_OESTE_VUELTA_PIN, &OESTE_VUELTA_config);

    gpio_pin_config_t OESTE_VERDE_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTA4 (pin 30)  */
    GPIO_PinInit(BOARD_INITPINS_OESTE_VERDE_GPIO, BOARD_INITPINS_OESTE_VERDE_PIN, &OESTE_VERDE_config);

    gpio_pin_config_t OESTE_AMARILLO_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTA12 (pin 32)  */
    GPIO_PinInit(BOARD_INITPINS_OESTE_AMARILLO_GPIO, BOARD_INITPINS_OESTE_AMARILLO_PIN, &OESTE_AMARILLO_config);

    gpio_pin_config_t NORTE_VERDE_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTB0 (pin 43)  */
    GPIO_PinInit(BOARD_INITPINS_NORTE_VERDE_GPIO, BOARD_INITPINS_NORTE_VERDE_PIN, &NORTE_VERDE_config);

    gpio_pin_config_t NORTE_AMARILLO_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTB1 (pin 44)  */
    GPIO_PinInit(BOARD_INITPINS_NORTE_AMARILLO_GPIO, BOARD_INITPINS_NORTE_AMARILLO_PIN, &NORTE_AMARILLO_config);

    gpio_pin_config_t NORTE_ROJO_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTB2 (pin 45)  */
    GPIO_PinInit(BOARD_INITPINS_NORTE_ROJO_GPIO, BOARD_INITPINS_NORTE_ROJO_PIN, &NORTE_ROJO_config);

    gpio_pin_config_t NORTE_VUELTA_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTB3 (pin 46)  */
    GPIO_PinInit(BOARD_INITPINS_NORTE_VUELTA_GPIO, BOARD_INITPINS_NORTE_VUELTA_PIN, &NORTE_VUELTA_config);

    gpio_pin_config_t ESTE_VUELTA_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTC0 (pin 55)  */
    GPIO_PinInit(BOARD_INITPINS_ESTE_VUELTA_GPIO, BOARD_INITPINS_ESTE_VUELTA_PIN, &ESTE_VUELTA_config);

    gpio_pin_config_t NORTE_SENSOR_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTC2 (pin 57)  */
    GPIO_PinInit(BOARD_INITPINS_NORTE_SENSOR_GPIO, BOARD_INITPINS_NORTE_SENSOR_PIN, &NORTE_SENSOR_config);

    gpio_pin_config_t ESTE_ROJO_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTC3 (pin 58)  */
    GPIO_PinInit(BOARD_INITPINS_ESTE_ROJO_GPIO, BOARD_INITPINS_ESTE_ROJO_PIN, &ESTE_ROJO_config);

    gpio_pin_config_t ESTE_AMARILLO_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTC4 (pin 61)  */
    GPIO_PinInit(BOARD_INITPINS_ESTE_AMARILLO_GPIO, BOARD_INITPINS_ESTE_AMARILLO_PIN, &ESTE_AMARILLO_config);

    gpio_pin_config_t ESTE_VERDE_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTC5 (pin 62)  */
    GPIO_PinInit(BOARD_INITPINS_ESTE_VERDE_GPIO, BOARD_INITPINS_ESTE_VERDE_PIN, &ESTE_VERDE_config);

    gpio_pin_config_t ESTE_SENSOR_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTC7 (pin 64)  */
    GPIO_PinInit(BOARD_INITPINS_ESTE_SENSOR_GPIO, BOARD_INITPINS_ESTE_SENSOR_PIN, &ESTE_SENSOR_config);

    gpio_pin_config_t OESTE_ROJO_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTD4 (pin 77)  */
    GPIO_PinInit(BOARD_INITPINS_OESTE_ROJO_GPIO, BOARD_INITPINS_OESTE_ROJO_PIN, &OESTE_ROJO_config);

    gpio_pin_config_t SUR_VERDE_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTE20 (pin 13)  */
    GPIO_PinInit(BOARD_INITPINS_SUR_VERDE_GPIO, BOARD_INITPINS_SUR_VERDE_PIN, &SUR_VERDE_config);

    gpio_pin_config_t SUR_AMARILLO_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTE21 (pin 14)  */
    GPIO_PinInit(BOARD_INITPINS_SUR_AMARILLO_GPIO, BOARD_INITPINS_SUR_AMARILLO_PIN, &SUR_AMARILLO_config);

    gpio_pin_config_t SUR_ROJO_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTE22 (pin 15)  */
    GPIO_PinInit(BOARD_INITPINS_SUR_ROJO_GPIO, BOARD_INITPINS_SUR_ROJO_PIN, &SUR_ROJO_config);

    gpio_pin_config_t SUR_VUELTA_config = {
        .pinDirection = kGPIO_DigitalOutput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTE23 (pin 16)  */
    GPIO_PinInit(BOARD_INITPINS_SUR_VUELTA_GPIO, BOARD_INITPINS_SUR_VUELTA_PIN, &SUR_VUELTA_config);

    gpio_pin_config_t SUR_SENSOR_config = {
        .pinDirection = kGPIO_DigitalInput,
        .outputLogic = 0U
    };
    /* Initialize GPIO functionality on pin PTE29 (pin 21)  */
    GPIO_PinInit(BOARD_INITPINS_SUR_SENSOR_GPIO, BOARD_INITPINS_SUR_SENSOR_PIN, &SUR_SENSOR_config);

    const port_pin_config_t OESTE_SENSOR = {/* Internal pull-up resistor is enabled */
                                            kPORT_PullUp,
                                            /* Slow slew rate is configured */
                                            kPORT_SlowSlewRate,
                                            /* Passive filter is disabled */
                                            kPORT_PassiveFilterDisable,
                                            /* Low drive strength is configured */
                                            kPORT_LowDriveStrength,
                                            /* Pin is configured as PTA1 */
                                            kPORT_MuxAsGpio};
    /* PORTA1 (pin 27) is configured as PTA1 */
    PORT_SetPinConfig(BOARD_INITPINS_OESTE_SENSOR_PORT, BOARD_INITPINS_OESTE_SENSOR_PIN, &OESTE_SENSOR);

    /* PORTA12 (pin 32) is configured as PTA12 */
    PORT_SetPinMux(BOARD_INITPINS_OESTE_AMARILLO_PORT, BOARD_INITPINS_OESTE_AMARILLO_PIN, kPORT_MuxAsGpio);

    /* PORTA2 (pin 28) is configured as PTA2 */
    PORT_SetPinMux(BOARD_INITPINS_OESTE_VUELTA_PORT, BOARD_INITPINS_OESTE_VUELTA_PIN, kPORT_MuxAsGpio);

    /* PORTA4 (pin 30) is configured as PTA4 */
    PORT_SetPinMux(BOARD_INITPINS_OESTE_VERDE_PORT, BOARD_INITPINS_OESTE_VERDE_PIN, kPORT_MuxAsGpio);

    /* PORTB0 (pin 43) is configured as PTB0 */
    PORT_SetPinMux(BOARD_INITPINS_NORTE_VERDE_PORT, BOARD_INITPINS_NORTE_VERDE_PIN, kPORT_MuxAsGpio);

    /* PORTB1 (pin 44) is configured as PTB1 */
    PORT_SetPinMux(BOARD_INITPINS_NORTE_AMARILLO_PORT, BOARD_INITPINS_NORTE_AMARILLO_PIN, kPORT_MuxAsGpio);

    /* PORTB2 (pin 45) is configured as PTB2 */
    PORT_SetPinMux(BOARD_INITPINS_NORTE_ROJO_PORT, BOARD_INITPINS_NORTE_ROJO_PIN, kPORT_MuxAsGpio);

    /* PORTB3 (pin 46) is configured as PTB3 */
    PORT_SetPinMux(BOARD_INITPINS_NORTE_VUELTA_PORT, BOARD_INITPINS_NORTE_VUELTA_PIN, kPORT_MuxAsGpio);

    /* PORTC0 (pin 55) is configured as PTC0 */
    PORT_SetPinMux(BOARD_INITPINS_ESTE_VUELTA_PORT, BOARD_INITPINS_ESTE_VUELTA_PIN, kPORT_MuxAsGpio);

    const port_pin_config_t NORTE_SENSOR = {/* Internal pull-up resistor is enabled */
                                            kPORT_PullUp,
                                            /* Slow slew rate is configured */
                                            kPORT_SlowSlewRate,
                                            /* Passive filter is disabled */
                                            kPORT_PassiveFilterDisable,
                                            /* Low drive strength is configured */
                                            kPORT_LowDriveStrength,
                                            /* Pin is configured as PTC2 */
                                            kPORT_MuxAsGpio};
    /* PORTC2 (pin 57) is configured as PTC2 */
    PORT_SetPinConfig(BOARD_INITPINS_NORTE_SENSOR_PORT, BOARD_INITPINS_NORTE_SENSOR_PIN, &NORTE_SENSOR);

    /* PORTC3 (pin 58) is configured as PTC3 */
    PORT_SetPinMux(BOARD_INITPINS_ESTE_ROJO_PORT, BOARD_INITPINS_ESTE_ROJO_PIN, kPORT_MuxAsGpio);

    /* PORTC4 (pin 61) is configured as PTC4 */
    PORT_SetPinMux(BOARD_INITPINS_ESTE_AMARILLO_PORT, BOARD_INITPINS_ESTE_AMARILLO_PIN, kPORT_MuxAsGpio);

    /* PORTC5 (pin 62) is configured as PTC5 */
    PORT_SetPinMux(BOARD_INITPINS_ESTE_VERDE_PORT, BOARD_INITPINS_ESTE_VERDE_PIN, kPORT_MuxAsGpio);

    const port_pin_config_t ESTE_SENSOR = {/* Internal pull-up resistor is enabled */
                                           kPORT_PullUp,
                                           /* Fast slew rate is configured */
                                           kPORT_FastSlewRate,
                                           /* Passive filter is disabled */
                                           kPORT_PassiveFilterDisable,
                                           /* Low drive strength is configured */
                                           kPORT_LowDriveStrength,
                                           /* Pin is configured as PTC7 */
                                           kPORT_MuxAsGpio};
    /* PORTC7 (pin 64) is configured as PTC7 */
    PORT_SetPinConfig(BOARD_INITPINS_ESTE_SENSOR_PORT, BOARD_INITPINS_ESTE_SENSOR_PIN, &ESTE_SENSOR);

    /* PORTD4 (pin 77) is configured as PTD4 */
    PORT_SetPinMux(BOARD_INITPINS_OESTE_ROJO_PORT, BOARD_INITPINS_OESTE_ROJO_PIN, kPORT_MuxAsGpio);

    /* PORTE20 (pin 13) is configured as PTE20 */
    PORT_SetPinMux(BOARD_INITPINS_SUR_VERDE_PORT, BOARD_INITPINS_SUR_VERDE_PIN, kPORT_MuxAsGpio);

    /* PORTE21 (pin 14) is configured as PTE21 */
    PORT_SetPinMux(BOARD_INITPINS_SUR_AMARILLO_PORT, BOARD_INITPINS_SUR_AMARILLO_PIN, kPORT_MuxAsGpio);

    /* PORTE22 (pin 15) is configured as PTE22 */
    PORT_SetPinMux(BOARD_INITPINS_SUR_ROJO_PORT, BOARD_INITPINS_SUR_ROJO_PIN, kPORT_MuxAsGpio);

    /* PORTE23 (pin 16) is configured as PTE23 */
    PORT_SetPinMux(BOARD_INITPINS_SUR_VUELTA_PORT, BOARD_INITPINS_SUR_VUELTA_PIN, kPORT_MuxAsGpio);

    const port_pin_config_t SUR_SENSOR = {/* Internal pull-up resistor is enabled */
                                          kPORT_PullUp,
                                          /* Slow slew rate is configured */
                                          kPORT_SlowSlewRate,
                                          /* Passive filter is disabled */
                                          kPORT_PassiveFilterDisable,
                                          /* Low drive strength is configured */
                                          kPORT_LowDriveStrength,
                                          /* Pin is configured as PTE29 */
                                          kPORT_MuxAsGpio};
    /* PORTE29 (pin 21) is configured as PTE29 */
    PORT_SetPinConfig(BOARD_INITPINS_SUR_SENSOR_PORT, BOARD_INITPINS_SUR_SENSOR_PIN, &SUR_SENSOR);
}
/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
