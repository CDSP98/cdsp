#include "reg51.h"

void mdelay(unsigned int t)
{
 unsigned char n;
 for(;t>0;t--)
  for(n=0;n<125;n++)
  {;}
}

 void main()
 {
   unsigned char i,j;
   unsigned int led;

   while(1)
	{
	mdelay(500);
	led=0xfe; //����һ�������
 	for(i=0;i<8;i++)//ѭ��8��
		{
		 P1=led;
		 mdelay(500);
		 led=led<<1;//LED�����������ε���
		 if(P1==0x00)
			{
			mdelay(500);
			led=0x7f;
				for(j=0;j<8;j++)//ѭ��8��
				{ 
				P1=led;
   				led=led>>1;//LED�����������ε���
				mdelay(500);
				}
			}
		}
   	}

 } 