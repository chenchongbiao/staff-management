#ifndef __SERVICE_USER_H__
#define __SERVICE_USER_H__
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h> 
#include <time.h>
#include "mapper_user.h"
#include "mapper_dprt.h" 
#include "struct.h"
#include "utils.h"
/*
===========================================================================================================================										
														
													管理员操作
														
===========================================================================================================================
*/
// 添加员工
bool save_staff(sqlite3 *db,DATABASE *datainfo,USER *p_user);
// 删除员工
bool delete_staff(sqlite3 *db,DATABASE *datainfo,USER *p_user);
// 修改员工信息
bool update_staff(sqlite3 *db,DATABASE *datainfo,USER *p_user);
// 查找员工信息
bool select_staff(sqlite3 *db,DATABASE *datainfo,USER *p_user);
// 管理员查找所有员工信息
bool select_all_staff(sqlite3 *db,DATABASE *datainfo);
// 删除数据库
bool delete_database(sqlite3 *db,DATABASE *datainfo);
//================================================管理员操作结束=========================================================


/*
===========================================================================================================================

													部门经理操作

===========================================================================================================================
*/
// 部门经理查找所有员工信息
bool select_all_staff(sqlite3 *db,DATABASE *datainfo,USER *p_user);
//================================================部门经理操作结束=========================================================




/*
===========================================================================================================================

													一般员工操作

===========================================================================================================================
*/
// 员工入职
bool staff_induction(sqlite3 *db,DATABASE *datainfo,USER *p_user);
// 员工离职
bool staff_dimission(sqlite3 *db,DATABASE *datainfo,USER *p_user);
// 修改个人信息
bool update_info(sqlite3 *db,DATABASE *datainfo,USER *p_user);
//================================================一般员工操作结束=========================================================

/*
===========================================================================================================================

														公共函数

===========================================================================================================================
*/
// 登录
bool login(sqlite3 *db,DATABASE *datainfo,USER *p_user);
// 打印用户数据
void print_user_Info(sqlite3 *db,DATABASE *datainfo);
// 当前用户的信息
void curr_user_info(char **data,USER *p_user);
// 修改用户名
bool update_username(sqlite3 *db,DATABASE *datainfo,USER *p_user);
// 修改姓名
bool update_name(sqlite3 *db,DATABASE *datainfo,USER *p_user);
// 修改密码
bool update_password(sqlite3 *db,DATABASE *datainfo,USER *p_user);
// 修改权限
bool update_role(sqlite3 *db,DATABASE *datainfo,USER *p_user);
// 修改性别
bool update_sex(sqlite3 *db,DATABASE *datainfo,USER *p_user);
// 调离部门
bool update_dprt(sqlite3 *db,DATABASE *datainfo,USER *p_user);
// 修改学历
bool update_edu(sqlite3 *db,DATABASE *datainfo,USER *p_user);
// 修改员工号
bool update_staffId(sqlite3 *db,DATABASE *datainfo,USER *p_user);
// 修改电话
bool update_mobile(sqlite3 *db,DATABASE *datainfo,USER *p_user);
// 修改在职状态
bool update_status(sqlite3 *db,DATABASE *datainfo,USER *p_user);
// 询问是否修改信息
int alert(char *info);
//// 输入整型变量
//int input_int(char *info,int &data);
//// 输入字符型变量
//int input_str(char *info,char *data);
// 给结构体的字符指针开辟内存
void malloc_user(USER *user);
// 释放结构体的字符指针
void free_user(USER *user);
// 打印分割线
void bound();
#endif 
