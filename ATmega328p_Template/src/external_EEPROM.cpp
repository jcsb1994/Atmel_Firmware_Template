#include "app_config.h"
#ifdef EXTERNAL_EEPROM_CONFIG

#include "external_EEPROM.h"

int data = 0;

/*##################################################
            FUNCTIONS
##################################################*/

/***************************************************************************
 * 
 * Two functions are needed to write to and read from DS1307.
 * 1) Wire transmission is initiated
 * 2) The memory address to access is 16 bits long
 * 3) data is written to this address if needed, then transmission is ended
 * 4) to read, 1 byte is requested from the chip, then stored
 * 
 ***************************************************************************/


void writeTo(unsigned int cell_address, uint8_t wData) {
  Wire.beginTransmission(EEPROM_I2C_ADDR);
  Wire.write((int)(cell_address >> 8)); 
  Wire.write((int)(cell_address & 0xFF));
  Wire.write(wData);
  Wire.endTransmission();
  delay(100);
}

uint8_t readFrom(unsigned int cell_address) {
  Wire.beginTransmission(EEPROM_I2C_ADDR);
  Wire.write((int)(cell_address >> 8)); 
  Wire.write((int)(cell_address & 0xFF));
  Wire.endTransmission();

  Wire.requestFrom(EEPROM_I2C_ADDR, 1);

  delay(10);

uint8_t rData = 0;
  if(Wire.available()) {
    rData = Wire.read();
  }

  return rData;
}

#endif

