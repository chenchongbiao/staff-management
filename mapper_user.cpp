#include "mapper_user.h"
/*
			���ݿ��ȡ��ʽ 
*/ 
///////////////////////////////////����û�/////////////////////////////////////////////
int save_user(sqlite3 *db,DATABASE *datainfo, USER user)
{
	char *save_sql = "INSERT INTO user (username,name,password,role_id,sex,department_id,education,staff_id,mobile,status)\
            		  VALUES ('%s', '%s','%s',%d,%d,%d,%d,%d,%s,%d);"; 
    select_user_by_staffId(db,datainfo,user.staff_id);		// ʹ��Ա���Ų����Ƿ��Ѿ��������û��� 
    if (datainfo->rowCount > 1){
    	return 2;											// Ա�����Ѿ����� 
	}
	select_user_by_username(db,datainfo,user.username);
    if (datainfo->rowCount > 1){
    	return 3;											// �û����Ѿ����� 
	}
	// ��ʼ�������û�
	sprintf(datainfo->sql,save_sql,user.username,user.name,user.password,user.role_id,user.sex,user.department_id,user.education,user.staff_id,user.mobile,user.status); 
	printf("%s",save_sql); 
	exec(db,datainfo);	
	return 1; 
}
///////////////////////////////////ɾ���û�/////////////////////////////////////////////
// ͨ��Ա����ɾ�� 
int delete_user_by_staffId(sqlite3 *db,DATABASE *datainfo,int staff_id)
{
	char *delete_sql = "DELETE FROM user where staff_id = %d;"; 
	select_user_by_staffId(db,datainfo,staff_id);		// �����Ƿ���ڸ��û� 
    if (datainfo->rowCount == 0){
    	return 2;											// Ա���Ų�����
	}
	sprintf(datainfo->sql,delete_sql,staff_id);
	exec(db,datainfo);										// ִ����� 
	return 1;
}

///////////////////////////////////�޸��û�/////////////////////////////////////////////
// ͨ��Ա���Ų��� 
int update_user_by_staffId(sqlite3 *db,DATABASE *datainfo, USER user)
{
	char *update_sql = "UPDATE user SET username = '%s', name = '%s', password = '%s', role_id = %d,\
						sex = %d, department_id = %d,education = %d, mobile = '%s', status = %d\
						WHERE staff_id = %d;";
	sprintf(datainfo->sql,update_sql,user.username,user.name,user.password,user.role_id,user.sex,user.department_id,user.education,user.mobile,user.status,user.staff_id);
	exec(db,datainfo);
	return 1; 
}
///////////////////////////////////�����û�/////////////////////////////////////////////// 

// ͨ���û������� 
int select_user_by_username(sqlite3 *db,DATABASE *datainfo,char *username)
{
	char *select_sql = "SELECT * FROM user WHERE username = '%s';";
	sprintf(datainfo->sql,select_sql,username);
	exec(db,datainfo);
	return 1;
}

// ͨ��Ա���Ų��� 
int select_user_by_staffId(sqlite3 *db,DATABASE *datainfo,int staff_id)
{	
	char *select_sql = "SELECT * FROM user WHERE staff_id = %d;";
	sprintf(datainfo->sql,select_sql,staff_id);
	exec(db,datainfo);
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
	return 1;
}

// ִ�����ݿ���� 
int exec(sqlite3 *db,DATABASE *datainfo)
{
	if(SQLITE_OK != sqlite3_get_table(db ,datainfo->sql , &datainfo->tableData , &datainfo->rowCount , &datainfo->columnCount , &datainfo->errorInfo ))
	{
		printf("\nERROR:%s\n",datainfo->errorInfo);
		return 0;											// ����ʧ�� 
	}
	return 1; 
}



/*
			�ļ���ȡ��ʽ 
*/
///////////////////////////////////����û�/////////////////////////////////////////////
int save_user(USERS *p_users,USER user)
{
	if (p_users->length >= USER_NUM_MAX) // �û����� 
		return 0; 
	// ��������Ա��β
	p_users->users[p_users->length++] = user;
	return 1; 
}
///////////////////////////////////ɾ���û�/////////////////////////////////////////////
///////////////////////////////////�޸��û�/////////////////////////////////////////////
int update_user(USERS *p_users,USER user)
{
    int index = select_user_by_username(*p_users,user.username);
    if (index < 0 || index >= p_users->length)
    	return 0;
    p_users->users[index] = user;
	return 1; 
}
///////////////////////////////////�����û�/////////////////////////////////////////////// 

// ͨ���û������� 
int select_user_by_username(USERS users,char *p_username)
{
	int i;
	for (i = 0; i < users.length; i++)
	{
		if (strcmp(users.users[i].username ,p_username) == 0)	// �û���һ��
		{
			return i;		// ��������λ�� 
		} 
	} 
	return -1;
}
