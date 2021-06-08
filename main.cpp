#include "main.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	USERS users;						// ��Ŷ�ȡ���û����� 
	DEPARTMENTS dprts;					// ��Ŷ���Ĳ�������
	 
	
	USER user, curr_user;				// curr_userΪ��ǰ��¼�û� 
	DEPARTMENT dprt;					// ����ʵ�� 
	
	char ch,password[30];
	int menu_item,menu_item2; 			// �˵���
	bool dirty[] = {false,false,false}; // ������users,cards, transactions�����־�����Ϊtrue�������˳�����ǰ��Ҫ��ʾ���� 
	bool is_logout, is_success;			// ע����־ 
	printf("�Ƿ��ʼ�����ݣ���y/n��");
	scanf("%c",&ch);
	if(ch == 'Y' || ch == 'y')
	{
		init_data_files();
		printf("ϵͳ��ʼ����ϣ�����������\n");
		return 0;
	}
	
	// �������� 
 	if (!read_users(&users)) {
 		printf("�����û���Ϣʧ�ܣ�������ֹ��\n");
 		return 0;
	}
	

	while(true){	
		system("cls");
		show_prelogin_menu();	 // ��ʾ��¼ǰ�˵�������¼�ɹ�������� 
		scanf("%d", &menu_item);
		switch(menu_item)
		{	
			case 1:
				printf("\t\t��ʼ��"); 
				// ��ʼ��¼
				is_success = login(users,&curr_user); 	
				if(!is_success) // ��¼ʧ��ʱ
					break;
					
				// ��¼�ɹ������ݲ�ͬ�û���ʾ�˵� 
				switch (curr_user.role_id)
				{
					case 0: // һ��Ա��	
						is_logout = false;
						while (true)
						{
							staff_menu();
							scanf("%d",&menu_item);
							switch(menu_item)
							{
								case 1: // Ա����ְ
									staff_induction(&users,&curr_user);
									dirty[0] = true;	// �û����ݱ��޸ģ��������־
									break;
								case 2: // Ա����ְ
									staff_induction(&users,&curr_user);
									dirty[0] = true;	// �û����ݱ��޸ģ��������־
									break;
								case 3:
									printf("�޸ĸ�����Ϣ");
									dirty[0] = true;	// �û����ݱ��޸ģ��������־
									break; 
								case 0:
									printf("������һҳ!");
									is_logout = true;
									break;
								default:	// ��������Ƿ����֣�����ջ����� 
									fflush(stdin);
							}
							if (is_logout) // ������һҳ 
								break;
						}
					case 1: // ���ž��� 
						is_logout = false;					
						while(true)
						{
							manage_menu();
							scanf("%d",&menu_item);
							switch(menu_item)
							{
								case 1: // �ò����µ�Ա������ 
									while(true)
									{
										staff_manage_menu();
										scanf("%d",&menu_item2);
										switch(menu_item2)
										{
											case 1:
												printf("���Ա��");
												break;
											case 2:
												printf("ɾ��Ա��");
												break;
											case 3:
												printf("�޸�Ա��");
												break;
											case 4:
												printf("����Ա��");
												break;
											case 5: 
												printf("��Ϣ����");
												break;
											case 0:	
												printf("������һҳ!");
												break;
											default:	// ��������Ƿ����֣�����ջ����� 
												fflush(stdin);
										}
									}
									staff_induction(&users,&curr_user);
									dirty[0] = true;	// �û����ݱ��޸ģ��������־
									break;
								case 2: // Ա����ѯͳ��
									while(true)
									{
										total_staff();
										scanf("%d",&menu_item2);
										switch(menu_item2)
										{
											case 1: // ���Ա�
												printf("���Ա�");
												break;
											case 2:
												printf("������");
												break; 
											case 3:
												printf("��ѧ��"); 
												break;
											case 0:	
												printf("������һҳ!");
												break;
											default:	// ��������Ƿ����֣�����ջ����� 
												fflush(stdin);
										}
									} 
									break;
								case 0:
									printf("������һҳ!");
									is_logout = true;
									break;
								default:	// ��������Ƿ����֣�����ջ����� 
									fflush(stdin);
							}
							if (is_logout) // ������һҳ 
								break;
						} 
					case 2:  // ����Ա 
						is_logout = false;	
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
												printf("\t\t������һҳ!\n");
												goto admin_menu;
												break;
											default:	// ��������Ƿ����֣�����ջ����� 
												fflush(stdin);
										}
									}
									staff_induction(&users,&curr_user);
									dirty[0] = true;	// �û����ݱ��޸ģ��������־
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
												printf("������һҳ!");
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
												count_by_sex(users,curr_user);
												break;
											case 2:	// ������ 
												count_by_dprt(users,curr_user);
												break; 
											case 3: // ��ѧ�� 
												count_by_edu(users,curr_user);
												break;
											case 0:	
												printf("������һҳ!");
												goto admin_menu;
												break;
											default:	// ��������Ƿ����֣�����ջ����� 
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
				if (!save_data(dirty, 1, users)) 	// �˳�ϵͳǰ���������� 
				printf("��������ʧ��\n");
				exit(0);
			default:
				fflush(stdin);
		} 
	}
	
	
	return 0;
}


// �洢�������� 
bool save_data(bool *dirty, int size, USERS users){
	int ret = true;
	char ch;
	
	for (int i = 0; i < size; i ++){
		if (dirty[i]) {
			switch (i){
			case 0:
				printf("�û���Ϣ�Ѿ����޸ģ��Ƿ񱣴棿(Y/N)");
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

// ��ʼ�������ļ�����������1��ϵͳ����Ա�û� 
void init_data_files(){
	USERS users;     // �û����� 

	USER admin,manage;		
	strcpy(admin.user_name, "admin");		// ����Ա 
	admin.role_id = 2;						// Ȩ��id 
	admin.status = 1;						// ��ְ 
	strcpy(admin.name, "admin");			
	strcpy(admin.password, "admin");	
	save_user(&users, admin); 
							
	strcpy(manage.user_name, "manage");		// ���ž��� 
	manage.role_id = 2;						// Ȩ��id 
	manage.status = 1;						// ��ְ 
	manage.department_id = -1;  
	strcpy(manage.name, "manage");
	strcpy(manage.password, "manage");	
	save_user(&users, manage); 
	
	// ��ղ����������ļ� 
	write_users(users);
}

