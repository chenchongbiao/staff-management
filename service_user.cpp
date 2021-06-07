#include <stdio.h>
#include <string.h>
#include "mapper_user.h"
#include "service_user.h"
#include "struct.h"
bool login(USERS users, USER *p_user) // 用户登录 
{
	USER user; // 存放用户实体 
	int index; // 用户索引位置 
	printf("username:");
	scanf("%s", p_user->user_name);
	printf("password: ");
	scanf("%s", p_user->password);
	index = select_user(users,p_user->user_name);
	if (index == -1)  
	{
		printf("用户名或密码输入错误！"); 
		return false; // 该用户不存在 
	}else{
		if (strcmp(users.users[index].password,p_user->password) != 0) // 由用户但是密码输入错误
		{
			printf("用户名或密码输入错误！"); 
			return false;
		}else{
			*p_user = users.users[index];     // 把用户信息赋值给传进来的用户变量 
			printf("登录成功，欢迎[%s]用户\n",p_user->name);
			return true;
		}

	}
}
