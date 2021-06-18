#include "mapper_user.h"
/*
			数据库读取方式 
*/ 
///////////////////////////////////添加用户/////////////////////////////////////////////
int save_user(sqlite3 *db,DATABASE *datainfo, USER user)
{
	char *save_sql = "INSERT INTO user (username,name,password,role_id,sex,department_id,education,staff_id,mobile,status)\
            		  VALUES ('%s', '%s','%s',%d,%d,%d,%d,%d,%s,%d);"; 
    select_user_by_staffId(db,datainfo,user.staff_id);		// 使用员工号查找是否已经创建该用户了 
    if (datainfo->rowCount > 1){
    	return 2;											// 员工号已经存在 
	}
	select_user_by_username(db,datainfo,user.username);
    if (datainfo->rowCount > 1){
    	return 3;											// 用户名已经存在 
	}
	// 开始创建新用户
	sprintf(datainfo->sql,save_sql,user.username,user.name,user.password,user.role_id,user.sex,user.department_id,user.education,user.staff_id,user.mobile,user.status); 
	printf("%s",save_sql); 
	exec(db,datainfo);	
	return 1; 
}
///////////////////////////////////删除用户/////////////////////////////////////////////
// 通过员工号删除 
int delete_user_by_staffId(sqlite3 *db,DATABASE *datainfo,int staff_id)
{
	char *delete_sql = "DELETE FROM user where staff_id = %d;"; 
	select_user_by_staffId(db,datainfo,staff_id);		// 查找是否存在该用户 
    if (datainfo->rowCount == 0){
    	return 2;											// 员工号不存在
	}
	sprintf(datainfo->sql,delete_sql,staff_id);
	exec(db,datainfo);										// 执行语句 
	return 1;
}

///////////////////////////////////修改用户/////////////////////////////////////////////
// 通过员工号查找 
int update_user_by_staffId(sqlite3 *db,DATABASE *datainfo, USER user)
{
	char *update_sql = "UPDATE user SET username = '%s', name = '%s', password = '%s', role_id = %d,\
						sex = %d, department_id = %d,education = %d, mobile = '%s', status = %d\
						WHERE staff_id = %d;";
	sprintf(datainfo->sql,update_sql,user.username,user.name,user.password,user.role_id,user.sex,user.department_id,user.education,user.mobile,user.status,user.staff_id);
	exec(db,datainfo);
	return 1; 
}
///////////////////////////////////查找用户/////////////////////////////////////////////// 

// 通过用户名查找 
int select_user_by_username(sqlite3 *db,DATABASE *datainfo,char *username)
{
	char *select_sql = "SELECT * FROM user WHERE username = '%s';";
	sprintf(datainfo->sql,select_sql,username);
	exec(db,datainfo);
	return 1;
}

// 通过员工号查找 
int select_user_by_staffId(sqlite3 *db,DATABASE *datainfo,int staff_id)
{	
	char *select_sql = "SELECT * FROM user WHERE staff_id = %d;";
	sprintf(datainfo->sql,select_sql,staff_id);
	exec(db,datainfo);
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
	return 1;
}

// 执行数据库语句 
int exec(sqlite3 *db,DATABASE *datainfo)
{
	if(SQLITE_OK != sqlite3_get_table(db ,datainfo->sql , &datainfo->tableData , &datainfo->rowCount , &datainfo->columnCount , &datainfo->errorInfo ))
	{
		printf("\nERROR:%s\n",datainfo->errorInfo);
		return 0;											// 查找失败 
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
    int index = select_user_by_username(*p_users,user.username);
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
		if (strcmp(users.users[i].username ,p_username) == 0)	// 用户名一致
		{
			return i;		// 返回索引位置 
		} 
	} 
	return -1;
}
