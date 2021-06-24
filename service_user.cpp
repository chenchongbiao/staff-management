#include "service_user.h"
char *column_name[] = {"�û���","����","����","Ȩ��","�Ա�","����","ѧ��","Ա����","�绰","��ְ״̬"};
char *role[] = {"��ͨ�û�","���ž���","����Ա"};
char *sex[] = {"Ů","��"};
char *education[] = {"Сѧ","������ѧ","�߼���ѧ","��ר","ְУ","�м�","ר��","����","˶ʿ�о���","��ʿ�о���"};
char *status[] = {"��ְ","��ְ"};

/*
===========================================================================================================================

													����Ա����

===========================================================================================================================
*/
// ���Ա��
bool save_staff(sqlite3 *db,DATABASE *datainfo,USER *p_user)
{
	USER *user;
    user = (struct USER*)malloc(sizeof(struct USER));
    char **dprt;
	int code;
    malloc_user(user);                   // ���ṹ��ָ�뿪���ڴ�
    select_all_dprt(db,datainfo);        // �������в���
    dprt = datainfo->tableData;
	input_str("�û���",user->username);
    input_str("����",user->password);
    input_str("����",user->name);
	if (p_user->role_id == 2)	     	// �жϵ�ǰ�û�Ϊ����Ա������ѡ����ӹܲ��Ź���Ա�ͳ�������Ա
	{
		for(int i = 0;i < 3;i++)
			printf("\t\t%d--%s\n",i,role[i]);
		input_int("�û���Ȩ��",user->role_id);
	}else if(p_user->role_id == 1){     // �ж��û�Ϊ���Ź���Ա����Ӳ��ų�Ա
		user->role_id = 0;
	}
	for(int i = 0;i < 2;i++)
		printf("\t\t%d--%s\n",i,sex[i]);
	input_int("�Ա�",user->sex);
	if (p_user->role_id == 2)           // �жϵ�ǰ�û�Ϊ����Ա������ѡ��������еĲ��ų�Ա
	{
        for(int i = datainfo->columnCount;i < (datainfo->rowCount+1)*datainfo->columnCount;i+=2) // �����ݿ�����ȡ���ݻ�ò����б�
        {
            printf("\t\t%d--%s\n",i/2,dprt[i+1]);
        }

		input_int("����",user->department_id);
		user->department_id = atoi(dprt[user->department_id*2]);
	}else{
		user->department_id = p_user->department_id;
	}
    for(int i = 0;i < 10;i++)
        printf("\t\t%d--%s\n",i,education[i]);
	input_int("ѧ��",user->education);
	input_str("Ա����",user->staff_id);
	while(select_user_by_staffId(db,datainfo,user->staff_id) != 2)
	{
		printf("\t\tԱ�����Ѿ���������������\n");
		input_str("Ա����",user->staff_id);
	}
	input_str("�绰",user->mobile);
	user->status = 0;
    save_user(db,datainfo,*user);
    free_user(user);
    system("pause");
	return true;

}

// ɾ��Ա��
bool delete_staff(sqlite3 *db,DATABASE *datainfo,USER *p_user)
{
    int code;                                                // ����ֵ
    USER *user = (struct USER*)malloc(sizeof(struct USER));// ���Ա����Ϣ�Ľṹ��
    char **data = (char **)malloc(20);                      // Ա����Ϣ�Ķ�λ����
    malloc_user(user);                                       // ���ṹ��ָ�뿪���ڴ�
    input_str("Ա����",user->staff_id);
    code = select_user_by_staffId(db,datainfo,user->staff_id);// ͨ��Ա���Ų���
    if (code == 2)
    {
        printf("\t\t��Ա�������ڣ�");
        return false;
    }
    data = datainfo->tableData;
    curr_user_info(data,user);
    if(p_user->role_id == 1 && user->department_id == p_user->department_id) // �ж�ɾ�����û��벿�Ź���Ա����ͬһ������
    {
        code = delete_user_by_staffId(db,datainfo,user->staff_id);                   // ����Ա����ɾ��
        if(code == 0)
        {
            printf("\t\tɾ��ʧ�ܣ�\n");
            return false;
        }else{
            printf("\t\tɾ���ɹ���\n");
            return true;
        }

    }else if(p_user->role_id == 1 && user->department_id != p_user->department_id){

        printf("\t\t��û��ɾ����Ա����Ȩ�ޣ�");
        return false;
    }
    // ����Ա��ֱ�ӽ���ɾ������
    code = delete_user_by_staffId(db,datainfo,user->staff_id);                      // ����Ա����ɾ��
    if(code == 0)
    {
        printf("\t\tɾ��ʧ�ܣ�\n");
        return false;
    }else{
        printf("\t\tɾ���ɹ���\n");
        return true;
    }
}

// �޸�Ա����Ϣ
bool update_staff(sqlite3 *db,DATABASE *datainfo,USER *p_user)
{
    int code;                                                // ����ֵ
    USER *user = (struct USER*)malloc(sizeof(struct USER));// ���Ա����Ϣ�Ľṹ��
    char **data = (char **)malloc(20);                      // Ա����Ϣ�Ķ�λ����
    malloc_user(user);                                       // ���ṹ��ָ�뿪���ڴ�
    input_str("Ա����",user->staff_id);
    code = select_user_by_staffId(db,datainfo,user->staff_id);// ͨ��Ա���Ų���
    if (code == 2)
    {
        printf("\t\t��Ա�������ڣ�");
        return false;
    }
    data = datainfo->tableData;
    curr_user_info(data,user);                                  // �ѻ�ȡ����Ϣ��ֵ��user
	update_username(db,datainfo,user);
	update_name(db,datainfo,user);
	update_password(db,datainfo,user);
	if(p_user->role_id == 2)
    {
        update_role(db,datainfo,user);
    }
    update_sex(db,datainfo,user);
    update_staffId(db,datainfo,user);
	update_edu(db,datainfo,user);
	update_mobile(db,datainfo,user);
	update_status(db,datainfo,user);
}

// ����Ա����Ϣ
bool select_staff(sqlite3 *db,DATABASE *datainfo,USER *p_user)
{
    int code;                                                // ����ֵ
    USER *user = (struct USER*)malloc(sizeof(struct USER));// ���Ա����Ϣ�Ľṹ��
    char **data = (char **)malloc(20);
    malloc_user(user);                                       // ���ṹ��ָ�뿪���ڴ�
    input_str("Ա����",user->staff_id);
    code = select_user_by_staffId(db,datainfo,user->staff_id);// ͨ��Ա���Ų���
    if (code == 2)
    {
        printf("\t\t��Ա�������ڣ�");
        system("pause");
        return false;
    }
    data = datainfo->tableData;
    curr_user_info(data,user);                                  // �ѻ�ȡ����Ϣ��ֵ��user
    if(p_user->role_id == 1 && user->department_id != p_user->department_id)
    {
        printf("\t\t��û��Ȩ�޲鿴��Ա����Ϣ��");
        system("pause");
        return false;
    }
	print_user_Info(db,datainfo);
	system("pause");
	return true;
}

// ����Ա��������Ա����Ϣ
bool select_all_staff(sqlite3 *db,DATABASE *datainfo)
{
    int code;                                                // ����ֵ
    char **data = (char **)malloc(20);
    code = select_all_user(db,datainfo);// ͨ��Ա���Ų���
    if (code == 2)
    {
        printf("\t\t���ݿ���û����Ϣ��");
        system("pause");
        return false;
    }
    data = datainfo->tableData;
	print_user_Info(db,datainfo);
	system("pause");
	return true;
}
// ɾ�����ݿ�
bool delete_database(sqlite3 *db,DATABASE *datainfo)
{
    int code;                                                // ����ֵ
    char ch;
    printf("\t\t�Ƿ�ɾ�����ݿ⣿�ò��������棡��Y/N��");
    fflush(stdin);
    scanf("%c",&ch);
    if(ch == 'Y' || ch == 'y')
    {
        code = del_data(db,datainfo);
        if(code == 0)
            printf("\t\t���ݿ�ɾ��ʧ�ܣ�");
        else
            printf("\t\t���ݿ�ɾ���ɹ���");
    }
	system("pause");
	return true;
}

//================================================����Ա��������=========================================================


/*
===========================================================================================================================

													���ž������

===========================================================================================================================
*/
// ���ž����������Ա����Ϣ
bool select_all_staff(sqlite3 *db,DATABASE *datainfo,USER *p_user)
{
    int code;                                                // ����ֵ
    char **data = (char **)malloc(20);
    code = select_all_user(db,datainfo,p_user->department_id);// ͨ��Ա���Ų���
    if (code == 2)
    {
        printf("\t\t���ݿ���û����Ϣ��");
        system("pause");
        return false;
    }
    data = datainfo->tableData;
	print_user_Info(db,datainfo);
	system("pause");
	return true;
}
//================================================���ž����������=======================================================


/*
===========================================================================================================================

													һ��Ա������

===========================================================================================================================
*/
// Ա����ְ
bool staff_induction(sqlite3 *db,DATABASE *datainfo,USER *p_user)
{
    char ch;
	select_user_by_staffId(db,datainfo,p_user->staff_id);
	if (p_user->status == -1)
	{
		printf("\t\t�Ѿ���ְ�޷�������");
		return false;
	}
	p_user->status = 1;
	update_user_status(db,datainfo,*p_user);
	select_user_by_staffId(db,datainfo,p_user->staff_id);
	print_user_Info(db,datainfo);
	printf("\t\t��ȷ����Ϣ����Ҫ�����޸�������Y");
	scanf("%c",&ch);
	if (ch == 'Y' || ch == 'y')
        update_info(db,datainfo,p_user);
	getchar();
	return true;
}

// Ա����ְ
bool staff_dimission(sqlite3 *db,DATABASE *datainfo,USER *p_user)
{
	char ch;
	printf("\t\t�Ƿ�ȷ����ְ������������(y/n)");
	fflush(stdin);
	scanf("%c",&ch);
	if (ch == 'y' || ch == 'Y')
	{
		p_user->status = 0;
		update_user_status(db,datainfo,*p_user);
		printf("\t\t��ȷ����ְ��");
		return true;
	}
	return false;
}

// �޸ĸ�����Ϣ
bool update_info(sqlite3 *db,DATABASE *datainfo,USER *p_user)
{
	char ch;
	if (p_user->status == -1)
	{
		printf("�Ѿ���ְ�޷�������");
		getchar();
		return false;
	}
	update_username(db,datainfo,p_user);
	update_name(db,datainfo,p_user);
	update_password(db,datainfo,p_user);
	update_sex(db,datainfo,p_user);
	update_edu(db,datainfo,p_user);
	update_mobile(db,datainfo,p_user);
	system("pause");
	return true;
}


//================================================һ��Ա����������=========================================================

/*
===========================================================================================================================

														��������

===========================================================================================================================
*/

// �û���¼
bool login(sqlite3 *db,DATABASE *datainfo,USER *p_user)
{
	USER *user;
	int res,i; 				// �û�����λ��
	char ch;				// �����ַ�����
	char **data;			// ���ջش�����
	char username[30];
	char password[30];
	printf("\t\t�������û��������룺\n");
	printf("\n\t\tusername:");
	scanf("%s", username);
	printf("\n\t\tpassword:");
	while((ch=getch())!='\r')		// 	��������
	{
		if(ch=='\b' && i > 0)
		{
			printf("\b \b");
			--i;
		}else if(ch!='\b'){
			password[i++]=ch;
			printf("*");
		}
	}
	password[i] = '\0';
	res = select_user_by_username(db,datainfo,username);
	switch(res)
	{
		case 1:
			if(datainfo->rowCount > 0)
			{
				res = select_user_by_password(db,datainfo,username,password);   			// ���ز������2Ϊ�Ҳ�������
				switch(res)
				{
					case 1:
						data = datainfo->tableData;
//						if(datainfo->rowCount > 0)
//						{
//					  		printf("���ݱ�ļ�¼:\n");
//						    for(int i=0;i<(datainfo->rowCount+1)*datainfo->columnCount;i++)
//						    {
//								printf("%-7s   ",datainfo->tableData[i]);
//
//						        if((i+1)%datainfo->columnCount == 0)
//						        {
//						            printf("\n");
//						        }
//							}
//						}

						p_user->name = data[11];
                        printf("\n\t\t��½�ɹ�����ӭ[%s]�û�\n",p_user->name);			// ��11������Ϊ�û�����
                        return true;

					case 2:
						printf("\t\t�û������������������");
						return false;
				}
			}
			return true;
		case 2:
			printf("\n\t\t�û����������������");
			return false; // ���û�������
	}
}

// ��ӡ�û�����
void print_user_Info(sqlite3 *db,DATABASE *datainfo)
{
	if(datainfo->rowCount > 0)
	{
//		char *column_name[] = {"�û���","����","����","Ȩ��","�Ա�","����","ѧ��","Ա����","�绰","��ְ״̬"};
//		char *role[] = {"��ͨ�û�","���ž���","����Ա"};
//		char *sex[] = {"Ů","��"};
//		char *dprt[] = {"������","������","��Ʒ��"};
//		char *education[] = {"Сѧ","������ѧ","�߼���ѧ","��ר","ְУ","�м�","ר��","����","˶ʿ�о���","��ʿ�о���"};
//		char *status[] = {"��ְ","��ְ"};
		char **data;            // �����û�����
		char **dprt;            // ���в�������
		DATABASE dprtdata;
		data = datainfo->tableData;
		select_all_dprt(db,&dprtdata);        // �������в���
		dprt = dprtdata.tableData;

		for(int i=0;i < datainfo->columnCount;i++)
		{
			data[i] = column_name[i];
		}
		bound();
	    for(int i=0;i<(datainfo->rowCount+1)*datainfo->columnCount;i++)
	    {
	    	if((i+1)%datainfo->columnCount == 3 && i > 9)
				datainfo->tableData[i] = "******";		// ����Ȩ�޵������滻
	    	if((i+1)%datainfo->columnCount == 4 && i > 9)
				datainfo->tableData[i] = role[atoi(datainfo->tableData[i])];		// ����Ȩ�޵������滻
			if((i+1)%datainfo->columnCount == 5 && i > 9)
	    		datainfo->tableData[i] = sex[atoi(datainfo->tableData[i])];			// �����Ա�������滻
			if((i+1)%datainfo->columnCount == 6 && i > 9)
            {
                for(int j=dprtdata.columnCount;j<(dprtdata.rowCount+1)*dprtdata.columnCount;j+=2)         // ͨ��ѭ����������ƥ���Ӧ��rowid
                    if (strcmp(datainfo->tableData[i], dprt[j])==0)
                         datainfo->tableData[i] = dprt[j+1];		// ���ݲ��ŵ������滻

            }
	    	if((i+1)%datainfo->columnCount == 7 && i > 9)
	    		datainfo->tableData[i] = education[atoi(datainfo->tableData[i])];	// ����ѧ���������滻
			if((i+1)%datainfo->columnCount == 0 && i > 9)
				datainfo->tableData[i] = status[atoi(datainfo->tableData[i])];		// ������ְ״̬�������滻
			printf("%-12s",datainfo->tableData[i]);
	        if((i+1)%datainfo->columnCount == 0)
	        {
	            bound();
	        }
		}
	}
}


// ���û�����Ϣ���и�ֵ
void curr_user_info(char **data,USER *p_user)
{
	p_user->username = data[10];
	p_user->name = data[11];
	p_user->role_id = atoi(data[13]);
	p_user->sex = atoi(data[14]);
	p_user->department_id = atoi(data[15]);
	p_user->education = atoi(data[16]);
	p_user->staff_id = data[17];
	p_user->mobile = data[18];
	p_user->status = atoi(data[19]);
}


// �޸��û���
bool update_username(sqlite3 *db,DATABASE *datainfo,USER *p_user)
{
	int code;
	if (alert("�û���"))
	{
		input_str("�û���",p_user->username);
		code = select_user_by_username(db,datainfo,p_user->username);
		if (code = 2) // ���ݿ���û����ͬ�û���
		{
			update_user_username(db,datainfo,*p_user);
			return true;
		}
	}
	return false;
}

// �޸�����
bool update_name(sqlite3 *db,DATABASE *datainfo,USER *p_user)
{
	int code;
	if (alert("����"))
	{
		input_str("����",p_user->name);
		update_user_name(db,datainfo,*p_user);
		return true;
	}
	return false;
}

// �޸�����
bool update_password(sqlite3 *db,DATABASE *datainfo,USER *p_user)
{
	int code,flag=true;
	char *password;
	if (alert("����"))
	{
		input_str("������",p_user->password);
		code = update_user_password(db,datainfo,*p_user);
		if (code)
		{
			printf("\n\t\t�����޸ĳɹ���");
		}
		p_user->password = password;
		return true;
	}
	return false;
}

// �޸�Ȩ��
bool update_role(sqlite3 *db,DATABASE *datainfo,USER *p_user)
{
    int code;
	if (alert("Ȩ��"))
	{
        for(int i = 0;i < 3;i++)
			printf("\t\t%d--%s\n",i,role[i]);
 		printf("\n\t\t������Ҫ�޸�Ȩ�ޣ�");
		fflush(stdin);
		scanf("%d",&p_user->role_id);
		update_user_role(db,datainfo,*p_user);
		return true;
	}
	return false;
}
// �޸��Ա�
bool update_sex(sqlite3 *db,DATABASE *datainfo,USER *p_user)
{
    int code;
	if (alert("�Ա�"))
	{
		fflush(stdin);
		if (p_user->role_id == 1) p_user->role_id = 0;
		else p_user->role_id = 1;
		update_user_sex(db,datainfo,*p_user);
		return true;
	}
	return false;
}

// ���벿��
bool update_dprt(sqlite3 *db,DATABASE *datainfo,USER *p_user)
{
	int code;
    char **dprt;
    select_all_dprt(db,datainfo);        // �������в���
    dprt = datainfo->tableData;
	if (alert("���� "))
	{
        for(int i = datainfo->columnCount;i < (datainfo->rowCount+1)*datainfo->columnCount;i+=2) // �����ݿ�����ȡ���ݻ�ò����б�
        {
            printf("\t\t%d--%s\n",i/2,dprt[i+1]);
        }
		input_int("����",p_user->department_id);
		update_user_dprt(db,datainfo,*p_user);
		return true;
	}
	return false;
}

// �޸�ѧ��
bool update_edu(sqlite3 *db,DATABASE *datainfo,USER *p_user)
{
	int code;
	if (alert("ѧ�� "))
	{
        for(int i = 0;i < 10;i++)
            printf("\t\t%d--%s\n",i,education[i]);
		input_int("ѧ��",p_user->education);
		update_user_edu(db,datainfo,*p_user);
		return true;
	}
	return false;
}

// �޸�Ա����
bool update_staffId(sqlite3 *db,DATABASE *datainfo,USER *p_user)
{
	int code;
	char *new_staffId=(char *)malloc(20);
	if (alert("Ա����"))
	{
        input_str("Ա����",new_staffId);
        while(select_user_by_staffId(db,datainfo,new_staffId) != 2)
        {
            printf("\t\tԱ�����Ѿ���������������\n");
            input_str("Ա����",new_staffId);
        }
		update_user_staffId(db,datainfo,*p_user,new_staffId);
		strcpy(p_user->staff_id,new_staffId);
		free(new_staffId);
		return true;
	}
	free(new_staffId);
	return false;
}

// �޸ĵ绰
bool update_mobile(sqlite3 *db,DATABASE *datainfo,USER *p_user)
{
	int code;
	if (alert("�绰 "))
	{
		input_str("�绰",p_user->mobile);
		update_user_mobile(db,datainfo,*p_user);
		return true;
	}
	return false;
}

// �޸���ְ״̬
bool update_status(sqlite3 *db,DATABASE *datainfo,USER *p_user)
{
    int code;
    char ch;
	if (alert("��ְ״̬"))
	{
		if (p_user->status == 1)
        {
            printf("\t\t�Ƿ�����Ա����(Y/N)");
            fflush(stdin);
            scanf("%c",&ch);
            if (ch == 'y' || ch == 'Y')
            {
                p_user->status = -1;
            }
        }else{
            printf("\t\t�Ƿ�����Ա����ְ��(Y/N)");
            fflush(stdin);
            scanf("%c",&ch);
            if (ch == 'y' || ch == 'Y')
            {
                p_user->status = 1;
            }
        }
		update_user_status(db,datainfo,*p_user);
		return true;
	}
	return false;
}
// ѯ���Ƿ��޸���Ϣ���ַ�������
int alert(char *info)
{
	char ch;
	printf("\n\t\t�Ƿ��޸�%s?(Y/N)",info);
	fflush(stdin);
	scanf("%c",&ch);
	if (ch == 'y' || ch == 'Y')
	{
		return 1;
	}
	return 0;
}

//// �������ͱ���
//int input_int(char *info,int &data)
//{
//	printf("\t\t������%s��",info);
//	fflush(stdin);
//	scanf("%d",&data);
//	return 1;
//}
//
//// �����ַ��ͱ���
//int input_str(char *info,char *data)
//{
//	printf("\t\t������%s��",info);
//	fflush(stdin);
//	scanf("%s",data);
//	return 1;
//}

// ���ṹ����ַ�ָ�뿪���ڴ�
void malloc_user(USER *user)
{

    user->username = (char *)malloc(30);
 	user->password = (char *)malloc(30);
    user->name = (char *)malloc(30);
    user->staff_id = (char *)malloc(30);
    user->mobile = (char *)malloc(30);
}

// �ͷŽṹ����ַ�ָ��
void free_user(USER *user)
{
    free(user->username);
    free(user->password);
    free(user->name);
    free(user->staff_id);
    free(user->mobile);
    free(user);
}

void bound()
{
    printf("\n===============================================================================================================================\n");
}

