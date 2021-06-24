#include "main.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char** argv) {
	USERS users;						// 存放读取的用户数据
	DEPARTMENTS dprts;					// 存放读入的部门数据
	USER user, curr_user;				// curr_user为当前登录用户
	DEPARTMENT dprt;					// 部门实体
	DATABASE datainfo;					// 数据库返回信息
	char ch,password[30];
	int menu_item,menu_item2; 			// 菜单项
	bool is_success;			// 注销标志
	int role; 							// 权限
	char **data;


//=====================================================测试开始
//	char test[30] = "admin";
//	int notOpen = sqlite3_open(dbname, &db);
//    if( notOpen )
//    {
//        fprintf(stderr, "数据库连接失败: %s\n ", sqlite3_errmsg(db));
//        sqlite3_close(db);
//        exit(1);
//    }

//    user.username = (char *)malloc(30);
//    user.name = (char *)malloc(30);
//    user.password = (char *)malloc(30);
//    user.mobile = (char *)malloc(30);
//    user.staff_id = (char *)malloc(30);
//    user.username = (char *)malloc(30);
//    user.username = (char *)malloc(30);
//    user.username = (char *)malloc(30);
//    user.username = (char *)malloc(30);
//    user.username = (char *)malloc(30);
//	scanf("%s",user.username);
//	scanf("%s",user.name);
//	scanf("%s",user.password);
//	scanf("%s",user.mobile);
//	user.role_id = 2;
//	user.sex = 2;
//	user.department_id = 5;
//	user.education = 5;
//	user.staff_id = "28890";
//	user.status = 0;
//	save_user(db,&datainfo,user);

//	update_user_by_staffId(db,&datainfo,user);
//	delete_user_by_staffId(db,&datainfo,6);


/*=====================================================
                    部门功能测试
  =====================================================
*/
//	int notOpen = sqlite3_open(dbname, &db);
//	scanf("%s",dprt.NAME);
//	dprt.rowid = 4;
//	update_user_by_dprtId(db,&datainfo, dprt);
//	printf("%d",datainfo.rowCount);
//	if(datainfo.rowCount > 0)
//	{
//	    printf("数据表的记录:\n");
//	    if(datainfo.rowCount > 0)
//		{
//	  		printf("数据表的记录:\n");
//		    for(int i=0;i<(datainfo.rowCount+1)*datainfo.columnCount;i++)
//		    {
//				printf("%-7s\t",datainfo.tableData[i]);
//
//		        if((i+1)%datainfo.columnCount == 0)
//		        {
//		            printf("\n");
//		        }
//			}
//		}
//	}


//				if(datainfo.rowCount > 0)
//				{
//					curr[0] = column_name[0],curr[1] = column_name[1];
//					for(int i=0;i <(datainfo.rowCount+1)*datainfo.columnCount;i+=10)
//					{
//						printf("%8s %8s %8s %8s %8s %8s %8s ",curr[i],curr[i+1],curr[i+2],curr[i+3],curr[i+4],curr[i+5],curr[i+6],curr[i+7]);
//						printf("\n");
//					}
//
//				}



//    dprt.NAME = (char *)malloc(20);
//	scanf("%s",dprt.NAME);
//    save_dprt(db,&datainfo,dprt);
//    char **dprtdata;
//    // 查找所有部门
//    select_all_dprt(db,&datainfo);
//    dprtdata = datainfo.tableData;
//    for(int i = datainfo.columnCount;i < (datainfo.rowCount+1)*datainfo.columnCount;i+=2)
//    {
//        printf("rowid== %s-----  data[%d]==%s\n",dprtdata[i],i/2,dprtdata[i+1]);
//    }
//	system("pause");
//	return 0;

//==============================================测试结束=================================================


	init_database();
	home:
	while(true){
		system("cls");
		show_prelogin_menu();	 // 显示登录前菜单，若登录成功，则继续
		scanf("%d", &menu_item);
		switch(menu_item)
		{
			case 1:

				// 开始登录
				is_success = login(db,&datainfo,&curr_user);
				if(!is_success) // 登录失败时
					break;
				data = datainfo.tableData;
				curr_user_info(data,&curr_user);
				// 登录成功，根据不同用户显示菜单
				switch (curr_user.role_id)
				{
					case 0: // 一般员工
						while (true)
						{
							system("cls");
							staff_menu();
							scanf("%d",&menu_item);
							switch(menu_item)
							{
								case 1: // 员工确认入职
									staff_induction(db,&datainfo,&curr_user);
									break;
								case 2: // 员工离职
									staff_dimission(db,&datainfo,&curr_user);
									break;
								case 3:	// 修改用户信息
									update_info(db,&datainfo,&curr_user);
									break;
								case 0:
								    goto home;
									break;
								default:	// 若输入的是非数字，则清空缓冲区
									fflush(stdin);
							}
						}
						break;
					case 1: // 部门经理
						while(true)
						{
						    manage:
							system("cls");
							manage_menu();
							scanf("%d",&menu_item);
							switch(menu_item)
							{
								case 1: // 该部门下的员工管理
									while(true)
									{
										system("cls");
										staff_manage_menu();
										scanf("%d",&menu_item2);
										switch(menu_item2)
										{
											case 1:
												save_staff(db,&datainfo,&curr_user);
												break;
											case 2:
												delete_staff(db,&datainfo,&curr_user);
												break;
											case 3:
												update_staff(db,&datainfo,&curr_user);
												break;
											case 4:
												select_staff(db,&datainfo,&curr_user);
												break;
											case 5:
												select_all_staff(db,&datainfo,&curr_user);
												break;
											case 0:
												goto manage;
												break;
											default:	// 若输入的是非数字，则清空缓冲区
												fflush(stdin);
										}
									}
									break;
								case 2: // 员工查询统计
									while(true)
									{
									    system("cls");
										total_staff();
										scanf("%d",&menu_item2);
										switch(menu_item2)
										{
											case 1: // 按性别
												count_by_sex(db,&datainfo,&curr_user);
												break;
											case 2:
												count_by_dprt(db,&datainfo,&curr_user);
												break;
											case 3:
												count_by_edu(db,&datainfo,&curr_user);
												break;
											case 0:
												goto manage;
												break;
											default:	// 若输入的是非数字，则清空缓冲区
												fflush(stdin);
										}
									}
									break;
								case 0:
								    goto home;
									break;
								default:	// 若输入的是非数字，则清空缓冲区
									fflush(stdin);
							}
						}
						break;
					case 2:  // 管理员
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
												save_staff(db,&datainfo,&curr_user);
												break;
											case 2:
												delete_staff(db,&datainfo,&curr_user);
												break;
											case 3:
												update_staff(db,&datainfo,&curr_user);
												break;
											case 4:
												select_staff(db,&datainfo,&curr_user);
												break;
											case 5:
												select_all_staff(db,&datainfo,&curr_user);
												break;
											case 0:
												goto admin_menu;
												break;
											default:	// 若输入的是非数字，则清空缓冲区
												fflush(stdin);
										}
									}
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
												admin_save_dapart(db,&datainfo);
												break;
											case 2:
												admin_delete_dapart(db,&datainfo);
												break;
											case 3:
												admin_udpate_dapart(db,&datainfo);
												break;
											case 4:
												admin_select_dapart(db,&datainfo);
												break;
											case 5:
												dapart_info(db,&datainfo);
												break;
											case 0:
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
												count_by_sex(db,&datainfo);

												break;
											case 2:	// 按部门
												count_by_dprt(db,&datainfo);
												break;
											case 3: // 按学历
												count_by_edu(db,&datainfo);
												break;
											case 0:
												goto admin_menu;
												break;
											default:	// 若输入的是非数字，则清空缓冲区
												fflush(stdin);
										}
									}
								case 4:
									// 删除数据库
                                    delete_database(db,&datainfo);
									exit(0);
//									break;
								case 0:
								    goto home;
								default:
									fflush(stdin);

							}
						}
					default:
						exit(0);

				}
				break;
			case 0:
				exit(0);
			default:
				fflush(stdin);
		}
	}


	return 0;
}
void init_database()
{
	system("mode con cols=120 lines=40");
	//	printf("正在连接数库\n");
//	Sleep(3000);
//	system("cls");
	int staff_res,dprt_res;
	char *name = "admin";
	DATABASE data;
	// 创建用户表并插入一个用户
	char *user_sql = "CREATE TABLE if not exists [user](\
				  [username] VARCHAR(30) NOT NULL DEFAULT NULL, \
				  [name] VARCHAR(30) NOT NULL DEFAULT NULL, \
				  [password] VARCHAR(30) NOT NULL DEFAULT NULL, \
				  [role_id] INT(1) NOT NULL, \
				  [sex] INT(1) NOT NULL, \
				  [department_id] INT(11) NOT NULL, \
				  [education] INT(1) NOT NULL, \
				  [staff_id] VARCHAR(11) NOT NULL, \
				  [mobile] VARCHAR(13) NOT NULL, \
				  [status] INT(1) NOT NULL)\;\
				  INSERT INTO user (username,name,password,role_id,sex,\
				  department_id,education,staff_id,mobile,status)\
                  VALUES ('admin','admin','admin',2,1,0 ,-1, 0,0,1);";
	// 创建部门表语句
	char *dprt_sql = "CREATE TABLE if not exists [department](\
			  [name] VARCHAR(30) NOT NULL DEFAULT NULL);";

	// 添加管理员用户
//	char *add_admin = "INSERT INTO user (username,name,password,role_id,sex,department_id,education,staff_id,mobile,status)\
//           				VALUES ('admin','admin','admin',2,1,0 ,-1, 0,0,1);";

    int notOpen = sqlite3_open(dbname, &db);

    /*该例程打开一个指向 SQLite 数据库文件的连接，返回一个用于其他 SQLite 程序的数据库连接对象。

	如果 filename 参数是 NULL 或 ':memory:'，那么 sqlite3_open() 将会在 RAM 中创建一个内存数据库，

	这只会在 session 的有效时间内持续。如果文件名 filename 不为 NULL，那么 sqlite3_open() 将使用这个参数值尝试打开数据库文件。

	如果该名称的文件不存在，sqlite3_open() 将创建一个新的命名为该名称的数据库文件并打开。*/


    if( notOpen )
    {
        fprintf(stderr, "数据库连接失败: %s\n ", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(1);
    }

    else printf("数据库连接成功！\n",db);
    int res = select_user_by_username(db,&data,name);
    if (res != 1)
    {
	   	staff_res = sqlite3_exec(db,user_sql,NULL,NULL,NULL);
		dprt_res =  sqlite3_exec(db,dprt_sql,NULL,NULL,NULL);
		if(staff_res !=SQLITE_OK)
		{
			printf("创建用户表表失败！%s\n",sqlite3_errmsg(db));
			exit(1);
		}
		if(dprt_res !=SQLITE_OK)
		{
			printf("创建部门表表失败！%s\n",sqlite3_errmsg(db));
			exit(1);
		}
	}

//    Sleep(1000);
//	system("cls");
}







