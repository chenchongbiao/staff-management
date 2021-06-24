#include "service_user.h"
char *column_name[] = {"用户名","姓名","密码","权限","性别","部门","学历","员工号","电话","在职状态"};
char *role[] = {"普通用户","部门经理","管理员"};
char *sex[] = {"女","男"};
char *education[] = {"小学","初级中学","高级中学","中专","职校","中技","专科","本科","硕士研究生","博士研究生"};
char *status[] = {"离职","在职"};

/*
===========================================================================================================================

													管理员操作

===========================================================================================================================
*/
// 添加员工
bool save_staff(sqlite3 *db,DATABASE *datainfo,USER *p_user)
{
	USER *user;
    user = (struct USER*)malloc(sizeof(struct USER));
    char **dprt;
	int code;
    malloc_user(user);                   // 给结构体指针开辟内存
    select_all_dprt(db,datainfo);        // 查找所有部门
    dprt = datainfo->tableData;
	input_str("用户名",user->username);
    input_str("密码",user->password);
    input_str("姓名",user->name);
	if (p_user->role_id == 2)	     	// 判断当前用户为管理员，可以选择添加管部门管理员和超级管理员
	{
		for(int i = 0;i < 3;i++)
			printf("\t\t%d--%s\n",i,role[i]);
		input_int("用户的权限",user->role_id);
	}else if(p_user->role_id == 1){     // 判断用户为部门管理员则添加部门成员
		user->role_id = 0;
	}
	for(int i = 0;i < 2;i++)
		printf("\t\t%d--%s\n",i,sex[i]);
	input_int("性别",user->sex);
	if (p_user->role_id == 2)           // 判断当前用户为管理员，可以选择添加所有的部门成员
	{
        for(int i = datainfo->columnCount;i < (datainfo->rowCount+1)*datainfo->columnCount;i+=2) // 从数据库中提取数据获得部门列表
        {
            printf("\t\t%d--%s\n",i/2,dprt[i+1]);
        }

		input_int("部门",user->department_id);
		user->department_id = atoi(dprt[user->department_id*2]);
	}else{
		user->department_id = p_user->department_id;
	}
    for(int i = 0;i < 10;i++)
        printf("\t\t%d--%s\n",i,education[i]);
	input_int("学历",user->education);
	input_str("员工号",user->staff_id);
	while(select_user_by_staffId(db,datainfo,user->staff_id) != 2)
	{
		printf("\t\t员工号已经存在请重新输入\n");
		input_str("员工号",user->staff_id);
	}
	input_str("电话",user->mobile);
	user->status = 0;
    save_user(db,datainfo,*user);
    free_user(user);
    system("pause");
	return true;

}

// 删除员工
bool delete_staff(sqlite3 *db,DATABASE *datainfo,USER *p_user)
{
    int code;                                                // 返回值
    USER *user = (struct USER*)malloc(sizeof(struct USER));// 存放员工信息的结构体
    char **data = (char **)malloc(20);                      // 员工信息的二位数组
    malloc_user(user);                                       // 给结构体指针开辟内存
    input_str("员工号",user->staff_id);
    code = select_user_by_staffId(db,datainfo,user->staff_id);// 通过员工号查找
    if (code == 2)
    {
        printf("\t\t该员工不存在！");
        return false;
    }
    data = datainfo->tableData;
    curr_user_info(data,user);
    if(p_user->role_id == 1 && user->department_id == p_user->department_id) // 判断删除的用户与部门管理员来着同一个部门
    {
        code = delete_user_by_staffId(db,datainfo,user->staff_id);                   // 根据员工号删除
        if(code == 0)
        {
            printf("\t\t删除失败！\n");
            return false;
        }else{
            printf("\t\t删除成功！\n");
            return true;
        }

    }else if(p_user->role_id == 1 && user->department_id != p_user->department_id){

        printf("\t\t您没有删除该员工的权限！");
        return false;
    }
    // 管理员可直接进行删除操作
    code = delete_user_by_staffId(db,datainfo,user->staff_id);                      // 根据员工号删除
    if(code == 0)
    {
        printf("\t\t删除失败！\n");
        return false;
    }else{
        printf("\t\t删除成功！\n");
        return true;
    }
}

// 修改员工信息
bool update_staff(sqlite3 *db,DATABASE *datainfo,USER *p_user)
{
    int code;                                                // 返回值
    USER *user = (struct USER*)malloc(sizeof(struct USER));// 存放员工信息的结构体
    char **data = (char **)malloc(20);                      // 员工信息的二位数组
    malloc_user(user);                                       // 给结构体指针开辟内存
    input_str("员工号",user->staff_id);
    code = select_user_by_staffId(db,datainfo,user->staff_id);// 通过员工号查找
    if (code == 2)
    {
        printf("\t\t该员工不存在！");
        return false;
    }
    data = datainfo->tableData;
    curr_user_info(data,user);                                  // 把获取的信息赋值给user
	update_username(db,datainfo,user);
	update_name(db,datainfo,user);
	update_password(db,datainfo,user);
	if(p_user->role_id == 2)
    {
        update_role(db,datainfo,user);
    }
    update_sex(db,datainfo,user);
    update_staffId(db,datainfo,user);
	update_edu(db,datainfo,user);
	update_mobile(db,datainfo,user);
	update_status(db,datainfo,user);
}

// 查找员工信息
bool select_staff(sqlite3 *db,DATABASE *datainfo,USER *p_user)
{
    int code;                                                // 返回值
    USER *user = (struct USER*)malloc(sizeof(struct USER));// 存放员工信息的结构体
    char **data = (char **)malloc(20);
    malloc_user(user);                                       // 给结构体指针开辟内存
    input_str("员工号",user->staff_id);
    code = select_user_by_staffId(db,datainfo,user->staff_id);// 通过员工号查找
    if (code == 2)
    {
        printf("\t\t该员工不存在！");
        system("pause");
        return false;
    }
    data = datainfo->tableData;
    curr_user_info(data,user);                                  // 把获取的信息赋值给user
    if(p_user->role_id == 1 && user->department_id != p_user->department_id)
    {
        printf("\t\t您没有权限查看该员工信息！");
        system("pause");
        return false;
    }
	print_user_Info(db,datainfo);
	system("pause");
	return true;
}

// 管理员查找所有员工信息
bool select_all_staff(sqlite3 *db,DATABASE *datainfo)
{
    int code;                                                // 返回值
    char **data = (char **)malloc(20);
    code = select_all_user(db,datainfo);// 通过员工号查找
    if (code == 2)
    {
        printf("\t\t数据库中没有信息！");
        system("pause");
        return false;
    }
    data = datainfo->tableData;
	print_user_Info(db,datainfo);
	system("pause");
	return true;
}
// 删除数据库
bool delete_database(sqlite3 *db,DATABASE *datainfo)
{
    int code;                                                // 返回值
    char ch;
    printf("\t\t是否删除数据库？该操作不可逆！（Y/N）");
    fflush(stdin);
    scanf("%c",&ch);
    if(ch == 'Y' || ch == 'y')
    {
        code = del_data(db,datainfo);
        if(code == 0)
            printf("\t\t数据库删除失败！");
        else
            printf("\t\t数据库删除成功！");
    }
	system("pause");
	return true;
}

//================================================管理员操作结束=========================================================


/*
===========================================================================================================================

													部门经理操作

===========================================================================================================================
*/
// 部门经理查找所有员工信息
bool select_all_staff(sqlite3 *db,DATABASE *datainfo,USER *p_user)
{
    int code;                                                // 返回值
    char **data = (char **)malloc(20);
    code = select_all_user(db,datainfo,p_user->department_id);// 通过员工号查找
    if (code == 2)
    {
        printf("\t\t数据库中没有信息！");
        system("pause");
        return false;
    }
    data = datainfo->tableData;
	print_user_Info(db,datainfo);
	system("pause");
	return true;
}
//================================================部门经理操作结束=======================================================


/*
===========================================================================================================================

													一般员工操作

===========================================================================================================================
*/
// 员工入职
bool staff_induction(sqlite3 *db,DATABASE *datainfo,USER *p_user)
{
    char ch;
	select_user_by_staffId(db,datainfo,p_user->staff_id);
	if (p_user->status == -1)
	{
		printf("\t\t已经离职无法操作！");
		return false;
	}
	p_user->status = 1;
	update_user_status(db,datainfo,*p_user);
	select_user_by_staffId(db,datainfo,p_user->staff_id);
	print_user_Info(db,datainfo);
	printf("\t\t请确认信息，需要进行修改请输入Y");
	scanf("%c",&ch);
	if (ch == 'Y' || ch == 'y')
        update_info(db,datainfo,p_user);
	getchar();
	return true;
}

// 员工离职
bool staff_dimission(sqlite3 *db,DATABASE *datainfo,USER *p_user)
{
	char ch;
	printf("\t\t是否确认离职？操作不可逆(y/n)");
	fflush(stdin);
	scanf("%c",&ch);
	if (ch == 'y' || ch == 'Y')
	{
		p_user->status = 0;
		update_user_status(db,datainfo,*p_user);
		printf("\t\t已确认离职！");
		return true;
	}
	return false;
}

// 修改个人信息
bool update_info(sqlite3 *db,DATABASE *datainfo,USER *p_user)
{
	char ch;
	if (p_user->status == -1)
	{
		printf("已经离职无法操作！");
		getchar();
		return false;
	}
	update_username(db,datainfo,p_user);
	update_name(db,datainfo,p_user);
	update_password(db,datainfo,p_user);
	update_sex(db,datainfo,p_user);
	update_edu(db,datainfo,p_user);
	update_mobile(db,datainfo,p_user);
	system("pause");
	return true;
}


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
	printf("\t\t请输入用户名和密码：\n");
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
                        printf("\n\t\t登陆成功！欢迎[%s]用户\n",p_user->name);			// 第11个数据为用户姓名
                        return true;

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
void print_user_Info(sqlite3 *db,DATABASE *datainfo)
{
	if(datainfo->rowCount > 0)
	{
//		char *column_name[] = {"用户名","姓名","密码","权限","性别","部门","学历","员工号","电话","在职状态"};
//		char *role[] = {"普通用户","部门经理","管理员"};
//		char *sex[] = {"女","男"};
//		char *dprt[] = {"技术部","开发部","产品部"};
//		char *education[] = {"小学","初级中学","高级中学","中专","职校","中技","专科","本科","硕士研究生","博士研究生"};
//		char *status[] = {"离职","在职"};
		char **data;            // 所有用户数据
		char **dprt;            // 所有部门数据
		DATABASE dprtdata;
		data = datainfo->tableData;
		select_all_dprt(db,&dprtdata);        // 查找所有部门
		dprt = dprtdata.tableData;

		for(int i=0;i < datainfo->columnCount;i++)
		{
			data[i] = column_name[i];
		}
		bound();
	    for(int i=0;i<(datainfo->rowCount+1)*datainfo->columnCount;i++)
	    {
	    	if((i+1)%datainfo->columnCount == 3 && i > 9)
				datainfo->tableData[i] = "******";		// 根据权限的数字替换
	    	if((i+1)%datainfo->columnCount == 4 && i > 9)
				datainfo->tableData[i] = role[atoi(datainfo->tableData[i])];		// 根据权限的数字替换
			if((i+1)%datainfo->columnCount == 5 && i > 9)
	    		datainfo->tableData[i] = sex[atoi(datainfo->tableData[i])];			// 根据性别的数字替换
			if((i+1)%datainfo->columnCount == 6 && i > 9)
            {
                for(int j=dprtdata.columnCount;j<(dprtdata.rowCount+1)*dprtdata.columnCount;j+=2)         // 通过循环部门数组匹配对应的rowid
                    if (strcmp(datainfo->tableData[i], dprt[j])==0)
                         datainfo->tableData[i] = dprt[j+1];		// 根据部门的数字替换

            }
	    	if((i+1)%datainfo->columnCount == 7 && i > 9)
	    		datainfo->tableData[i] = education[atoi(datainfo->tableData[i])];	// 根据学历的数字替换
			if((i+1)%datainfo->columnCount == 0 && i > 9)
				datainfo->tableData[i] = status[atoi(datainfo->tableData[i])];		// 根据在职状态的数字替换
			printf("%-12s",datainfo->tableData[i]);
	        if((i+1)%datainfo->columnCount == 0)
	        {
	            bound();
	        }
		}
	}
}


// 对用户的信息进行赋值
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
		input_str("用户名",p_user->username);
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
		input_str("姓名",p_user->name);
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
		input_str("新密码",p_user->password);
		code = update_user_password(db,datainfo,*p_user);
		if (code)
		{
			printf("\n\t\t密码修改成功！");
		}
		p_user->password = password;
		return true;
	}
	return false;
}

// 修改权限
bool update_role(sqlite3 *db,DATABASE *datainfo,USER *p_user)
{
    int code;
	if (alert("权限"))
	{
        for(int i = 0;i < 3;i++)
			printf("\t\t%d--%s\n",i,role[i]);
 		printf("\n\t\t请输入要修改权限：");
		fflush(stdin);
		scanf("%d",&p_user->role_id);
		update_user_role(db,datainfo,*p_user);
		return true;
	}
	return false;
}
// 修改性别
bool update_sex(sqlite3 *db,DATABASE *datainfo,USER *p_user)
{
    int code;
	if (alert("性别"))
	{
		fflush(stdin);
		if (p_user->role_id == 1) p_user->role_id = 0;
		else p_user->role_id = 1;
		update_user_sex(db,datainfo,*p_user);
		return true;
	}
	return false;
}

// 调离部门
bool update_dprt(sqlite3 *db,DATABASE *datainfo,USER *p_user)
{
	int code;
    char **dprt;
    select_all_dprt(db,datainfo);        // 查找所有部门
    dprt = datainfo->tableData;
	if (alert("部门 "))
	{
        for(int i = datainfo->columnCount;i < (datainfo->rowCount+1)*datainfo->columnCount;i+=2) // 从数据库中提取数据获得部门列表
        {
            printf("\t\t%d--%s\n",i/2,dprt[i+1]);
        }
		input_int("部门",p_user->department_id);
		update_user_dprt(db,datainfo,*p_user);
		return true;
	}
	return false;
}

// 修改学历
bool update_edu(sqlite3 *db,DATABASE *datainfo,USER *p_user)
{
	int code;
	if (alert("学历 "))
	{
        for(int i = 0;i < 10;i++)
            printf("\t\t%d--%s\n",i,education[i]);
		input_int("学历",p_user->education);
		update_user_edu(db,datainfo,*p_user);
		return true;
	}
	return false;
}

// 修改员工号
bool update_staffId(sqlite3 *db,DATABASE *datainfo,USER *p_user)
{
	int code;
	char *new_staffId=(char *)malloc(20);
	if (alert("员工号"))
	{
        input_str("员工号",new_staffId);
        while(select_user_by_staffId(db,datainfo,new_staffId) != 2)
        {
            printf("\t\t员工号已经存在请重新输入\n");
            input_str("员工号",new_staffId);
        }
		update_user_staffId(db,datainfo,*p_user,new_staffId);
		strcpy(p_user->staff_id,new_staffId);
		free(new_staffId);
		return true;
	}
	free(new_staffId);
	return false;
}

// 修改电话
bool update_mobile(sqlite3 *db,DATABASE *datainfo,USER *p_user)
{
	int code;
	if (alert("电话 "))
	{
		input_str("电话",p_user->mobile);
		update_user_mobile(db,datainfo,*p_user);
		return true;
	}
	return false;
}

// 修改在职状态
bool update_status(sqlite3 *db,DATABASE *datainfo,USER *p_user)
{
    int code;
    char ch;
	if (alert("在职状态"))
	{
		if (p_user->status == 1)
        {
            printf("\t\t是否调离该员工？(Y/N)");
            fflush(stdin);
            scanf("%c",&ch);
            if (ch == 'y' || ch == 'Y')
            {
                p_user->status = -1;
            }
        }else{
            printf("\t\t是否允许员工入职？(Y/N)");
            fflush(stdin);
            scanf("%c",&ch);
            if (ch == 'y' || ch == 'Y')
            {
                p_user->status = 1;
            }
        }
		update_user_status(db,datainfo,*p_user);
		return true;
	}
	return false;
}
// 询问是否修改信息，字符串类型
int alert(char *info)
{
	char ch;
	printf("\n\t\t是否修改%s?(Y/N)",info);
	fflush(stdin);
	scanf("%c",&ch);
	if (ch == 'y' || ch == 'Y')
	{
		return 1;
	}
	return 0;
}

//// 输入整型变量
//int input_int(char *info,int &data)
//{
//	printf("\t\t请输入%s：",info);
//	fflush(stdin);
//	scanf("%d",&data);
//	return 1;
//}
//
//// 输入字符型变量
//int input_str(char *info,char *data)
//{
//	printf("\t\t请输入%s：",info);
//	fflush(stdin);
//	scanf("%s",data);
//	return 1;
//}

// 给结构体的字符指针开辟内存
void malloc_user(USER *user)
{

    user->username = (char *)malloc(30);
 	user->password = (char *)malloc(30);
    user->name = (char *)malloc(30);
    user->staff_id = (char *)malloc(30);
    user->mobile = (char *)malloc(30);
}

// 释放结构体的字符指针
void free_user(USER *user)
{
    free(user->username);
    free(user->password);
    free(user->name);
    free(user->staff_id);
    free(user->mobile);
    free(user);
}

void bound()
{
    printf("\n===============================================================================================================================\n");
}

