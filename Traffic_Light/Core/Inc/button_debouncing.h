/*
 * button_debouncing.h
 *
 *  Created on: Nov 21, 2021
 *      Author: HH
 */

#ifndef INC_BUTTON_DEBOUNCING_H_
#define INC_BUTTON_DEBOUNCING_H_

void button_reading(void);
GPIO_PinState get_button2_value();
unsigned char get_flag_for_button2_press_1s();
int is_button1_pressed();
int is_button3_pressed();
int is_button2_pressed();
#endif /* INC_BUTTON_DEBOUNCING_H_ */
