#include "service_dprt.h"


//================================================����Ա����=========================================================
// ��Ӳ��� 
bool admin_save_dapart(sqlite3 *db,DATABASE *datainfo)
{
    int code;
    DEPARTMENT *dprt;
    dprt = (struct DEPARTMENT*)malloc(sizeof(struct DEPARTMENT));
    dprt->NAME = (char *)malloc(20);                                // �����ڴ�
    input_str("��������",dprt->NAME);
    code = save_dprt(db,datainfo,*dprt);
    while(code == 2)
    {
        printf("\t\t���������Ѿ���������������\n");
        input_str("��������",dprt->NAME);
        code = save_dprt(db,datainfo,*dprt);
    }
    free(dprt->NAME);
    free(dprt);
    system("pause");
    return true;
}
// ɾ������
bool admin_delete_dapart(sqlite3 *db,DATABASE *datainfo)
{
    int code;
    DEPARTMENT *dprt;
    char **data;
    dprt = (struct DEPARTMENT*)malloc(sizeof(struct DEPARTMENT));
    select_all_dprt(db,datainfo);        // �������в���
    data = datainfo->tableData;
    for(int i = datainfo->columnCount;i < (datainfo->rowCount+1)*datainfo->columnCount;i+=2) // �����ݿ�����ȡ���ݻ�ò����б�
    {
        printf("\t\t%d--%s\n",i/2,data[i+1]);
    }
    input_int("����",dprt->rowid);
    dprt->rowid = atoi(data[dprt->rowid*2]);
    delete_user_by_dprtId(db,datainfo,*dprt);
    free(dprt);
    return true;
}
// �޸Ĳ���
bool admin_udpate_dapart(sqlite3 *db,DATABASE *datainfo)
{
    return true;
}
// ���Ҳ���
bool admin_select_dapart(sqlite3 *db,DATABASE *datainfo)
{
    return true;
}
// ������Ϣ����
bool dapart_info(sqlite3 *db,DATABASE *datainfo)
{
    return true;
}

