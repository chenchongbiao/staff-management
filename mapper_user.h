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
int delete_user_by_staffId(sqlite3 *db,DATABASE *datainfo,char staff_id); 
/*
===========================================================================================================================																								
														�޸��û� 												
===========================================================================================================================
*/
// �޸��û��� 
int update_user_username(sqlite3 *db,DATABASE *datainfo,USER user); 
// �޸����� 
int update_user_name(sqlite3 *db,DATABASE *datainfo,USER user); 
// �޸���ְ״̬
int update_user_status(sqlite3 *db,DATABASE *datainfo,USER user); 
// ͨ��Ա�����޸ĸ�����Ϣ 
int update_user_by_staffId(sqlite3 *db,DATABASE *datainfo, USER user);

/*
===========================================================================================================================																								
														�����û� 												
===========================================================================================================================
*/

// ͨ��Ա���Ų��� 
int select_user_by_staffId(sqlite3 *db,DATABASE *datainfo,char *staff_id);
// ͨ���û������� 
int select_user_by_username(sqlite3 *db,DATABASE *datainfo,char *username);
// ��֤���� 
int select_user_by_password(sqlite3 *db,DATABASE *datainfo,char *username,char *password);
// ִ�����ݿ���� 
int exec(sqlite3 *db,DATABASE *datainfo);


/*
			�ļ���ȡ��ʽ 
*/ 
///////////////////////////////////����û�/////////////////////////////////////////////
int save_user(USERS *p_users,USER user);
///////////////////////////////////ɾ���û�/////////////////////////////////////////////
///////////////////////////////////�޸��û�/////////////////////////////////////////////
int update_user(USERS *p_users,USER user);
///////////////////////////////////�����û�/////////////////////////////////////////////// 

// ͨ���û������� 
//int select_user_by_username(USERS users,char *p_username);
#endif
