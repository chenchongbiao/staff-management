#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"

// ��¼ǰ�˵�
void show_prelogin_menu(){
	printf("\n\n\t1. ��¼\n");
	printf("\t2. �˳�\n");
	printf("\n\t��ѡ�����Ĳ�����");
} 

// ���˵�������ʾ
void main_menu()           
{
    printf("\t\t****************************\n");
    printf("\t\t*                          *\n");
    printf("\t\t*     ��ҵԱ������ϵͳ     *\n");
    printf("\t\t*                          *\n");
    printf("\t\t****************************\n");
    printf("\t\t*     1.Ա�����˹���       *\n");
    printf("\t\t*                          *\n");
    printf("\t\t*     2.�� �� �� ��        *\n");
    printf("\t\t*                          *\n");
    printf("\t\t*     3.Ա����ѯͳ��       *\n");
    printf("\t\t*                          *\n");
    printf("\t\t*     0.�˳�ϵͳ           *\n");
    printf("\t\t*     ��ѡ����(0-3��     *\n");
    printf("\t\t****************************\n");
}

// Ա�����˹���
void staff_menu(){
	printf("\t\t****************************\n");
    printf("\t\t*                          *\n");
    printf("\t\t*     Ա �� �� �� �� ��    *\n");
    printf("\t\t*                          *\n");
    printf("\t\t****************************\n");
    printf("\t\t*     1.Ա �� �� ְ        *\n");
    printf("\t\t*                          *\n");
    printf("\t\t*     2.Ա �� �� ְ        *\n");
    printf("\t\t*                          *\n");
    printf("\t\t*     3.Ա �� �� ְ        *\n");
    printf("\t\t*                          *\n");
    printf("\t\t*     0.������һҳ         *\n");
    printf("\t\t*     ��ѡ����(0-3��     *\n");
    printf("\t\t****************************\n");
} 

// ���Ź���
void depart_menu(){
	printf("\t\t****************************\n");
    printf("\t\t*                          *\n");
    printf("\t\t*     ��  ��  ��  ��       *\n");
    printf("\t\t*                          *\n");
    printf("\t\t****************************\n");
    printf("\t\t*     1.�� �� �� ��        *\n");
    printf("\t\t*                          *\n");
    printf("\t\t*     2.�� �� �� ��        *\n");
    printf("\t\t*                          *\n");
    printf("\t\t*     0.������һҳ         *\n");
    printf("\t\t*     ��ѡ����(0-2��     *\n");
    printf("\t\t****************************\n");
}

// Ա����ѯͳ�� 
void total_menu(){
	printf("\t\t****************************\n");
    printf("\t\t*                          *\n");
    printf("\t\t*      Ա����ѯͳ��        *\n");
    printf("\t\t*                          *\n");
    printf("\t\t****************************\n");
    printf("\t\t*     1.Ա�����˲�ѯ       *\n");
    printf("\t\t*                          *\n");
    printf("\t\t*     2.Ա �� ͳ ��        *\n");
    printf("\t\t*                          *\n");
    printf("\t\t*     0.������һҳ         *\n");
    printf("\t\t*     ��ѡ����(0-2��     *\n");
    printf("\t\t****************************\n");
}  

// Ա��ͳ�� 
void totalstaff(){ 
	printf("\t\t****************************\n");
    printf("\t\t*                          *\n");
    printf("\t\t*     Ա  ��  ͳ  ��       *\n");
    printf("\t\t*                          *\n");
    printf("\t\t****************************\n");
    printf("\t\t*     1.��  ��  ��         *\n");
    printf("\t\t*                          *\n");
    printf("\t\t*     2.��  ��  ��         *\n");
    printf("\t\t*                          *\n");
    printf("\t\t*     3.��  ѧ  ��         *\n");
    printf("\t\t*                          *\n");
    printf("\t\t*     0.������һҳ         *\n");
    printf("\t\t*     ��ѡ����(0-3��     *\n");
    printf("\t\t****************************\n");
}
