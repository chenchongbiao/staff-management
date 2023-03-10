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
int delete_user_by_staffId(sqlite3 *db,DATABASE *datainfo,char *staff_id);
/*
===========================================================================================================================
														修改用户
===========================================================================================================================
*/
// 修改用户名
int update_user_username(sqlite3 *db,DATABASE *datainfo,USER user);
// 修改姓名
int update_user_name(sqlite3 *db,DATABASE *datainfo,USER user);
// 修改密码
int update_user_password(sqlite3 *db,DATABASE *datainfo,USER user);
// 修改权限
int update_user_role(sqlite3 *db,DATABASE *datainfo,USER user);
// 修改性别
int update_user_sex(sqlite3 *db,DATABASE *datainfo,USER user);
// 修改员工部门
int update_user_dprt(sqlite3 *db,DATABASE *datainfo,USER user);
// 修改学历
int update_user_edu(sqlite3 *db,DATABASE *datainfo,USER user);
// 修改员工号
int update_user_staffId(sqlite3 *db,DATABASE *datainfo,USER user,char *new_staffId);
// 修改电话
int update_user_mobile(sqlite3 *db,DATABASE *datainfo,USER user);
// 修改在职状态
int update_user_status(sqlite3 *db,DATABASE *datainfo,USER user);

/*
===========================================================================================================================
														查找用户
===========================================================================================================================
*/

// 通过员工号查找
int select_user_by_staffId(sqlite3 *db,DATABASE *datainfo,char *staff_id);
// 通过用户名查找
int select_user_by_username(sqlite3 *db,DATABASE *datainfo,char *username);
// 查找所有员工信息（管理员）
int select_all_user(sqlite3 *db,DATABASE *datainfo);
// 查找所有员工信息（部门管理员）
int select_all_user(sqlite3 *db,DATABASE *datainfo,int dprt_id);
// 分性别统计员工（管理员）
int count_user_by_sex(sqlite3 *db,DATABASE *datainfo);
// 分学历统计员工（管理员）
int count_user_by_dprt(sqlite3 *db,DATABASE *datainfo);
// 分学历统计员工（管理员）
int count_user_by_edu(sqlite3 *db,DATABASE *datainfo);
// 分性别统计员工(部门管理员)
int count_user_by_sex(sqlite3 *db,DATABASE *datainfo,int dprt_id);
// 分部门统计员工（部门管理员）
int count_user_by_dprt(sqlite3 *db,DATABASE *datainfo,int dprt_id);
// 分学历统计员工（部门管理员）
int count_user_by_edu(sqlite3 *db,DATABASE *datainfo,int dprt_id);
// 验证密码
int select_user_by_password(sqlite3 *db,DATABASE *datainfo,char *username,char *password);
// 执行数据库语句
int exec(sqlite3 *db,DATABASE *datainfo);
// 删除数据库
int del_data(sqlite3 *db,DATABASE *datainfo);


#endif
