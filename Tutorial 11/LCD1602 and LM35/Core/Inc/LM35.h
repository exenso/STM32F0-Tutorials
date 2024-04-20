/*
 * LM35.h
 *
 *  Created on: Apr 18, 2024
 *      Author: Anwar
 */

#ifndef INC_LM35_H_
#define INC_LM35_H_

/*
 The LM35 outputs a voltage proportional to the surrounding temperature. The standard calibration factor is:
 10 mV per degree Celsius (°C)
 This means for every 1°C increase in temperature, the output voltage of the LM35 increases by 10 mV.
 Converting ADC Value to Temperature:

 Here's the basic algorithm to convert the ADC value (obtained from the microcontroller's ADC) to temperature:

Calculate voltage based on ADC value:

voltage = (reference_voltage * ADC_value) / (2^ADC_resolution - 1)

Calculate temperature using LM35 calibration factor:

temperature = voltage / 0.01

0.01: Conversion factor (10 mV/°C)


example : For STM32 reference_voltage = 3.3V and ADC_resolution = 12bit = 2^12 = 4096


 */

float LM35_Read(uint16_t ADCvalue , float Ref_voltage, uint16_t bit_Resulation){


	float voltage  = ( ADCvalue * Ref_voltage) / bit_Resulation;

	float Temp = voltage / 0.01;

    return Temp;
}


#endif /* INC_LM35_H_ */
