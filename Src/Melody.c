/**
 ******************************************************************************
 * @file    Melody.h
 * @created 11/02/1398 9:01:22 AM
 * @author  Mehdi Adham
 * @brief   This file contains all the functions buzzer Melody
 ******************************************************************************
  @verbatim     
  ==============================================================================      
                        ##### How to use this Library #####
  ============================================================================== 

  Use Play_Melody(MelodyName, Volume) in main.c or our file

  Melody  ->

  You can create any other melody like the one below

	const Melody_Typedef OK_Melody = {
		notes	{NOTE_CS6 ,NOTE_FS6},
		tempo	{5 ,8},
		Count	2
	};

  Example :
  Play_Melody(TOUCH1_Melody, Volume);

  Volume  value =>(1-30)

  BUZZER hardware Config in Melody.h file

  Example :
  htim                    htim2
  TIM_CHANNEL             TIM_CHANNEL_3
  TIMER                   TIM2

 ******************************************************************************
  @endverbatim
 */
#include "Melody.h"
#include "task.h"

extern TIM_HandleTypeDef htim3;


/* Example Melody */

const Melody_Typedef OK_Melody = {
		/*notes*/	{NOTE_CS6 ,NOTE_FS6},
		/*tempo*/	{5 ,8},
		/*Count*/	2
};

const Melody_Typedef ERROR_Melody = {
		/*notes*/	{NOTE_F6 ,NOTE_FS6,  NOTE_F6},
		/*tempo*/	{8, 8, 8},
		/*Count*/	3
};


void Play_Melody(Melody_Typedef MelodyName ,uint8_t Volume){

	//Volume = 10;

	__HAL_TIM_SET_COMPARE(&htim, TIM_CHANNEL, Volume);

	TIM_CCxChannelCmd(TIMER, TIM_CHANNEL, TIM_CCx_ENABLE);

	for(uint8_t i=0; i < MelodyName.noteCount; i++){

		TIM_CCxChannelCmd(TIMER, TIM_CHANNEL, TIM_CCx_ENABLE);

		TIMER->PSC = SET_FREQ(MelodyName.notes[i]);

		HAL_Delay(1000/MelodyName.noteDuration[i]);

		TIM_CCxChannelCmd(TIMER, TIM_CHANNEL, TIM_CCx_DISABLE);

		HAL_Delay(10);

	}
	TIM_CCxChannelCmd(TIMER, TIM_CHANNEL, TIM_CCx_DISABLE);

}





