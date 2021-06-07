#ifndef __STRUCT_H__
#define __STRUCT_H__

#define USER_NAME_LEN           30		// 用户名长度 
#define USER_NUM_MAX			1000	// 用户最大数量 
#define PWD_LEN                 30  	// 密码长度 
#define EDUCATION_LEN			30  	// 学历存放数组长度 
#define DEPART_NAME_LEN         30 		// 部门名称长度 
#define DEPART_NUM_MAX			50		// 部门最大数量 
#define DIR_LEN_MAX				256 	// 路径的最大长度 
struct USER{
	char user_name[USER_NAME_LEN];	// 用户名 
	char password[PWD_LEN];			// 密码 
	int role_id;					// 角色ID：0 一般员工, 1 部门管理员, 2 系统管理员 
	int sex; 						// 性别 
	int department_id;				// 部门id 
	char education[EDUCATION_LEN];	// 学历 
	int employee_id;			    // 员工号 
	bool status;						// 在职状态 1 入职，0离职 
};

struct DEPARTMENT{
	char NAME[DEPART_NAME_LEN];		// 部门名称 
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

#endif 
