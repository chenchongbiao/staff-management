#ifndef __FILE_UTIL_H__ 
#define __FILE_UTIL_H__ 
#include <stdio.h>
#include <direct.h>
#include <string.h>
#include "struct.h"
/*
	�ļ����� 

*/
bool read_users(USERS *p_users);  				// ���û���Ϣ
bool write_users(USERS users);     				// д�û���Ϣ
bool read_dprts(DEPARTMENTS *p_dprts);			// ��������Ϣ
bool write_dprts(DEPARTMENTS dprts);			// д������Ϣ

#endif
