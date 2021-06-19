#include "service_user.h"



/*
===========================================================================================================================										
														
													����Ա����
														
===========================================================================================================================
*/
// ���Ա��
bool admin_save_user(USERS *p_users)
{
	system("cls");
	USER user; // ������Ա��������
	printf("\t\t�������û���:");
	scanf("%s",user.username);
	printf("\n\t\t����������:"); 
	scanf("%s",user.name);
	printf("\n\t\t������Ȩ�ޣ�0 һ��Ա�� 1 ���Ź���Ա 2 ϵͳ����Ա��");
	scanf("%d",&user.role_id);
	printf("\n\t\t�����ò���");
	return true; 
}
// ɾ��Ա��
bool admin_delete_user(USERS *p_users)
{
	system("cls");
	printf("\t\tɾ��Ա��\n"); 
	return true; 
}
// �޸�Ա��
bool admin_udpate_user(USERS *p_users)
{
	system("cls");
	printf("\t\t�޸�Ա��\n"); 	
	return true; 
}
// ����Ա��
bool admin_select_user(USERS users)
{
	system("cls");
	printf("\t\t����Ա��\n"); 	
	return true; 
}
// ��Ϣ���� 
bool staff_info(USERS users)
{
	system("cls");
	printf("\t\t��Ϣ����\n"); 
	return true; 	
}
//================================================����Ա��������=========================================================


/*
===========================================================================================================================										
														
													���ž������
														
===========================================================================================================================
*/
//================================================���ž����������=======================================================


/*
===========================================================================================================================										
														
													һ��Ա������
														
===========================================================================================================================
*/
// Ա����ְ 
bool staff_induction(sqlite3 *db,DATABASE *datainfo,USER *p_user)
{
	select_user_by_staffId(db,datainfo,p_user->staff_id);
//	char **data; 
//	char *column_name[] = {"����","�û���"};
//	data = datainfo->tableData;
//	data[0] = column_name[0],data[1] = column_name[1]; 
//	for(int i=0;i <(datainfo->rowCount+1)*datainfo->columnCount;i+=10)
//	{
//		printf("%8s %8s %8s %8s %8s %8s %8s ",data[i],data[i+1],data[i+2],data[i+3],data[i+4],data[i+5],data[i+6],data[i+7]);
//		printf("\n");
//	}
	printUserInfo(datainfo);
	update_user_status(db,datainfo,*p_user);
	system("pause");
	return true;
}
// �޸ĸ�����Ϣ 
bool update_info(sqlite3 *db,DATABASE *datainfo,USER *p_user)
{
	char ch; 
	update_username(db,datainfo,p_user);
	update_name(db,datainfo,p_user);
	update_password(db,datainfo,p_user);
	update_edu(db,datainfo,p_user);
	printf("%d",p_user->education);
	system("pause");
	return true;
}

// Ա����ְ 
//bool staff_dimission(USERS *p_users,USER *p_user)
//{
//	char ch;
//	int result;
//	printf("�Ƿ�ȷ����ְ������������(y/n)");
//	scanf("%c",&ch);
//	if (ch == 'y' || ch == 'Y')
//	{
//		p_user->status = 0;
//		printf("��ȷ����ְ��");
//		return true;
//	}
//	return false;
//}
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
	printf("�������û��������룺\n"); 
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
//	p_user->password[i] = '\0';    // �ַ�����\0��β 
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

						system("pause");
						
//						if (data[19] == "1")											// ��19������Ϊ��ְ��״̬ 
//						{			
							printf("\n\t\t��½�ɹ�����ӭ[%s]�û�\n",p_user->name);			// ��11������Ϊ�û����� 
							return true;
//						}else{
//							printf("\n\t\t�Ѿ���ְ���޷���¼��");
//							return false;
//						}
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
void printUserInfo(DATABASE *datainfo)
{
	if(datainfo->rowCount > 0) 
	{ 
		char **data; 
//		char *column_name[] = {"�û���","����","����","Ȩ��","�Ա�","����","ѧ��","Ա����","�绰","��ְ״̬"};
//		char *role[] = {"��ͨ�û�","���ž���","����Ա"};
//		char *sex[] = {"Ů","��"}; 
//		char *dprt[] = {"������","������","��Ʒ��"};
//		char *education[] = {"Сѧ","������ѧ","�߼���ѧ","��ר","ְУ","�м�","ר��","����","˶ʿ�о���","��ʿ�о���"};
//		char *status[] = {"��ְ","��ְ"}; 
		data = datainfo->tableData;
		for(int i=0;i < 10;i++)
		{
			data[i] = column_name[i];
		} 
		printf("\n===============================================================================================================================\n");
	    for(int i=0;i<(datainfo->rowCount+1)*datainfo->columnCount;i++)
	    {
	    	if((i+1)%datainfo->columnCount == 4 && i > 9)
				datainfo->tableData[i] = "******";		// ����Ȩ�޵������滻 
	    	if((i+1)%datainfo->columnCount == 4 && i > 9)
				datainfo->tableData[i] = role[atoi(datainfo->tableData[i])];		// ����Ȩ�޵������滻 
			if((i+1)%datainfo->columnCount == 5 && i > 9)
	    		datainfo->tableData[i] = sex[atoi(datainfo->tableData[i])];			// �����Ա�������滻 
			if((i+1)%datainfo->columnCount == 6 && i > 9)
	    		datainfo->tableData[i] = dprt[atoi(datainfo->tableData[i])];		// ���ݲ��ŵ������滻 
	    	if((i+1)%datainfo->columnCount == 7 && i > 9)	
	    		datainfo->tableData[i] = education[atoi(datainfo->tableData[i])];	// ����ѧ���������滻 
			if((i+1)%datainfo->columnCount == 0 && i > 9)
				datainfo->tableData[i] = status[atoi(datainfo->tableData[i])];		// ������ְ״̬�������滻 
			printf("%-12s",datainfo->tableData[i]);							
	        if((i+1)%datainfo->columnCount == 0)
	        {
	            printf("\n===============================================================================================================================\n");
	        }
		} 
	} 
}


// �Ե�ǰ�û�����Ϣ���и�ֵ 
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
		printf("\n\t\t�������û�����");
		fflush(stdin);
		scanf("%s",p_user->username); 
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
		printf("\n\t\t������������");
		fflush(stdin);
		scanf("%s",p_user->name); 
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
		while(flag)
		{
			printf("\n\t\t������ԭ���룺");
			fflush(stdin);
			scanf("%s",password); 
			code = select_user_by_password(db,datainfo,p_user->username,password);
			p_user->password = password; 
			if (code == 2)
			{
				printf("�����������"); 
			}else{
				flag = false;
			}

		}
		printf("\n\t\t�����������룺");
		fflush(stdin);
		scanf("%s",password); 
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

// �޸�ѧ�� 
bool update_edu(sqlite3 *db,DATABASE *datainfo,USER *p_user) 
{	
	int code;
	if (alert("ѧ�� "))
	{
		printf("\n\t\t������ѧ����");
		fflush(stdin);
		scanf("%d",&p_user->education); 
		update_user_edu(db,datainfo,*p_user); 
		return true;
	}
	return false;
}

// �޸�ѧ�� 
bool update_mobile(sqlite3 *db,DATABASE *datainfo,USER *p_user) 
{	
	int code;
	if (alert("�绰 "))
	{
		printf("\n\t\t������绰��");
		fflush(stdin);
		scanf("%s",&p_user->mobile); 
		update_user_edu(db,datainfo,*p_user); 
		printf("%s",p_user->mobile);
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



