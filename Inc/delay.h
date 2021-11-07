#ifndef __DELAY_H
#define __DELAY_H




void delay(__IO uint32_t nTime);

void delay_decrement(void);

void _delay_us(TIM_TypeDef *timer, unsigned int time) ;

void _delay_ms(TIM_TypeDef *timer, unsigned int time) ;


#endif