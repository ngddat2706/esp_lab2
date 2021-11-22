/*
 * led_display.h
 *
 *  Created on: Nov 21, 2021
 *      Author: HH
 */

#ifndef INC_LED_DISPLAY_H_
#define INC_LED_DISPLAY_H_

void display7SEG(int counter);
void displayLedTopBottom(int index);
void displayLedLeftRight(int index);
void displayTrafficLight_LeftRight(void);
void displayTrafficLight(void);
void clearAllLedEdit(void);
void clearAllLedTraffic(void);
void DisplayMain(void);
void DisplayMainEdit(int time_Edit, int Mode);
int getTimeRed();
int getTimeGreen();
int getTimeAmber();
void setTimeRed(int timeRed);
void setTimeGreen(int timeGreen);
void setTimeAmber(int timeAmber);
void setTime();
#endif /* INC_LED_DISPLAY_H_ */
