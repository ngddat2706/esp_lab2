/*
 * led_display.c
 *
 *  Created on: Nov 21, 2021
 *      Author: HH
 */
#include "main.h"

#define TIME_PER_SECOND			250	// time to increase a second
#define TIME_RUN7SEGMENT		18
#define TIME_RUN7SEGMENT_EDIT	12

int time_RED = 5;
int time_GREEN = 3;
int time_AMBER = 2;

int time_RED_TopBottom = 5;
int time_GREEN_TopBottom = 3;
int time_AMBER_TopBottom = 2;

int time_RED_LeftRight = 5;
int time_GREEN_LeftRight = 3;
int time_AMBER_LeftRight = 2;

int time_run = TIME_PER_SECOND;
int time_led7Segment = TIME_RUN7SEGMENT;
int time_led7Segment_edit = TIME_RUN7SEGMENT_EDIT;
int time7SEG_TopBottom = 3;
int time7SEG_LeftRight = 5;

void display7SEG(int counter){
   	  switch(counter){
   	  case 0:
   		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_13, 1);
   		  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_14, 0);
   		  break;
   	  case 1:
   	  	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13, 1);
   	  	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_14, 0);
   	  	break;
   	  case 2:
   	  	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_9|GPIO_PIN_12, 1);
   	  	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_13|GPIO_PIN_14, 0);
   	  	break;
   	  case 3:
   	  	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11|GPIO_PIN_12, 1);
   	  	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_13|GPIO_PIN_14, 0);
   	  	break;
   	  case 4:
   	  	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7|GPIO_PIN_10|GPIO_PIN_11, 1);
   	  	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14, 0);
   	  	break;
   	  case 5:
   	  	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8|GPIO_PIN_11, 1);
   	  	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14, 0);
   	  	break;
   	  case 6:
   	  	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_8, 1);
   	  	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14, 0);
   	  	break;
   	  case 7:
   	  	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13, 1);
   	  	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_14, 0);
   	  	break;
   	  case 8:
   	  	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14, 0);
   	  	break;
   	  case 9:
   	  	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_11, 1);
   	  	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14, 0);
   	  	break;
   	  default:
   		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10|GPIO_PIN_11|GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14, 1);
   		break;

   	  }
}

void displayLedTopBottom(int index){
	switch(index){
	case 0:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 0);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 1);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 1);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 1);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 1);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 0);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 1);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 0);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 1);
		break;
	default:
		break;
	}
}

void displayLedLeftRight(int index){
	switch(index){
	case 0:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 0);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 1);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 1);
		break;
	case 1:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 1);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 0);
		break;
	case 2:
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 0);
		HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 1);
		break;
	default:
		break;
	}
}

void displayTrafficLight_LeftRight(void){
	if(time_RED_LeftRight > 0){
		time_RED_LeftRight--;
		displayLedLeftRight(0);
		time7SEG_LeftRight = time_RED_LeftRight;

	}else if(time_GREEN_LeftRight >=0){
		time7SEG_LeftRight = time_GREEN_LeftRight;
		time_GREEN_LeftRight--;
		displayLedLeftRight(1);

	}else if(time_AMBER_LeftRight >= 0){
		time7SEG_LeftRight = time_AMBER_LeftRight;
		time_AMBER_LeftRight--;
		displayLedLeftRight(2);

	}

}

void displayTrafficLight(void){
	if(time_run <= 0){
		if(time_GREEN_TopBottom > 0){
			displayTrafficLight_LeftRight();
			time_GREEN_TopBottom--;
			displayLedTopBottom(1);
			time7SEG_TopBottom = time_GREEN_TopBottom;

		}else if(time_AMBER_TopBottom >= 0){
			displayTrafficLight_LeftRight();
			time7SEG_TopBottom = time_AMBER_TopBottom;
			time_AMBER_TopBottom--;
			displayLedTopBottom(2);
		}else if(time_RED_TopBottom >= 0){
			displayTrafficLight_LeftRight();
			time7SEG_TopBottom = time_RED_TopBottom;
			time_RED_TopBottom--;
			displayLedTopBottom(0);

		}else{
			time_RED_TopBottom = time_RED;
			time_GREEN_TopBottom = time_GREEN;
			time_AMBER_TopBottom = time_AMBER;
			time_RED_LeftRight = time_RED;
			time_GREEN_LeftRight = time_GREEN;
			time_AMBER_LeftRight = time_AMBER;
		}
		time_run = TIME_PER_SECOND;
	}

	time_run--;

}

void clearAllLedEdit(void){
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, 0);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 0);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, 0);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, 0);
}

void clearAllLedTraffic(void){
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, 0);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 0);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, 0);
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, 0);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, 1);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_3, 1);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1, 1);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, 1);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_5, 1);
	HAL_GPIO_WritePin(GPIOA, GPIO_PIN_6, 1);
}

void DisplayMain(void){
	displayTrafficLight();
	if(time_led7Segment > 15){
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, 1);
		display7SEG(0);

	}else if(time_led7Segment > 12){
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, 0);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 1);
		display7SEG(1);

	}else if(time_led7Segment > 9){
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 0);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, 1);
		display7SEG(time7SEG_TopBottom / 10);

	}else if(time_led7Segment > 6){
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, 0);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 1);
		display7SEG(time7SEG_TopBottom % 10);

	}else if(time_led7Segment > 3){
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_1, 0);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, 1);
		display7SEG(time7SEG_LeftRight / 10);

	}else if(time_led7Segment > 0){
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_2, 0);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, 1);
		display7SEG(time7SEG_LeftRight % 10);

	}else{
		time_led7Segment = TIME_RUN7SEGMENT;
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3, 0);

	}
	time_led7Segment--;
}

void DisplayMainEdit(int time_Edit, int Mode){
	if(time_led7Segment > 9){
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, 1);
		display7SEG(Mode / 10);

	}else if(time_led7Segment > 6){
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_4, 0);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 1);
		display7SEG(Mode % 10);

	}else if(time_led7Segment > 3){
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 0);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, 1);
		display7SEG(time_Edit / 10);

	}else if(time_led7Segment > 0){
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_6, 0);
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, 1);
		display7SEG(time_Edit % 10);

	}else{
		time_led7Segment = TIME_RUN7SEGMENT;
		HAL_GPIO_WritePin(GPIOB, GPIO_PIN_7, 0);
	}
	time_led7Segment--;
}

int getTimeRed(){
	return time_RED;
}

int getTimeGreen(){
	return time_GREEN;
}

int getTimeAmber(){
	return time_AMBER;
}

void setTimeRed(int timeRed){
	time_RED = timeRed;
}

void setTimeGreen(int timeGreen){
	time_GREEN = timeGreen;
}

void setTimeAmber(int timeAmber){
	time_AMBER = timeAmber;
}

void setTime(){
	time_RED_LeftRight = time_RED;
	time_GREEN_LeftRight = time_GREEN;
	time_AMBER_LeftRight = time_AMBER;
	time_RED_TopBottom = time_RED;
	time_GREEN_TopBottom = time_GREEN;
	time_AMBER_TopBottom = time_AMBER;
}
