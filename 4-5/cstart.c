#include<stdint.h>

volatile uint8_t *uart0 = (uint8_t*)0x10009000;

void write(const char* s)
{
	while(*s)
	{
		*uart0 = *s++;
	}
}

int main()
{
	const char* s = "I am Piyush\n";
	write(s);
	*uart0 = 'H';
	*uart0 = 'E';
	*uart0 = 'L';
	*uart0 = 'L';
	*uart0 = 'O';
	*uart0 = '\n';
	while(*s != '\0')
	{
		*uart0 = *s;
		s++;
	}
	while(1) {};
	return  0;
}
