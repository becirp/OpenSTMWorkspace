/*
 * stm32f446xx_gpio.c
 *
 *  Created on: Nov 13, 2019
 *      Author: BecirP
 */


#include "stm32f446xx_gpio.h"

/******************************************************************************
 * @fn     		-   GPIO_PClockControl
 *
 * @brief		-	This function disables or enables peripheral clock for a given GPIO pin
 *
 * @param1		-	Base address of GPIO peripheral
 * @param2		-	ENABLE or DISABLE macros
 *
 * @return		-	none
 *
 * @note  		-	none
 */
void GPIO_PClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnDi)
{
	if(EnDi == 1)
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_PCLK_EN();
		}
		if(pGPIOx == GPIOB)
		{
			GPIOB_PCLK_EN();
		}
		if(pGPIOx == GPIOC)
		{
			GPIOC_PCLK_EN();
		}
		if(pGPIOx == GPIOD)
		{
			GPIOD_PCLK_EN();
		}
		if(pGPIOx == GPIOE)
		{
			GPIOE_PCLK_EN();
		}
		if(pGPIOx == GPIOF)
		{
			GPIOF_PCLK_EN();
		}
		if(pGPIOx == GPIOG)
		{
			GPIOG_PCLK_EN();
		}
		if(pGPIOx == GPIOH)
		{
			GPIOH_PCLK_EN();
		}
	}
	else
	{
		if(pGPIOx == GPIOA)
		{
			GPIOA_PCLK_DI();
		}
		if(pGPIOx == GPIOB)
		{
			GPIOB_PCLK_DI();
		}
		if(pGPIOx == GPIOC)
		{
			GPIOC_PCLK_DI();
		}
		if(pGPIOx == GPIOD)
		{
			GPIOD_PCLK_DI();
		}
		if(pGPIOx == GPIOE)
		{
			GPIOE_PCLK_DI();
		}
		if(pGPIOx == GPIOF)
		{
			GPIOF_PCLK_DI();
		}
		if(pGPIOx == GPIOG)
		{
			GPIOG_PCLK_DI();
		}
		if(pGPIOx == GPIOH)
		{
			GPIOH_PCLK_DI();
		}
	}

}

/******************************************************************************
 * @fn     		-   GPIO_Init
 *
 * @brief		-	This function initializes GPIO port according to the handle
 *
 * @param1		-	GPIO structure handle with appropriate configuration
 *
 * @return		-	none
 *
 * @note  		-	none
 */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle)
{
	//1. Configure the mode of GPIO pin
	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG)
	{
		//non-interrupt mode
		pGPIOHandle->pGPIOx->MODER &= ~(0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)); //bitwise clear register
		pGPIOHandle->pGPIOx->MODER |= (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber)); //bitwise set register
	}
	else
	{
		//todo: code later, interrupt mode
	}

	//2. Configure the speed of GPIO pin
	pGPIOHandle->pGPIOx->OSPEEDER &= ~(0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OSPEEDER |= (pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));

	//3. Configure the pupd of GPIO pin
	pGPIOHandle->pGPIOx->PUPDR &= ~(0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->PUPDR |= (pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));

	//4. Configure the otype of GPIO pin
	pGPIOHandle->pGPIOx->OTYPER &= ~(0x1 << pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber);
	pGPIOHandle->pGPIOx->OTYPER |= (pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType << (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));

	//5. Configure the alternate functionality of GPIO pin
	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTERNATE)
	{
		uint8_t reg_select, reg_shift;
		reg_select = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber / 8;
		reg_shift = pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber % 8;
		pGPIOHandle->pGPIOx->AFRL[reg_select] &= ~(0xF << (4 * reg_shift));
		pGPIOHandle->pGPIOx->AFRL[reg_select] |= (pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunctionMode << (4 * reg_shift));
	}
}


/******************************************************************************
 * @fn     		-   GPIO_DeInit
 *
 * @brief		-	This function resets GPIOx registers
 *
 * @param1		-	Base address of GPIO peripheral
 *
 * @return		-	none
 *
 * @note  		-	none
 */

void GPIO_DeInit(GPIO_RegDef_t *pGPIOx)
{
	if(pGPIOx == GPIOA)
	{
		GPIOA_REG_RESET();
	}
	if(pGPIOx == GPIOB)
	{
		GPIOB_REG_RESET();
	}
	if(pGPIOx == GPIOC)
	{
		GPIOC_REG_RESET();
	}
	if(pGPIOx == GPIOD)
	{
		GPIOD_REG_RESET();
	}
	if(pGPIOx == GPIOE)
	{
		GPIOE_REG_RESET();
	}
	if(pGPIOx == GPIOF)
	{
		GPIOF_REG_RESET();
	}
	if(pGPIOx == GPIOG)
	{
		GPIOG_REG_RESET();
	}
	if(pGPIOx == GPIOH)
	{
		GPIOH_REG_RESET();
	}

}

/******************************************************************************
 * @fn     		-   GPIO_ReadInputPin
 *
 * @brief		-	This function reads GPIOx IDR register of designated PIN and returns it's value
 *
 * @param1		-	Base address of GPIO peripheral
 * @param2		-	Pin number
 *
 * @return		-	0 or 1
 *
 * @note  		-	none
 */
uint8_t GPIO_ReadInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	return (uint8_t)((pGPIOx->IDR >> PinNumber) & 0x01);
}


/******************************************************************************
 * @fn     		-   GPIO_ReadInputPort
 *
 * @brief		-	This function reads GPIOx IDR register and returns it's value
 *
 * @param1		-	Base address of GPIO peripheral
 *
 * @return		-	2 bytes
 *
 * @note  		-	none
 */

uint16_t GPIO_ReadInputPort(GPIO_RegDef_t *pGPIOx)
{
	return (uint16_t)pGPIOx->IDR;
}


/******************************************************************************
 * @fn     		-   GPIO_WriteOutputPin
 *
 * @brief		-	This function writes to GPIOx pin corresponding bit field value
 *
 * @param1		-	Base address of GPIO peripheral
 * @param2		-	Pin number
 * @param3		-	value
 *
 * @return		-	none
 *
 * @note  		-	none
 */
void GPIO_WriteOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value)
{
	if(Value == GPIO_PIN_SET)
	{
		pGPIOx->ODR |= (1 << PinNumber);
	}
	else
	{
		pGPIOx->ODR &= ~(1 << PinNumber);
	}
}


/******************************************************************************
 * @fn     		-   GPIO_WriteOutputPort
 *
 * @brief		-	This function writes to GPIOx port 2bytes
 *
 * @param1		-	Base address of GPIO peripheral
 * @param2		-	Value
 *
 * @return		-	none
 *
 * @note  		-	none
 */
void GPIO_WriteOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value)
{
	pGPIOx->ODR = Value;
}


/******************************************************************************
 * @fn     		-   GPIO_ToggleOutputPin
 *
 * @brief		-	This function toggles output pin between HIGH and LOW
 *
 * @param1		-	Base address of GPIO peripheral
 * @param2		-	Pin number
 *
 * @return		-	none
 *
 * @note  		-	none
 */
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber)
{
	pGPIOx->ODR ^= (1 << PinNumber);
}



/*
 * IRQ configuration and ISR handling
 */
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnDi)
{

}
void GPIO_IRQHandling(uint8_t PinNumber)
{

}


