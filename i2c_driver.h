

#ifndef __I2C_DRIVER_H
#define __I2C_DRIVER_H


#include "mcu_specific_header_file.h"



/*
 *  Configuration structure for SPIx peripheral
 */
 
typedef struct
{
		uint32_t I2C_SCLSpeed;
		uint8_t	 I2C_DeviceAddress;
		uint8_t	 I2C_ACKControl;
		uint16_t I2C_FMDutyCycle;
}I2C_Config_t;



/*
 *Handle structure for I2Cx peripheral
 */

typedef struct
{
		I2C_RegDef_t * pI2Cx;
		I2C_Config_t  I2C_Config;
}I2C_Handle_t;





/*
 * @I2C_SCLSpeed
 */

#define	I2C_SCL_SPEED_SM			100000												//Standard Mode 100k
#define	I2C_SCL_SPEED_FM4k		400000												//Fast Mode 400k , Note: Anything greater then 400k is considered as Fast Mode
#define	I2C_SCL_SPEED_FM2k		200000												//Fast Mode 200k


/*
 * @I2C_SlaveAddress
 */

// user is going to mention the adrress of Slave, therefore no macros.


/*
 * @I2C_AckControl
 */

#define I2C_ACK_ENABLE        1
#define I2C_ACK_DISABLE       0


/*
 * @I2C_FMDutyCycle
 */
 
#define I2C_FM_DUTY_2        0
#define I2C_FM_DUTY_16_9     1

/*
 *	@I2C related status flags definitions ( Masking details of various flags )
 */
 
 #define I2C_SB_FLAG						  ( 1 << I2C_SR1_SB )
 #define I2C_ADDR_FLAG						( 1 << 1 )
 #define I2C_BTF_FLAG				  		( 1 << 2 )
 #define I2C_ADD10_FLAG						( 1 << 3 )
 #define I2C_STOPF_FLAG						( 1 << 4 )
 #define I2C_RxNE_FLAG						( 1 << 6 )
 #define I2C_TxE_FLAG				  		( 1 << 7 )
 #define I2C_BERR_FLAG						( 1 << 8 )
 #define I2C_ARLO_FLAG						( 1 << 9 )
 #define I2C_AF_FLAG				   		( 1 << 10 )
 #define I2C_OVR_FLAG							( 1 << 11 )
 #define I2C_PEC_ERR_FLAG					( 1 << 12 )
 #define I2C_TIMEOUT_FLAG					( 1 << 14 )
 #define I2C_SMBALERT_FLAG				( 1 << 15 )
 
 
 /*
 *	@Other I2C related Macros
 */
 
 #define I2C_DISABLE_SR						RESET
 #define I2C_ENABLE_SR						SET

/******************************************************************************************
 *								APIs supported by this driver
 *		 For more information about the APIs check the function definitions
 ******************************************************************************************/
 
/*
 * Peripheral Clock setup
 */
 
 void I2C_PeriClockControl ( I2C_RegDef_t * pI2Cx, uint8_t ENorDi );

/*
 * Init or Deinit
 */
 
 void I2C_Init ( I2C_Handle_t * pI2Cx );
 void I2C_Deinit ( I2C_RegDef_t * pI2Cx );
 
/*
 * Data Send and Receive
 */ 
 
 void I2C_MasterSendData ( I2C_RegDef_t * pI2Cx, uint8_t * pTxbuffer, uint32_t Len, uint8_t SlaveAddr, uint8_t Sr );
 void I2C_MasterReceiveData ( I2C_RegDef_t * pI2Cx, uint8_t * pRxbuffer, uint8_t Len, uint8_t SlaveAddr, uint8_t Sr);


/*
 * Other Peripheral Control APIs
 */
 
 void I2C_PeripheralControl ( I2C_RegDef_t * pI2Cx, uint8_t EnorDi );
 void I2C_ManageAcking(I2C_RegDef_t *pI2Cx, uint8_t EnorDi);
	
 uint32_t RCC_GetPCLK1Value ( void ) ;
 
 
#endif
