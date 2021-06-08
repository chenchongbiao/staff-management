#include "main.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	USERS users;						// 存放读取的用户数据 
	DEPARTMENTS dprts;					// 存放读入的部门数据
	 
	
	USER user, curr_user;				// curr_user为当前登录用户 
	DEPARTMENT dprt;					// 部门实体 
	
	char ch,password[30];
	int menu_item,menu_item2; 			// 菜单项
	bool dirty[] = {false,false,false}; // 依次是users,cards, transactions的脏标志，如果为true，则在退出程序前，要提示保存 
	bool is_logout, is_success;			// 注销标志 
	printf("是否初始化数据？（y/n）");
	scanf("%c",&ch);
	if(ch == 'Y' || ch == 'y')
	{
		init_data_files();
		printf("系统初始化完毕！请重启程序！\n");
		return 0;
	}
	
	// 加载数据 
 	if (!read_users(&users)) {
 		printf("加载用户信息失败，程序终止！\n");
 		return 0;
	}
	

	while(true){	
		system("cls");
		show_prelogin_menu();	 // 显示登录前菜单，若登录成功，则继续 
		scanf("%d", &menu_item);
		switch(menu_item)
		{	
			case 1:
				printf("\t\t开始！"); 
				// 开始登录
				is_success = login(users,&curr_user); 	
				if(!is_success) // 登录失败时
					break;
					
				// 登录成功，根据不同用户显示菜单 
				switch (curr_user.role_id)
				{
					case 0: // 一般员工	
						is_logout = false;
						while (true)
						{
							staff_menu();
							scanf("%d",&menu_item);
							switch(menu_item)
							{
								case 1: // 员工入职
									staff_induction(&users,&curr_user);
									dirty[0] = true;	// 用户数据被修改，设置脏标志
									break;
								case 2: // 员工离职
									staff_induction(&users,&curr_user);
									dirty[0] = true;	// 用户数据被修改，设置脏标志
									break;
								case 3:
									printf("修改个人信息");
									dirty[0] = true;	// 用户数据被修改，设置脏标志
									break; 
								case 0:
									printf("返回上一页!");
									is_logout = true;
									break;
								default:	// 若输入的是非数字，则清空缓冲区 
									fflush(stdin);
							}
							if (is_logout) // 返回上一页 
								break;
						}
					case 1: // 部门经理 
						is_logout = false;					
						while(true)
						{
							manage_menu();
							scanf("%d",&menu_item);
							switch(menu_item)
							{
								case 1: // 该部门下的员工管理 
									while(true)
									{
										staff_manage_menu();
										scanf("%d",&menu_item2);
										switch(menu_item2)
										{
											case 1:
												printf("添加员工");
												break;
											case 2:
												printf("删除员工");
												break;
											case 3:
												printf("修改员工");
												break;
											case 4:
												printf("查找员工");
												break;
											case 5: 
												printf("信息总览");
												break;
											case 0:	
												printf("返回上一页!");
												break;
											default:	// 若输入的是非数字，则清空缓冲区 
												fflush(stdin);
										}
									}
									staff_induction(&users,&curr_user);
									dirty[0] = true;	// 用户数据被修改，设置脏标志
									break;
								case 2: // 员工查询统计
									while(true)
									{
										total_staff();
										scanf("%d",&menu_item2);
										switch(menu_item2)
										{
											case 1: // 按性别
												printf("按性别");
												break;
											case 2:
												printf("按部门");
												break; 
											case 3:
												printf("按学历"); 
												break;
											case 0:	
												printf("返回上一页!");
												break;
											default:	// 若输入的是非数字，则清空缓冲区 
												fflush(stdin);
										}
									} 
									break;
								case 0:
									printf("返回上一页!");
									is_logout = true;
									break;
								default:	// 若输入的是非数字，则清空缓冲区 
									fflush(stdin);
							}
							if (is_logout) // 返回上一页 
								break;
						} 
					case 2:  // 管理员 
						is_logout = false;	
						while(true)
						{
							admin_menu: 
							system("cls");
							admin_menu();
							scanf("%d",&menu_item);
							switch(menu_item)
							{
								case 1: // 全部员工管理 
									while(true)
									{
										system("cls");
										staff_manage_menu();
										scanf("%d",&menu_item2);
										switch(menu_item2)
										{
											case 1:
												admin_save_user(&users);
												break;
											case 2:
												admin_delete_user(&users);
												break;
											case 3:
												admin_udpate_user(&users);
												break;
											case 4:
												admin_select_user(users);
												break;
											case 5: 
												staff_info(users);
												break;
											case 0:	
												printf("\t\t返回上一页!\n");
												goto admin_menu;
												break;
											default:	// 若输入的是非数字，则清空缓冲区 
												fflush(stdin);
										}
									}
									staff_induction(&users,&curr_user);
									dirty[0] = true;	// 用户数据被修改，设置脏标志
									break;
								case 2:
									while(true)
									{
										system("cls");
										depart_manage_menu();
										scanf("%d",&menu_item2);
										switch(menu_item2)
										{
											case 1:
												admin_save_dapart(&dprts);
												break;
											case 2:
												admin_delete_dapart(&dprts);
												break;
											case 3:
												admin_udpate_dapart(&dprts);
												break;
											case 4:
												admin_select_dapart(dprts);
												break;
											case 5: 
												dapart_info(dprts);
												break;
											case 0:	
												printf("返回上一页!");
												goto admin_menu;
												break;
											default:	// 若输入的是非数字，则清空缓冲区 
												fflush(stdin);
										}
									}								
								case 3:
									while(true)
									{
										system("cls");
										total_staff();
										scanf("%d",&menu_item2);
										switch(menu_item2)   //  
										{
											case 1: // 按性别
												count_by_sex(users,curr_user);
												break;
											case 2:	// 按部门 
												count_by_dprt(users,curr_user);
												break; 
											case 3: // 按学历 
												count_by_edu(users,curr_user);
												break;
											case 0:	
												printf("返回上一页!");
												goto admin_menu;
												break;
											default:	// 若输入的是非数字，则清空缓冲区 
												fflush(stdin);
										}
									} 
								case 0:
									exit(0);
								default:
									fflush(stdin);
								
							} 
						} 
					default:
						exit(0);
						
				} 
			case 0:
				if (!save_data(dirty, 1, users)) 	// 退出系统前，保存数据 
				printf("保存数据失败\n");
				exit(0);
			default:
				fflush(stdin);
		} 
	}
	
	
	return 0;
}


// 存储所有数据 
bool save_data(bool *dirty, int size, USERS users){
	int ret = true;
	char ch;
	
	for (int i = 0; i < size; i ++){
		if (dirty[i]) {
			switch (i){
			case 0:
				printf("用户信息已经被修改，是否保存？(Y/N)");
				fflush(stdin);
				scanf("%c", &ch);
				if (ch != 'N' && ch != 'n') 
					ret = write_users(users);
				break;
				
			}
		}	
	}
	
	return ret;
} 

// 初始化数据文件，并创建第1个系统管理员用户 
void init_data_files(){
	USERS users;     // 用户数组 

	USER admin,manage;		
	strcpy(admin.user_name, "admin");		// 管理员 
	admin.role_id = 2;						// 权限id 
	admin.status = 1;						// 在职 
	strcpy(admin.name, "admin");			
	strcpy(admin.password, "admin");	
	save_user(&users, admin); 
							
	strcpy(manage.user_name, "manage");		// 部门经理 
	manage.role_id = 2;						// 权限id 
	manage.status = 1;						// 在职 
	manage.department_id = -1;  
	strcpy(manage.name, "manage");
	strcpy(manage.password, "manage");	
	save_user(&users, manage); 
	
	// 清空并创建数据文件 
	write_users(users);
}

