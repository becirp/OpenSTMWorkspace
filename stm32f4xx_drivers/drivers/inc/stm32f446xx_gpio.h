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
	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode;
	uint8_t GPIO_PinSpeed;
	uint8_t GPIO_PinPuPdControl;
	uint8_t GPIO_PinOPType;
	uint8_t GPIO_PinAltFunctionMode;
}GPIO_PinConfig_t;

/*
 * Handle structure for GPIO pin
 */

typedef struct
{
	GPIO_RegDef_t *pGPIOx;    			/*!< Holds GPIO Base Address of the port to which the pin belongs */
	GPIO_PinConfig_t GPIO_PinConfig;	/*!< Holds GPIO pin configuration settings 						  */

}GPIO_Handle_t;

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
void GPIO_ReadInputPin(void);
void GPIO_ReadInputPort(void);
void GPIO_WriteOutputPin(void);
void GPIO_WriteOutputPort(void);
void GPIO_ToggleOutputPin(void);

/*
 * IRQ configuration and ISR handling
 */
void GPIO_IRQConfig(void);
void GPIO_IRQHandling(void);














#endif /* INC_STM32F446XX_GPIO_H_ */
