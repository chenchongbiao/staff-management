#ifndef __MAPPER_USER_H__
#define __MAPPER_USER_H__    
#include <stdio.h>
#include <string.h>
#include "struct.h" 
#include "sqlite3.h"

/*
			���ݿ��ȡ��ʽ 
*/ 
/*
===========================================================================================================================																								
												     	����û� 												
===========================================================================================================================
*/
int save_user(sqlite3 *db,DATABASE *datainfo, USER user);
/*
===========================================================================================================================
												     	ɾ���û�
===========================================================================================================================
*/
// ͨ��Ա����ɾ��
int delete_user_by_staffId(sqlite3 *db,DATABASE *datainfo,char *staff_id);
/*
===========================================================================================================================
														�޸��û�
===========================================================================================================================
*/
// �޸��û���
int update_user_username(sqlite3 *db,DATABASE *datainfo,USER user);
// �޸�����
int update_user_name(sqlite3 *db,DATABASE *datainfo,USER user);
// �޸�����
int update_user_password(sqlite3 *db,DATABASE *datainfo,USER user);
// �޸�Ȩ��
int update_user_role(sqlite3 *db,DATABASE *datainfo,USER user);
// �޸��Ա�
int update_user_sex(sqlite3 *db,DATABASE *datainfo,USER user);
// �޸�Ա������
int update_user_dprt(sqlite3 *db,DATABASE *datainfo,USER user);
// �޸�ѧ��
int update_user_edu(sqlite3 *db,DATABASE *datainfo,USER user);
// �޸�Ա����
int update_user_staffId(sqlite3 *db,DATABASE *datainfo,USER user,char *new_staffId);
// �޸ĵ绰
int update_user_mobile(sqlite3 *db,DATABASE *datainfo,USER user);
// �޸���ְ״̬
int update_user_status(sqlite3 *db,DATABASE *datainfo,USER user);

/*
===========================================================================================================================
														�����û�
===========================================================================================================================
*/

// ͨ��Ա���Ų���
int select_user_by_staffId(sqlite3 *db,DATABASE *datainfo,char *staff_id);
// ͨ���û�������
int select_user_by_username(sqlite3 *db,DATABASE *datainfo,char *username);
// ��������Ա����Ϣ������Ա��
int select_all_user(sqlite3 *db,DATABASE *datainfo);
// ��������Ա����Ϣ�����Ź���Ա��
int select_all_user(sqlite3 *db,DATABASE *datainfo,int dprt_id);
// ���Ա�ͳ��Ա��������Ա��
int count_user_by_sex(sqlite3 *db,DATABASE *datainfo);
// ��ѧ��ͳ��Ա��������Ա��
int count_user_by_dprt(sqlite3 *db,DATABASE *datainfo);
// ��ѧ��ͳ��Ա��������Ա��
int count_user_by_edu(sqlite3 *db,DATABASE *datainfo);
// ���Ա�ͳ��Ա��(���Ź���Ա)
int count_user_by_sex(sqlite3 *db,DATABASE *datainfo,int dprt_id);
// �ֲ���ͳ��Ա�������Ź���Ա��
int count_user_by_dprt(sqlite3 *db,DATABASE *datainfo,int dprt_id);
// ��ѧ��ͳ��Ա�������Ź���Ա��
int count_user_by_edu(sqlite3 *db,DATABASE *datainfo,int dprt_id);
// ��֤����
int select_user_by_password(sqlite3 *db,DATABASE *datainfo,char *username,char *password);
// ִ�����ݿ����
int exec(sqlite3 *db,DATABASE *datainfo);
// ɾ�����ݿ�
int del_data(sqlite3 *db,DATABASE *datainfo);


#endif
