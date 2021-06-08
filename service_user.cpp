#include "service_user.h"

// 用户登录 
bool login(USERS users, USER *p_user)
{
	USER user; // 存放用户实体 
	int index; // 用户索引位置 
	
	printf("\n\t\tusername:");
	scanf("%s", p_user->user_name);
	printf("\n\t\tpassword:");
	scanf("%s", p_user->password);
	index = select_user_by_username(users,p_user->user_name);
	if (index == -1)  
	{
		printf("\t\t用户名或密码输入错误！"); 
		return false; // 该用户不存在 
	}else{
		if (strcmp(users.users[index].password,p_user->password) != 0) // 由用户但是密码输入错误
		{
			printf("\t\t用户名或密码输入错误！"); 
			return false;
		}else{
			*p_user = users.users[index];     // 把用户信息赋值给传进来的用户变量 
						if (p_user->status == 0)
			{
				printf("\t\t已离职！无法登录！");
				return false;
			}
			printf("\t\t登录成功，欢迎[%s]用户\n",p_user->name);
			return true;
		}

	}
}

// 员工入职 
bool staff_induction(USERS *p_users,USER *p_user)
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
		scanf("%s",p_user->password);
	}
	result = update_user(p_users,*p_user);
	if (result == 1)
	{
		printf("入职成功！");
		return true;
	}else{
		printf("操作失败！请联系管理员");
		return false;
	}
}

// 员工离职 
bool staff_dimission(USERS *p_users,USER *p_user)
{
	char ch;
	int result;
	printf("是否确认离职？操作不可逆(y/n)");
	scanf("%c",&ch);
	if (ch == 'y' || ch == 'Y')
	{
		p_user->status = 0;
		printf("已确认离职！");
		return true;
	}
	return false;
}


