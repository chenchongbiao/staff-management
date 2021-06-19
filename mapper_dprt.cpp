#include "mapper_dprt.h"

/*
			数据库读取方式 
*/ 
///////////////////////////////////添加部门/////////////////////////////////////////////
int save_dprt(sqlite3 *db,DATABASE *datainfo, DEPARTMENT dprt)
{
	char *save_sql = "INSERT INTO department (name) VALUES ('%s');";
	select_dprt_by_name(db,datainfo,dprt);
	if (datainfo->rowCount > 1){
    	return 2;											// 部门已经存在 
	}
	sprintf(datainfo->sql,save_sql,dprt.NAME);
	exec(db,datainfo); 
	return 1;
}
///////////////////////////////////删除部门/////////////////////////////////////////////
int delete_user_by_dprtId(sqlite3 *db,DATABASE *datainfo, DEPARTMENT dprt)
{
	char *delete_sql = "DELETE FROM department WHERE rowid = %d;";
	select_dprt_by_name(db,datainfo,dprt);
	if (datainfo->rowCount == 0){
    	return 2;											// 部门不存在存在 
	}
	sprintf(datainfo->sql,delete_sql,dprt.NAME,dprt.rowid);
	exec(db,datainfo);
	return 1;
}
///////////////////////////////////修改部门/////////////////////////////////////////////
// 根据rowid修改部门 
int update_user_by_dprtId(sqlite3 *db,DATABASE *datainfo, DEPARTMENT dprt)
{
	char *update_sql = "UPDATE department SET name = '%s' WHERE rowid = %d;";
	select_dprt_by_name(db,datainfo,dprt);
	if (datainfo->rowCount > 1){
    	return 2;											// 部门已经存在 
	}
	sprintf(datainfo->sql,update_sql,dprt.NAME,dprt.rowid);
	exec(db,datainfo);
	return 1;
}
///////////////////////////////////查找部门/////////////////////////////////////////////// 
// 根据部门名字查找 
int select_dprt_by_name(sqlite3 *db,DATABASE *datainfo, DEPARTMENT dprt)
{
	char *select_sql = "SELECT rowid,* FROM department WHERE name = '%s';";
	sprintf(datainfo->sql,select_sql,dprt.NAME);
	exec(db,datainfo);
	return 1;
}



