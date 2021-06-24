#ifndef __UTILS_H__
#define __UTILS_H__
#include <stdio.h>
#include <windows.h> 
#include <wchar.h>
#include "utils.h"
//改变字体颜色
void color(short x);
// gbk编码转换为utf8编码
void gbk_to_utf8(char *word);
// 输入整型变量
int input_int(char *info,int &data);
// 输入字符型变量
int input_str(char *info,char *data);
#endif 
