#ifndef __STRUCT_H__
#define __STRUCT_H__

#define USERNAME_LEN            30		// 用户名长度 
#define USER_NUM_MAX			1000	// 用户最大数量 
#define NAME_LEN				30      // 用户姓名		
#define PWD_LEN                 30  	// 密码长度 
#define DEPART_NAME_LEN         30 		// 部门名称长度 
#define DEPART_NUM_MAX			50		// 部门最大数量 
#define DEPART_ID_MAX			11		// 部门id最大长度 
#define MOBILE_LEN 				13		// 电话号码长度 
#define DIR_LEN_MAX				256 	// 路径的最大长度 

struct USER{
	char *username;					// 用户名 		
	char *name;						// 姓名 
	char *password;					// 密码 
	int role_id;					// 角色ID：0 一般员工, 1 部门管理员, 2 系统管理员 
	int sex; 						// 性别  0 表示女，1 表示男 
	int department_id;				// 部门id 
	int education;	         	    // 学历    0小学 1初级中学 2高级中学 3中专 4职校 5中技 6专科 7本科 8硕士研究生 9博士研究生
	char *staff_id;				    // 员工号 
	char *mobile;					// 电话号码 
	int status;						// 在职状态 1 在职，0离职 
//	char username[USERNAME_LEN];	// 用户名 
//	char name[NAME_LEN];			// 姓名 
//	char password[PWD_LEN];			// 密码 
//	int role_id;					// 角色ID：0 一般员工, 1 部门管理员, 2 系统管理员 
//	int sex; 						// 性别  0 表示女，1 表示男 
//	int department_id;				// 部门id 
//	int education;	                // 学历    0小学 1初级中学 2高级中学 3中专 4职校 5中技 6专科 7本科 8硕士研究生 9博士研究生
//	int staff_id;				    // 员工号 
//	char mobile[MOBILE_LEN];		// 电话号码 
//	bool status;					// 在职状态 1 在职，0离职 
};

struct DEPARTMENT{
	int rowid;						// 部门的id号 
//	char NAME[DEPART_NAME_LEN];		// 部门名称 
	char *NAME;		// 部门名称 
	
};

struct USERS{
	USER users[USER_NUM_MAX];		// 用户数组 
	int length;						// 用户数量 
	
	USERS(){
		length = 0;					// 用户数量初始化0 
	} 
};

struct DEPARTMENTS{
	DEPARTMENT departments[DEPART_NUM_MAX];     // 部门数组 
	int length;									// 部门个数 
	DEPARTMENTS(){
		length = 0;								// 部门数量初始化为0 
	} 
};

struct DATABASE
{
	char sql[200]; // 存放sql语句 
	char *errorInfo; // 错误信息 	
	int rowCount; // 行数
	int columnCount; // 列数
	char **tableData; // 数据表的记录
//	DATABASE()
//	{
//		int rowCount = 0; // 行数
//		int columnCount = 0; // 列数
//		char **tableData = NULL; /
//	} 
};

#endif 
