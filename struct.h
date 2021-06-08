#ifndef __STRUCT_H__
#define __STRUCT_H__

#define USERNAME_LEN            30		// �û������� 
#define USER_NUM_MAX			1000	// �û�������� 
#define NAME_LEN				30      // �û�����		
#define PWD_LEN                 30  	// ���볤�� 
#define DEPART_NAME_LEN         30 		// �������Ƴ��� 
#define DEPART_NUM_MAX			50		// ����������� 
#define DIR_LEN_MAX				256 	// ·������󳤶� 
struct USER{
	char user_name[USERNAME_LEN];	// �û��� 
	char name[NAME_LEN];			// ���� 
	char password[PWD_LEN];			// ���� 
	int role_id;					// ��ɫID��0 һ��Ա��, 1 ���Ź���Ա, 2 ϵͳ����Ա 
	int sex; 						// �Ա�  0 ��ʾŮ��1 ��ʾ�� 
	int department_id;				// ����id 
	int education;					// ѧ��    0Сѧ 1������ѧ 2�߼���ѧ 3��ר 4ְУ 5�м� 6ר�� 7���� 8˶ʿ�о��� 9��ʿ�о���  
	int employee_id;			    // Ա���� 
	bool status;					// ��ְ״̬ 1 ��ְ��0��ְ 
};

struct DEPARTMENT{
	char NAME[DEPART_NAME_LEN];		// �������� 
};

struct USERS{
	USER users[USER_NUM_MAX];		// �û����� 
	int length;						// �û����� 
	
	USERS(){
		length = 0;					// �û�������ʼ��0 
	} 
};
struct DEPARTMENTS{
	DEPARTMENT departments[DEPART_NUM_MAX];     // �������� 
	int length;									// ���Ÿ��� 
	DEPARTMENTS(){
		length = 0;								// ����������ʼ��Ϊ0 
	} 
};

#endif 
