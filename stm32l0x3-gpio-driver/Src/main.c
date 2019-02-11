/*
 * main.c
 *
 *      Author: coolnumber9
 */

#include "stm32l0x3_gpio_driver.h"
#include "led.h"
#include "main.h"

/**
	* @brief  Initialize the LEDs
	* @param  None
	* @retval None
	*/
void led_init(void)
{
	gpio_pin_conf_t led_pin_conf;

	 /* Enable the clock for the GPIO ports A and B */
	_HAL_RCC_GPIOA_CLK_ENABLE();
	_HAL_RCC_GPIOB_CLK_ENABLE();

	led_pin_conf.mode = GPIO_PIN_OUTPUT_MODE;
	led_pin_conf.op_type = GPIO_PIN_OP_TYPE_PUSHPULL;
	led_pin_conf.speed = GPIO_PIN_SPEED_MEDIUM;
	led_pin_conf.pull = GPIO_PIN_NO_PULL_PUSH;

	led_pin_conf.pin = LED_RED;
	hal_gpio_init(GPIO_PORT_A, &led_pin_conf);

	led_pin_conf.pin = LED_GREEN;
	hal_gpio_init(GPIO_PORT_B, &led_pin_conf);
}

int main(void)
{
	uint32_t i;

	/* Initializes the LEDs */
	led_init();	// TODO: Transfer to led driver source file.

	while(1)
	{
		/* Generates a square wave...
		 * - Freq: at about 0.525 Hz
		 * - Pulse width: ~1 second
		 * - Period: ~1.9-2 seconds
		 * - Duty cycle: 50%
		
		       |~~~~~|     |~~~~~|
           |     |     |     |
           |     |     |     |
           |     |     |     |
      ~~~~~|     |~~~~~|     |~~~~~
		 */
		
		led_turn_on(GPIO_PORT_A, LED_RED);
		led_turn_on(GPIO_PORT_B, LED_GREEN);

		for(i=0;i < 500000; i++);

		led_turn_off(GPIO_PORT_A, LED_RED);
		led_turn_off(GPIO_PORT_B, LED_GREEN);

		for(i=0; i < 500000; i++);
	}

	//return 0;
}
