#include "mapper_dprt.h"

/*
			���ݿ��ȡ��ʽ 
*/ 
///////////////////////////////////��Ӳ���/////////////////////////////////////////////
int save_dprt(sqlite3 *db,DATABASE *datainfo, DEPARTMENT dprt)
{
	char *save_sql = "INSERT INTO department (name) VALUES ('%s');";
	select_dprt_by_name(db,datainfo,dprt);
	if (datainfo->rowCount > 1){
    	return 2;											// �����Ѿ����� 
	}
	sprintf(datainfo->sql,save_sql,dprt.NAME);
	exec(db,datainfo); 
	return 1;
}
///////////////////////////////////ɾ������/////////////////////////////////////////////
int delete_user_by_dprtId(sqlite3 *db,DATABASE *datainfo, DEPARTMENT dprt)
{
	char *delete_sql = "DELETE FROM department WHERE rowid = %d;";
	select_dprt_by_name(db,datainfo,dprt);
	if (datainfo->rowCount == 0){
    	return 2;											// ���Ų����ڴ��� 
	}
	sprintf(datainfo->sql,delete_sql,dprt.NAME,dprt.rowid);
	exec(db,datainfo);
	return 1;
}
///////////////////////////////////�޸Ĳ���/////////////////////////////////////////////
// ����rowid�޸Ĳ��� 
int update_user_by_dprtId(sqlite3 *db,DATABASE *datainfo, DEPARTMENT dprt)
{
	char *update_sql = "UPDATE department SET name = '%s' WHERE rowid = %d;";
	select_dprt_by_name(db,datainfo,dprt);
	if (datainfo->rowCount > 1){
    	return 2;											// �����Ѿ����� 
	}
	sprintf(datainfo->sql,update_sql,dprt.NAME,dprt.rowid);
	exec(db,datainfo);
	return 1;
}
///////////////////////////////////���Ҳ���/////////////////////////////////////////////// 
// ���ݲ������ֲ��� 
int select_dprt_by_name(sqlite3 *db,DATABASE *datainfo, DEPARTMENT dprt)
{
	char *select_sql = "SELECT rowid,* FROM department WHERE name = '%s';";
	sprintf(datainfo->sql,select_sql,dprt.NAME);
	exec(db,datainfo);
	return 1;
}



