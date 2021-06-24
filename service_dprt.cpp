#include "service_dprt.h"


//================================================管理员操作=========================================================
// 添加部门 
bool admin_save_dapart(sqlite3 *db,DATABASE *datainfo)
{
    int code;
    DEPARTMENT *dprt;
    dprt = (struct DEPARTMENT*)malloc(sizeof(struct DEPARTMENT));
    dprt->NAME = (char *)malloc(20);                                // 开辟内存
    input_str("部门名称",dprt->NAME);
    code = save_dprt(db,datainfo,*dprt);
    while(code == 2)
    {
        printf("\t\t部门名称已经存在请重新输入\n");
        input_str("部门名称",dprt->NAME);
        code = save_dprt(db,datainfo,*dprt);
    }
    free(dprt->NAME);
    free(dprt);
    system("pause");
    return true;
}
// 删除部门
bool admin_delete_dapart(sqlite3 *db,DATABASE *datainfo)
{
    int code;
    DEPARTMENT *dprt;
    char **data;
    dprt = (struct DEPARTMENT*)malloc(sizeof(struct DEPARTMENT));
    select_all_dprt(db,datainfo);        // 查找所有部门
    data = datainfo->tableData;
    for(int i = datainfo->columnCount;i < (datainfo->rowCount+1)*datainfo->columnCount;i+=2) // 从数据库中提取数据获得部门列表
    {
        printf("\t\t%d--%s\n",i/2,data[i+1]);
    }
    input_int("部门",dprt->rowid);
    dprt->rowid = atoi(data[dprt->rowid*2]);
    delete_user_by_dprtId(db,datainfo,*dprt);
    free(dprt);
    return true;
}
// 修改部门
bool admin_udpate_dapart(sqlite3 *db,DATABASE *datainfo)
{
    return true;
}
// 查找部门
bool admin_select_dapart(sqlite3 *db,DATABASE *datainfo)
{
    return true;
}
// 部门信息总览
bool dapart_info(sqlite3 *db,DATABASE *datainfo)
{
    return true;
}

