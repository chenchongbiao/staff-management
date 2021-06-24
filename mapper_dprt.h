#ifndef __MAPPER_DPRT__
#define __MAPPER_DPRT__
#include <stdio.h>
#include <string.h>
#include "struct.h" 
#include "sqlite3.h"

/*
			数据库读取方式 
*/ 
///////////////////////////////////添加部门/////////////////////////////////////////////
int save_dprt(sqlite3 *db,DATABASE *datainfo, DEPARTMENT dprt);
///////////////////////////////////删除部门/////////////////////////////////////////////
// 通过rowid删除部门
int update_user_by_dprtId(sqlite3 *db,DATABASE *datainfo, DEPARTMENT dprt);
///////////////////////////////////修改部门/////////////////////////////////////////////
// 根据rowid修改部门
int delete_user_by_dprtId(sqlite3 *db,DATABASE *datainfo, DEPARTMENT dprt);
///////////////////////////////////查找部门///////////////////////////////////////////////
// 根据部门名字查找
int select_dprt_by_name(sqlite3 *db,DATABASE *datainfo,DEPARTMENT dprt);
// 执行数据库语句
int exec(sqlite3 *db,DATABASE *datainfo);
// 查找所有部门
int select_all_dprt(sqlite3 *db,DATABASE *datainfo);
// 根据id查找部门
int select_dprt_by_id(sqlite3 *db,DATABASE *datainfo, int rowid);
#endif
