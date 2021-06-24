#include "service_count.h"


/*
=====================================================管理员操作=============================================================

============================================================================================================================
*/
// 按性别统计员工
bool count_by_sex(sqlite3 *db,DATABASE *datainfo)
{
    char *column_name[] = {"性别","统计结果"};
    char *sex[] = {"女","男"};
    char **data;
    int code;
    printf("按性别统计员工");
    code = count_user_by_sex(db,datainfo);         // 按性别统计员工
    if(code == 2)
    {
        printf("没有数据！");
        return false;
    }
    data = datainfo->tableData;             // 取出统计数据
    for(int i=0;i < datainfo->columnCount;i++)  // 替换列名
    {
        data[i] = column_name[i];
    }
    count_bound();
    for(int i=0;i<(datainfo->rowCount+1)*datainfo->columnCount;i++)
    {
        if((i+1)%datainfo->columnCount == 1 && i > 1)
            datainfo->tableData[i] = sex[atoi(datainfo->tableData[i])];			// 根据性别的数字替换
        printf("%-12s",datainfo->tableData[i]);
        if((i+1)%datainfo->columnCount == 0)
        {
            count_bound();
        }
    }
    system("pause");
	return true;
}
// 按部门统计员工
bool count_by_dprt(sqlite3 *db,DATABASE *datainfo)
{
    char *column_name[] = {"部门","统计结果"};
    char **dprt;            // 所有部门数据
    char **data;
    int code;
    DATABASE dprtdata;
    select_all_dprt(db,&dprtdata);                   // 查找所有部门
    dprt = dprtdata.tableData;
    code = count_user_by_dprt(db,datainfo);         // 按部门统计员工
    data = datainfo->tableData;
    printf("按部门统计员工");
    if(code == 2)
    {
        printf("没有数据！");
        return false;
    }
    data = datainfo->tableData;             // 取出统计数据
    for(int i=0;i < datainfo->columnCount;i++)  // 替换列名
    {
        data[i] = column_name[i];
    }
    count_bound();
    for(int i=0;i<(datainfo->rowCount+1)*datainfo->columnCount;i++)
    {
        if((i+1)%datainfo->columnCount == 1 && i > 1)
        {
            for(int j=dprtdata.columnCount;j<(dprtdata.rowCount+1)*dprtdata.columnCount;j+=2)         // 通过循环部门数组匹配对应的rowid
                if (strcmp(datainfo->tableData[i], dprt[j])==0)
                     datainfo->tableData[i] = dprt[j+1];		// 根据部门的数字替换
        }
        printf("%-12s",datainfo->tableData[i]);
        if((i+1)%datainfo->columnCount == 0)
        {
            count_bound();
        }
    }
    system("pause");
	return true;
}
// 按学历统计员工
bool count_by_edu(sqlite3 *db,DATABASE *datainfo)
{
    char *education[] = {"小学","初级中学","高级中学","中专","职校","中技","专科","本科","硕士研究生","博士研究生"};
    char *column_name[] = {"学历","统计结果"};
    char **data;
    int code;
    code = count_user_by_edu(db,datainfo);         // 按性别统计员工
    printf("按学历统计员工");
    if(code == 2)
    {
        printf("没有数据！");
        return false;
    }
    data = datainfo->tableData;             // 取出统计数据
    for(int i=0;i < datainfo->columnCount;i++)  // 替换列名
    {
        data[i] = column_name[i];
    }
    count_bound();
    for(int i=0;i<(datainfo->rowCount+1)*datainfo->columnCount;i++)
    {
        if((i+1)%datainfo->columnCount == 1 && i > 1)
            datainfo->tableData[i] = education[atoi(datainfo->tableData[i])];			// 根据性别的数字替换
        printf("%-12s",datainfo->tableData[i]);
        if((i+1)%datainfo->columnCount == 0)
        {
            count_bound();
        }
    }
    system("pause");
	return true;
	return true;
}
//================================================管理员操作结束=========================================================


/*
=====================================================部门经理操作===========================================================

============================================================================================================================
*/
// 按性别统计员工
bool count_by_sex(sqlite3 *db,DATABASE *datainfo,USER *p_user)
{
    char *column_name[] = {"性别","统计结果"};
    char *sex[] = {"女","男"};
    char **data;
    int code;
    printf("按性别统计员工");
    code = count_user_by_sex(db,datainfo,p_user->department_id);         // 按性别统计员工
    if(code == 2)
    {
        printf("没有数据！");
        return false;
    }
    data = datainfo->tableData;             // 取出统计数据
    for(int i=0;i < datainfo->columnCount;i++)  // 替换列名
    {
        data[i] = column_name[i];
    }
    count_bound();
    for(int i=0;i<(datainfo->rowCount+1)*datainfo->columnCount;i++)
    {
        if((i+1)%datainfo->columnCount == 1 && i > 1)
            datainfo->tableData[i] = sex[atoi(datainfo->tableData[i])];			// 根据性别的数字替换
        printf("%-12s",datainfo->tableData[i]);
        if((i+1)%datainfo->columnCount == 0)
        {
            count_bound();
        }
    }
    system("pause");
	return true;
}
// 按部门统计员工
bool count_by_dprt(sqlite3 *db,DATABASE *datainfo,USER *p_user)
{
    char *column_name[] = {"部门","统计结果"};
    char **dprt;            // 所有部门数据
    char **data;
    int code;
    DATABASE dprtdata;
    select_all_dprt(db,&dprtdata);                   // 查找所有部门
    dprt = dprtdata.tableData;
    code = count_user_by_dprt(db,datainfo,p_user->department_id);         // 按部门统计员工
    data = datainfo->tableData;
    printf("按部门统计员工");
    if(code == 2)
    {
        printf("没有数据！");
        return false;
    }
    data = datainfo->tableData;             // 取出统计数据
    for(int i=0;i < datainfo->columnCount;i++)  // 替换列名
    {
        data[i] = column_name[i];
    }
    count_bound();
    for(int i=0;i<(datainfo->rowCount+1)*datainfo->columnCount;i++)
    {
        if((i+1)%datainfo->columnCount == 1 && i > 1)
        {
            for(int j=dprtdata.columnCount;j<(dprtdata.rowCount+1)*dprtdata.columnCount;j+=2)         // 通过循环部门数组匹配对应的rowid
                if (strcmp(datainfo->tableData[i], dprt[j])==0)
                     datainfo->tableData[i] = dprt[j+1];		// 根据部门的数字替换
        }
        printf("%-12s",datainfo->tableData[i]);
        if((i+1)%datainfo->columnCount == 0)
        {
            count_bound();
        }
    }
    system("pause");
	return true;
}
// 按学历统计员工
bool count_by_edu(sqlite3 *db,DATABASE *datainfo,USER *p_user)
{
    char *education[] = {"小学","初级中学","高级中学","中专","职校","中技","专科","本科","硕士研究生","博士研究生"};
    char *column_name[] = {"学历","统计结果"};
    char **data;
    int code;
    code = count_user_by_edu(db,datainfo,p_user->department_id);         // 按性别统计员工
    printf("按学历统计员工");
    if(code == 2)
    {
        printf("没有数据！");
        return false;
    }
    data = datainfo->tableData;             // 取出统计数据
    for(int i=0;i < datainfo->columnCount;i++)  // 替换列名
    {
        data[i] = column_name[i];
    }
    count_bound();
    for(int i=0;i<(datainfo->rowCount+1)*datainfo->columnCount;i++)
    {
        if((i+1)%datainfo->columnCount == 1 && i > 1)
            datainfo->tableData[i] = education[atoi(datainfo->tableData[i])];			// 根据性别的数字替换
        printf("%-12s",datainfo->tableData[i]);
        if((i+1)%datainfo->columnCount == 0)
        {
            count_bound();
        }
    }
    system("pause");
	return true;
	return true;
}
//================================================部门经理操作结束=========================================================


void count_bound()
{
    printf("\n=============================\n");
}
