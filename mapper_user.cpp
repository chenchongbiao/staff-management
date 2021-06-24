#include "mapper_user.h"
/*
			���ݿ��ȡ��ʽ 
*/ 
/*
===========================================================================================================================																								
												     	����û�												
===========================================================================================================================
*/
int save_user(sqlite3 *db,DATABASE *datainfo, USER user)
{
	int code;
	char *save_sql = "INSERT INTO user (username,name,password,role_id,sex,department_id,education,staff_id,mobile,status)\
            		  VALUES ('%s', '%s','%s','%d','%d','%d','%d','%s','%s','%d');";
//    select_user_by_staffId(db,datainfo,user.staff_id);		// ʹ��Ա���Ų����Ƿ��Ѿ��������û���
//    if (datainfo->rowCount > 1){
//    	code = 2;											// Ա�����Ѿ�����
//	}
//	select_user_by_username(db,datainfo,user.username);
//    if (datainfo->rowCount > 1){
//    	code = 3;											// �û����Ѿ�����
//	}
	// ��ʼ�������û�
	sprintf(datainfo->sql,save_sql,user.username,user.name,user.password,user.role_id,user.sex,user.department_id,user.education,user.staff_id,user.mobile,user.status);
	code = exec(db,datainfo);
	return code;
}

/*
===========================================================================================================================
												     	ɾ���û�
===========================================================================================================================
*/
// ͨ��Ա����ɾ��
int delete_user_by_staffId(sqlite3 *db,DATABASE *datainfo,char *staff_id)
{
	int code;
	char *delete_sql = "DELETE FROM user where staff_id = '%s';";
	sprintf(datainfo->sql,delete_sql,staff_id);
	code = exec(db,datainfo);										// ִ�����
	return code;
}

/*
===========================================================================================================================
												     	�޸��û�
===========================================================================================================================
*/
// �޸��û���
int update_user_username(sqlite3 *db,DATABASE *datainfo,USER user)
{
	int code;
	char *update_sql = "UPDATE user SET username = '%s' WHERE staff_id = '%s';";
	sprintf(datainfo->sql,update_sql,user.username,user.staff_id);
	code = exec(db,datainfo);
	return code;
}

// �޸�����
int update_user_name(sqlite3 *db,DATABASE *datainfo,USER user)
{
	int code;
	char *update_sql = "UPDATE user SET name = '%s' WHERE staff_id = '%s';";
	sprintf(datainfo->sql,update_sql,user.name,user.staff_id);
	code = exec(db,datainfo);
	return code;
}

// �޸�����
int update_user_password(sqlite3 *db,DATABASE *datainfo,USER user)
{
	int code;
	char *update_sql = "UPDATE user SET password = '%s' WHERE staff_id = '%s';";
	sprintf(datainfo->sql,update_sql,user.password,user.staff_id);
	code = exec(db,datainfo);
	return code;
}
// �޸�Ȩ��
int update_user_role(sqlite3 *db,DATABASE *datainfo,USER user)
{
    int code;
	char *update_sql = "UPDATE user SET role_id = %d WHERE staff_id = '%s';";
	sprintf(datainfo->sql,update_sql,user.role_id,user.staff_id);
	code = exec(db,datainfo);
	return code;
}
// �޸��Ա�
int update_user_sex(sqlite3 *db,DATABASE *datainfo,USER user)
{
    int code;
	char *update_sql = "UPDATE user SET sex = %d WHERE staff_id = '%s';";
	sprintf(datainfo->sql,update_sql,user.sex,user.staff_id);
	code = exec(db,datainfo);
	return code;
}
// �޸�Ա������
int update_user_dprt(sqlite3 *db,DATABASE *datainfo,USER user)
{
	int code;
	char *update_sql = "UPDATE user SET department_id = %d WHERE staff_id  = '%s';";
	sprintf(datainfo->sql,update_sql,user.department_id,user.staff_id);
	code = exec(db,datainfo);
	return code;
}
// �޸�ѧ��
int update_user_edu(sqlite3 *db,DATABASE *datainfo,USER user)
{
	int code;
	char *update_sql = "UPDATE user SET education = %d WHERE staff_id  = '%s';";
	sprintf(datainfo->sql,update_sql,user.education,user.staff_id);
	code = exec(db,datainfo);
	return code;
}

// �޸�Ա����
int update_user_staffId(sqlite3 *db,DATABASE *datainfo,USER user,char *new_staffId)
{
	int code;
	char *update_sql = "UPDATE user SET staff_id = '%s' WHERE staff_id  = '%s';";
	sprintf(datainfo->sql,update_sql,new_staffId,user.staff_id);
	code = exec(db,datainfo);
	return code;
}

// �޸ĵ绰
int update_user_mobile(sqlite3 *db,DATABASE *datainfo,USER user)
{
	int code;
	char *update_sql = "UPDATE user SET mobile = '%s' WHERE staff_id  = '%s';";
	sprintf(datainfo->sql,update_sql,user.mobile,user.staff_id);
	code = exec(db,datainfo);
	return code;
}

// �޸���ְ״̬
int update_user_status(sqlite3 *db,DATABASE *datainfo,USER user)
{
	int code;
	char *update_sql = "UPDATE user SET status = %d WHERE staff_id = '%s';";
	sprintf(datainfo->sql,update_sql,user.status,user.staff_id);
	code = exec(db,datainfo);
	return code;
}

/*
===========================================================================================================================
												     	�����û�
===========================================================================================================================
*/
// ͨ���û�������
int select_user_by_username(sqlite3 *db,DATABASE *datainfo,char *username)
{
	int code;
	char *select_sql = "SELECT * FROM user WHERE username = '%s';";
	sprintf(datainfo->sql,select_sql,username);
	code = exec(db,datainfo);
	if (datainfo->rowCount == 0){
    	code = 2;											// Ա���Ų�����
    	return code;
	}
	return code;
}

// ͨ��Ա���Ų���
int select_user_by_staffId(sqlite3 *db,DATABASE *datainfo,char *staff_id)
{
	int code;
	char *select_sql = "SELECT * FROM user WHERE staff_id = '%s';";
	sprintf(datainfo->sql,select_sql,staff_id);
	code = exec(db,datainfo);
	if (datainfo->rowCount == 0){
		code = 2;											// Ա���Ų�����
	}
//	else if(datainfo->rowCount > 0)
//	{
//	    printf("���ݱ�ļ�¼:\n");
//	    for(int i=0;i<(datainfo->rowCount+1)*datainfo->columnCount;i++)
//	    {
//	        printf("%-7s\t",datainfo->tableData[i]);
//	        if((i+1)%datainfo->columnCount == 0)
//	        {
//	            printf("\n");
//	        }
//	    }
//
//	}
	return code;
}

// ��������Ա����Ϣ������Ա��
int select_all_user(sqlite3 *db,DATABASE *datainfo)
{
	int code;
	char *select_sql = "SELECT * FROM user;";
	sprintf(datainfo->sql,select_sql);
	code = exec(db,datainfo);
	if (datainfo->rowCount == 0){
    	code = 2;											// û����Ϣ
    	return code;
	}
	return code;
}

// ��������Ա����Ϣ�����Ź���Ա��
int select_all_user(sqlite3 *db,DATABASE *datainfo,int dprt_id)
{
	int code;
	char *select_sql = "SELECT * FROM user WHERE department_id = %d;";
	sprintf(datainfo->sql,select_sql,dprt_id);
	code = exec(db,datainfo);
	if (datainfo->rowCount == 0){
    	code = 2;											// û����Ϣ
    	return code;
	}
	return code;
}

// ʹ����������û�����֤�û������Ƿ���ȷ
int select_user_by_password(sqlite3 *db,DATABASE *datainfo,char *username,char *password)
{
	int code;
	char *select_sql = "SELECT * FROM user WHERE username = '%s' AND password = '%s';";
	sprintf(datainfo->sql,select_sql,username,password);
	code = exec(db,datainfo);
	if (datainfo->rowCount == 0){
    	code = 2;											// Ա��������
    	return code;
	}
	return code;
}

// ���Ա�ͳ��Ա��(����Ա)
int count_user_by_sex(sqlite3 *db,DATABASE *datainfo)
{
	int code;
	char *select_sql = "SELECT sex,COUNT(*) FROM user GROUP BY sex;";
	sprintf(datainfo->sql,select_sql);
	code = exec(db,datainfo);
	if (datainfo->rowCount == 0){
    	code = 2;											// û������
    	return code;
	}
	return code;
}

// ��ѧ��ͳ��Ա��������Ա��
int count_user_by_dprt(sqlite3 *db,DATABASE *datainfo)
{
	int code;
	char *select_sql = "SELECT department_id,COUNT(*) FROM user GROUP BY department_id;";
	sprintf(datainfo->sql,select_sql);
	code = exec(db,datainfo);
	if (datainfo->rowCount == 0){
    	code = 2;											// û������
    	return code;
	}
	return code;
}

// ��ѧ��ͳ��Ա��������Ա��
int count_user_by_edu(sqlite3 *db,DATABASE *datainfo)
{
	int code;
	char *select_sql = "SELECT education,COUNT(*) FROM user GROUP BY education;";
	sprintf(datainfo->sql,select_sql);
	code = exec(db,datainfo);
	if (datainfo->rowCount == 0){
    	code = 2;											// û������
    	return code;
	}
	return code;
}
// ���Ա�ͳ��Ա��(���Ź���Ա)
int count_user_by_sex(sqlite3 *db,DATABASE *datainfo,int dprt_id)
{
	int code;
	char *select_sql = "SELECT sex,COUNT(*) FROM user WHERE department_id = %d GROUP BY sex;";
	sprintf(datainfo->sql,select_sql,dprt_id);
	code = exec(db,datainfo);
	if (datainfo->rowCount == 0){
    	code = 2;											// û������
    	return code;
	}
	return code;
}

// �ֲ���ͳ��Ա�������Ź���Ա��
int count_user_by_dprt(sqlite3 *db,DATABASE *datainfo,int dprt_id)
{
	int code;
	char *select_sql = "SELECT department_id,COUNT(*) FROM user WHERE department_id = %d GROUP BY department_id;";
	sprintf(datainfo->sql,select_sql,dprt_id);
	code = exec(db,datainfo);
	if (datainfo->rowCount == 0){
    	code = 2;											// û������
    	return code;
	}
	return code;
}

// ��ѧ��ͳ��Ա�������Ź���Ա��
int count_user_by_edu(sqlite3 *db,DATABASE *datainfo,int dprt_id)
{
	int code;
	char *select_sql = "SELECT education,COUNT(*) FROM user WHERE department_id = %d GROUP BY education;";
	sprintf(datainfo->sql,select_sql,dprt_id);
	code = exec(db,datainfo);
	if (datainfo->rowCount == 0){
    	code = 2;											// û������
    	return code;
	}
	return code;
}
// ִ�����ݿ����
int exec(sqlite3 *db,DATABASE *datainfo)
{
	if(SQLITE_OK != sqlite3_get_table(db ,datainfo->sql , &datainfo->tableData , &datainfo->rowCount , &datainfo->columnCount , &datainfo->errorInfo ))
	{
		printf("\nERROR:%s\n",datainfo->errorInfo);
		return 0;											// ִ��ʧ��
	}
	return 1;
}


/*
======================================================================================
                                        ɾ�����ݿ�
======================================================================================
*/
// ɾ�����ݿ�
int del_data(sqlite3 *db,DATABASE *datainfo)
{
    int code;
	char *select_sql = "DROP TABLE department;\
                        DROP TABLE user;";
	sprintf(datainfo->sql,select_sql);
	code = exec(db,datainfo);
	return code;
}
