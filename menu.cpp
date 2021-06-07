#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"

// 登录前菜单
void show_prelogin_menu(){
	printf("\n\n\t1. 登录\n");
	printf("\t2. 退出\n");
	printf("\n\t请选择您的操作：");
} 

// 主菜单功能显示
void main_menu()           
{
    printf("\t\t****************************\n");
    printf("\t\t*                          *\n");
    printf("\t\t*     企业员工管理系统     *\n");
    printf("\t\t*                          *\n");
    printf("\t\t****************************\n");
    printf("\t\t*     1.员工个人管理       *\n");
    printf("\t\t*                          *\n");
    printf("\t\t*     2.部 门 管 理        *\n");
    printf("\t\t*                          *\n");
    printf("\t\t*     3.员工查询统计       *\n");
    printf("\t\t*                          *\n");
    printf("\t\t*     0.退出系统           *\n");
    printf("\t\t*     请选择功能(0-3）     *\n");
    printf("\t\t****************************\n");
}

// 员工个人管理
void staff_menu(){
	printf("\t\t****************************\n");
    printf("\t\t*                          *\n");
    printf("\t\t*     员 工 个 人 管 理    *\n");
    printf("\t\t*                          *\n");
    printf("\t\t****************************\n");
    printf("\t\t*     1.员 工 入 职        *\n");
    printf("\t\t*                          *\n");
    printf("\t\t*     2.员 工 离 职        *\n");
    printf("\t\t*                          *\n");
    printf("\t\t*     3.员 工 调 职        *\n");
    printf("\t\t*                          *\n");
    printf("\t\t*     0.返回上一页         *\n");
    printf("\t\t*     请选择功能(0-3）     *\n");
    printf("\t\t****************************\n");
} 

// 部门管理
void depart_menu(){
	printf("\t\t****************************\n");
    printf("\t\t*                          *\n");
    printf("\t\t*     部  门  管  理       *\n");
    printf("\t\t*                          *\n");
    printf("\t\t****************************\n");
    printf("\t\t*     1.新 增 部 门        *\n");
    printf("\t\t*                          *\n");
    printf("\t\t*     2.部 门 总 览        *\n");
    printf("\t\t*                          *\n");
    printf("\t\t*     0.返回上一页         *\n");
    printf("\t\t*     请选择功能(0-2）     *\n");
    printf("\t\t****************************\n");
}

// 员工查询统计 
void total_menu(){
	printf("\t\t****************************\n");
    printf("\t\t*                          *\n");
    printf("\t\t*      员工查询统计        *\n");
    printf("\t\t*                          *\n");
    printf("\t\t****************************\n");
    printf("\t\t*     1.员工个人查询       *\n");
    printf("\t\t*                          *\n");
    printf("\t\t*     2.员 工 统 计        *\n");
    printf("\t\t*                          *\n");
    printf("\t\t*     0.返回上一页         *\n");
    printf("\t\t*     请选择功能(0-2）     *\n");
    printf("\t\t****************************\n");
}  

// 员工统计 
void totalstaff(){ 
	printf("\t\t****************************\n");
    printf("\t\t*                          *\n");
    printf("\t\t*     员  工  统  计       *\n");
    printf("\t\t*                          *\n");
    printf("\t\t****************************\n");
    printf("\t\t*     1.按  性  别         *\n");
    printf("\t\t*                          *\n");
    printf("\t\t*     2.按  部  门         *\n");
    printf("\t\t*                          *\n");
    printf("\t\t*     3.按  学  历         *\n");
    printf("\t\t*                          *\n");
    printf("\t\t*     0.返回上一页         *\n");
    printf("\t\t*     请选择功能(0-3）     *\n");
    printf("\t\t****************************\n");
}
