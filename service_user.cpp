#include <stdio.h>
#include <string.h>
#include "mapper_user.h"
#include "service_user.h"
#include "struct.h"
// �û���¼ 
bool login(USERS users, USER *p_user)
{
	USER user; // ����û�ʵ�� 
	int index; // �û�����λ�� 
	printf("username:");
	scanf("%s", p_user->user_name);
	printf("password: ");
	scanf("%s", p_user->password);
	index = select_user(users,p_user->user_name);
	if (index == -1)  
	{
		printf("�û����������������"); 
		return false; // ���û������� 
	}else{
		if (strcmp(users.users[index].password,p_user->password) != 0) // ���û����������������
		{
			printf("�û����������������"); 
			return false;
		}else{
			*p_user = users.users[index];     // ���û���Ϣ��ֵ�����������û����� 
			printf("��¼�ɹ�����ӭ[%s]�û�\n",p_user->name);
			return true;
		}

	}
}

// Ա����ְ 
bool starr_induction(USERS *p_user,USER *p_user)
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
		scanf("%s",p_user.password);
	}
	result = update_user(&p_users,*user);
	if (result == 1)
	{
		printf("��ְ�ɹ���");
		return true;
	}else{
		printf("����ʧ�ܣ�����ϵ����Ա");
		return false;
	}
}
