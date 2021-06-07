#include <stdio.h>
#include <string.h>
#include "mapper_user.h"
#include "service_user.h"
#include "struct.h"
// 用户登录 
bool login(USERS users, USER *p_user)
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

// 员工入职 
bool starr_induction(USERS *p_user,USER *p_user)
{
	char ch;
	int result;
	printf("请输入你的姓名\n");
	scanf("%s",p_user->name);
	printf("请输入你的性别( 0 表示女 1 表示男)\n");
	scanf("%d",p_user->sex); 
	printf("请输入你的学历\n");
	scanf("%s",p_user->education);
	printf("是否要修改密码？(y/n)");
	scanf("%c",&ch);
	if (ch == 'y' || ch == 'Y')
	{
		printf("请输入新密码：");
		scanf("%s",p_user.password);
	}
	result = update_user(&p_users,*user);
	if (result == 1)
	{
		printf("入职成功！");
		return true;
	}else{
		printf("操作失败！请联系管理员");
		return false;
	}
}
