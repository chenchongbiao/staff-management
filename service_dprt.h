#ifndef __SERVICE_DPRT_H__ 
#define __SERVICE_DPRT_H__ 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mapper_dprt.h"
#include "struct.h"
#include "utils.h" 


//================================================管理员操作=========================================================
// 添加部门
bool admin_save_dapart(sqlite3 *db,DATABASE *datainfo);
// 删除部门
bool admin_delete_dapart(sqlite3 *db,DATABASE *datainfo);
// 修改部门
bool admin_udpate_dapart(sqlite3 *db,DATABASE *datainfo);
// 查找部门
bool admin_select_dapart(sqlite3 *db,DATABASE *datainfo);
// 部门信息总览
bool dapart_info(sqlite3 *db,DATABASE *datainfo);
//================================================管理员操作结束=========================================================





#endif
