/*
 * button_debouncing.c
 *
 *  Created on: Nov 21, 2021
 *      Author: HH
 */
#include "main.h"
#define NO_OF_BUTTONS		1
#define DURATION_FOR_AUTO_INCREASING	254

static GPIO_PinState buttonBuffer[NO_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer1[NO_OF_BUTTONS];
static GPIO_PinState debounceButtonBuffer2[NO_OF_BUTTONS];
static uint16_t counterForButtonPress1s[NO_OF_BUTTONS];
static uint8_t flagForButtonPress1s[NO_OF_BUTTONS];

int button1_State = 0;
int button3_State = 0;
int button2_State = 0;

void button_reading(void){
	for(char i = 0; i < NO_OF_BUTTONS; i++){
		debounceButtonBuffer2[i] = debounceButtonBuffer1[i];
		debounceButtonBuffer1[i] = HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_9);
		if(debounceButtonBuffer1[i] == debounceButtonBuffer2[i])
			buttonBuffer[i] = debounceButtonBuffer1[i];
		if(buttonBuffer[i] == GPIO_PIN_SET){
			if(counterForButtonPress1s[i] < DURATION_FOR_AUTO_INCREASING){
				counterForButtonPress1s[i]++;
			}
			else{
				flagForButtonPress1s[i] = 1;
			}
		}
		else{
			counterForButtonPress1s[i] = 0;
			flagForButtonPress1s[i] = 0;
		}
	}
}

GPIO_PinState get_button2_value(){
	return buttonBuffer[0];
}

unsigned char get_flag_for_button2_press_1s(){
	return flagForButtonPress1s[0];
}

int is_button1_pressed(){
	if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_8) == GPIO_PIN_SET){
		button1_State = 1;
		return 0;
	}
	if(button1_State == 1){
		button1_State = 0;
		return 1;
	}
}

int is_button3_pressed(){
	if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_10) == GPIO_PIN_SET){
		button3_State = 1;
		return 0;
	}
	if(button3_State == 1){
		button3_State = 0;
		return 1;
	}
}

int is_button2_pressed(){
	if(HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_9) == GPIO_PIN_SET){
		button2_State = 1;
		return 0;
	}
	if(button2_State == 1){
		button2_State = 0;
		return 1;
	}
}



