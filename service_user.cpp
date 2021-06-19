#include "service_user.h"



/*
===========================================================================================================================										
														
													管理员操作
														
===========================================================================================================================
*/
// 添加员工
bool admin_save_user(USERS *p_users)
{
	system("cls");
	USER user; // 存放添加员工的数据
	printf("\t\t请设置用户名:");
	scanf("%s",user.username);
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


/*
===========================================================================================================================										
														
													部门经理操作
														
===========================================================================================================================
*/
//================================================部门经理操作结束=======================================================


/*
===========================================================================================================================										
														
													一般员工操作
														
===========================================================================================================================
*/
// 员工入职 
bool staff_induction(sqlite3 *db,DATABASE *datainfo,USER *p_user)
{
	select_user_by_staffId(db,datainfo,p_user->staff_id);
//	char **data; 
//	char *column_name[] = {"姓名","用户名"};
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
// 修改个人信息 
bool update_info(sqlite3 *db,DATABASE *datainfo,USER *p_user)
{
	char ch; 
	update_username(db,datainfo,p_user);
	update_name(db,datainfo,p_user);
	update_password(db,datainfo,p_user);
	printf("%s",p_user->password);
	system("pause");
	return true;
}

// 员工离职 
//bool staff_dimission(USERS *p_users,USER *p_user)
//{
//	char ch;
//	int result;
//	printf("是否确认离职？操作不可逆(y/n)");
//	scanf("%c",&ch);
//	if (ch == 'y' || ch == 'Y')
//	{
//		p_user->status = 0;
//		printf("已确认离职！");
//		return true;
//	}
//	return false;
//}
//================================================一般员工操作结束=========================================================

/*
===========================================================================================================================										
														
														公共函数 
														
===========================================================================================================================
*/

// 用户登录 
bool login(sqlite3 *db,DATABASE *datainfo,USER *p_user)
{
	USER *user;
	int res,i; 				// 用户索引位置 
	char ch;				// 接收字符输入 
	char **data;			// 接收回传数据 
	char username[30];
	char password[30];
	printf("请输入用户名和密码：\n"); 
	printf("\n\t\tusername:");
	scanf("%s", username); 
	printf("\n\t\tpassword:");
	while((ch=getch())!='\r')		// 	接收密码 
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
//	p_user->password[i] = '\0';    // 字符串以\0结尾 
	password[i] = '\0';
	res = select_user_by_username(db,datainfo,username);
	switch(res)
	{
		case 1:
			if(datainfo->rowCount > 0) 
			{
				res = select_user_by_password(db,datainfo,username,password);   			// 返回操作结果2为找不到密码
				switch(res)
				{
					case 1:
						data = datainfo->tableData;
//						if(datainfo->rowCount > 0) 
//						{
//					  		printf("数据表的记录:\n");
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
						
//						if (data[19] == "1")											// 第19个数据为在职在状态 
//						{			
							printf("\n\t\t登陆成功！欢迎[%s]用户\n",p_user->name);			// 第11个数据为用户姓名 
							return true;
//						}else{
//							printf("\n\t\t已经离职！无法登录！");
//							return false;
//						}
					case 2:
						printf("\t\t用户名或者密码输入错误！"); 
						return false;
				} 
			}
			return true;
		case 2:
			printf("\n\t\t用户名或密码输入错误！"); 
			return false; // 该用户不存在 
	}
}

// 打印用户数据 
void printUserInfo(DATABASE *datainfo)
{
	if(datainfo->rowCount > 0) 
	{ 
		char **data; 
		char *column_name[] = {"用户名","姓名","密码","权限","性别","部门","学历","员工号","电话","在职状态"};
		char *role[] = {"普通用户","部门经理","管理员"};
		char *sex[] = {"女","男"}; 
		char *dprt[] = {"技术部","开发部","产品部"};
		char *education[] = {"小学","初级中学","高级中学","中专","职校","中技","专科","本科","硕士研究生","博士研究生"};
		char *status[] = {"离职","在职"}; 
		data = datainfo->tableData;
		for(int i=0;i < 10;i++)
		{
			data[i] = column_name[i];
		} 
		printf("=============================================================================================================");
	    for(int i=0;i<(datainfo->rowCount+1)*datainfo->columnCount;i++)
	    {
	    	if((i+1)%datainfo->columnCount == 4 && i > 9)
				datainfo->tableData[i] = role[atoi(datainfo->tableData[i])];		// 根据权限的数字替换 
			if((i+1)%datainfo->columnCount == 5 && i > 9)
	    		datainfo->tableData[i] = sex[atoi(datainfo->tableData[i])];			// 根据性别的数字替换 
			if((i+1)%datainfo->columnCount == 6 && i > 9)
	    		datainfo->tableData[i] = dprt[atoi(datainfo->tableData[i])];		// 根据部门的数字替换 
	    	if((i+1)%datainfo->columnCount == 7 && i > 9)	
	    		datainfo->tableData[i] = education[atoi(datainfo->tableData[i])];	// 根据学历的数字替换 
			if((i+1)%datainfo->columnCount == 0 && i > 9)
				datainfo->tableData[i] = status[atoi(datainfo->tableData[i])];		// 根据在职状态的数字替换 
			printf("%-12s",datainfo->tableData[i]);							
	        if((i+1)%datainfo->columnCount == 0)
	        {
	            printf("\n");
	        }
	        printf("=============================================================================================================");
		} 
	} 
}


// 对当前用户的信息进行赋值 
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


// 修改用户名
bool update_username(sqlite3 *db,DATABASE *datainfo,USER *p_user) 
{	
	int code;
	if (alert("用户名"))
	{
		printf("\n\t\t请输入用户名：");
		fflush(stdin);
		scanf("%s",p_user->username); 
		code = select_user_by_username(db,datainfo,p_user->username);
		if (code = 2) // 数据库中没有相同用户名 
		{
			update_user_username(db,datainfo,*p_user); 
			return true; 
		} 
	}
	return false;
}

// 修改姓名 
bool update_name(sqlite3 *db,DATABASE *datainfo,USER *p_user) 
{	
	int code;
	if (alert("姓名"))
	{
		printf("\n\t\t请输入姓名：");
		fflush(stdin);
		scanf("%s",p_user->name); 
		update_user_name(db,datainfo,*p_user); 
		return true;
	}
	return false;
}

// 修改密码 
bool update_password(sqlite3 *db,DATABASE *datainfo,USER *p_user) 
{	
	int code,flag=true;
	char *password;
	if (alert("密码"))
	{
		while(flag)
		{
			printf("\n\t\t请输入原密码：");
			fflush(stdin);
			scanf("%s",password); 
			code = select_user_by_password(db,datainfo,p_user->username,password);
			p_user->password = password; 
			if (code == 2)
			{
				printf("密码输入错误！"); 
			}else{
				flag = false;
			}
		}

//		update_user_password(db,datainfo,*p_user); 
		return true;
	}
	return false;
}
 
// 询问是否修改信息，字符串类型 
int alert(char *info)
{
	char ch;
	printf("\t\t是否修改%s?(Y/N)",info);
	fflush(stdin);
	scanf("%c",&ch);
	if (ch == 'y' || ch == 'Y')
	{
		return 1;
	}
	return 0;
}



