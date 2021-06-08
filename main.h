#ifndef __MAIN_H__
#define __MAIN_H_
#include <stdio.h>
#include <time.h>
#include <string.h> 
#include <stdlib.h>
#include "struct.h"
#include "file_util.h"
#include "menu.h"
#include "service_user.h"
#include "mapper_user.h" 
#include "service_dprt.h"
#include "mapper_dprt.h"
#include "service_count.h"
bool save_data(bool *dirty, int size, USERS users);	// 保存所有内存数据 
void init_data_files();										// 初始化数据文件 
#endif
