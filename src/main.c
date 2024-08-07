/*
 * Private defines
 */
#define F_CPU 3333333UL
#define USART_BAUD(fcpu, baud) ((4UL * fcpu) / baud)
#define TWI_BAUD(fcpu, fscl) (fcpu / fscl / 2 > 5 ? fcpu / fscl / 2 - 5 : 0)

#define STR_SIZE 64

/*
 * External includes
 */
#include <avr/io.h>
#include <stdio.h>
#include <util/delay.h>

/*
 * Private includes
 */
#include "adc.h"
#include "gpio.h"
#include "twi.h"
#include "usart.h"

int main()
{
  GPIO_init();
  ADC_init();
  USART_init(USART_BAUD(F_CPU, 9600));

  uint16_t data;
  char data_string[STR_SIZE];

  while (1)
  {
    _delay_ms(50);

    // get average of 16 ADC samples
    data = ADC_read() >> 4;
    sprintf(data_string, "%u\r\n", data);

    USART_write_string(data_string);
  }
}