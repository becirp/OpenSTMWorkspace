/*
 * 002_led_button.c
 *
 *  Created on: Dec 1, 2019
 *      Author: becir
 */


#include "stm32f446xx.h"
#include "stm32f446xx_gpio.h"

#define BUTTON_PRESSED (uint8_t)0

void delay(void)
{
	for(uint32_t i = 0; i < 500000; i++);
}


int main(void)
{

	GPIO_Handle_t led_GPIO, button_GPIO;

	led_GPIO.pGPIOx = GPIOA;
	led_GPIO.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_5;
	led_GPIO.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUTPUT;
	led_GPIO.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;
	led_GPIO.GPIO_PinConfig.GPIO_PinOPType = GPIO_OUT_TYPE_PP;
	led_GPIO.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	GPIO_PClockControl(GPIOA, ENABLE);
	GPIO_Init(&led_GPIO);

	button_GPIO.pGPIOx = GPIOC;
	button_GPIO.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_13;
	button_GPIO.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_INPUT;
	button_GPIO.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_LOW;
	button_GPIO.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	GPIO_PClockControl(GPIOC, ENABLE);
	GPIO_Init(&button_GPIO);

	while(1)
	{
		if(GPIO_ReadInputPin(GPIOC, GPIO_PIN_13) == BUTTON_PRESSED)
		{
			GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_5);
			delay();
		}
	}

	return 0;
}


