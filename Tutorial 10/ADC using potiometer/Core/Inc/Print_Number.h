/*
 * Print_Number.h
 *
 *  Created on: Apr 7, 2024
 *      Author: Anwar
 */

#ifndef INC_PRINT_NUMBER_H_
#define INC_PRINT_NUMBER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*  if IntToStrON define value set 1 and FloatToStrON define value set 0 Only Int to string conversion
 complie and rest of the code skip */

#define IntToStrON 		 1

/*  if IntToStrON define value set 0 and FloatToStrON define value set 1 Only Float to string conversion
 complie and rest of the code skip */
#define FloatToStrON 	 0


#if (IntToStrON == 1 )

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

// This function  convert sign or unsign int value to string value.

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



#elif (FloatToStrON == 1)

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

// This function  convert sign or unsign int value to string value.

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

#endif

#endif /* INC_PRINT_NUMBER_H_ */
