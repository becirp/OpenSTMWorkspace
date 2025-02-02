/*
 * stm32f446xx_gpio.h
 *
 *  Created on: Nov 13, 2019
 *      Author: BecirP
 */

#ifndef INC_STM32F446XX_GPIO_H_
#define INC_STM32F446XX_GPIO_H_

#include "stm32f446xx.h"

/*
 * Configuration structure for GPIO pin
 */

typedef struct
{
	uint8_t GPIO_PinNumber;				/*!< Possible values from  	@GPIO_PIN_NUMBERS		*/
	uint8_t GPIO_PinMode;				/*!< Possible values from  	@GPIO_PIN_MODES  		*/
	uint8_t GPIO_PinSpeed;				/*!< Possible values from  	@GPIO_PIN_SPEED  		*/
	uint8_t GPIO_PinPuPdControl;		/*!< Possible values from  	@GPIO_PIN_PUPD  		*/
	uint8_t GPIO_PinOPType;				/*!< Possible values from  	@GPIO_PIN_OUT_MODES	    */
	uint8_t GPIO_PinAltFunctionMode;	/*!< Possible values from  	@GPIO_PIN_ALTERNATE	    */
}GPIO_PinConfig_t;

/*
 * Handle structure for GPIO pin
 */

typedef struct
{
	GPIO_RegDef_t *pGPIOx;    			/*!< Holds GPIO Base Address of the port to which the pin belongs */
	GPIO_PinConfig_t GPIO_PinConfig;	/*!< Holds GPIO pin configuration settings 						  */
}GPIO_Handle_t;

/*
 * @GPIO_PIN_MODES
 * GPIO pin input possible modes
 */

#define GPIO_MODE_INPUT 		0
#define GPIO_MODE_OUTPUT 		1
#define GPIO_MODE_ALTERNATE 	2
#define GPIO_MODE_ANALOG		3
#define GPIO_MODE_IN_FT			4
#define GPIO_MODE_IN_RT			5
#define GPIO_MODE_IN_RFT		6

/*
 * @GPIO_PIN_OUT_MODES
 * GPIO pin output possible modes
 */

#define GPIO_OUT_TYPE_PP		0
#define GPIO_OUT_TYPE_OD		1

/*
 * @GPIO_PIN_SPEED
 * GPIO pin possible output speed
 */

#define GPIO_SPEED_LOW			0
#define GPIO_SPEED_MEDIUM		1
#define GPIO_SPEED_FAST			2
#define GPIO_SPEED_HIGH			3

/*
 * @GPIO_PIN_PUPD
 * GPIO pin pull up pull down configurations
 */

#define GPIO_NO_PUPD			0
#define GPIO_PIN_PU				1
#define GPIO_PIN_PD				2

/*
 * @GPIO_PIN_NUMBERS
 * GPIO pin numbers definitions
 */

#define GPIO_PIN_0				0
#define GPIO_PIN_1				1
#define GPIO_PIN_2				2
#define GPIO_PIN_3				3
#define GPIO_PIN_4				4
#define GPIO_PIN_5				5
#define GPIO_PIN_6				6
#define GPIO_PIN_7				7
#define GPIO_PIN_8				8
#define GPIO_PIN_9				9
#define GPIO_PIN_10				10
#define GPIO_PIN_11				11
#define GPIO_PIN_12				12
#define GPIO_PIN_13				13
#define GPIO_PIN_14				14
#define GPIO_PIN_15				15




/******************************************************************************/
/*                                                                            */
/*                	 APIs supported by this driver                            */
/*                                                                            */
/******************************************************************************/

/*
 * Peripheral clock setup
 */
void GPIO_PClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnDi);

/*
 * Init and de-init
 */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);

/*
 * Data read and write
 */
uint8_t GPIO_ReadInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
uint16_t GPIO_ReadInputPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value);
void GPIO_WriteOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value);
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);

/*
 * IRQ configuration and ISR handling
 */
void GPIO_IRQNumberConfig(uint8_t IRQNumber, uint8_t EnDi);
void GPIO_IRQHandling(uint8_t PinNumber);
void GPIO_IRQPriorityCfg(uint8_t IRQNumber, uint8_t IRQPriority);














#endif /* INC_STM32F446XX_GPIO_H_ */
