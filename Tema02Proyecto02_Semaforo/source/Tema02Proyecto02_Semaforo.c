 
/**
 * @file    Tema02Proyecto02_Semaforo.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"
#include "fsl_tpm.h"

/* TODO: insert other include files here. */

/* TODO: insert other definitions and declarations here. */

#define NORTE_ROJO 2u/*PIN PTB2*/
#define NORTE_AMARILLO 1u/*PIN PTB1*/
#define NORTE_VERDE 0u/*PIN PTB0*/
#define NORTE_VUELTA 3u/*PIN PTB3*/
#define NORTE_SENSOR 2u/*PIN PTC2*/

#define SUR_ROJO 22u/*PIN PTE22*/
#define SUR_AMARILLO 21u/*PIN PTE21*/
#define SUR_VERDE 20u/*PIN PTE20*/
#define SUR_VUELTA 23u/*PIN PTE23*/
#define SUR_SENSOR 29u/*PIN PTE29*/

#define ESTE_ROJO 3u/*PIN PTC3*/
#define ESTE_AMARILLO 4u/*PIN PTC4*/
#define ESTE_VERDE 5u/*PIN PTC5*/
#define ESTE_VUELTA 0u/*PIN PTC0*/
#define ESTE_SENSOR 7u/*PIN PTC7*/

#define OESTE_ROJO 4u/*PIN PTD4*/
#define OESTE_AMARILLO 12u/*PIN PTA12*/
#define OESTE_VERDE 4u/*PIN PTA4*/
#define OESTE_VUELTA 2u/*PIN PTA2*/
#define OESTE_SENSOR 1u/*PIN PTA1*/


typedef struct{
	uint8_t NORTEROJO;
	uint8_t NORTEAMARILLO;
	uint8_t NORTEVERDE;
	uint8_t NORTEVUELTA;
	uint8_t SURROJO;
	uint8_t SURAMARILLO;
	uint8_t SURVERDE;
	uint8_t SURVUELTA;
	uint8_t ESTEROJO;
	uint8_t ESTEAMARILLO;
	uint8_t ESTEVERDE;
	uint8_t ESTEVUELTA;
	uint8_t OESTEROJO;
	uint8_t OESTEAMARILLO;
	uint8_t OESTEVERDE;
	uint8_t OESTEVUELTA;
	uint16_t TIMER_MOD;
} state;

/*
 * @brief   Application entry point.
 */
int main(void) {

	int i;

  	/* Init board hardware. */
     BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
  	/* Init FSL debug console. */
    BOARD_InitDebugConsole();

    tpm_config_t config;

    TPM_GetDefaultConfig (&config);
    config.prescale= kTPM_Prescale_Divide_128;
    TPM_Init (TPM0, &config);
    TPM_Init (TPM1, &config);

    state FSM [23];

    FSM[0]=(state){.NORTEROJO=0u, .NORTEAMARILLO=0u, .NORTEVERDE=0u, .NORTEVUELTA=0u, .SURROJO=0u, .SURAMARILLO=0u, .SURVERDE=0u, .SURVUELTA=0u, .ESTEROJO=0u, .ESTEAMARILLO=0u, .ESTEVERDE=0u, .ESTEVUELTA=0u, .OESTEROJO=0u, .OESTEAMARILLO=0u, .OESTEVERDE=0u, .OESTEVUELTA=0u, .TIMER_MOD=256u};/*EXTRA*/

    FSM[1]=(state){.NORTEROJO= 0u, .NORTEAMARILLO= 0u, .NORTEVERDE= 1u, .NORTEVUELTA= 0u, .SURROJO= 0u, .SURAMARILLO= 0u, .SURVERDE= 1u, .SURVUELTA= 0u, .ESTEROJO= 1u, .ESTEAMARILLO= 0u, .ESTEVERDE= 0u, .ESTEVUELTA= 0u, .OESTEROJO= 1u, .OESTEAMARILLO= 0u, .OESTEVERDE= 0u, .OESTEVUELTA= 0u, .TIMER_MOD= 2040u};/*NORTE y SUR estan en verde por 8 seg*/
    FSM[2]=(state){.NORTEROJO= 0u, .NORTEAMARILLO= 0u, .NORTEVERDE= 1u, .NORTEVUELTA= 0u, .SURROJO= 0u, .SURAMARILLO= 0u, .SURVERDE= 1u, .SURVUELTA= 0u, .ESTEROJO= 1u, .ESTEAMARILLO= 0u, .ESTEVERDE= 0u, .ESTEVUELTA= 0u, .OESTEROJO= 1u, .OESTEAMARILLO= 0u, .OESTEVERDE= 0u, .OESTEVUELTA= 0u, .TIMER_MOD= 1792u};/*NORTE y SUR estan en verde por 7 seg*/
    FSM[3]=(state){.NORTEROJO= 0u, .NORTEAMARILLO= 1u, .NORTEVERDE= 0u, .NORTEVUELTA= 0u, .SURROJO= 0u, .SURAMARILLO= 1u, .SURVERDE= 0u, .SURVUELTA= 0u, .ESTEROJO= 1u, .ESTEAMARILLO= 0u, .ESTEVERDE= 0u, .ESTEVUELTA= 0u, .OESTEROJO= 1u, .OESTEAMARILLO= 0u, .OESTEVERDE= 0u, .OESTEVUELTA= 0u, .TIMER_MOD= 512u};/*NORTE y SUR estan en amarillo por 2 seg*/

    FSM[4]=(state){.NORTEROJO= 1u, .NORTEAMARILLO= 0u, .NORTEVERDE= 0u, .NORTEVUELTA= 0u, .SURROJO= 1u, .SURAMARILLO= 0u, .SURVERDE= 0u, .SURVUELTA= 0u, .ESTEROJO= 0u, .ESTEAMARILLO= 0u, .ESTEVERDE= 1u, .ESTEVUELTA= 0u, .OESTEROJO= 0u, .OESTEAMARILLO= 0u, .OESTEVERDE= 1u, .OESTEVUELTA= 0u, .TIMER_MOD= 2040u};/*ESTE y OESTE estan en verde por 8 seg*/
    FSM[5]=(state){.NORTEROJO= 1u, .NORTEAMARILLO= 0u, .NORTEVERDE= 0u, .NORTEVUELTA= 0u, .SURROJO= 1u, .SURAMARILLO= 0u, .SURVERDE= 0u, .SURVUELTA= 0u, .ESTEROJO= 0u, .ESTEAMARILLO= 0u, .ESTEVERDE= 1u, .ESTEVUELTA= 0u, .OESTEROJO= 0u, .OESTEAMARILLO= 0u, .OESTEVERDE= 1u, .OESTEVUELTA= 0u, .TIMER_MOD= 1792u};/*ESTE y OESTE estan en verde por 7 seg*/
    FSM[6]=(state){.NORTEROJO= 1u, .NORTEAMARILLO= 0u, .NORTEVERDE= 0u, .NORTEVUELTA= 0u, .SURROJO= 1u, .SURAMARILLO= 0u, .SURVERDE= 0u, .SURVUELTA= 0u, .ESTEROJO= 0u, .ESTEAMARILLO= 1u, .ESTEVERDE= 0u, .ESTEVUELTA= 0u, .OESTEROJO= 0u, .OESTEAMARILLO= 1u, .OESTEVERDE= 0u, .OESTEVUELTA= 0u, .TIMER_MOD= 512u};/*ESTE y OESTE estan en amarillo por 2 seg*/


    FSM[7]=(state){.NORTEROJO= 0u, .NORTEAMARILLO= 0u, .NORTEVERDE= 1u, .NORTEVUELTA= 0u, .SURROJO= 0u, .SURAMARILLO= 1u, .SURVERDE= 0u, .SURVUELTA= 0u, .ESTEROJO= 1u, .ESTEAMARILLO= 0u, .ESTEVERDE= 0u, .ESTEVUELTA= 0u, .OESTEROJO= 1u, .OESTEAMARILLO= 0u, .OESTEVERDE= 0u, .OESTEVUELTA= 0u, .TIMER_MOD= 512u};/*Sensor de NORTE se activa por 2 seg y SUR esta en amarillo*/

    FSM[8]=(state){.NORTEROJO= 0u, .NORTEAMARILLO= 0u, .NORTEVERDE= 1u, .NORTEVUELTA= 1u, .SURROJO= 1u, .SURAMARILLO= 0u, .SURVERDE= 0u, .SURVUELTA= 0u, .ESTEROJO= 1u, .ESTEAMARILLO= 0u, .ESTEVERDE= 0u, .ESTEVUELTA= 0u, .OESTEROJO= 1u, .OESTEAMARILLO= 0u, .OESTEVERDE= 0u, .OESTEVUELTA= 0u, .TIMER_MOD= 1280u};/*El VERDE de la VUELTA de NORTE se enciende 5 seg*/

    FSM[9]=(state){.NORTEROJO= 0u, .NORTEAMARILLO= 1u, .NORTEVERDE= 0u, .NORTEVUELTA= 0u, .SURROJO= 1u, .SURAMARILLO= 0u, .SURVERDE= 0u, .SURVUELTA= 0u, .ESTEROJO= 1u, .ESTEAMARILLO= 0u, .ESTEVERDE= 0u, .ESTEVUELTA= 0u, .OESTEROJO= 1u, .OESTEAMARILLO= 0u, .OESTEVERDE= 0u, .OESTEVUELTA= 0u, .TIMER_MOD= 512u};/*NORTE cambia a amarillo por 2 seg*/


    FSM[10]=(state){.NORTEROJO= 0u, .NORTEAMARILLO= 1u, .NORTEVERDE= 0u, .NORTEVUELTA= 0u, .SURROJO= 0u, .SURAMARILLO= 0u, .SURVERDE= 1u, .SURVUELTA= 0u, .ESTEROJO= 1u, .ESTEAMARILLO= 0u, .ESTEVERDE= 0u, .ESTEVUELTA= 0u, .OESTEROJO= 1u, .OESTEAMARILLO= 0u, .OESTEVERDE= 0u, .OESTEVUELTA= 0u, .TIMER_MOD= 512u};/*Sensor de Sur se activa por 2 seg y NORTE esta en amarillo*/

    FSM[11]=(state){.NORTEROJO= 1u, .NORTEAMARILLO= 0u, .NORTEVERDE= 0u, .NORTEVUELTA= 0u, .SURROJO= 0u, .SURAMARILLO= 0u, .SURVERDE= 1u, .SURVUELTA= 1u, .ESTEROJO= 1u, .ESTEAMARILLO= 0u, .ESTEVERDE= 0u, .ESTEVUELTA= 0u, .OESTEROJO= 1u, .OESTEAMARILLO= 0u, .OESTEVERDE= 0u, .OESTEVUELTA= 0u, .TIMER_MOD= 1280u};/*El VERDE de lA VUELTA de SUR se enciende 5 seg*/

    FSM[12]=(state){.NORTEROJO= 1u, .NORTEAMARILLO= 0u, .NORTEVERDE= 0u, .NORTEVUELTA= 0u, .SURROJO= 0u, .SURAMARILLO= 1u, .SURVERDE= 0u, .SURVUELTA= 0u, .ESTEROJO= 1u, .ESTEAMARILLO= 0u, .ESTEVERDE= 0u, .ESTEVUELTA= 0u, .OESTEROJO= 1u, .OESTEAMARILLO= 0u, .OESTEVERDE= 0u, .OESTEVUELTA= 0u, .TIMER_MOD= 512u};/*SUR cambia a amarillo por 2 seg*/


    FSM[13]=(state){.NORTEROJO= 0u, .NORTEAMARILLO= 1u, .NORTEVERDE= 0u, .NORTEVUELTA= 0u, .SURROJO= 0u, .SURAMARILLO= 1u, .SURVERDE= 0u, .SURVUELTA= 0u, .ESTEROJO= 1u, .ESTEAMARILLO= 0u, .ESTEVERDE= 0u, .ESTEVUELTA= 0u, .OESTEROJO= 1u, .OESTEAMARILLO= 0u, .OESTEVERDE= 0u, .OESTEVUELTA= 0u, .TIMER_MOD= 512u};/*NORTE y SUR cambian a amarillo para las vueltas*/

    FSM[14]=(state){.NORTEROJO= 1u, .NORTEAMARILLO= 0u, .NORTEVERDE= 0u, .NORTEVUELTA= 1u, .SURROJO= 1u, .SURAMARILLO= 0u, .SURVERDE= 0u, .SURVUELTA= 1u, .ESTEROJO= 1u, .ESTEAMARILLO= 0u, .ESTEVERDE= 0u, .ESTEVUELTA= 0u, .OESTEROJO= 1u, .OESTEAMARILLO= 0u, .OESTEVERDE= 0u, .OESTEVUELTA= 0u, .TIMER_MOD= 1792u};/*Las VUELTAS de NORTE y SUR estan en VERDE*/


    FSM[15]=(state){.NORTEROJO= 1u, .NORTEAMARILLO= 0u, .NORTEVERDE= 0u, .NORTEVUELTA= 0u, .SURROJO= 1u, .SURAMARILLO= 0u, .SURVERDE= 0u, .SURVUELTA= 0u, .ESTEROJO= 0u, .ESTEAMARILLO= 0u, .ESTEVERDE= 1u, .ESTEVUELTA= 0u, .OESTEROJO= 0u, .OESTEAMARILLO= 1u, .OESTEVERDE= 0u, .OESTEVUELTA= 0u, .TIMER_MOD= 512u};/*Sensor de ESTE se activa por 2 seg y OESTE esta en amarillo*/

    FSM[16]=(state){.NORTEROJO= 1u, .NORTEAMARILLO= 0u, .NORTEVERDE= 0u, .NORTEVUELTA= 0u, .SURROJO= 1u, .SURAMARILLO= 0u, .SURVERDE= 0u, .SURVUELTA= 0u, .ESTEROJO= 0u, .ESTEAMARILLO= 0u, .ESTEVERDE= 1u, .ESTEVUELTA= 1u, .OESTEROJO= 1u, .OESTEAMARILLO= 0u, .OESTEVERDE= 0u, .OESTEVUELTA= 0u, .TIMER_MOD= 1280u};/*El VERDE de la VUELTA de ESTE se enciende 5 seg*/

    FSM[17]=(state){.NORTEROJO= 1u, .NORTEAMARILLO= 0u, .NORTEVERDE= 0u, .NORTEVUELTA= 0u, .SURROJO= 1u, .SURAMARILLO= 0u, .SURVERDE= 0u, .SURVUELTA= 0u, .ESTEROJO= 0u, .ESTEAMARILLO= 1u, .ESTEVERDE= 0u, .ESTEVUELTA= 0u, .OESTEROJO= 1u, .OESTEAMARILLO= 0u, .OESTEVERDE= 0u, .OESTEVUELTA= 0u, .TIMER_MOD= 512u};/*ESTE cambia a amarillo por 2 seg*/


    FSM[18]=(state){.NORTEROJO= 1u, .NORTEAMARILLO= 0u, .NORTEVERDE= 0u, .NORTEVUELTA= 0u, .SURROJO= 1u, .SURAMARILLO= 0u, .SURVERDE= 0u, .SURVUELTA= 0u, .ESTEROJO= 0u, .ESTEAMARILLO= 1u, .ESTEVERDE= 0u, .ESTEVUELTA= 0u, .OESTEROJO= 0u, .OESTEAMARILLO= 0u, .OESTEVERDE= 1u, .OESTEVUELTA= 0u, .TIMER_MOD= 512u};/*SENSOR de OESTE se activa por 2 seg y ESTE esta en amarillo*/

    FSM[19]=(state){.NORTEROJO= 1u, .NORTEAMARILLO= 0u, .NORTEVERDE= 0u, .NORTEVUELTA= 0u, .SURROJO= 1u, .SURAMARILLO= 0u, .SURVERDE= 0u, .SURVUELTA= 0u, .ESTEROJO= 1u, .ESTEAMARILLO= 0u, .ESTEVERDE= 0u, .ESTEVUELTA= 0u, .OESTEROJO= 0u, .OESTEAMARILLO= 0u, .OESTEVERDE= 1u, .OESTEVUELTA= 1u, .TIMER_MOD= 1280u};/*El VERDE de la VUELTA de OESTE se enciende 5 seg*/

    FSM[20]=(state){.NORTEROJO= 1u, .NORTEAMARILLO= 0u, .NORTEVERDE= 0u, .NORTEVUELTA= 0u, .SURROJO= 1u, .SURAMARILLO= 0u, .SURVERDE= 0u, .SURVUELTA= 0u, .ESTEROJO= 1u, .ESTEAMARILLO= 0u, .ESTEVERDE= 0u, .ESTEVUELTA= 0u, .OESTEROJO= 0u, .OESTEAMARILLO= 1u, .OESTEVERDE= 0u, .OESTEVUELTA= 0u, .TIMER_MOD= 512u};/*OESTE cambia a amarillo por 2 segundos*/


    FSM[21]=(state){.NORTEROJO= 1u, .NORTEAMARILLO= 0u, .NORTEVERDE= 0u, .NORTEVUELTA= 0u, .SURROJO= 1u, .SURAMARILLO= 0u, .SURVERDE= 0u, .SURVUELTA= 0u, .ESTEROJO= 0u, .ESTEAMARILLO= 1u, .ESTEVERDE= 0u, .ESTEVUELTA= 0u, .OESTEROJO= 0u, .OESTEAMARILLO= 1u, .OESTEVERDE= 0u, .OESTEVUELTA= 0u, .TIMER_MOD= 512u};/*ESTE y OESTE cambian a amarillo para las vueltas*/

    FSM[22]=(state){.NORTEROJO= 1u, .NORTEAMARILLO= 0u, .NORTEVERDE= 0u, .NORTEVUELTA= 0u, .SURROJO= 1u, .SURAMARILLO= 0u, .SURVERDE= 0u, .SURVUELTA= 0u, .ESTEROJO= 1u, .ESTEAMARILLO= 0u, .ESTEVERDE= 0u, .ESTEVUELTA= 1u, .OESTEROJO= 1u, .OESTEAMARILLO= 0u, .OESTEVERDE= 0u, .OESTEVUELTA= 1u, .TIMER_MOD= 1792u};/*Las VUELTAS de NORTE y SUR estan en VERDE*/


    uint8_t SensorNORTE_REG=1;
    uint8_t SensorSUR_REG=1;
    uint8_t SensorESTE_REG=1;
    uint8_t SensorOESTE_REG=1;
    uint8_t SensorNORTE=0;
    uint8_t SensorSUR=0;
    uint8_t SensorESTE=0;
    uint8_t SensorOESTE=0;
    uint8_t estados=0;
    uint8_t TIMER_ON=0;
    uint32_t TIMER_FLAG;
    uint32_t MASK=1u<<8u;
    uint32_t MASK_OFF = MASK;

    while (1) {
    	GPIO_WritePinOutput (GPIOB, NORTE_ROJO, FSM[estados] .NORTEROJO);
    	GPIO_WritePinOutput (GPIOB, NORTE_AMARILLO, FSM[estados] .NORTEAMARILLO);
    	GPIO_WritePinOutput (GPIOB, NORTE_VERDE, FSM[estados] .NORTEVERDE);
    	GPIO_WritePinOutput (GPIOB, NORTE_VUELTA, FSM[estados] .NORTEVUELTA);
    	GPIO_WritePinOutput (GPIOE, SUR_ROJO, FSM[estados] .SURROJO);
    	GPIO_WritePinOutput (GPIOE, SUR_AMARILLO, FSM[estados] .SURAMARILLO);
    	GPIO_WritePinOutput (GPIOE, SUR_VERDE, FSM[estados] .SURVERDE);
    	GPIO_WritePinOutput (GPIOE, SUR_VUELTA, FSM[estados] .SURVUELTA);
    	GPIO_WritePinOutput (GPIOC, ESTE_ROJO, FSM[estados] .ESTEROJO);
    	GPIO_WritePinOutput (GPIOC, ESTE_AMARILLO, FSM[estados] .ESTEAMARILLO);
    	GPIO_WritePinOutput (GPIOC, ESTE_VERDE, FSM[estados] .ESTEVERDE);
    	GPIO_WritePinOutput (GPIOC, ESTE_VUELTA, FSM[estados] .ESTEVUELTA);
    	GPIO_WritePinOutput (GPIOD, OESTE_ROJO, FSM[estados] .OESTEROJO);
    	GPIO_WritePinOutput (GPIOA, OESTE_AMARILLO, FSM[estados] .OESTEAMARILLO);
    	GPIO_WritePinOutput (GPIOA, OESTE_VERDE, FSM[estados] .OESTEVERDE);
    	GPIO_WritePinOutput (GPIOA, OESTE_VUELTA, FSM[estados] .OESTEVUELTA);

    	SensorNORTE = GPIO_ReadPinInput (GPIOC, NORTE_SENSOR);
    	SensorSUR = GPIO_ReadPinInput (GPIOE, SUR_SENSOR);
    	SensorESTE = GPIO_ReadPinInput (GPIOC, ESTE_SENSOR);
    	SensorOESTE = GPIO_ReadPinInput (GPIOA, OESTE_SENSOR);


    	if (SensorNORTE == 0){
    		SensorNORTE_REG = 0;
    	}
    	if (SensorSUR == 0){
    		SensorSUR_REG = 0;
    	}
    	if (SensorESTE == 0){
    		SensorESTE_REG = 0;
    	}
    	if (SensorOESTE == 0){
    		SensorOESTE_REG = 0;
    	}

    	TIMER_FLAG = TPM_GetStatusFlags (TPM0);

    	switch (estados){

    	case 0:
    		TPM_SetTimerPeriod (TPM1, FSM[0] .TIMER_MOD);
    		TPM_StartTimer (TPM1, kTPM_SystemClock);

    		for (i=0; i<=9; i++){
    			GPIO_TogglePinsOutput (GPIOB, 1u<<1u);
    			GPIO_TogglePinsOutput (GPIOE, 1u<<21u);
    			GPIO_TogglePinsOutput (GPIOA, 1u<<12u);
    			GPIO_TogglePinsOutput (GPIOC, 1u<<4u);

    			do{

    			}while (!(TPM1 ->STATUS & MASK));
    			if (TPM1 -> STATUS & MASK){
    				TPM1 -> STATUS &= MASK_OFF;
    				TPM1 -> CNT=0;
    			}
    		}
    		TPM1 -> STATUS &= MASK_OFF;
    		TPM1 -> CNT=0;
    		TPM_StopTimer(TPM1);
    		estados=1;

    	case 1:
    		if (TIMER_ON == 0) {
    			TIMER_ON = 1;
    			TPM_SetTimerPeriod (TPM0, FSM[1] .TIMER_MOD);
    			TPM_StartTimer (TPM0, kTPM_SystemClock);
    		}
    		if (TIMER_FLAG) {
    			TPM_ClearStatusFlags (TPM0, 1u<8u);
    			TIMER_ON=0;
    			TPM_StopTimer(TPM0);
    			TPM0 -> CNT=0;

    			if ((SensorNORTE_REG==0)&& (SensorSUR_REG==1)){
    				SensorNORTE_REG=1;
    				SensorSUR_REG=1;
    				estados=7;
    			}
    			else if((SensorSUR_REG==0)&&(SensorNORTE_REG==1)){
    				SensorNORTE_REG=1;
    				SensorSUR_REG=1;
    				estados=10;
    			}
    			else if((SensorSUR_REG==0)&&(SensorNORTE_REG==0)){
    			    SensorNORTE_REG=1;
    			    SensorSUR_REG=1;
    			    estados=13;
    			}
    			else {
    				estados=2;
    			}
    		}
    		break;

    	case 2:
    		if (TIMER_ON==0){
    			TIMER_ON = 1;
    			TPM_SetTimerPeriod (TPM0, FSM[2] .TIMER_MOD);
    			TPM_StartTimer (TPM0, kTPM_SystemClock);
    		}
    		if (TIMER_FLAG){
    			TPM_ClearStatusFlags (TPM0, 1u<8u);
    			TIMER_ON=0;
    			TPM_StopTimer(TPM0);
    			TPM0 -> CNT=0;
    			estados=3;
    		}
    		break;

    	case 3:
    		if (TIMER_ON==0){
    			TIMER_ON = 1;
    		    TPM_SetTimerPeriod (TPM0, FSM[3] .TIMER_MOD);
    		    TPM_StartTimer (TPM0, kTPM_SystemClock);
    		}
    		if (TIMER_FLAG){
    			TPM_ClearStatusFlags (TPM0, 1u<8u);
    			TIMER_ON=0;
    		    TPM_StopTimer(TPM0);
    		    TPM0 -> CNT=0;
    		    estados=4;
    		}
    		break;

    	case 4:
    		if (TIMER_ON==0){
    		    TIMER_ON = 1;
    		    TPM_SetTimerPeriod (TPM0, FSM[4] .TIMER_MOD);
    		    TPM_StartTimer (TPM0, kTPM_SystemClock);
    		}
    		if (TIMER_FLAG){
    			TPM_ClearStatusFlags (TPM0, 1u<8u);
    		    TIMER_ON=0;
    		    TPM_StopTimer(TPM0);
    		    TPM0 -> CNT=0;

    		    if((SensorESTE_REG==0)&&(SensorOESTE_REG==1)){
    		    	SensorESTE_REG=1;
    		    	SensorOESTE_REG=1;
    		    	estados=15;
    		    }
    		    else if ((SensorOESTE_REG==0)&&(SensorESTE_REG==1)){
    		    	SensorESTE_REG=1;
    		    	SensorOESTE_REG=1;
    		    	estados=18;
    		    }
    		    else if ((SensorOESTE_REG==0)&&(SensorESTE_REG==0)){
    		        SensorESTE_REG=1;
    		        SensorOESTE_REG=1;
    		        estados=21;
    		    }
    		    else{
    		    	estados=5;
    		    }
    		 }
    		 break;

    	case 5:
    		if (TIMER_ON==0){

    		    TPM_SetTimerPeriod (TPM0, FSM[5] .TIMER_MOD);

    		    TPM_StartTimer (TPM0, kTPM_SystemClock);
    		    TIMER_ON = 1;
    		}
    		if (TIMER_FLAG){
    		    TPM_ClearStatusFlags (TPM0, 1u<8u);
    		    TIMER_ON=0;
    		    TPM_StopTimer(TPM0);
    		    TPM0 -> CNT=0;
    		    estados=6;
    		}
    		break;

    	case 6:
    	    if (TIMER_ON==0){
    	    	TIMER_ON = 1;
    	    	TPM_SetTimerPeriod (TPM0, FSM[6] .TIMER_MOD);
    	    	TPM_StartTimer (TPM0, kTPM_SystemClock);
    	    }
    	    if (TIMER_FLAG){
    	    	TPM_ClearStatusFlags (TPM0, 1u<8u);
    	    	TIMER_ON=0;
    	    	TPM_StopTimer(TPM0);
    	    	TPM0 -> CNT=0;
    	    	estados=1;
    	    }
    	    break;

    	case 7:
    		if (TIMER_ON==0){
    	    	TIMER_ON = 1;
    	    	TPM_SetTimerPeriod (TPM0, FSM[7] .TIMER_MOD);
    	    	TPM_StartTimer (TPM0, kTPM_SystemClock);
    		}
    		if (TIMER_FLAG){
    	    	TPM_ClearStatusFlags (TPM0, 1u<8u);
    	    	TIMER_ON=0;
    	    	TPM_StopTimer(TPM0);
    	    	TPM0 -> CNT=0;
    	    	estados=8;
    	    }
    		break;

    	case 8:
    		if (TIMER_ON==0){
    	    	TIMER_ON = 1;
    	    	TPM_SetTimerPeriod (TPM0, FSM[8] .TIMER_MOD);
    	    	TPM_StartTimer (TPM0, kTPM_SystemClock);
    	    }
    		if (TIMER_FLAG){
    	    	TPM_ClearStatusFlags (TPM0, 1u<8u);
    	    	TIMER_ON=0;
    	    	TPM_StopTimer(TPM0);
    	    	TPM0 -> CNT=0;
    	    	estados=9;
    	    }
    		break;

    	case 9:
    	    if (TIMER_ON==0){
    	    	TIMER_ON = 1;
    	    	TPM_SetTimerPeriod (TPM0, FSM[9] .TIMER_MOD);
    	    	TPM_StartTimer (TPM0, kTPM_SystemClock);
    	    }
    	    if (TIMER_FLAG){
    	    	TPM_ClearStatusFlags (TPM0, 1u<8u);
    	    	TIMER_ON=0;
    	    	TPM_StopTimer(TPM0);
    	    	TPM0 -> CNT=0;
    	    	estados=4;
    	    }
    	    break;

    	 case 10:
    	     if (TIMER_ON==0){
    	    	 TIMER_ON = 1;
    	    	 TPM_SetTimerPeriod (TPM0, FSM[10] .TIMER_MOD);
    	    	 TPM_StartTimer (TPM0, kTPM_SystemClock);
    	     }
    	     if (TIMER_FLAG){
    	    	 TPM_ClearStatusFlags (TPM0, 1u<8u);
    	    	 TIMER_ON=0;
    	    	 TPM_StopTimer(TPM0);
    	    	 TPM0 -> CNT=0;
    	    	 estados=11;
    	     }
    	     break;

    	 case 11:
    		 if (TIMER_ON==0){
    	     	 TIMER_ON = 1;
    	     	 TPM_SetTimerPeriod (TPM0, FSM[11] .TIMER_MOD);
    	     	 TPM_StartTimer (TPM0, kTPM_SystemClock);
    	     }
    		 if (TIMER_FLAG){
    	     	 TPM_ClearStatusFlags (TPM0, 1u<8u);
    	     	 TIMER_ON=0;
    	     	 TPM_StopTimer(TPM0);
    	     	 TPM0 -> CNT=0;
    	     	 estados=12;
    	     }
    		 break;

    	 case 12:
    	     if (TIMER_ON==0){
    	     	 TIMER_ON = 1;
    	     	 TPM_SetTimerPeriod (TPM0, FSM[12] .TIMER_MOD);
    	     	 TPM_StartTimer (TPM0, kTPM_SystemClock);
    	     }
    	     if (TIMER_FLAG){
    	     	 TPM_ClearStatusFlags (TPM0, 1u<8u);
    	     	 TIMER_ON=0;
    	     	 TPM_StopTimer(TPM0);
    	     	 TPM0 -> CNT=0;
    	     	 estados=4;
    	     }
    	     break;

    	 case 13:
    	     if (TIMER_ON==0){
    	     	 TIMER_ON = 1;
    	     	 TPM_SetTimerPeriod (TPM0, FSM[13] .TIMER_MOD);
    	     	 TPM_StartTimer (TPM0, kTPM_SystemClock);
    	     }
    	     if (TIMER_FLAG){
    	     	 TPM_ClearStatusFlags (TPM0, 1u<8u);
    	     	 TIMER_ON=0;
    	     	 TPM_StopTimer(TPM0);
    	     	 TPM0 -> CNT=0;
    	     	 estados=14;
    	    }
    	    break;

    	 case 14:
    	     if (TIMER_ON==0){
    	     	 TIMER_ON = 1;
    	     	 TPM_SetTimerPeriod (TPM0, FSM[14] .TIMER_MOD);
    	     	 TPM_StartTimer (TPM0, kTPM_SystemClock);
    	     }
    	     if (TIMER_FLAG){
    	     	 TPM_ClearStatusFlags (TPM0, 1u<8u);
    	     	 TIMER_ON=0;
    	     	 TPM_StopTimer(TPM0);
    	     	 TPM0 -> CNT=0;
    	     	 estados=3;
    	    }
    	    break;


    	 case 15:
    	     if (TIMER_ON==0){
    	     	 TIMER_ON = 1;
    	     	 TPM_SetTimerPeriod (TPM0, FSM[15] .TIMER_MOD);
    	     	 TPM_StartTimer (TPM0, kTPM_SystemClock);
    	     }
    	     if (TIMER_FLAG){
    	     	 TPM_ClearStatusFlags (TPM0, 1u<8u);
    	     	 TIMER_ON=0;
    	     	 TPM_StopTimer(TPM0);
    	     	 TPM0 -> CNT=0;
    	     	 estados=16;
    	     }
    	     break;


    	 case 16:
    		 if (TIMER_ON==0){
    	     	 TIMER_ON = 1;
    	     	 TPM_SetTimerPeriod (TPM0, FSM[16] .TIMER_MOD);
    	     	 TPM_StartTimer (TPM0, kTPM_SystemClock);
    	     }
    	     if (TIMER_FLAG){
    	     	 TPM_ClearStatusFlags (TPM0, 1u<8u);
    	     	 TIMER_ON=0;
    	     	 TPM_StopTimer(TPM0);
    	     	 TPM0 -> CNT=0;
    	     	 estados=17;
    	     }
    	     break;

    	 case 17:
    	     if (TIMER_ON==0){
    	     	 TIMER_ON = 1;
    	     	 TPM_SetTimerPeriod (TPM0, FSM[17] .TIMER_MOD);
    	     	 TPM_StartTimer (TPM0, kTPM_SystemClock);
    	     }
    	     if (TIMER_FLAG){
    	     	 TPM_ClearStatusFlags (TPM0, 1u<8u);
    	     	 TIMER_ON=0;
    	     	 TPM_StopTimer(TPM0);
    	     	 TPM0 -> CNT=0;
    	     	 estados=1;
    	     }
    	     break;


    	 case 18:
    		 if (TIMER_ON==0){
    	     	 TIMER_ON = 1;
    	     	 TPM_SetTimerPeriod (TPM0, FSM[18] .TIMER_MOD);
    	     	 TPM_StartTimer (TPM0, kTPM_SystemClock);
    	     }
    	     if (TIMER_FLAG){
    	     	 TPM_ClearStatusFlags (TPM0, 1u<8u);
    	     	 TIMER_ON=0;
    	     	 TPM_StopTimer(TPM0);
    	     	 TPM0 -> CNT=0;
    	     	 estados=19;
    	     }
    	     break;


    	 case 19:
    	     if (TIMER_ON==0){
    	     	 TIMER_ON = 1;
    	     	 TPM_SetTimerPeriod (TPM0, FSM[19] .TIMER_MOD);
    	     	 TPM_StartTimer (TPM0, kTPM_SystemClock);
    	     }
    	     if (TIMER_FLAG){
    	     	 TPM_ClearStatusFlags (TPM0, 1u<8u);
    	     	 TIMER_ON=0;
    	     	 TPM_StopTimer(TPM0);
    	     	 TPM0 -> CNT=0;
    	     	 estados=20;
    	     }
    	     break;

    	 case 20:
    	     if (TIMER_ON==0){
    	     	 TIMER_ON = 1;
    	     	 TPM_SetTimerPeriod (TPM0, FSM[20] .TIMER_MOD);
    	     	 TPM_StartTimer (TPM0, kTPM_SystemClock);
    	     }
    	     if (TIMER_FLAG){
    	     	 TPM_ClearStatusFlags (TPM0, 1u<8u);
    	     	 TIMER_ON=0;
    	     	 TPM_StopTimer(TPM0);
    	     	 TPM0 -> CNT=0;
    	     	 estados=1;
    	     }
    	     break;


    	 case 21:
    	     if (TIMER_ON==0){
    	     	 TIMER_ON = 1;
    	     	 TPM_SetTimerPeriod (TPM0, FSM[21] .TIMER_MOD);
    	     	 TPM_StartTimer (TPM0, kTPM_SystemClock);
    	     }
    	     if (TIMER_FLAG){
    	     	 TPM_ClearStatusFlags (TPM0, 1u<8u);
    	     	 TIMER_ON=0;
    	     	 TPM_StopTimer(TPM0);
    	     	 TPM0 -> CNT=0;
    	     	 estados=22;
    	     }
    	     break;


    	 case 22:
    	     if (TIMER_ON==0){
    	     	 TIMER_ON = 1;
    	     	 TPM_SetTimerPeriod (TPM0, FSM[22] .TIMER_MOD);
    	     	 TPM_StartTimer (TPM0, kTPM_SystemClock);
    	     }
    	     if (TIMER_FLAG){
    	     	 TPM_ClearStatusFlags (TPM0, 1u<8u);
    	     	 TIMER_ON=0;
    	     	 TPM_StopTimer(TPM0);
    	     	 TPM0 -> CNT=0;
    	     	 estados=6;
    	     }
    	     break;
    	}
    }


    return 0 ;
}
