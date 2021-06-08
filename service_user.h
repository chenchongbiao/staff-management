#ifndef __SERVICE_USER_H__
#define __SERVICE_USER_H__
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h> 
#include "mapper_user.h"
#include "struct.h"

bool login(USERS users, USER *p_user); // 登录 


//================================================管理员操作=========================================================
// 添加员工
bool admin_save_user(USERS *p_users);
// 删除员工
bool admin_delete_user(USERS *p_users);
// 修改员工
bool admin_udpate_user(USERS *p_users);
// 查找员工
bool admin_select_user(USERS users);
// 员工信息总览 
bool staff_info(USERS users);
//================================================管理员操作结束=========================================================



//===============================================部门经理操作=========================================================

//================================================部门经理操作结束=========================================================




//===============================================一般员工操作=========================================================
// 员工入职 
bool staff_induction(USERS *p_users,USER *p_user);
// 员工离职 
bool staff_dimission(USERS *p_users,USER *p_user);
//================================================一般员工操作结束=========================================================




#endif 
