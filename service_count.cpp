#include "service_count.h"


/*
=====================================================����Ա����=============================================================

============================================================================================================================
*/
// ���Ա�ͳ��Ա��
bool count_by_sex(sqlite3 *db,DATABASE *datainfo)
{
    char *column_name[] = {"�Ա�","ͳ�ƽ��"};
    char *sex[] = {"Ů","��"};
    char **data;
    int code;
    printf("���Ա�ͳ��Ա��");
    code = count_user_by_sex(db,datainfo);         // ���Ա�ͳ��Ա��
    if(code == 2)
    {
        printf("û�����ݣ�");
        return false;
    }
    data = datainfo->tableData;             // ȡ��ͳ������
    for(int i=0;i < datainfo->columnCount;i++)  // �滻����
    {
        data[i] = column_name[i];
    }
    count_bound();
    for(int i=0;i<(datainfo->rowCount+1)*datainfo->columnCount;i++)
    {
        if((i+1)%datainfo->columnCount == 1 && i > 1)
            datainfo->tableData[i] = sex[atoi(datainfo->tableData[i])];			// �����Ա�������滻
        printf("%-12s",datainfo->tableData[i]);
        if((i+1)%datainfo->columnCount == 0)
        {
            count_bound();
        }
    }
    system("pause");
	return true;
}
// ������ͳ��Ա��
bool count_by_dprt(sqlite3 *db,DATABASE *datainfo)
{
    char *column_name[] = {"����","ͳ�ƽ��"};
    char **dprt;            // ���в�������
    char **data;
    int code;
    DATABASE dprtdata;
    select_all_dprt(db,&dprtdata);                   // �������в���
    dprt = dprtdata.tableData;
    code = count_user_by_dprt(db,datainfo);         // ������ͳ��Ա��
    data = datainfo->tableData;
    printf("������ͳ��Ա��");
    if(code == 2)
    {
        printf("û�����ݣ�");
        return false;
    }
    data = datainfo->tableData;             // ȡ��ͳ������
    for(int i=0;i < datainfo->columnCount;i++)  // �滻����
    {
        data[i] = column_name[i];
    }
    count_bound();
    for(int i=0;i<(datainfo->rowCount+1)*datainfo->columnCount;i++)
    {
        if((i+1)%datainfo->columnCount == 1 && i > 1)
        {
            for(int j=dprtdata.columnCount;j<(dprtdata.rowCount+1)*dprtdata.columnCount;j+=2)         // ͨ��ѭ����������ƥ���Ӧ��rowid
                if (strcmp(datainfo->tableData[i], dprt[j])==0)
                     datainfo->tableData[i] = dprt[j+1];		// ���ݲ��ŵ������滻
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
// ��ѧ��ͳ��Ա��
bool count_by_edu(sqlite3 *db,DATABASE *datainfo)
{
    char *education[] = {"Сѧ","������ѧ","�߼���ѧ","��ר","ְУ","�м�","ר��","����","˶ʿ�о���","��ʿ�о���"};
    char *column_name[] = {"ѧ��","ͳ�ƽ��"};
    char **data;
    int code;
    code = count_user_by_edu(db,datainfo);         // ���Ա�ͳ��Ա��
    printf("��ѧ��ͳ��Ա��");
    if(code == 2)
    {
        printf("û�����ݣ�");
        return false;
    }
    data = datainfo->tableData;             // ȡ��ͳ������
    for(int i=0;i < datainfo->columnCount;i++)  // �滻����
    {
        data[i] = column_name[i];
    }
    count_bound();
    for(int i=0;i<(datainfo->rowCount+1)*datainfo->columnCount;i++)
    {
        if((i+1)%datainfo->columnCount == 1 && i > 1)
            datainfo->tableData[i] = education[atoi(datainfo->tableData[i])];			// �����Ա�������滻
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
//================================================����Ա��������=========================================================


/*
=====================================================���ž������===========================================================

============================================================================================================================
*/
// ���Ա�ͳ��Ա��
bool count_by_sex(sqlite3 *db,DATABASE *datainfo,USER *p_user)
{
    char *column_name[] = {"�Ա�","ͳ�ƽ��"};
    char *sex[] = {"Ů","��"};
    char **data;
    int code;
    printf("���Ա�ͳ��Ա��");
    code = count_user_by_sex(db,datainfo,p_user->department_id);         // ���Ա�ͳ��Ա��
    if(code == 2)
    {
        printf("û�����ݣ�");
        return false;
    }
    data = datainfo->tableData;             // ȡ��ͳ������
    for(int i=0;i < datainfo->columnCount;i++)  // �滻����
    {
        data[i] = column_name[i];
    }
    count_bound();
    for(int i=0;i<(datainfo->rowCount+1)*datainfo->columnCount;i++)
    {
        if((i+1)%datainfo->columnCount == 1 && i > 1)
            datainfo->tableData[i] = sex[atoi(datainfo->tableData[i])];			// �����Ա�������滻
        printf("%-12s",datainfo->tableData[i]);
        if((i+1)%datainfo->columnCount == 0)
        {
            count_bound();
        }
    }
    system("pause");
	return true;
}
// ������ͳ��Ա��
bool count_by_dprt(sqlite3 *db,DATABASE *datainfo,USER *p_user)
{
    char *column_name[] = {"����","ͳ�ƽ��"};
    char **dprt;            // ���в�������
    char **data;
    int code;
    DATABASE dprtdata;
    select_all_dprt(db,&dprtdata);                   // �������в���
    dprt = dprtdata.tableData;
    code = count_user_by_dprt(db,datainfo,p_user->department_id);         // ������ͳ��Ա��
    data = datainfo->tableData;
    printf("������ͳ��Ա��");
    if(code == 2)
    {
        printf("û�����ݣ�");
        return false;
    }
    data = datainfo->tableData;             // ȡ��ͳ������
    for(int i=0;i < datainfo->columnCount;i++)  // �滻����
    {
        data[i] = column_name[i];
    }
    count_bound();
    for(int i=0;i<(datainfo->rowCount+1)*datainfo->columnCount;i++)
    {
        if((i+1)%datainfo->columnCount == 1 && i > 1)
        {
            for(int j=dprtdata.columnCount;j<(dprtdata.rowCount+1)*dprtdata.columnCount;j+=2)         // ͨ��ѭ����������ƥ���Ӧ��rowid
                if (strcmp(datainfo->tableData[i], dprt[j])==0)
                     datainfo->tableData[i] = dprt[j+1];		// ���ݲ��ŵ������滻
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
// ��ѧ��ͳ��Ա��
bool count_by_edu(sqlite3 *db,DATABASE *datainfo,USER *p_user)
{
    char *education[] = {"Сѧ","������ѧ","�߼���ѧ","��ר","ְУ","�м�","ר��","����","˶ʿ�о���","��ʿ�о���"};
    char *column_name[] = {"ѧ��","ͳ�ƽ��"};
    char **data;
    int code;
    code = count_user_by_edu(db,datainfo,p_user->department_id);         // ���Ա�ͳ��Ա��
    printf("��ѧ��ͳ��Ա��");
    if(code == 2)
    {
        printf("û�����ݣ�");
        return false;
    }
    data = datainfo->tableData;             // ȡ��ͳ������
    for(int i=0;i < datainfo->columnCount;i++)  // �滻����
    {
        data[i] = column_name[i];
    }
    count_bound();
    for(int i=0;i<(datainfo->rowCount+1)*datainfo->columnCount;i++)
    {
        if((i+1)%datainfo->columnCount == 1 && i > 1)
            datainfo->tableData[i] = education[atoi(datainfo->tableData[i])];			// �����Ա�������滻
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
//================================================���ž����������=========================================================


void count_bound()
{
    printf("\n=============================\n");
}
