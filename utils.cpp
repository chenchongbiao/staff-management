#include "utils.h"

//�ı�������ɫ 
void color(short x) {  
    if(x>=0 && x<=15)//������0-15�ķ�Χ��ɫ  
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x); 
    else
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);  //Ĭ�ϵ���ɫ��ɫ  
} 
