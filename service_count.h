#ifndef __SERVICE_COUNT_H__
#define __SERVICE_COUNT_H__
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "struct.h"
#include "service_count.h"
#include "mapper_dprt.h"
#include "mapper_user.h" 
#include "sqlite3.h"

/*
=====================================================管理员操作=============================================================

============================================================================================================================
*/
// 按性别统计员工
bool count_by_sex(sqlite3 *db,DATABASE *datainfo);
// 按部门统计员工
bool count_by_dprt(sqlite3 *db,DATABASE *datainfo);
// 按学历统计员工
bool count_by_edu(sqlite3 *db,DATABASE *datainfo);

//================================================管理员操作结束=========================================================

/*
=====================================================部门经理操作=============================================================

============================================================================================================================
*/

// 按性别统计员工
bool count_by_sex(sqlite3 *db,DATABASE *datainfo,USER *user);
// 按部门统计员工
bool count_by_dprt(sqlite3 *db,DATABASE *datainfo,USER *user);
// 按学历统计员工
bool count_by_edu(sqlite3 *db,DATABASE *datainfo,USER *user);
//================================================部门经理操作结束=========================================================

void count_bound();

#endif
