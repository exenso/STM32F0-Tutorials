/*
 * LCD1602.c
 *
 *  Created on: April 18, 2024
 *      Author: Anwar Hossain Mokhter
 */

#include <LCD1602.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stm32f0xx_hal.h"

/*********** Define the LCD PINS below ****************/
//LCD1602_HandleTypeDef LCD;


/****************** define the timer handler below  **************/
#define timer htim1


extern TIM_HandleTypeDef timer;
void delay (uint16_t us)
{
	__HAL_TIM_SET_COUNTER(&timer, 0);
	while (__HAL_TIM_GET_COUNTER(&timer) < us);
}

/****************************************************************************************************************************************************************/

void send_to_lcd (char data, int rs)
{

	HAL_GPIO_WritePin(RS_GPIO_Port, RS_Pin, rs);  // rs = 1 for data, rs=0 for command

	/* write the data to the respective pin */
	HAL_GPIO_WritePin(D7_GPIO_Port, D7_Pin, ((data>>3)&0x01));
	HAL_GPIO_WritePin(D6_GPIO_Port, D6_Pin, ((data>>2)&0x01));
	HAL_GPIO_WritePin(D5_GPIO_Port, D5_Pin, ((data>>1)&0x01));
	HAL_GPIO_WritePin(D4_GPIO_Port, D4_Pin, ((data>>0)&0x01));

	/* Toggle EN PIN to send the data
	 * if the HCLK > 100 MHz, use the  20 us delay
	 * if the LCD still doesn't work, increase the delay to 50, 80 or 100..
	 */
	HAL_GPIO_WritePin(EN_GPIO_Port, EN_Pin, 1);
	delay (20);
	HAL_GPIO_WritePin(EN_GPIO_Port, EN_Pin, 0);
	delay (20);
}

void lcd_send_cmd (char cmd)
{
    char datatosend;

    /* send upper nibble first */
    datatosend = ((cmd>>4)&0x0f);
    send_to_lcd(datatosend,0);  // RS must be 0 while sending command

    /* send Lower Nibble */
    datatosend = ((cmd)&0x0f);
	send_to_lcd(datatosend, 0);
}

void lcd_send_data (char data)
{
	char datatosend;

	/* send higher nibble */
	datatosend = ((data>>4)&0x0f);
	send_to_lcd(datatosend, 1);  // rs =1 for sending data

	/* send Lower nibble */
	datatosend = ((data)&0x0f);
	send_to_lcd(datatosend, 1);
}

void lcd_clear (void)
{
	lcd_send_cmd(0x01);
	HAL_Delay(2);
}

void lcd_xy(int row, int col)
{
    switch (row)
    {
        case 0:
            col |= 0x80;
            break;
        case 1:
            col |= 0xC0;
            break;
    }

    lcd_send_cmd (col);
}


void lcd_init (void)
{
	// 4 bit initialisation
	HAL_Delay(50);  // wait for >40ms
	lcd_send_cmd (0x30);
	HAL_Delay(5);  // wait for >4.1ms
	lcd_send_cmd (0x30);
	HAL_Delay(1);  // wait for >100us
	lcd_send_cmd (0x30);
	HAL_Delay(10);
	lcd_send_cmd (0x20);  // 4bit mode
	HAL_Delay(10);

  // dislay initialisation
	lcd_send_cmd (0x28); // Function set --> DL=0 (4 bit mode), N = 1 (2 line display) F = 0 (5x8 characters)
	HAL_Delay(1);
	lcd_send_cmd (0x08); //Display on/off control --> D=0,C=0, B=0  ---> display off
	HAL_Delay(1);
	lcd_send_cmd (0x01);  // clear display
	HAL_Delay(1);
	HAL_Delay(1);
	lcd_send_cmd (0x06); //Entry mode set --> I/D = 1 (increment cursor) & S = 0 (no shift)
	HAL_Delay(1);
	lcd_send_cmd (0x0C); //Display on/off control --> D = 1, C and B = 0. (Cursor and blink, last two bits)
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




/**************** Below Function convert int and float value into String*************************************** */

void reverse(char str[], int n) {
  // Helper function to reverse a string in-place
  int start = 0;
  int end = n - 1;
  while (start < end) {
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    start++;
    end--;
  }
}

void int_to_str(int value, char str[]) {
  // Function to convert integer to string
  int i = 0;
  if (value == 0) {
    str[i++] = '0';
  } else {
    // Handle negative values
    int isNegative = value < 0;
    value = abs(value);
    while (value > 0) {
      str[i++] = (value % 10) + '0';
      value /= 10;
    }
    if (isNegative) {
      str[i++] = '-';
    }
  }
  str[i] = '\0';
  reverse(str, i);
}



void float_to_str(float value, char str[], int precision) {
  // Function to convert float to string with custom precision
  int i = 0;
  int int_part = (int)value;

  // Convert integer part
  int_to_str(int_part, str);
  i = strlen(str);

  // Handle decimal part (if any)
  if (precision > 0) {
    str[i++] = '.';
    float decimal_part = value - int_part;
    for (int j = 0; j < precision; j++) {
      decimal_part *= 10;
      int digit = (int)decimal_part;
      str[i++] = digit + '0';
      decimal_part -= digit;
    }
  }
  str[i] = '\0';
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**************** Below Function Send String ,Int and Float to LCD*************************************** */

void LCD_String (char *str)
{
	while (*str) lcd_send_data (*str++);
}



void LCD_intValue(int value){
	char str[20];
	int_to_str(value,  str);
	LCD_String(str);
	LCD_String(" ");
}





void LCD_floatValue(float value, int precision) {
  // Function to convert float to string with custom precision
  char str[20];
  float_to_str(value, str, precision);
  LCD_String(str);
  LCD_String(" ");
}



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

