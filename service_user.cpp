#include "service_user.h"

// 用户登录 
bool login(USERS users, USER *p_user)
{
	USER user; 				// 存放用户实体 
	int index,i; 			// 用户索引位置 
	i=0;				    // 接受密码输入的索引位置 
	char ch;				//接收字符输入 
	printf("\n\t\tusername:");
	scanf("%s", p_user->user_name);
	printf("\n\t\tpassword:");
	while((ch=getch())!='\r')
	{
		if(ch=='\b' && i > 0)
		{
			printf("\b \b");
			--i;
		}else if(ch!='\b'){
			p_user->password[i++]=ch;
			printf("*");
		}
	}
	p_user->password[i] = '\0';    // 字符串以\0结尾 
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

//================================================管理员操作=========================================================
// 添加员工
bool admin_save_user(USERS *p_users)
{
	system("cls");
	USER user; // 存放添加员工的数据
	printf("\t\t请设置用户名:");
	scanf("%s",user.user_name);
	printf("\n\t\t请输入姓名:"); 
	scanf("%s",user.name);
	printf("\n\t\t请设置权限（0 一般员工 1 部门管理员 2 系统管理员）");
	scanf("%d",&user.role_id);
	printf("\n\t\t请设置部门");
	return true; 
}
// 删除员工
bool admin_delete_user(USERS *p_users)
{
	system("cls");
	printf("\t\t删除员工\n"); 
	return true; 
}
// 修改员工
bool admin_udpate_user(USERS *p_users)
{
	system("cls");
	printf("\t\t修改员工\n"); 	
	return true; 
}
// 查找员工
bool admin_select_user(USERS users)
{
	system("cls");
	printf("\t\t查找员工\n"); 	
	return true; 
}
// 信息总览 
bool staff_info(USERS users)
{
	system("cls");
	printf("\t\t信息总览\n"); 
	return true; 	
}
//================================================管理员操作结束=========================================================

//================================================部门经理操作=========================================================
//================================================部门经理操作结束=========================================================


//================================================一般员工操作=========================================================
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
//================================================一般员工操作结束=========================================================





