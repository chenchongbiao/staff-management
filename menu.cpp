#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"

// 登录前菜单
void show_prelogin_menu(){
    printf("\t\t***********************************************\n");
    printf("\t\t*                  1.登录                     *\n");
    printf("\t\t*                                             *\n");
    printf("\t\t*                  0.退出系统                 *\n");
    printf("\t\t*                  请选择功能(0-1）           *\n");
    printf("\t\t***********************************************\n");
    printf("\t\t请输入序号【  】\b\b\b\b");
}

// 管理员菜单功能显示
void admin_menu()
{
    printf("\t\t**********************************************\n");
    printf("\t\t*                                            *\n");
    printf("\t\t*               企业员工管理系统             *\n");
    printf("\t\t*                                            *\n");
    printf("\t\t**********************************************\n");
    printf("\t\t*               1.员 工 管 理                *\n");
    printf("\t\t*                                            *\n");
    printf("\t\t*               2.部 门管 理                 *\n");
    printf("\t\t*                                            *\n");
    printf("\t\t*               3.员 工 查 询 统 计          *\n");
    printf("\t\t*                                            *\n");
    printf("\t\t*               4.删 除 数 据 库             *\n");
    printf("\t\t*                                            *\n");
    printf("\t\t*               0.退出系统                   *\n");
    printf("\t\t*               请选择功能(0-3）             *\n");
    printf("\t\t**********************************************\n");
    printf("\t\t请输入序号【  】\b\b\b\b");
}

// 部门经理菜单功能显示
void manage_menu()
{
    printf("\t\t**********************************************\n");
    printf("\t\t*                                            *\n");
    printf("\t\t*               企业员工管理系统             *\n");
    printf("\t\t*                                            *\n");
    printf("\t\t**********************************************\n");
    printf("\t\t*               1.员 工 管 理                *\n");
    printf("\t\t*                                            *\n");
    printf("\t\t*               2.员 工 查 询 统 计          *\n");
    printf("\t\t*                                            *\n");
    printf("\t\t*               0.退出系统                   *\n");
    printf("\t\t*               请选择功能(0-3）             *\n");
    printf("\t\t**********************************************\n");
    printf("\t\t请输入序号【  】\b\b\b\b");
}

// 员工个人管理
void staff_menu(){
	printf("\t\t**********************************************\n");
    printf("\t\t*                                            *\n");
    printf("\t\t*              员 工 个 人 管 理             *\n");
    printf("\t\t*                                            *\n");
    printf("\t\t**********************************************\n");
    printf("\t\t*              1.员 工 入 职                 *\n");
    printf("\t\t*                                            *\n");
    printf("\t\t*              2.员 工 离 职                 *\n");
    printf("\t\t*                                            *\n");
    printf("\t\t*              3.修改个人信息                *\n");
    printf("\t\t*                                            *\n");
    printf("\t\t*              0.返回上一页                  *\n");
    printf("\t\t*              请选择功能(0-3）              *\n");
    printf("\t\t**********************************************\n");
    printf("\t\t请输入序号【  】\b\b\b\b");
}

// 员工管理
void staff_manage_menu(){
	printf("\t\t**********************************************\n");
    printf("\t\t*                                            *\n");
    printf("\t\t*             员 工 管  理                   *\n");
    printf("\t\t*                                            *\n");
    printf("\t\t**********************************************\n");
    printf("\t\t*             1.添 加 员 工                  *\n");
    printf("\t\t*                                            *\n");
    printf("\t\t*             2.删 除 员 工                  *\n");
    printf("\t\t*                                            *\n");
    printf("\t\t*             3.修 改 员 工                  *\n");
    printf("\t\t*                                            *\n");
    printf("\t\t*             4.查 找 员 工                  *\n");
    printf("\t\t*                                            *\n");
    printf("\t\t*             5.信 息 总 览                  *\n");
    printf("\t\t*                                            *\n");
    printf("\t\t*             0.返回上一页                   *\n");
    printf("\t\t*             请选择功能(0-5）               *\n");
    printf("\t\t**********************************************\n");
    printf("\t\t请输入序号【  】\b\b\b\b");
}



// 部门管理
void depart_manage_menu(){
	printf("\t\t**********************************************\n");
    printf("\t\t*                                            *\n");
    printf("\t\t*             部  门  管  理                 *\n");
    printf("\t\t*                                            *\n");
    printf("\t\t**********************************************\n");
    printf("\t\t*             1.添 加 部 门                  *\n");
    printf("\t\t*                                            *\n");
    printf("\t\t*             2.删 除 部 门                  *\n");
    printf("\t\t*                                            *\n");
    printf("\t\t*             3.修 改 部 门                  *\n");
    printf("\t\t*                                            *\n");
    printf("\t\t*             4.查 找 部 门                  *\n");
    printf("\t\t*                                            *\n");
    printf("\t\t*             5.部 门 总 览                  *\n");
    printf("\t\t*                                            *\n");
    printf("\t\t*             0.返回上一页                   *\n");
    printf("\t\t*             请选择功能(0-5）               *\n");
    printf("\t\t**********************************************\n");
    printf("\t\t请输入序号【  】\b\b\b\b");
}

// 员工查询统计
void total_menu(){
	printf("\t\t**********************************************\n");
    printf("\t\t*                                            *\n");
    printf("\t\t*             员工查询统计                   *\n");
    printf("\t\t*                                            *\n");
    printf("\t\t**********************************************\n");
    printf("\t\t*             1.员工个人查询                 *\n");
    printf("\t\t*                                            *\n");
    printf("\t\t*             2.员 工 统 计                  *\n");
    printf("\t\t*                                            *\n");
    printf("\t\t*             0.返回上一页                   *\n");
    printf("\t\t*             请选择功能(0-2）               *\n");
    printf("\t\t**********************************************\n");
    printf("\t\t请输入序号【  】\b\b\b\b");
}



// 员工统计
void total_staff(){
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
    printf("\t\t请输入序号【  】\b\b\b\b");
}

