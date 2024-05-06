/*
 * DS321RTC.h
 *
 *  Created on: May 2, 2024
 *      Author: Anwar
 */

#ifndef INC_DS321RTC_H_
#define INC_DS321RTC_H_

#define RTC_I2C hi2c1   //Need to change if you chose another I2C



extern I2C_HandleTypeDef RTC_I2C; // I2C handle


#define DS3231_ADDRESS 0xD0  // DS3231 Slave Receiver Mode (Write Mode)  1101000 0 = 0xD0 From datasheet

typedef struct{
	uint8_t seconds;
	uint8_t minutes;
	uint8_t hour;
	uint8_t dayofweek;
	uint8_t dayofmonth;
	uint8_t month;
	uint8_t year;

}TIME;

TIME time;


// Convert normal decimal numbers to binary coded decimal
uint8_t decToBcd(int val)
{
  return (uint8_t)( (val/10*16) + (val%10) );
}
// Convert binary coded decimal to normal decimal numbers
int bcdToDec(uint8_t val)
{
  return (int)( (val/16*10) + (val%16) );
}



void Set_Time (uint8_t sec, uint8_t min, uint8_t hour, uint8_t dow, uint8_t dom, uint8_t month, uint8_t year)
{
	uint8_t set_time[7];
	set_time[0] = decToBcd(sec);
	set_time[1] = decToBcd(min);
	set_time[2] = decToBcd(hour);
	set_time[3] = decToBcd(dow);
	set_time[4] = decToBcd(dom);
	set_time[5] = decToBcd(month);
	set_time[6] = decToBcd(year);

	  /* write memoray address 0x00 to 0x06 and each 1 byte,set time eqaul to array data varibale
	   * ,store 7 byte data(0x00 to 0x06 address) and time out 1000ms*/

	HAL_I2C_Mem_Write(&RTC_I2C, DS3231_ADDRESS, 0x00, 1, set_time, 7, 1000);

	/*

  * @brief  Write an amount of data in blocking mode to a specific memory address
  * @param  hi2c Pointer to a I2C_HandleTypeDef structure that contains
  *                the configuration information for the specified I2C.
  * @param  DevAddress Target device address: The device 7 bits address value
  *         in datasheet must be shifted to the left before calling the interface
  * @param  MemAddress Internal memory address
  * @param  MemAddSize Size of internal memory address
  * @param  pData Pointer to data buffer
  * @param  Size Amount of data to be sent
  * @param  Timeout Timeout duration
  * @retval HAL status
  */
//HAL_StatusTypeDef HAL_I2C_Mem_Write(I2C_HandleTypeDef *hi2c, uint16_t DevAddress, uint16_t MemAddress, uint16_t MemAddSize, uint8_t *pData, uint16_t Size, uint32_t Timeout);

}


void Get_Time (void)
{
	uint8_t get_time[7];
	HAL_I2C_Mem_Read(&RTC_I2C, DS3231_ADDRESS, 0x00, 1, get_time, 7, 1000);
	time.seconds = bcdToDec(get_time[0]);
	time.minutes = bcdToDec(get_time[1]);
	time.hour =   bcdToDec(get_time[2]);
	time.dayofweek = bcdToDec(get_time[3]);
	time.dayofmonth = bcdToDec(get_time[4]);
	time.month = bcdToDec(get_time[5]);
	time.year = bcdToDec(get_time[6]);
}



#endif /* INC_DS321RTC_H_ */
