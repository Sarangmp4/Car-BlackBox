#include <xc.h>
#include "main.h"

unsigned char tick_count=180;

void __interrupt() isr(void)
{
	static unsigned long count;
     
	if (TMR0IF)
	{
		TMR0 = TMR0 + 8;

		if (count++ == 20000) // 1 second
		{
            
			count = 0;
            tick_count--;
            
            
		}
		TMR0IF = 0;
	}
}