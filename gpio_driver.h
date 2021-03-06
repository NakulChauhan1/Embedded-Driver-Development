//gpio_driver.h contains driver specific data.
//Write all driver header related details here. It will have APIs prototype (majoritly).


#ifndef GPIO_DRIVER_H
#define GPIO_DRIVER_H




#include "mcu_specific_header_file.h"						//This file contains mcu specific data //#include "stm32f446xx.h"//Write all the header details here

typedef struct																																																						//user must pass something to driver layer, some functionality which he want to change, so there must be some strucure which he can fill (apart from base address of Port), so this is structure which he had to fill, in order to have its work done.																																		
{
	 	uint8_t GPIO_PinNumber;							/* possible values from @GPIO_PINs */
		uint8_t GPIO_PinMode;								/* possible values from @GPIO_PIN_MODES */
		uint8_t GPIO_PinOPType;							/* possible values from @GPIO_OPTYPE */
		uint8_t GPIO_PinSpeed;							/* possible values from @GPIO_PIN_SPEED */
		uint8_t GPIO_PinPuPdControl;				/* possible values from @GPIO_PD_PU */
		uint8_t GPIO_PinAltFunMode;					/* possible values from @GPIO_ALTFUNCT */										                       //uint8_t IDR;uint8_t ODR;	uint8_t BSRR;uint8_t LCKR;						//we are not including IDR, ODR because these are not configuration of a pin, if we want to use these register then we will use addreses from mcu specific header file. remember our purpose in driver file is to help user to configure pin
		
}GPIO_PinConfig_t;																																																				//this structure is optional, without it we would have to make functions which consisits of too many arguements, equal to number of members of structure.


typedef struct																				
{
		GPIO_RegDef_t * pGPIOx;
		GPIO_PinConfig_t GPIO_PinConfig;
}GPIO_Handle_t;


//user application can use this macro whenever user application wants to do the settings.
/*
* @GPIO_PIN_MODES
* GPIO pin possible mode																										//since these macros are peripheral specific therefore we are creating it in driver.h not mcu_specific.h
*/
#define GPIO_MODE_INP	 		0
#define GPIO_MODE_OUT 		1
#define GPIO_MODE_ALTFN 	2
#define GPIO_MODE_ANALOG 	3
#define GPIO_MODE_IT_FT 	4			//values 4,5,6 are assumed for interrupt functionalit, they values are not taken from reference manual.
#define GPIO_MODE_IT_RT 	5
#define GPIO_MODE_IT_RFT 	6



/*
* @GPIO_OPTYPE
* GPIO Pin possible output types
*/
#define GPIO_OP_TYPE_PP  0
#define GPIO_OP_TYPE_OD  1



/*
* @GPIO_PIN_SPEED
* GPIO Pin possible output speed
*/
#define GPIO_SPEED_LOW	 0
#define GPIO_SPEED_MED   1
#define GPIO_SPEED_FAST  2
#define GPIO_SPEED_HIGH  3


/*
* @GPIO_PD_PU
* GPIO Pin Pull up and Pull up macros
*/
#define GPIO_NO_PUPD	     0
#define GPIO_PIN_PU   		 1
#define GPIO_PIN_PD			   2



/*
* @GPIO_PINs
* GPIO Pin macros
*/
#define GPIO_PIN_NO_0  0
#define GPIO_PIN_NO_1  1
#define GPIO_PIN_NO_2  2
#define GPIO_PIN_NO_3  3
#define GPIO_PIN_NO_4  4
#define GPIO_PIN_NO_5  5
#define GPIO_PIN_NO_6  6
#define GPIO_PIN_NO_7  7
#define GPIO_PIN_NO_8  8
#define GPIO_PIN_NO_9  9
#define GPIO_PIN_NO_10 10
#define GPIO_PIN_NO_11 11
#define GPIO_PIN_NO_12 12
#define GPIO_PIN_NO_13 13
#define GPIO_PIN_NO_14 14
#define GPIO_PIN_NO_15 15


/*
* @GPIO_ALTFUNCT
* GPIO Pin macros for Alternate Functionality
*/


/*

.
.
.
.

#define	0 
#define	1
#define	2
#define	3
#define	4
#define	5
#define	6
#define	7

.
.
.
.
*/


/******************************************************************************************
 *								APIs supported by this driver
 *		 For more information about the APIs check the function definitions
 ******************************************************************************************/


/*
* Init and De-init
*/

void GPIO_Init( GPIO_Handle_t *pGPIOHandle );																																								//GPIO_Handle_t structure will be filled by application programmer ie. all 6 member elemnts will be initialised at application layer will be passed to this function.
void GPIO_DeInit( GPIO_RegDef_t *pGPIOx );


/*
* Peripheral Clock setup
*/

void GPIO_PeriClockControl( GPIO_RegDef_t * pGPIOx, uint8_t ENorDI);																												//enable or disable, the peripheral clock for a given GPIO base. NOw since we have to choose 0 or 1, so we have to create macro for both values to make task of user easy.



/*
* Data read and write
*/

uint16_t  GPIO_ReadFromInputPort( GPIO_RegDef_t *pGPIOx );																																	//return type is uint16_t because Input Data Register is 16bit long
uint8_t  GPIO_ReadFromInputPin( GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
void GPIO_WriteToOutputPort( GPIO_RegDef_t *pGPIOx, uint16_t Value);
void GPIO_WriteToOutputPin( GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);		
void GPIO_ToggleOutputPin( GPIO_RegDef_t * pGPIOx, uint8_t PinNumber );


/*
* IRQ Configuration and ISR handling
*/

void GPIO_InterruptConfig( uint32_t IRQNumber, uint8_t EnorDi );																																	//used to configure IRQ number like enabling it, disabling, changing priority
void GPIO_IRQPriorityConfig( uint8_t IRQNumber, uint32_t IRQPriority );
void GPIO_IRQHandling( uint8_t PinNumber );																																									//means whenever interrupt occurs, user application should call this function in order to process that interrupt.

uint8_t getportcode( GPIO_RegDef_t *pGPIOx ) ;

#endif
