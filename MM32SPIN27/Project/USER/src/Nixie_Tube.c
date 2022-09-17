#include "Nixie_Tube.h"
/*****************����ܿ��ƿ���*************************/
#define  Nixie_Tube1_ON          	gpio_set(B8 ,0)
#define  Nixie_Tube2_ON          	gpio_set(D6 ,0)
#define  Nixie_Tube3_ON          	gpio_set(C11,0)
#define  Nixie_Tube4_ON          	gpio_set(C10,0)

#define  Nixie_Tube1_OFF          gpio_set(B8 ,1) 
#define  Nixie_Tube2_OFF          gpio_set(D6 ,1) 
#define  Nixie_Tube3_OFF          gpio_set(C11,1) 
#define  Nixie_Tube4_OFF          gpio_set(C10,1) 
/******************************************************/
//Nixie_Tube1_ON
#define  Tube1_ON   	gpio_set(B6 ,0)//a             
#define  Tube2_ON   	gpio_set(A15,0)//b        
#define  Tube3_ON   	gpio_set(B3 ,0)//c       
#define  Tube4_ON   	gpio_set(B7 ,0)//d       
#define  Tube5_ON   	gpio_set(B9 ,0)//e      
#define  Tube6_ON   	gpio_set(B4 ,0)//f       
#define  Tube7_ON   	gpio_set(C12,0)//g       
#define  Tube8_ON   	gpio_set(B5 ,0)//�� 
//Nixie_Tube1_OFF
#define  Tube1_OFF   	gpio_set(B6 ,1)//a             
#define  Tube2_OFF   	gpio_set(A15,1)//b        
#define  Tube3_OFF   	gpio_set(B3 ,1)//c       
#define  Tube4_OFF   	gpio_set(B7 ,1)//d       
#define  Tube5_OFF   	gpio_set(B9 ,1)//e      
#define  Tube6_OFF   	gpio_set(B4 ,1)//f       
#define  Tube7_OFF   	gpio_set(C12,1)//g       
#define  Tube8_OFF   	gpio_set(B5 ,1)//��

int a,b,c,d;
int ss=-999;
int chack_i;
int data_bit;

void Nixie_Tube_Init()
{
	gpio_init(D7 , GPO, 1, GPO_PUSH_PULL);
	gpio_init(B3 , GPO, 1, GPO_PUSH_PULL);
	gpio_init(B4 , GPO, 1, GPO_PUSH_PULL);
	gpio_init(B5 , GPO, 1, GPO_PUSH_PULL);
	gpio_init(B6 , GPO, 1, GPO_PUSH_PULL);
	gpio_init(B7 , GPO, 1, GPO_PUSH_PULL);
	gpio_init(B8 , GPO, 1, GPO_PUSH_PULL);
	gpio_init(B9 , GPO, 1, GPO_PUSH_PULL);
	gpio_init(D6 , GPO, 1, GPO_PUSH_PULL);
	gpio_init(C10, GPO, 1, GPO_PUSH_PULL);
	gpio_init(C11, GPO, 1, GPO_PUSH_PULL);
	gpio_init(C12, GPO, 1, GPO_PUSH_PULL);
	gpio_init(A15, GPO, 1, GPO_PUSH_PULL);
}
/**********************************
*������Nixie_Tube_S(uint16 i)
*����Ƽ�
*���ܣ���ʾ������ֵ��-999-9999
*���أ���
*���ܣ�i Ҫ��ʾ��ĳ����
********************************/
void Nixie_Tube_S(int i)
{  if(i<0)
    {
    i=ABS(i);
    Nixie_Tube1_ON;
    Nixie_Tube2_OFF;
    Nixie_Tube3_OFF;
    Nixie_Tube4_OFF;
   // Nixie_Tube(a);
    Tube7_ON;
    Tube1_OFF;
    Tube2_OFF;
    Tube3_OFF;
    Tube4_OFF;
    Tube5_OFF;
    Tube6_OFF;
    systick_delay_ms(2);
    b=i/100;
    Nixie_Tube1_OFF;
    Nixie_Tube2_ON;
    Nixie_Tube3_OFF;
    Nixie_Tube4_OFF;
    Nixie_Tube(b);
    systick_delay_ms(2);
    c=(i%100)/10;
    Nixie_Tube1_OFF;
    Nixie_Tube2_OFF;
    Nixie_Tube3_ON;
    Nixie_Tube4_OFF;
    Nixie_Tube(c);
    systick_delay_ms(2);
    d=(i%100)%10/1;
    Nixie_Tube1_OFF;
    Nixie_Tube2_OFF;
    Nixie_Tube3_OFF;
    Nixie_Tube4_ON;
    Nixie_Tube(d);
    systick_delay_ms(2);
    }
   else
   {
    a=i/1000;
    Nixie_Tube1_ON;
    Nixie_Tube2_OFF;
    Nixie_Tube3_OFF;
    Nixie_Tube4_OFF;
    Nixie_Tube(a);
    systick_delay_ms(2);
    b=(i%1000)/100;
    Nixie_Tube1_OFF;
    Nixie_Tube2_ON;
    Nixie_Tube3_OFF;
    Nixie_Tube4_OFF;
    Nixie_Tube(b);
    systick_delay_ms(2);
    c=((i%1000)%100)/10;
    Nixie_Tube1_OFF;
    Nixie_Tube2_OFF;
    Nixie_Tube3_ON;
    Nixie_Tube4_OFF;
    Nixie_Tube(c);
    systick_delay_ms(2);
    d=(i%1000)%100%10;
    Nixie_Tube1_OFF;
    Nixie_Tube2_OFF;
    Nixie_Tube3_OFF;
    Nixie_Tube4_ON;
    Nixie_Tube(d);
    systick_delay_ms(2);
   }
}

/***********************************
*������Nixie_Tube(int number)
*���ܣ�����������ʾ��ֵ
*����Ƽ�
*���أ���
*����˵����number ĳ�������Ҫ��ʾ��0-9����
*�ڲ�����
************************************/
void Nixie_Tube(int number)
{
  Nixie_Tube_ON();
  //Tube8_OFF;
  switch(number)
  {
    case(0):
      {
       Tube7_OFF;  
      }break;
    case(1):
      {
       Tube1_OFF;
       Tube4_OFF;
       Tube5_OFF;
       Tube6_OFF;
       Tube7_OFF;
      }break;
    case(2):
      {
       Tube6_OFF;
       Tube3_OFF;
      }break;
    case(3):
      {
       Tube5_OFF;
       Tube6_OFF;
      }break;
    case(4):
      {
       Tube1_OFF;
       Tube4_OFF;
       Tube5_OFF;
      }break;
    case(5):
      {
       Tube2_OFF;
       Tube5_OFF;
      }break;
    case(6):
      {
      Tube2_OFF;
      }break;
    case(7):
      {
       Tube4_OFF;
       Tube5_OFF;
       Tube6_OFF;
       Tube7_OFF;
      }break;
    case(8):
      {
      ;
      }break;
    case(9):
      {
        Tube5_OFF;
      }break;
  }


}

/*********************************
*������Nixie_Tube_ON()
*���ܣ�����ܿ��ض�
*����Ƽ�
*���أ���
*����˵������
*�ڲ�����
***********************************/
void Nixie_Tube_ON()
{
   Tube1_ON;
   Tube2_ON;
   Tube3_ON;
   Tube4_ON;
   Tube5_ON;
   Tube6_ON;
   Tube7_ON;
   Tube8_OFF;

}
/*********************************
*������Nixie_Tube_OFF()
*���ܣ�����ܿ��ض�
*����Ƽ�
*���أ���
*����˵������
*�ڲ�����
*********************************/
void Nixie_Tube_OFF()
{
  Tube1_OFF;      
  Tube2_OFF;        
  Tube3_OFF;      
  Tube4_OFF;      
  Tube5_OFF;     
  Tube6_OFF;       
  Tube7_OFF;
}
