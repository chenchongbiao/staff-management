#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"

// ��¼ǰ�˵�
void show_prelogin_menu(){
    printf("\t\t***********************************************\n");
    printf("\t\t*                  1.��¼                     *\n");
    printf("\t\t*                                             *\n");
    printf("\t\t*                  0.�˳�ϵͳ                 *\n");
    printf("\t\t*                  ��ѡ����(0-1��           *\n");
    printf("\t\t***********************************************\n");
    printf("\t\t��������š�  ��\b\b\b\b");
}

// ����Ա�˵�������ʾ
void admin_menu()
{
    printf("\t\t**********************************************\n");
    printf("\t\t*                                            *\n");
    printf("\t\t*               ��ҵԱ������ϵͳ             *\n");
    printf("\t\t*                                            *\n");
    printf("\t\t**********************************************\n");
    printf("\t\t*               1.Ա �� �� ��                *\n");
    printf("\t\t*                                            *\n");
    printf("\t\t*               2.�� �Ź� ��                 *\n");
    printf("\t\t*                                            *\n");
    printf("\t\t*               3.Ա �� �� ѯ ͳ ��          *\n");
    printf("\t\t*                                            *\n");
    printf("\t\t*               4.ɾ �� �� �� ��             *\n");
    printf("\t\t*                                            *\n");
    printf("\t\t*               0.�˳�ϵͳ                   *\n");
    printf("\t\t*               ��ѡ����(0-3��             *\n");
    printf("\t\t**********************************************\n");
    printf("\t\t��������š�  ��\b\b\b\b");
}

// ���ž���˵�������ʾ
void manage_menu()
{
    printf("\t\t**********************************************\n");
    printf("\t\t*                                            *\n");
    printf("\t\t*               ��ҵԱ������ϵͳ             *\n");
    printf("\t\t*                                            *\n");
    printf("\t\t**********************************************\n");
    printf("\t\t*               1.Ա �� �� ��                *\n");
    printf("\t\t*                                            *\n");
    printf("\t\t*               2.Ա �� �� ѯ ͳ ��          *\n");
    printf("\t\t*                                            *\n");
    printf("\t\t*               0.�˳�ϵͳ                   *\n");
    printf("\t\t*               ��ѡ����(0-3��             *\n");
    printf("\t\t**********************************************\n");
    printf("\t\t��������š�  ��\b\b\b\b");
}

// Ա�����˹���
void staff_menu(){
	printf("\t\t**********************************************\n");
    printf("\t\t*                                            *\n");
    printf("\t\t*              Ա �� �� �� �� ��             *\n");
    printf("\t\t*                                            *\n");
    printf("\t\t**********************************************\n");
    printf("\t\t*              1.Ա �� �� ְ                 *\n");
    printf("\t\t*                                            *\n");
    printf("\t\t*              2.Ա �� �� ְ                 *\n");
    printf("\t\t*                                            *\n");
    printf("\t\t*              3.�޸ĸ�����Ϣ                *\n");
    printf("\t\t*                                            *\n");
    printf("\t\t*              0.������һҳ                  *\n");
    printf("\t\t*              ��ѡ����(0-3��              *\n");
    printf("\t\t**********************************************\n");
    printf("\t\t��������š�  ��\b\b\b\b");
}

// Ա������
void staff_manage_menu(){
	printf("\t\t**********************************************\n");
    printf("\t\t*                                            *\n");
    printf("\t\t*             Ա �� ��  ��                   *\n");
    printf("\t\t*                                            *\n");
    printf("\t\t**********************************************\n");
    printf("\t\t*             1.�� �� Ա ��                  *\n");
    printf("\t\t*                                            *\n");
    printf("\t\t*             2.ɾ �� Ա ��                  *\n");
    printf("\t\t*                                            *\n");
    printf("\t\t*             3.�� �� Ա ��                  *\n");
    printf("\t\t*                                            *\n");
    printf("\t\t*             4.�� �� Ա ��                  *\n");
    printf("\t\t*                                            *\n");
    printf("\t\t*             5.�� Ϣ �� ��                  *\n");
    printf("\t\t*                                            *\n");
    printf("\t\t*             0.������һҳ                   *\n");
    printf("\t\t*             ��ѡ����(0-5��               *\n");
    printf("\t\t**********************************************\n");
    printf("\t\t��������š�  ��\b\b\b\b");
}



// ���Ź���
void depart_manage_menu(){
	printf("\t\t**********************************************\n");
    printf("\t\t*                                            *\n");
    printf("\t\t*             ��  ��  ��  ��                 *\n");
    printf("\t\t*                                            *\n");
    printf("\t\t**********************************************\n");
    printf("\t\t*             1.�� �� �� ��                  *\n");
    printf("\t\t*                                            *\n");
    printf("\t\t*             2.ɾ �� �� ��                  *\n");
    printf("\t\t*                                            *\n");
    printf("\t\t*             3.�� �� �� ��                  *\n");
    printf("\t\t*                                            *\n");
    printf("\t\t*             4.�� �� �� ��                  *\n");
    printf("\t\t*                                            *\n");
    printf("\t\t*             5.�� �� �� ��                  *\n");
    printf("\t\t*                                            *\n");
    printf("\t\t*             0.������һҳ                   *\n");
    printf("\t\t*             ��ѡ����(0-5��               *\n");
    printf("\t\t**********************************************\n");
    printf("\t\t��������š�  ��\b\b\b\b");
}

// Ա����ѯͳ��
void total_menu(){
	printf("\t\t**********************************************\n");
    printf("\t\t*                                            *\n");
    printf("\t\t*             Ա����ѯͳ��                   *\n");
    printf("\t\t*                                            *\n");
    printf("\t\t**********************************************\n");
    printf("\t\t*             1.Ա�����˲�ѯ                 *\n");
    printf("\t\t*                                            *\n");
    printf("\t\t*             2.Ա �� ͳ ��                  *\n");
    printf("\t\t*                                            *\n");
    printf("\t\t*             0.������һҳ                   *\n");
    printf("\t\t*             ��ѡ����(0-2��               *\n");
    printf("\t\t**********************************************\n");
    printf("\t\t��������š�  ��\b\b\b\b");
}



// Ա��ͳ��
void total_staff(){
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
    printf("\t\t��������š�  ��\b\b\b\b");
}

