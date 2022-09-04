#include "CRC16.h"
#include "Log.h"


unsigned short CRC16(unsigned short *nData, unsigned char wLength)
{
	unsigned int w = 0;
	unsigned short shift_cnt;
	unsigned short var;


	if (nData)
	{
		w = 0xffffU;
		for (int i=0; i<= wLength; i++)
		{

			var = *nData++;

			w = (unsigned int)((w / 256U) * 256U + ((w % 256U) ^ (var &0xFF00)>>8));

			for (shift_cnt = 0; shift_cnt < 8; shift_cnt++)
			{
				if ((w & 0x1) == 1)
					w = (unsigned int)((w >> 1) ^ 0xa001U);
				else
					w >>= 1;
			}

			w = (unsigned int)((w / 256U) * 256U + ((w % 256U) ^ (var &0xFF)));

			for (shift_cnt = 0; shift_cnt < 8; shift_cnt++)
			{
				if ((w & 0x1) == 1)
					w = (unsigned int)((w >> 1) ^ 0xa001U);
				else
					w >>= 1;
			}
		} 
	}
	return (unsigned short) w;
}
