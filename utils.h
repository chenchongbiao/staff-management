#ifndef __UTILS_H__
#define __UTILS_H__
#include <stdio.h>
#include <windows.h> 
#include <wchar.h>
#include "utils.h"
//�ı�������ɫ
void color(short x);
// gbk����ת��Ϊutf8����
void gbk_to_utf8(char *word);
// �������ͱ���
int input_int(char *info,int &data);
// �����ַ��ͱ���
int input_str(char *info,char *data);
#endif 
