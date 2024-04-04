/*
 * GPIO_Remap.h
 *
 *  Created on: Apr 4, 2024
 *      Author: Anwar
 */

#ifndef INC_GPIO_REMAP_H_
#define INC_GPIO_REMAP_H_

/////////////////////////// PORT Remap Library //////////////////////////////
#define PORT_SIZE   8       // Max 16

typedef struct
{
    GPIO_TypeDef*   PORT[PORT_SIZE]; // GPIO PORT structure
    uint16_t        PIN[PORT_SIZE];  // GPIO PIN Number
} PORT_Remap_TypeDef;

void Write_PORT_Remap(PORT_Remap_TypeDef* Prm, uint16_t data){
    uint8_t i;
    for(i=0; i<PORT_SIZE; i++){
        HAL_GPIO_WritePin(Prm->PORT[i], Prm->PIN[i], (data & (0x0001 << i))? GPIO_PIN_SET:GPIO_PIN_RESET);
    }
}
/////////////////////////////////////////////////////////////////////////////

/*

/// This is below code is example code of above lib

uint8_t seg_table[] = {
    //pgfedcba
    0b11000000,  // 0
    0b11111001,  // 1
    0b10100100,  // 2
    0b10110000,  // 3
    0b10011001,  // 4
    0b10010010,  // 5
    0b10000010,  // 6
    0b11111000,  // 7
    0b10000000,  // 8
    0b10010000   // 9
};

PORT_Remap_TypeDef PORTrm;
uint8_t UART1_rxBuffer[2] = {0};
uint8_t ch0;

void main(){

    PORTrm.PORT[0] = GPIOA; PORTrm.PIN[0] = a_Pin;
    PORTrm.PORT[1] = GPIOA; PORTrm.PIN[1] = b_Pin;
    PORTrm.PORT[2] = GPIOA; PORTrm.PIN[2] = c_Pin;
    PORTrm.PORT[3] = GPIOA; PORTrm.PIN[3] = d_Pin;
    PORTrm.PORT[4] = GPIOA; PORTrm.PIN[4] = e_Pin;
    PORTrm.PORT[5] = GPIOA; PORTrm.PIN[5] = f_Pin;
    PORTrm.PORT[6] = GPIOA; PORTrm.PIN[6] = g_Pin;
    PORTrm.PORT[7] = GPIOA; PORTrm.PIN[7] = h_Pin;

    while(1){
        HAL_UART_Receive (&huart1, UART1_rxBuffer, 2, 100);

        ch0 = UART1_rxBuffer[0];
        ch0 = ch0-48; // convert character to number
        ch0 = (ch0 > 9)? 9:ch0;
        Write_PORT_Remap(&PORTrm, seg_table[ch0]);
    }

}

*/

#endif /* INC_GPIO_REMAP_H_ */
