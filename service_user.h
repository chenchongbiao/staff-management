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
														
													����Ա����
														
===========================================================================================================================
*/
// ���Ա��
bool save_staff(sqlite3 *db,DATABASE *datainfo,USER *p_user);
// ɾ��Ա��
bool delete_staff(sqlite3 *db,DATABASE *datainfo,USER *p_user);
// �޸�Ա����Ϣ
bool update_staff(sqlite3 *db,DATABASE *datainfo,USER *p_user);
// ����Ա����Ϣ
bool select_staff(sqlite3 *db,DATABASE *datainfo,USER *p_user);
// ����Ա��������Ա����Ϣ
bool select_all_staff(sqlite3 *db,DATABASE *datainfo);
// ɾ�����ݿ�
bool delete_database(sqlite3 *db,DATABASE *datainfo);
//================================================����Ա��������=========================================================


/*
===========================================================================================================================

													���ž������

===========================================================================================================================
*/
// ���ž����������Ա����Ϣ
bool select_all_staff(sqlite3 *db,DATABASE *datainfo,USER *p_user);
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
// �޸�Ȩ��
bool update_role(sqlite3 *db,DATABASE *datainfo,USER *p_user);
// �޸��Ա�
bool update_sex(sqlite3 *db,DATABASE *datainfo,USER *p_user);
// ���벿��
bool update_dprt(sqlite3 *db,DATABASE *datainfo,USER *p_user);
// �޸�ѧ��
bool update_edu(sqlite3 *db,DATABASE *datainfo,USER *p_user);
// �޸�Ա����
bool update_staffId(sqlite3 *db,DATABASE *datainfo,USER *p_user);
// �޸ĵ绰
bool update_mobile(sqlite3 *db,DATABASE *datainfo,USER *p_user);
// �޸���ְ״̬
bool update_status(sqlite3 *db,DATABASE *datainfo,USER *p_user);
// ѯ���Ƿ��޸���Ϣ
int alert(char *info);
//// �������ͱ���
//int input_int(char *info,int &data);
//// �����ַ��ͱ���
//int input_str(char *info,char *data);
// ���ṹ����ַ�ָ�뿪���ڴ�
void malloc_user(USER *user);
// �ͷŽṹ����ַ�ָ��
void free_user(USER *user);
// ��ӡ�ָ���
void bound();
#endif 
