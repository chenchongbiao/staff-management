#ifndef __MAPPER_USER_H__
#define __MAPPER_USER_H__    
#include <stdio.h>
#include <string.h>
#include "struct.h" 
#include "sqlite3.h"

/*
			数据库读取方式 
*/ 
/*
===========================================================================================================================																								
												     	添加用户 												
===========================================================================================================================
*/
int save_user(sqlite3 *db,DATABASE *datainfo, USER user); 
/*
===========================================================================================================================																								
												     	删除用户 												
===========================================================================================================================
*/
// 通过员工号删除 
int delete_user_by_staffId(sqlite3 *db,DATABASE *datainfo,char staff_id); 
/*
===========================================================================================================================																								
														修改用户 												
===========================================================================================================================
*/
// 修改用户名 
int update_user_username(sqlite3 *db,DATABASE *datainfo,USER user); 
// 修改姓名 
int update_user_name(sqlite3 *db,DATABASE *datainfo,USER user); 
// 修改在职状态
int update_user_status(sqlite3 *db,DATABASE *datainfo,USER user); 
// 通过员工号修改个人信息 
int update_user_by_staffId(sqlite3 *db,DATABASE *datainfo, USER user);

/*
===========================================================================================================================																								
														查找用户 												
===========================================================================================================================
*/

// 通过员工号查找 
int select_user_by_staffId(sqlite3 *db,DATABASE *datainfo,char *staff_id);
// 通过用户名查找 
int select_user_by_username(sqlite3 *db,DATABASE *datainfo,char *username);
// 验证密码 
int select_user_by_password(sqlite3 *db,DATABASE *datainfo,char *username,char *password);
// 执行数据库语句 
int exec(sqlite3 *db,DATABASE *datainfo);


/*
			文件读取方式 
*/ 
///////////////////////////////////添加用户/////////////////////////////////////////////
int save_user(USERS *p_users,USER user);
///////////////////////////////////删除用户/////////////////////////////////////////////
///////////////////////////////////修改用户/////////////////////////////////////////////
int update_user(USERS *p_users,USER user);
///////////////////////////////////查找用户/////////////////////////////////////////////// 

// 通过用户名查找 
//int select_user_by_username(USERS users,char *p_username);
#endif
