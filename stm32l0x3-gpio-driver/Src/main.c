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
	
	/* Configure the button interrupt as falling edge */
	hal_gpio_configure_interrupt(GPIO_BUTTON_PIN, INT_RISING_FALLING_EDGE);
	
	/* Enable the interrupt on EXTI0 line */
	/* Button is mapped within EXTI 0 - 1 */
	hal_gpio_enable_interrupt(GPIO_BUTTON_PIN, EXTI0_1_IRQn);

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

		for(i=0; i < 500000; i++);

		led_turn_off(GPIO_PORT_A, LED_RED);
		led_turn_off(GPIO_PORT_B, LED_GREEN);

		for(i=0; i < 500000; i++);
	}
}

/**
	* @brief  ISR for the configured EXTI0_1 interrupt (User button on the discovery board)  
	* @retval None
	*/
void EXTI0_IRQHandler(void)
{
	/* Make sure to clear the sticky pending interrupt bit first 
	 * of EXTI pending register.
 	 */
  hal_gpio_clear_interrupt(GPIO_BUTTON_PIN);

	led_toggle(GPIOD,LED_RED);
	led_toggle(GPIOD,LED_GREEN);
}
