#ifndef __SERVICE_USER_H__
#define __SERVICE_USER_H__
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mapper_user.h"
#include "struct.h"

bool login(USERS users, USER *p_user); // ��¼ 

////////////////////////////////////////////////����Ա����///////////////////////////////////////////////// 
// ���Ա��
bool admin_save_user(USERS *p_users);
// ɾ��Ա��
bool admin_delete_user(USERS *p_users);
// �޸�Ա��
bool admin_udpate_user(USERS *p_users);
// ����Ա��
bool admin_select_user(USERS users);
// Ա����Ϣ���� 
bool staff_info(USERS users);

// ��Ӳ��� 
bool admin_save_dapart(DEPARTMENTS *p_dprts);
// ɾ������ 
bool admin_delete_dapart(DEPARTMENTS *p_dprts);
// �޸Ĳ��� 
bool admin_udpate_dapart(DEPARTMENTS *p_dprts);
// ���Ҳ��� 
bool admin_select_dapart(DEPARTMENTS dprts);
// ������Ϣ���� 
bool dapart_info(DEPARTMENTS dprts);

////////////////////////////////////////////////���ž������///////////////////////////////////////////////

////////////////////////////////////////////////һ��Ա������///////////////////////////////////////////////
///////////////////////////////////////////һ���û�///////////////////////////////////////// 
// Ա����ְ 
bool staff_induction(USERS *p_users,USER *p_user);
// Ա����ְ 
bool staff_dimission(USERS *p_users,USER *p_user);
#endif 
