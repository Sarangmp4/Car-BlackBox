#ifndef external_eeprom
#define external_eeprom

#define SLAVE_READ		0xA1
#define SLAVE_WRITE		0xA0



void write_external_eeprom(unsigned char ,  unsigned char );
unsigned char read_external_eeprom(unsigned char );


#endif