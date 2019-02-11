/*
 * main.h
 *
 *      Author: coolnumber9
 */

#ifndef MAIN_H_
#define MAIN_H_

#define GPIO_BUTTON_PIN							0	/* Connected to PORT A Pin 0 */

#define GPIO_PIN_13                	((uint16_t)0x2000U)  /* Pin 13 selected   */
#define GPIO_PIN_14                	((uint16_t)0x4000U)  /* Pin 14 selected   */

#define SWDIO_Pin 									GPIO_PIN_13
#define SWDIO_GPIO_Port 						GPIOA
#define SWCLK_Pin 									GPIO_PIN_14
#define SWCLK_GPIO_Port 						GPIOA

#endif /* MAIN_H_ */
