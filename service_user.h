#ifndef __SERVICE_USER_H__
#define __SERVICE_USER_H__
#include <stdio.h>
#include <string.h>
#include "mapper_user.h"
#include "struct.h"

bool login(USERS users, USER *p_user); // ��¼ 
///////////////////////////////////////////һ���û�///////////////////////////////////////// 
// Ա����ְ 
bool staff_induction(USERS *p_users,USER *p_user);
bool staff_dimission(USERS *p_users,USER *p_user);
#endif 
