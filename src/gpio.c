/*
 * External includes
 */
#include <avr/io.h>

/*
 * Private includes
 */
#include "gpio.h"

/*
 * Private defines
 */
#define USER_LED_PIN 5

/*
 * Configure GPIO pins
 */
void GPIO_init()
{
  // PF5 output
  PORTF.DIRSET |= 1 << USER_LED_PIN;
  // PF5 low
  PORTF.OUTCLR |= 1 << USER_LED_PIN;
}
