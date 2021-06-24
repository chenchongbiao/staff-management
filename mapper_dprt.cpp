#include "mapper_dprt.h"

/*
			���ݿ��ȡ��ʽ 
*/ 
int save_dprt(sqlite3 *db,DATABASE *datainfo, DEPARTMENT dprt)
{
    int code;
	char *save_sql = "INSERT INTO department (name) VALUES ('%s');";
	select_dprt_by_name(db,datainfo,dprt);
	if (datainfo->rowCount > 1){
        code = 2;                        // �����Ѿ�����
        return code;
	}
	sprintf(datainfo->sql,save_sql,dprt.NAME);
	code = exec(db,datainfo);
	return code;
}
///////////////////////////////////ɾ������/////////////////////////////////////////////
int delete_user_by_dprtId(sqlite3 *db,DATABASE *datainfo, DEPARTMENT dprt)
{
    int code;
	char *delete_sql = "DELETE FROM department WHERE rowid = %d;";
	select_dprt_by_name(db,datainfo,dprt);
	if (datainfo->rowCount == 0){
    	code = 2;											// ���Ų����ڴ���
    	return code;
	}
	sprintf(datainfo->sql,delete_sql,dprt.NAME,dprt.rowid);
	code = exec(db,datainfo);
	return code;
}
///////////////////////////////////�޸Ĳ���/////////////////////////////////////////////
// ����rowid�޸Ĳ���
int update_user_by_dprtId(sqlite3 *db,DATABASE *datainfo, DEPARTMENT dprt)
{
    int code;
	char *update_sql = "UPDATE department SET name = '%s' WHERE rowid = %d;";
	select_dprt_by_name(db,datainfo,dprt);
	if (datainfo->rowCount > 1){
    	code = 2;											// �����Ѿ�����
    	return code;
	}
	sprintf(datainfo->sql,update_sql,dprt.NAME,dprt.rowid);
	exec(db,datainfo);
	return code;
}
///////////////////////////////////���Ҳ���///////////////////////////////////////////////
// ���ݲ������ֲ���
int select_dprt_by_name(sqlite3 *db,DATABASE *datainfo, DEPARTMENT dprt)
{
	int code;
	char *select_sql = "SELECT rowid,* FROM department WHERE name = '%s';";
	sprintf(datainfo->sql,select_sql,dprt.NAME);
	code = exec(db,datainfo);
	return code;
}
// ����id���Ҳ���
int select_dprt_by_id(sqlite3 *db,DATABASE *datainfo, int rowid)
{
    int code;
	char *select_sql = "SELECT * FROM department WHERE rowid = '%d';";
	sprintf(datainfo->sql,select_sql,rowid);
	code = exec(db,datainfo);
	return code;
}
// �������в���
int select_all_dprt(sqlite3 *db,DATABASE *datainfo)
{
    int code;
    char *select_sql = "SELECT rowid,* FROM department;";
	sprintf(datainfo->sql,select_sql);
	code = exec(db,datainfo);
	return code;
}


