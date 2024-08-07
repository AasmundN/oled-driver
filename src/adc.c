/*
 * External includes
 */
#include <avr/io.h>

/*
 * Private includes
 */
#include "adc.h"

void ADC_init()
{
  // AIN0 pin as input
  ADC0.MUXPOS |= ADC_MUXPOS_AIN0_gc;
  // accumulate 16 samples
  ADC0.CTRLB |= ADC_SAMPNUM_ACC16_gc;
  // 10-bit resolution; ADC enabled
  ADC0.CTRLA |= ADC_ENABLE_bm;
}

uint16_t ADC_read()
{
  // start ADC conversion
  ADC0.COMMAND = 0x1;

  // wait for result ready
  while (!(ADC0.INTFLAGS & ADC_RESRDY_bm))
    ;

  return ADC0.RES;
}