#ifndef __FILE_UTIL_H__ 
#define __FILE_UTIL_H__ 
#include <stdio.h>
#include <direct.h>
#include <string.h>
#include "struct.h"
/*
	文件访问 

*/
bool read_users(USERS *p_users);  				// 读用户信息
bool write_users(USERS users);     				// 写用户信息
bool read_dprts(DEPARTMENTS *p_dprts);			// 读部门信息
bool write_dprts(DEPARTMENTS dprts);			// 写部门信息

#endif
