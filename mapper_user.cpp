#include "mapper_user.h"
/*
			数据库读取方式 
*/ 
/*
===========================================================================================================================																								
												     	添加用户												
===========================================================================================================================
*/
int save_user(sqlite3 *db,DATABASE *datainfo, USER user)
{
	int code;
	char *save_sql = "INSERT INTO user (username,name,password,role_id,sex,department_id,education,staff_id,mobile,status)\
            		  VALUES ('%s', '%s','%s','%d','%d','%d','%d','%s','%s','%d');";
//    select_user_by_staffId(db,datainfo,user.staff_id);		// 使用员工号查找是否已经创建该用户了
//    if (datainfo->rowCount > 1){
//    	code = 2;											// 员工号已经存在
//	}
//	select_user_by_username(db,datainfo,user.username);
//    if (datainfo->rowCount > 1){
//    	code = 3;											// 用户名已经存在
//	}
	// 开始创建新用户
	sprintf(datainfo->sql,save_sql,user.username,user.name,user.password,user.role_id,user.sex,user.department_id,user.education,user.staff_id,user.mobile,user.status);
	code = exec(db,datainfo);
	return code;
}

/*
===========================================================================================================================
												     	删除用户
===========================================================================================================================
*/
// 通过员工号删除
int delete_user_by_staffId(sqlite3 *db,DATABASE *datainfo,char *staff_id)
{
	int code;
	char *delete_sql = "DELETE FROM user where staff_id = '%s';";
	sprintf(datainfo->sql,delete_sql,staff_id);
	code = exec(db,datainfo);										// 执行语句
	return code;
}

/*
===========================================================================================================================
												     	修改用户
===========================================================================================================================
*/
// 修改用户名
int update_user_username(sqlite3 *db,DATABASE *datainfo,USER user)
{
	int code;
	char *update_sql = "UPDATE user SET username = '%s' WHERE staff_id = '%s';";
	sprintf(datainfo->sql,update_sql,user.username,user.staff_id);
	code = exec(db,datainfo);
	return code;
}

// 修改姓名
int update_user_name(sqlite3 *db,DATABASE *datainfo,USER user)
{
	int code;
	char *update_sql = "UPDATE user SET name = '%s' WHERE staff_id = '%s';";
	sprintf(datainfo->sql,update_sql,user.name,user.staff_id);
	code = exec(db,datainfo);
	return code;
}

// 修改密码
int update_user_password(sqlite3 *db,DATABASE *datainfo,USER user)
{
	int code;
	char *update_sql = "UPDATE user SET password = '%s' WHERE staff_id = '%s';";
	sprintf(datainfo->sql,update_sql,user.password,user.staff_id);
	code = exec(db,datainfo);
	return code;
}
// 修改权限
int update_user_role(sqlite3 *db,DATABASE *datainfo,USER user)
{
    int code;
	char *update_sql = "UPDATE user SET role_id = %d WHERE staff_id = '%s';";
	sprintf(datainfo->sql,update_sql,user.role_id,user.staff_id);
	code = exec(db,datainfo);
	return code;
}
// 修改性别
int update_user_sex(sqlite3 *db,DATABASE *datainfo,USER user)
{
    int code;
	char *update_sql = "UPDATE user SET sex = %d WHERE staff_id = '%s';";
	sprintf(datainfo->sql,update_sql,user.sex,user.staff_id);
	code = exec(db,datainfo);
	return code;
}
// 修改员工部门
int update_user_dprt(sqlite3 *db,DATABASE *datainfo,USER user)
{
	int code;
	char *update_sql = "UPDATE user SET department_id = %d WHERE staff_id  = '%s';";
	sprintf(datainfo->sql,update_sql,user.department_id,user.staff_id);
	code = exec(db,datainfo);
	return code;
}
// 修改学历
int update_user_edu(sqlite3 *db,DATABASE *datainfo,USER user)
{
	int code;
	char *update_sql = "UPDATE user SET education = %d WHERE staff_id  = '%s';";
	sprintf(datainfo->sql,update_sql,user.education,user.staff_id);
	code = exec(db,datainfo);
	return code;
}

// 修改员工号
int update_user_staffId(sqlite3 *db,DATABASE *datainfo,USER user,char *new_staffId)
{
	int code;
	char *update_sql = "UPDATE user SET staff_id = '%s' WHERE staff_id  = '%s';";
	sprintf(datainfo->sql,update_sql,new_staffId,user.staff_id);
	code = exec(db,datainfo);
	return code;
}

// 修改电话
int update_user_mobile(sqlite3 *db,DATABASE *datainfo,USER user)
{
	int code;
	char *update_sql = "UPDATE user SET mobile = '%s' WHERE staff_id  = '%s';";
	sprintf(datainfo->sql,update_sql,user.mobile,user.staff_id);
	code = exec(db,datainfo);
	return code;
}

// 修改在职状态
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
												     	查找用户
===========================================================================================================================
*/
// 通过用户名查找
int select_user_by_username(sqlite3 *db,DATABASE *datainfo,char *username)
{
	int code;
	char *select_sql = "SELECT * FROM user WHERE username = '%s';";
	sprintf(datainfo->sql,select_sql,username);
	code = exec(db,datainfo);
	if (datainfo->rowCount == 0){
    	code = 2;											// 员工号不存在
    	return code;
	}
	return code;
}

// 通过员工号查找
int select_user_by_staffId(sqlite3 *db,DATABASE *datainfo,char *staff_id)
{
	int code;
	char *select_sql = "SELECT * FROM user WHERE staff_id = '%s';";
	sprintf(datainfo->sql,select_sql,staff_id);
	code = exec(db,datainfo);
	if (datainfo->rowCount == 0){
		code = 2;											// 员工号不存在
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
	return code;
}

// 查找所有员工信息（管理员）
int select_all_user(sqlite3 *db,DATABASE *datainfo)
{
	int code;
	char *select_sql = "SELECT * FROM user;";
	sprintf(datainfo->sql,select_sql);
	code = exec(db,datainfo);
	if (datainfo->rowCount == 0){
    	code = 2;											// 没有信息
    	return code;
	}
	return code;
}

// 查找所有员工信息（部门管理员）
int select_all_user(sqlite3 *db,DATABASE *datainfo,int dprt_id)
{
	int code;
	char *select_sql = "SELECT * FROM user WHERE department_id = %d;";
	sprintf(datainfo->sql,select_sql,dprt_id);
	code = exec(db,datainfo);
	if (datainfo->rowCount == 0){
    	code = 2;											// 没有信息
    	return code;
	}
	return code;
}

// 使用密码查找用户，验证用户密码是否正确
int select_user_by_password(sqlite3 *db,DATABASE *datainfo,char *username,char *password)
{
	int code;
	char *select_sql = "SELECT * FROM user WHERE username = '%s' AND password = '%s';";
	sprintf(datainfo->sql,select_sql,username,password);
	code = exec(db,datainfo);
	if (datainfo->rowCount == 0){
    	code = 2;											// 员工不存在
    	return code;
	}
	return code;
}

// 分性别统计员工(管理员)
int count_user_by_sex(sqlite3 *db,DATABASE *datainfo)
{
	int code;
	char *select_sql = "SELECT sex,COUNT(*) FROM user GROUP BY sex;";
	sprintf(datainfo->sql,select_sql);
	code = exec(db,datainfo);
	if (datainfo->rowCount == 0){
    	code = 2;											// 没有数据
    	return code;
	}
	return code;
}

// 分学历统计员工（管理员）
int count_user_by_dprt(sqlite3 *db,DATABASE *datainfo)
{
	int code;
	char *select_sql = "SELECT department_id,COUNT(*) FROM user GROUP BY department_id;";
	sprintf(datainfo->sql,select_sql);
	code = exec(db,datainfo);
	if (datainfo->rowCount == 0){
    	code = 2;											// 没有数据
    	return code;
	}
	return code;
}

// 分学历统计员工（管理员）
int count_user_by_edu(sqlite3 *db,DATABASE *datainfo)
{
	int code;
	char *select_sql = "SELECT education,COUNT(*) FROM user GROUP BY education;";
	sprintf(datainfo->sql,select_sql);
	code = exec(db,datainfo);
	if (datainfo->rowCount == 0){
    	code = 2;											// 没有数据
    	return code;
	}
	return code;
}
// 分性别统计员工(部门管理员)
int count_user_by_sex(sqlite3 *db,DATABASE *datainfo,int dprt_id)
{
	int code;
	char *select_sql = "SELECT sex,COUNT(*) FROM user WHERE department_id = %d GROUP BY sex;";
	sprintf(datainfo->sql,select_sql,dprt_id);
	code = exec(db,datainfo);
	if (datainfo->rowCount == 0){
    	code = 2;											// 没有数据
    	return code;
	}
	return code;
}

// 分部门统计员工（部门管理员）
int count_user_by_dprt(sqlite3 *db,DATABASE *datainfo,int dprt_id)
{
	int code;
	char *select_sql = "SELECT department_id,COUNT(*) FROM user WHERE department_id = %d GROUP BY department_id;";
	sprintf(datainfo->sql,select_sql,dprt_id);
	code = exec(db,datainfo);
	if (datainfo->rowCount == 0){
    	code = 2;											// 没有数据
    	return code;
	}
	return code;
}

// 分学历统计员工（部门管理员）
int count_user_by_edu(sqlite3 *db,DATABASE *datainfo,int dprt_id)
{
	int code;
	char *select_sql = "SELECT education,COUNT(*) FROM user WHERE department_id = %d GROUP BY education;";
	sprintf(datainfo->sql,select_sql,dprt_id);
	code = exec(db,datainfo);
	if (datainfo->rowCount == 0){
    	code = 2;											// 没有数据
    	return code;
	}
	return code;
}
// 执行数据库语句
int exec(sqlite3 *db,DATABASE *datainfo)
{
	if(SQLITE_OK != sqlite3_get_table(db ,datainfo->sql , &datainfo->tableData , &datainfo->rowCount , &datainfo->columnCount , &datainfo->errorInfo ))
	{
		printf("\nERROR:%s\n",datainfo->errorInfo);
		return 0;											// 执行失败
	}
	return 1;
}


/*
======================================================================================
                                        删除数据库
======================================================================================
*/
// 删除数据库
int del_data(sqlite3 *db,DATABASE *datainfo)
{
    int code;
	char *select_sql = "DROP TABLE department;\
                        DROP TABLE user;";
	sprintf(datainfo->sql,select_sql);
	code = exec(db,datainfo);
	return code;
}
