#include "Led_tape_ide.h"		// Additional Header

const unsigned char test0[]=
{
	BLUE,
	WHITE,
	BLACK,
	RED,
	GREEN,
	BLUE,
	WHITE,
	BLACK,
	RED,
	GREEN,
};
const unsigned char led0[]={
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0xff,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00
};
const unsigned char led1[]={
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0xff,0xff,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00
};
const unsigned char led2[]={
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0xff,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00
};
const unsigned char led3[]={
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0xff,0xff,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00
};
const unsigned char led4[]={
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0xff,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00
};
const unsigned char led5[]={
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0xff,0x00,0xff,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00
};
const unsigned char led6[]={
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0xff,0xff,0xff,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00,
	0x00,0x00,0x00
};

const unsigned char led7[]={
	0x00,0x00,0xff,
	0x00,0x00,0xff,
	0x00,0x00,0xff,
	0x00,0x00,0xff,
	0x00,0x00,0xff,
	0x00,0x00,0xff,
	0x00,0x00,0xff,
	0x00,0x00,0xff,
	0x00,0x00,0xff,
	0x00,0x00,0xff
};

unsigned char led_ram[30];

void setup(void)
{
	led.init(3,10);
}

void loop(void)
{
	int i;
	int j;
	for(i=0;i<30;i+=3)
	{
		led.write(&led0[i]);
		delay(100);
	}
	for(i=0;i<30;i+=3)
	{
		led.write(&led1[i]);
		delay(100);
	}
	for(i=0;i<30;i+=3)
	{
		led.write(&led2[i]);
		delay(100);
	}
	for(i=0;i<30;i+=3)
	{
		led.write(&led3[i]);
		delay(100);
	}
	for(i=0;i<30;i+=3)
	{
		led.write(&led4[i]);
		delay(100);
	}
	for(i=0;i<30;i+=3)
	{
		led.write(&led5[i]);
		delay(100);
	}
	for(i=0;i<30;i+=3)
	{
		led.write(&led6[i]);
		delay(100);
	}
	for(j=0;j<256;j+=1)
	{
		for(i=0;i<30;i+=3)
		{
			led_ram[i]=0;
			led_ram[i+1]=0;
			led_ram[i+2]=j;
		}
		led.write(led_ram);
		delay(10);
	}
	for(j=0;j<256;j+=1)
	{
		for(i=0;i<30;i+=3)
		{
			led_ram[i]=0;
			led_ram[i+1]=j;
			led_ram[i+2]=0xff;
		}
		led.write(led_ram);
		delay(10);
	}
	for(j=0;j<256;j+=1)
	{
		for(i=0;i<30;i+=3)
		{
			led_ram[i]=j;
			led_ram[i+1]=0xff;
			led_ram[i+2]=0xff;
		}
		led.write(led_ram);
		delay(10);
	}
}

