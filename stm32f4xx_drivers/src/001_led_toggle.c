/*
 * 001_led_toggle.c
 *
 *  Created on: Nov 15, 2019
 *      Author: BecirP
 */


#include "stm32f446xx.h"
#include "stm32f446xx_gpio.h"

void delay(void)
{
	for(uint32_t i = 0; i < 1000000; i++);
}


int main(void)
{

	GPIO_Handle_t ledGPIO;
	ledGPIO.pGPIOx = GPIOA;
	ledGPIO.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_5;
	ledGPIO.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUTPUT;
	ledGPIO.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	ledGPIO.GPIO_PinConfig.GPIO_PinOPType = GPIO_OUT_TYPE_PP;
	ledGPIO.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;


	GPIO_PClockControl(GPIOA, ENABLE);

	GPIO_Init(&ledGPIO);

	while(1)
	{
		GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_5);
		delay();
	}

	return 0;
}
