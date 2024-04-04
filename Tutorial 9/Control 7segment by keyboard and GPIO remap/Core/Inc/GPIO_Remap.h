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



#endif /* INC_GPIO_REMAP_H_ */
