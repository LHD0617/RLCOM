#ifndef	_NIXIE_TUBE_H_
#define _NIXIE_TUBE_H_
#include "zf_gpio.h"



#define   ABS(x)    (((x) > 0) ? (x) : (-(x)))//��x�ﲻ�����Լ��Լ�����䣬�����������
void Nixie_Tube(int number);//��ʾ��ֵ
void Nixie_Tube_ON();//ȫ��
void Nixie_Tube_OFF();//ȫ��
void Nixie_Tube_S(int i);//��ʾ-999-9999����
void Nixie_Tube_Init();





#endif


