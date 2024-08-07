#ifndef __USART__
#define __USART__

void USART_init(unsigned long baud);
void USART_write_string(char *str);

#endif // __USART__