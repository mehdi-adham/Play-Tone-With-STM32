#include "main.h"
#include "delay.h"


static __IO uint32_t _delay;


void delay(__IO uint32_t nTime){
  _delay = nTime;
  
  while(_delay != 0);
}

void delay_decrement(void){
  if (_delay--) {}
}

void _delay_us(TIM_TypeDef *timer, unsigned int time) {
  timer->CNT = 0;
  time -= 3;
  while (timer->CNT <= time) {}
}

void _delay_ms(TIM_TypeDef *timer, unsigned int time) {
  while (time--) {
    _delay_us(timer, 1000);
  }
}
