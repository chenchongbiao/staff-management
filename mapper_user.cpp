#include <string.h>
#include "mapper_user.h"

// ����û� 
// ɾ���û� 
// �޸��û� 
//////////////////////////////////�����û�/////////////////////////////////////////////// 

// ͨ���û������� 
int select_user_by_username(USERS users,char *p_username)
{
	int i;
	for (int = 0; i < users.length; i++)
	{
		if (strcmp(users.users[i].user_name ,p_username) == 0)	// �û���һ��
		{
			return i;		// ��������λ�� 
		} 
	} 
	return -1;
}
