#ifndef __SERVICE_COUNT_H__
#define __SERVICE_COUNT_H__
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "struct.h"
#include "service_count.h"

//====================================按性别统计员工 
bool count_by_sex(USERS users,USER user);
//====================================按部门统计员工 
bool count_by_dprt(USERS users,USER user);
//====================================按学历统计员工 
bool count_by_edu(USERS users,USER user);
//================================================管理员操作=========================================================

//================================================管理员操作结束=========================================================


//================================================部门经理操作=========================================================
//================================================部门经理操作结束=========================================================


#endif
