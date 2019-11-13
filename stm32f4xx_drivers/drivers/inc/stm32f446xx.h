/*
 * stm32f446xx.h
 *
 *  Created on: Nov 13, 2019
 *      Author: BecirP
 */

#ifndef INC_STM32F446XX_H_
#define INC_STM32F446XX_H_

#include <stdint.h>

#define __vo volatile


/******************************************************************************/
/*                                                                            */
/*                        Base Addresses of Peripherals                       */
/*                                                                            */
/******************************************************************************/

/*
 * Base adresses of flash and RAM memories
 */

#define FLASH_BASEADDR 				0x08000000U				//Base address of Flash memory (512KB)
#define SRAM1_BASEADDR 				0x20000000U				//Base address of SRAM1 memory (112KB)
#define SRAM2_BASEADDR				0x2001C000U				//Base address of SRAM2 memory (16KB)
#define ROM_BASEADDR				0x1FFF0000U				//Base address of System memory (30KB)
#define OTP_BASEADDR				0x1FFF7800U				//Base address of OTP memory (528B)
#define SRAM 						SRAM1_BASEADDR

/*
 * AHBx and APBx Bus peripheral base addresses
 */

#define PERIPH_BASE 				0x40000000U
#define APB1PERIPH_BASEADDR 		PERIPH_BASE
#define APB2PERIPH_BASEADDR			0x40010000U
#define AHB1PERIPH_BASEADDR 		0x40020000U
#define AHB2PERIPH_BASEADDR 		0x50000000U

/*
 * Base addresses of peripherals hanging on AHB1 bus
 */

#define GPIOA_BASEADDR              (AHB1PERIPH_BASEADDR + 0x0000U)
#define GPIOB_BASEADDR              (AHB1PERIPH_BASEADDR + 0x0400U)
#define GPIOC_BASEADDR              (AHB1PERIPH_BASEADDR + 0x0800U)
#define GPIOD_BASEADDR              (AHB1PERIPH_BASEADDR + 0x0C00U)
#define GPIOE_BASEADDR              (AHB1PERIPH_BASEADDR + 0x1000U)
#define GPIOF_BASEADDR              (AHB1PERIPH_BASEADDR + 0x1400U)
#define GPIOG_BASEADDR              (AHB1PERIPH_BASEADDR + 0x1800U)
#define GPIOH_BASEADDR              (AHB1PERIPH_BASEADDR + 0x1C00U)
#define RCC_BASEADDR	   		    (AHB1PERIPH_BASEADDR + 0x3800U)

/*
 * Base addresses of peripherals hanging on APB1 bus
 */

#define I2C1_BASEADDR               (APB1PERIPH_BASEADDR + 0x5400U)
#define I2C2_BASEADDR               (APB1PERIPH_BASEADDR + 0x5800U)
#define I2C3_BASEADDR               (APB1PERIPH_BASEADDR + 0x5C00U)

#define SPI2_BASEADDR               (APB1PERIPH_BASEADDR + 0x3800U)
#define SPI3_BASEADDR               (APB1PERIPH_BASEADDR + 0x3C00U)

#define USART2_BASEADDR             (APB1PERIPH_BASEADDR + 0x4400U)
#define USART3_BASEADDR             (APB1PERIPH_BASEADDR + 0x4800U)
#define UART4_BASEADDR              (APB1PERIPH_BASEADDR + 0x4C00U)
#define UART5_BASEADDR              (APB1PERIPH_BASEADDR + 0x5000U)

/*
 * Base addresses of peripherals hanging on APB2 bus
 */

#define EXTI_BASEADDR               (APB2PERIPH_BASEADDR + 0x3C00U)
#define SPI1_BASEADDR               (APB2PERIPH_BASEADDR + 0x3000U)
#define SYSCFG_BASEADDR             (APB2PERIPH_BASEADDR + 0x3800U)
#define USART1_BASEADDR             (APB2PERIPH_BASEADDR + 0x1000U)
#define USART6_BASEADDR             (APB2PERIPH_BASEADDR + 0x1400U)

/******************************************************************************/
/*                                                                            */
/*                  Peripheral Register Structure Definitions                 */
/*                                                                            */
/******************************************************************************/

typedef struct
{
	__vo uint32_t MODER;			 /*!< GPIO port mode register,               Address offset: 0x00      */
	__vo uint32_t OTYPER;			 /*!< GPIO port output type register,        Address offset: 0x04      */
	__vo uint32_t OSPEEDER;			 /*!< GPIO port output speed register,       Address offset: 0x08      */
	__vo uint32_t PUPDR;			 /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
	__vo uint32_t IDR;				 /*!< GPIO port input data register,         Address offset: 0x10      */
	__vo uint32_t ODR;				 /*!< GPIO port output data register,        Address offset: 0x14      */
	__vo uint32_t BSRR;				 /*!< GPIO port bit set/reset register,      Address offset: 0x18      */
	__vo uint32_t LCKR;				 /*!< GPIO port configuration lock register, Address offset: 0x1C      */
	__vo uint32_t AFRL[2];			 /*!< GPIO alternate function registers,     Address offset: 0x20-0x24 */
}GPIO_RegDef_t;

typedef struct
{
	__vo uint32_t CR;					/*!< RCC clock control register,     	 Address offset: 0x00 */
	__vo uint32_t PLL;					/*!< RCC PLL configuration register,     Address offset: 0x04 */
	__vo uint32_t CFGR;					/*!< RCC clock configuration register,   Address offset: 0x08 */
	__vo uint32_t CIR;					/*!< RCC clock interrupt register,       Address offset: 0x0C */
	__vo uint32_t AHB1;					/*!< RCC AHB1 peripheral reset register, Address offset: 0x10 */
	__vo uint32_t AHB2;					/*!< RCC AHB2 peripheral reset register, Address offset: 0x14 */
	__vo uint32_t AHB3;					/*!< RCC AHB3 peripheral reset register, Address offset: 0x18 */
	__vo uint32_t APB1;					/*!< RCC APB1 peripheral reset register, Address offset: 0x20 */
	__vo uint32_t APB2;					/*!< RCC APB1 peripheral reset register, Address offset: 0x24 */
	__vo uint32_t AHB1ENR;				/*!< RCC AHB1 peripheral clock enable register,   Address offset: 0x30 */
	__vo uint32_t AHB2ENR;				/*!< RCC AHB2 peripheral clock enable register,   Address offset: 0x34 */
	__vo uint32_t AHB3ENR;				/*!< RCC AHB3 peripheral clock enable register,   Address offset: 0x38 */
	__vo uint32_t APB1ENR;				/*!< RCC APB1 peripheral clock enable register,   Address offset: 0x40 */
	__vo uint32_t APB2ENR;				/*!< RCC APB2 peripheral clock enable register,   Address offset: 0x44 */
	__vo uint32_t AHB1LPENR;			/*!< RCC AHB1 peripheral clock enable in low power mode register,   Address offset: 0x50 */
	__vo uint32_t AHB2LPENR;			/*!< RCC AHB2 peripheral clock enable in low power mode register,   Address offset: 0x54 */
	__vo uint32_t AHB3LPENR;			/*!< RCC AHB3 peripheral clock enable in low power mode register,   Address offset: 0x58 */
	__vo uint32_t APB1LPENR;			/*!< RCC APB1 peripheral clock enable in low power mode register,   Address offset: 0x60 */
	__vo uint32_t APB2LPENR;			/*!< RCC APB2 peripheral clock enabled in low power mode register,  Address offset: 0x64 */
	__vo uint32_t BDCR;					/*!< RCC Backup domain control register,     		Address offset: 0x70 */
	__vo uint32_t CSR;					/*!< RCC clock control & status register,     		Address offset: 0x74 */
	__vo uint32_t SSCGR;				/*!< RCC spread spectrum clock generation register, Address offset: 0x80 */
	__vo uint32_t PLLI2SCFGR;			/*!< RCC PLLI2S configuration register,     	    Address offset: 0x84 */
	__vo uint32_t PLLSAICFGR;			/*!< RCC PLL configuration register,     		    Address offset: 0x88 */
	__vo uint32_t DCKCFGR;			    /*!< RCC Dedicated Clock Configuration Register,  Address offset: 0x8C */
	__vo uint32_t CKGATENR;			    /*!< RCC clocks gated enable register,     		  Address offset: 0x90 */
	__vo uint32_t DCKCFGR2;			    /*!< RCC dedicated clocks configuration register 2, Address offset: 0x94 */
}RCC_RegDef_t;


/*
 * Peripheral definitions -- peripheral base address type casted to RegDef structure
 */

#define GPIOA ((GPIO_RegDef_t*)GPIOA_BASEADDR)
#define GPIOB ((GPIO_RegDef_t*)GPIOB_BASEADDR)
#define GPIOC ((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOD ((GPIO_RegDef_t*)GPIOD_BASEADDR)
#define GPIOE ((GPIO_RegDef_t*)GPIOE_BASEADDR)
#define GPIOF ((GPIO_RegDef_t*)GPIOF_BASEADDR)
#define GPIOG ((GPIO_RegDef_t*)GPIOG_BASEADDR)
#define GPIOH ((GPIO_RegDef_t*)GPIOH_BASEADDR)

#define RCC   ((RCC_RegDef_t*)RCC_BASEADDR)

#endif /* INC_STM32F446XX_H_ */
