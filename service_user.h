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
														
													����Ա����
														
===========================================================================================================================
*/
// ���Ա��
bool save_staff(sqlite3 *db,DATABASE *datainfo,USER *p_user);
// ���Ա��
//bool admin_save_user(USERS *p_users);
//// ɾ��Ա��
//bool admin_delete_user(USERS *p_users);
//// �޸�Ա��
//bool admin_udpate_user(USERS *p_users);
//// ����Ա��
//bool admin_select_user(USERS users);
//// Ա����Ϣ���� 
//bool staff_info(USERS users);
//================================================����Ա��������=========================================================


/*
===========================================================================================================================										
														
													���ž������
														
===========================================================================================================================
*/
//================================================���ž����������=========================================================




/*
===========================================================================================================================										
														
													һ��Ա������
														
===========================================================================================================================
*/
// Ա����ְ 
bool staff_induction(sqlite3 *db,DATABASE *datainfo,USER *p_user);
// Ա����ְ 
bool staff_dimission(sqlite3 *db,DATABASE *datainfo,USER *p_user);
// �޸ĸ�����Ϣ 
bool update_info(sqlite3 *db,DATABASE *datainfo,USER *p_user);
//================================================һ��Ա����������=========================================================

/*
===========================================================================================================================										
														
														�������� 
														
===========================================================================================================================
*/
// ��¼ 
bool login(sqlite3 *db,DATABASE *datainfo,USER *p_user); 
// ��ӡ�û����� 
void print_user_Info(sqlite3 *db,DATABASE *datainfo);
// ��ǰ�û�����Ϣ 
void curr_user_info(char **data,USER *p_user);
// �޸��û��� 
bool update_username(sqlite3 *db,DATABASE *datainfo,USER *p_user); 
// �޸����� 
bool update_name(sqlite3 *db,DATABASE *datainfo,USER *p_user); 
// �޸����� 
bool update_password(sqlite3 *db,DATABASE *datainfo,USER *p_user);
// �޸�ѧ�� 
bool update_edu(sqlite3 *db,DATABASE *datainfo,USER *p_user);  
// �޸ĵ绰 
bool update_mobile(sqlite3 *db,DATABASE *datainfo,USER *p_user); 
// ѯ���Ƿ��޸���Ϣ
int alert(char *info); 
int input_int(char *info,int &data);
// �����ַ��ͱ���
int input_str(char *info,char *data);
// ���ṹ����ַ�ָ�뿪���ڴ�
void malloc_user(USER *user);
// �ͷŽṹ����ַ�ָ��
void free_user(USER *user);
#endif 
