#include <reg51.h>

void delay(unsigned int k)
{
	unsigned int i;
	for(i=0;i<=k;i++);
}
		
void main()
{
	unsigned char count=0;
	P3 = 0xFF;
	while(1)
	{
		for(count=0;count<=15;count++)
		{
			P3 = count;
		  delay(20000);
		}
  }
}