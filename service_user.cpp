#include <stdio.h>
#include <string.h>
#include "mapper_user.h"
#include "service_user.h"
#include "struct.h"
bool login(USERS users, USER *p_user) // �û���¼ 
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
