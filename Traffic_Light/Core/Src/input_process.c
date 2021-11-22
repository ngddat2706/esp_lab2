/*
 * input_process.c
 *
 *  Created on: Nov 21, 2021
 *      Author: HH
 */
#include "main.h"
#include "led_display.h"
#include "button_debouncing.h"

#define TIME_AUTO_INCREASES		100
#define TIME_BLINKING			249

enum ButtonMode { MODE_1 , MODE_2 , MODE_3, MODE_4} ;
enum ButtonMode buttonMode = MODE_1 ;

int time_RED_edit;
int time_GREEN_edit;
int time_AMBER_edit;

int timeAutoIncreases = 0;
int timeBlinking= 0;

void fsm_for_input_processing(void){
	switch(buttonMode){
	case MODE_1:
		if(is_button1_pressed()){
			time_RED_edit   = getTimeRed();
			time_GREEN_edit = getTimeGreen();
			time_AMBER_edit = getTimeAmber();
			clearAllLedTraffic();
			buttonMode = MODE_2;
		}
		else{
			DisplayMain();
		}
		break;
	case MODE_2:
		if(is_button1_pressed()){
			buttonMode = MODE_3;
			break;
		}
		else if( get_flag_for_button2_press_1s()){
			auto_increases_time();
		}else if(is_button2_pressed()){
			increases_time();
		}else if(is_button3_pressed()){
			setTimeRed(time_RED_edit);
		}
		DisplayMainEdit(time_RED_edit, 2);
		blinking_led();
		break;
	case MODE_3:
		if(is_button1_pressed()){
			buttonMode = MODE_4;
			break;
		}else if( get_flag_for_button2_press_1s()){
			auto_increases_time();
		}else if(is_button2_pressed()){
			increases_time();
		}else if(is_button3_pressed()){
			setTimeGreen(time_GREEN_edit);
		}
		DisplayMainEdit(time_GREEN_edit, 3);
		blinking_led();
		break;
	case MODE_4:
		if(is_button1_pressed()){
			setTime();
			clearAllLedEdit();
			buttonMode = MODE_1;
			break;
		}else if( get_flag_for_button2_press_1s()){
			auto_increases_time();
		}else if(is_button2_pressed()){
			increases_time();
		}else if(is_button3_pressed()){
			setTimeAmber(time_AMBER_edit);
		}
		DisplayMainEdit(time_AMBER_edit, 4);
		blinking_led();
		break;
	}
}

void increases_time(void){
	switch(buttonMode){
		case MODE_2:
			time_RED_edit++;
			if(time_RED_edit >= 99){
				time_RED_edit = 0;
			}
			break;
		case MODE_3:
			time_GREEN_edit++;
			if(time_GREEN_edit >= 99){
				time_GREEN_edit = 0;
			}
			break;
		case MODE_4:
			time_AMBER_edit++;
			if(time_AMBER_edit >= 99){
				time_AMBER_edit = 0;
			}
			break;
		}
}

void auto_increases_time(void){
	if(timeAutoIncreases >= TIME_AUTO_INCREASES){
		increases_time();
		timeAutoIncreases = 0;
	}
	timeAutoIncreases++;
}

void blinking_led(void){
	if(timeBlinking >= TIME_BLINKING){
		switch(buttonMode){
		case MODE_2:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 1);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 1);
			HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_1);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 1);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 1);
			HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4);
			break;
		case MODE_3:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 1);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 1);
			HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_3);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 1);
			HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_6);
			break;
		case MODE_4:
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 1);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 1);
			HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_2);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1);
			HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 1);
			HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
			break;
		}
		timeBlinking =0;
	}
	timeBlinking++;
}
