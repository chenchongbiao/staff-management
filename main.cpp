#include "main.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(int argc, char** argv) {
	USERS users;						// ��Ŷ�ȡ���û�����
	DEPARTMENTS dprts;					// ��Ŷ���Ĳ�������
	USER user, curr_user;				// curr_userΪ��ǰ��¼�û�
	DEPARTMENT dprt;					// ����ʵ��
	DATABASE datainfo;					// ���ݿⷵ����Ϣ
	char ch,password[30];
	int menu_item,menu_item2; 			// �˵���
	bool is_success;			// ע����־
	int role; 							// Ȩ��
	char **data;


//=====================================================���Կ�ʼ
//	char test[30] = "admin";
//	int notOpen = sqlite3_open(dbname, &db);
//    if( notOpen )
//    {
//        fprintf(stderr, "���ݿ�����ʧ��: %s\n ", sqlite3_errmsg(db));
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
                    ���Ź��ܲ���
  =====================================================
*/
//	int notOpen = sqlite3_open(dbname, &db);
//	scanf("%s",dprt.NAME);
//	dprt.rowid = 4;
//	update_user_by_dprtId(db,&datainfo, dprt);
//	printf("%d",datainfo.rowCount);
//	if(datainfo.rowCount > 0)
//	{
//	    printf("���ݱ�ļ�¼:\n");
//	    if(datainfo.rowCount > 0)
//		{
//	  		printf("���ݱ�ļ�¼:\n");
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
//    // �������в���
//    select_all_dprt(db,&datainfo);
//    dprtdata = datainfo.tableData;
//    for(int i = datainfo.columnCount;i < (datainfo.rowCount+1)*datainfo.columnCount;i+=2)
//    {
//        printf("rowid== %s-----  data[%d]==%s\n",dprtdata[i],i/2,dprtdata[i+1]);
//    }
//	system("pause");
//	return 0;

//==============================================���Խ���=================================================


	init_database();
	home:
	while(true){
		system("cls");
		show_prelogin_menu();	 // ��ʾ��¼ǰ�˵�������¼�ɹ��������
		scanf("%d", &menu_item);
		switch(menu_item)
		{
			case 1:

				// ��ʼ��¼
				is_success = login(db,&datainfo,&curr_user);
				if(!is_success) // ��¼ʧ��ʱ
					break;
				data = datainfo.tableData;
				curr_user_info(data,&curr_user);
				// ��¼�ɹ������ݲ�ͬ�û���ʾ�˵�
				switch (curr_user.role_id)
				{
					case 0: // һ��Ա��
						while (true)
						{
							system("cls");
							staff_menu();
							scanf("%d",&menu_item);
							switch(menu_item)
							{
								case 1: // Ա��ȷ����ְ
									staff_induction(db,&datainfo,&curr_user);
									break;
								case 2: // Ա����ְ
									staff_dimission(db,&datainfo,&curr_user);
									break;
								case 3:	// �޸��û���Ϣ
									update_info(db,&datainfo,&curr_user);
									break;
								case 0:
								    goto home;
									break;
								default:	// ��������Ƿ����֣�����ջ�����
									fflush(stdin);
							}
						}
						break;
					case 1: // ���ž���
						while(true)
						{
						    manage:
							system("cls");
							manage_menu();
							scanf("%d",&menu_item);
							switch(menu_item)
							{
								case 1: // �ò����µ�Ա������
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
											default:	// ��������Ƿ����֣�����ջ�����
												fflush(stdin);
										}
									}
									break;
								case 2: // Ա����ѯͳ��
									while(true)
									{
									    system("cls");
										total_staff();
										scanf("%d",&menu_item2);
										switch(menu_item2)
										{
											case 1: // ���Ա�
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
											default:	// ��������Ƿ����֣�����ջ�����
												fflush(stdin);
										}
									}
									break;
								case 0:
								    goto home;
									break;
								default:	// ��������Ƿ����֣�����ջ�����
									fflush(stdin);
							}
						}
						break;
					case 2:  // ����Ա
						while(true)
						{
							admin_menu:
							system("cls");
							admin_menu();
							scanf("%d",&menu_item);
							switch(menu_item)
							{
								case 1: // ȫ��Ա������
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
											default:	// ��������Ƿ����֣�����ջ�����
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
											default:	// ��������Ƿ����֣�����ջ�����
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
											case 1: // ���Ա�
												count_by_sex(db,&datainfo);

												break;
											case 2:	// ������
												count_by_dprt(db,&datainfo);
												break;
											case 3: // ��ѧ��
												count_by_edu(db,&datainfo);
												break;
											case 0:
												goto admin_menu;
												break;
											default:	// ��������Ƿ����֣�����ջ�����
												fflush(stdin);
										}
									}
								case 4:
									// ɾ�����ݿ�
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
	//	printf("������������\n");
//	Sleep(3000);
//	system("cls");
	int staff_res,dprt_res;
	char *name = "admin";
	DATABASE data;
	// �����û�������һ���û�
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
	// �������ű����
	char *dprt_sql = "CREATE TABLE if not exists [department](\
			  [name] VARCHAR(30) NOT NULL DEFAULT NULL);";

	// ��ӹ���Ա�û�
//	char *add_admin = "INSERT INTO user (username,name,password,role_id,sex,department_id,education,staff_id,mobile,status)\
//           				VALUES ('admin','admin','admin',2,1,0 ,-1, 0,0,1);";

    int notOpen = sqlite3_open(dbname, &db);

    /*�����̴�һ��ָ�� SQLite ���ݿ��ļ������ӣ�����һ���������� SQLite ��������ݿ����Ӷ���

	��� filename ������ NULL �� ':memory:'����ô sqlite3_open() ������ RAM �д���һ���ڴ����ݿ⣬

	��ֻ���� session ����Чʱ���ڳ���������ļ��� filename ��Ϊ NULL����ô sqlite3_open() ��ʹ���������ֵ���Դ����ݿ��ļ���

	��������Ƶ��ļ������ڣ�sqlite3_open() ������һ���µ�����Ϊ�����Ƶ����ݿ��ļ����򿪡�*/


    if( notOpen )
    {
        fprintf(stderr, "���ݿ�����ʧ��: %s\n ", sqlite3_errmsg(db));
        sqlite3_close(db);
        exit(1);
    }

    else printf("���ݿ����ӳɹ���\n",db);
    int res = select_user_by_username(db,&data,name);
    if (res != 1)
    {
	   	staff_res = sqlite3_exec(db,user_sql,NULL,NULL,NULL);
		dprt_res =  sqlite3_exec(db,dprt_sql,NULL,NULL,NULL);
		if(staff_res !=SQLITE_OK)
		{
			printf("�����û����ʧ�ܣ�%s\n",sqlite3_errmsg(db));
			exit(1);
		}
		if(dprt_res !=SQLITE_OK)
		{
			printf("�������ű��ʧ�ܣ�%s\n",sqlite3_errmsg(db));
			exit(1);
		}
	}

//    Sleep(1000);
//	system("cls");
}







