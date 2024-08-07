/*
 * External includes
 */
#include <avr/io.h>
#include <string.h>

/*
 * Private includes
 */
#include "usart.h"

void USART_init(unsigned long baud)
{
  // PB0 (USART3 TX) output
  PORTB.DIRSET |= 0x1;
  // baud rate 9600
  USART3.BAUD = baud;
  // async; no parity; 1 stop bit; 8 data bits
  USART3.CTRLC |= USART_CHSIZE_8BIT_gc;
  // enable TX and RX
  USART3.CTRLB |= USART_TXEN_bm | USART_RXEN_bm;
}

void USART_write_char(char data)
{
  // wait for transmission to complete
  while (!(USART3.STATUS & USART_DREIF_bm))
    ;

  // transmit data on uart
  USART3.TXDATAL = data;
}

void USART_write_string(char *str)
{
  for (int i = 0; i < strlen(str); i++)
    USART_write_char(str[i]);
}