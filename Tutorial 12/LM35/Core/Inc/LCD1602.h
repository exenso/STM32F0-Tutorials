/*
 * lcd1602.h
 *
 *  Created on: April 18, 2024
 *      Author: Anwar Hossain Mokhter
 */

#ifndef INC_LCD1602_H_
#define INC_LCD1602_H_

#include "main.h"



void lcd_init (void);   // initialize lcd

void lcd_send_cmd (char cmd);  // send command to the lcd

void lcd_send_data (char data);  // send data to the lcd

void LCD_String (char *str);  // send string to the lcd

void LCD_intValue(int value); // send int to the lcd

void LCD_floatValue(float value, int precision);  // send float to the lcd

void LCD_Print_fdot( int16_t intd); // only 4digit int dot work like 1234 =12.34

void lcd_xy(int row, int col);  // put cursor at the entered position row (0 or 1), col (0-15);

void lcd_clear (void);

#endif /* INC_LCD1602_H_ */
