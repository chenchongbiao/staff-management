#ifndef __SERVICE_USER_H__
#define __SERVICE_USER_H__
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mapper_user.h"
#include "struct.h"

bool login(USERS users, USER *p_user); // 登录 

////////////////////////////////////////////////管理员操作///////////////////////////////////////////////// 
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

// 添加部门 
bool admin_save_dapart(DEPARTMENTS *p_dprts);
// 删除部门 
bool admin_delete_dapart(DEPARTMENTS *p_dprts);
// 修改部门 
bool admin_udpate_dapart(DEPARTMENTS *p_dprts);
// 查找部门 
bool admin_select_dapart(DEPARTMENTS dprts);
// 部门信息总览 
bool dapart_info(DEPARTMENTS dprts);

////////////////////////////////////////////////部门经理操作///////////////////////////////////////////////

////////////////////////////////////////////////一般员工操作///////////////////////////////////////////////
///////////////////////////////////////////一般用户///////////////////////////////////////// 
// 员工入职 
bool staff_induction(USERS *p_users,USER *p_user);
// 员工离职 
bool staff_dimission(USERS *p_users,USER *p_user);
#endif 
