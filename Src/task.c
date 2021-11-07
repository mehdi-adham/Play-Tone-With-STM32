/**
  ******************************************************************************
  * @file    task.h
  * @created 11/02/1398 9:01:22 AM
  * @author  HSA R&D Team - Mehdi Adham
  * @brief   This file contains all the functions Event
  ******************************************************************************
  */

#include "main.h"
#include "task.h"

extern uint8_t get_data ;
extern UART_HandleTypeDef huart1;



void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart){
  if(huart -> Instance == USART1){
//    HAL_UART_Transmit_IT(&huart1, (uint8_t *)0x00, 1);
  }
  UNUSED(huart);
}



void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
  if(huart -> Instance == USART2){
  }
  if(huart ->Instance == USART1){
//
    HAL_UART_Receive_IT(&huart1 ,&get_data ,1);
  }
  UNUSED(huart);
}


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
  if(htim -> Instance == TIM15){

	}

  UNUSED(htim);
}






