#include "service_user.h"

// �û���¼ 
bool login(USERS users, USER *p_user)
{
	USER user; // ����û�ʵ�� 
	int index; // �û�����λ�� 
	
	printf("\n\t\tusername:");
	scanf("%s", p_user->user_name);
	printf("\n\t\tpassword:");
	scanf("%s", p_user->password);
	index = select_user_by_username(users,p_user->user_name);
	if (index == -1)  
	{
		printf("\t\t�û����������������"); 
		return false; // ���û������� 
	}else{
		if (strcmp(users.users[index].password,p_user->password) != 0) // ���û����������������
		{
			printf("\t\t�û����������������"); 
			return false;
		}else{
			*p_user = users.users[index];     // ���û���Ϣ��ֵ�����������û����� 
						if (p_user->status == 0)
			{
				printf("\t\t����ְ���޷���¼��");
				return false;
			}
			printf("\t\t��¼�ɹ�����ӭ[%s]�û�\n",p_user->name);
			return true;
		}

	}
}

// Ա����ְ 
bool staff_induction(USERS *p_users,USER *p_user)
{
	char ch;
	int result;
	printf("�������������\n");
	scanf("%s",p_user->name);
	printf("����������Ա�( 0 ��ʾŮ 1 ��ʾ��)\n");
	scanf("%d",p_user->sex); 
	printf("���������ѧ��\n");
	scanf("%s",p_user->education);
	printf("�Ƿ�Ҫ�޸����룿(y/n)");
	scanf("%c",&ch);
	if (ch == 'y' || ch == 'Y')
	{
		printf("�����������룺");
		scanf("%s",p_user->password);
	}
	result = update_user(p_users,*p_user);
	if (result == 1)
	{
		printf("��ְ�ɹ���");
		return true;
	}else{
		printf("����ʧ�ܣ�����ϵ����Ա");
		return false;
	}
}

// Ա����ְ 
bool staff_dimission(USERS *p_users,USER *p_user)
{
	char ch;
	int result;
	printf("�Ƿ�ȷ����ְ������������(y/n)");
	scanf("%c",&ch);
	if (ch == 'y' || ch == 'Y')
	{
		p_user->status = 0;
		printf("��ȷ����ְ��");
		return true;
	}
	return false;
}


