#ifndef	_NIXIE_TUBE_H_
#define _NIXIE_TUBE_H_
#include "zf_gpio.h"



#define   ABS(x)    (((x) > 0) ? (x) : (-(x)))//（x里不能有自加自减的语句，否则变量出错）
void Nixie_Tube(int number);//显示数值
void Nixie_Tube_ON();//全开
void Nixie_Tube_OFF();//全关
void Nixie_Tube_S(int i);//显示-999-9999整数
void Nixie_Tube_Init();





#endif


