#ifndef EEPROM_CHIP_H
#define EEPROM_CHIP_H

#include <main.h>

#define EEPROM_I2C_ADDR 80 //0x50
#define M_CELL_I2C_ADDR 20   //0x14

/***************************************************************************
 * writeTo function
 * 
 * This function writes 1 byte (8 bits)
 * to a 16 bits address on the EEPROM chip (24C_ series) 
 * 
 ***************************************************************************/

void writeTo(unsigned int cell_address, uint8_t wData);

/***************************************************************************
 * readFrom function
 * 
 * This function reads from a 16 bits address on the EEPROM chip (24C_ series) 
 * 
 ***************************************************************************/

uint8_t readFrom(unsigned int cell_address);

#endif