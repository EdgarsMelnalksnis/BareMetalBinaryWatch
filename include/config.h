#ifndef _VVC_CONFIG_H
#define _VVC_CONFIG_H
#include <stdint.h>

#define GPIO_7_MODER_POS_0 (14u)
#define GPIO_7_MODER_POS_1 (15u)
#define GPIO_8_MODER_POS_0 (16u)
#define GPIO_8_MODER_POS_1 (17u)
#define GPIO_9_MODER_POS_0 (18u)
#define GPIO_9_MODER_POS_1 (19u)
#define GPIO_10_MODER_POS_0 (20u)
#define GPIO_10_MODER_POS_1 (21u)
#define GPIO_11_MODER_POS_0 (22u)
#define GPIO_11_MODER_POS_1 (23u)
#define GPIO_12_MODER_POS_0 (24u)
#define GPIO_12_MODER_POS_1 (25u)

#ifdef __cplusplus
#define   __I     volatile             /*!< Defines 'read only' permissions */
#else
#define   __I     volatile const       /*!< Defines 'read only' permissions */
#endif
#define     __O     volatile             /*!< Defines 'write only' permissions */
#define     __IO    volatile             /*!< Defines 'read / write' permissions */

/* following defines should be used for structure members */
#define     __IM     volatile const      /*! Defines 'read only' structure member permissions */
#define     __OM     volatile            /*! Defines 'write only' structure member permissions */
#define     __IOM    volatile            /*! Defines 'read / write' structure member permissions */


#define PERIPH_BASE           (0x40000000UL) /*!< Peripheral base address in the alias region */
#define AHBPERIPH_BASE        (PERIPH_BASE + 0x00020000UL)

#define RCC_BASE              (AHBPERIPH_BASE + 0x00001000UL)
#define RCC                   ((RCC_TypeDef *) RCC_BASE)
#define RCC_IOPENR_IOPAEN_Pos            (0U)
#define RCC_IOPENR_GPIOAEN    (0x1UL << RCC_IOPENR_IOPAEN_Pos)

#define IOPPERIPH_BASE        (PERIPH_BASE + 0x10000000UL)
#define GPIOA_BASE            (IOPPERIPH_BASE + 0x00000000UL)
#define GPIOA                 ((GPIO_TypeDef *) GPIOA_BASE)

#define LED_PIN_7    (7u)
#define LED_PIN_8    (8u)
#define LED_PIN_9    (9u)
#define LED_PIN_10   (10u)
#define LED_PIN_11   (11u)
#define LED_PIN_12   (12u)

typedef struct
{
    __IO uint32_t CR;            /*!< RCC clock control register,                                   Address offset: 0x00 */
    __IO uint32_t ICSCR;         /*!< RCC Internal clock sources calibration register,              Address offset: 0x04 */
    __IO uint32_t CRRCR;         /*!< RCC Clock recovery RC register,                               Address offset: 0x08 */
    __IO uint32_t CFGR;          /*!< RCC Clock configuration register,                             Address offset: 0x0C */
    __IO uint32_t CIER;          /*!< RCC Clock interrupt enable register,                          Address offset: 0x10 */
    __IO uint32_t CIFR;          /*!< RCC Clock interrupt flag register,                            Address offset: 0x14 */
    __IO uint32_t CICR;          /*!< RCC Clock interrupt clear register,                           Address offset: 0x18 */
    __IO uint32_t IOPRSTR;       /*!< RCC IO port reset register,                                   Address offset: 0x1C */
    __IO uint32_t AHBRSTR;       /*!< RCC AHB peripheral reset register,                            Address offset: 0x20 */
    __IO uint32_t APB2RSTR;      /*!< RCC APB2 peripheral reset register,                           Address offset: 0x24 */
    __IO uint32_t APB1RSTR;      /*!< RCC APB1 peripheral reset register,                           Address offset: 0x28 */
    __IO uint32_t IOPENR;        /*!< RCC Clock IO port enable register,                            Address offset: 0x2C */
    __IO uint32_t AHBENR;        /*!< RCC AHB peripheral clock enable register,                     Address offset: 0x30 */
    __IO uint32_t APB2ENR;       /*!< RCC APB2 peripheral enable register,                          Address offset: 0x34 */
    __IO uint32_t APB1ENR;       /*!< RCC APB1 peripheral enable register,                          Address offset: 0x38 */
    __IO uint32_t IOPSMENR;      /*!< RCC IO port clock enable in sleep mode register,              Address offset: 0x3C */
    __IO uint32_t AHBSMENR;      /*!< RCC AHB peripheral clock enable in sleep mode register,       Address offset: 0x40 */
    __IO uint32_t APB2SMENR;     /*!< RCC APB2 peripheral clock enable in sleep mode register,      Address offset: 0x44 */
    __IO uint32_t APB1SMENR;     /*!< RCC APB1 peripheral clock enable in sleep mode register,      Address offset: 0x48 */
    __IO uint32_t CCIPR;         /*!< RCC clock configuration register,                             Address offset: 0x4C */
    __IO uint32_t CSR;           /*!< RCC Control/status register,                                  Address offset: 0x50 */
} RCC_TypeDef;




typedef struct
{
    __IO uint32_t MODER;        /*!< GPIO port mode register,                     Address offset: 0x00 */
    __IO uint32_t OTYPER;       /*!< GPIO port output type register,              Address offset: 0x04 */
    __IO uint32_t OSPEEDR;      /*!< GPIO port output speed register,             Address offset: 0x08 */
    __IO uint32_t PUPDR;        /*!< GPIO port pull-up/pull-down register,        Address offset: 0x0C */
    __IO uint32_t IDR;          /*!< GPIO port input data register,               Address offset: 0x10 */
    __IO uint32_t ODR;          /*!< GPIO port output data register,              Address offset: 0x14 */
    __IO uint32_t BSRR;         /*!< GPIO port bit set/reset registerBSRR,        Address offset: 0x18 */
    __IO uint32_t LCKR;         /*!< GPIO port configuration lock register,       Address offset: 0x1C */
    __IO uint32_t AFR[2];       /*!< GPIO alternate function register,            Address offset: 0x20-0x24 */
    __IO uint32_t BRR;          /*!< GPIO bit reset register,                     Address offset: 0x28 */
} GPIO_TypeDef;


#endif
