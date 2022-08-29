#include <REGX52.H>
#include "I2C.H"

#define SLAVE_ADDRESS 0x10

void send(void)
{
unsigned int i;
	
unsigned char str[]="Hello Robocon";
unsigned char *pstr=str;
	
for(i=0;i<13;i++)
	{
		I2C_Start();
		I2C_SendByte(SLAVE_ADDRESS);
		I2C_ReceiveAck();
		I2C_SendByte(*pstr++);
		I2C_ReceiveAck();
		I2C_SendByte(str[i]);
		I2C_ReceiveAck();
		I2C_Stop();
	}

}

