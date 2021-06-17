#include "mapper_user.h"
/*
			数据库读取方式 
*/ 
///////////////////////////////////添加用户/////////////////////////////////////////////
int save_user(sqlite3 *db)
{
	USER user;				// 用户信息 
	DEPARTMENT dprt;		// 部门信息 
	DATABASE database;		// 数据库信息 
	char ch;  				// 存放选择 
	char *save_sql = "INSERT INTO user (user_name,name,password,role_id,sex,department_id,education,staff_id,mobile,status)\
            		  VALUES ('%s', '%s', '%s', %d, %d , %d , %d, %d,%d,%d);"; 
            		  
	return 1; 
}
///////////////////////////////////删除用户/////////////////////////////////////////////
///////////////////////////////////修改用户/////////////////////////////////////////////
int update_user(sqlite3 *db)
{

	return 1; 
}
///////////////////////////////////查找用户/////////////////////////////////////////////// 

// 通过用户名查找 
int select_user_by_username(sqlite3 *db)
{
	
	return 1;
}

// 通过员工号查找 
int select_user_by_staffId(sqlite3 *db,DATABASE *datainfo,int staff_id)
{	
	USER user;				// 用户信息 
	DEPARTMENT dprt;		// 部门信息 
	DATABASE database;		// 数据库信息 
	char ch;				// 存放选择 
	char *select_sql = "SELECT * FROM user WHERE staff_id = %d;";
	sprintf(datainfo->sql,select_sql,staff_id);
	if(SQLITE_OK != sqlite3_get_table(db ,datainfo->sql , &datainfo->tableData , &datainfo->rowCount , &datainfo->columnCount , &datainfo->errorInfo ))

	{
		printf("\nERROR:%s\n",datainfo->errorInfo);
		return 0;
	}
//	else if(datainfo->rowCount > 0) 
//	{
//	    printf("数据表的记录:\n");
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
	else{
		printf("没有数据！\n");
		return 0;
	}
	return 1;
}



/*
			文件读取方式 
*/
///////////////////////////////////添加用户/////////////////////////////////////////////
int save_user(USERS *p_users,USER user)
{
	if (p_users->length >= USER_NUM_MAX) // 用户已满 
		return 0; 
	// 添加至线性表结尾
	p_users->users[p_users->length++] = user;
	return 1; 
}
///////////////////////////////////删除用户/////////////////////////////////////////////
///////////////////////////////////修改用户/////////////////////////////////////////////
int update_user(USERS *p_users,USER user)
{
    int index = select_user_by_username(*p_users,user.user_name);
    if (index < 0 || index >= p_users->length)
    	return 0;
    p_users->users[index] = user;
	return 1; 
}
///////////////////////////////////查找用户/////////////////////////////////////////////// 

// 通过用户名查找 
int select_user_by_username(USERS users,char *p_username)
{
	int i;
	for (i = 0; i < users.length; i++)
	{
		if (strcmp(users.users[i].user_name ,p_username) == 0)	// 用户名一致
		{
			return i;		// 返回索引位置 
		} 
	} 
	return -1;
}
