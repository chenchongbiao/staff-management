#ifndef __SERVICE_USER_H__
#define __SERVICE_USER_H__
#include <stdio.h>
//#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <conio.h> 
#include "mapper_user.h"
#include "mapper_dprt.h" 
#include "struct.h"
/*
===========================================================================================================================										
														
													管理员操作
														
===========================================================================================================================
*/
// 添加员工
bool save_staff(sqlite3 *db,DATABASE *datainfo,USER *p_user);
// 添加员工
//bool admin_save_user(USERS *p_users);
//// 删除员工
//bool admin_delete_user(USERS *p_users);
//// 修改员工
//bool admin_udpate_user(USERS *p_users);
//// 查找员工
//bool admin_select_user(USERS users);
//// 员工信息总览 
//bool staff_info(USERS users);
//================================================管理员操作结束=========================================================


/*
===========================================================================================================================										
														
													部门经理操作
														
===========================================================================================================================
*/
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
// 修改学历 
bool update_edu(sqlite3 *db,DATABASE *datainfo,USER *p_user);  
// 修改电话 
bool update_mobile(sqlite3 *db,DATABASE *datainfo,USER *p_user); 
// 询问是否修改信息
int alert(char *info); 
int input_int(char *info,int &data);
// 输入字符型变量
int input_str(char *info,char *data);
// 给结构体的字符指针开辟内存
void malloc_user(USER *user);
// 释放结构体的字符指针
void free_user(USER *user);
#endif 
