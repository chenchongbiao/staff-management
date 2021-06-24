#ifndef __MAIN_H__
#define __MAIN_H__
#include <stdio.h>
#include <time.h>
#include <string.h> 
#include <stdlib.h>
#include <windows.h> 							
#include "struct.h"
#include "menu.h"
#include "service_user.h"
#include "mapper_user.h" 
#include "service_dprt.h"
#include "mapper_dprt.h"
#include "service_count.h"
#include "sqlite3.h" 
#include "database.h"
#include "utils.h"
void init_database();
void curr_user_info(char **data,USER *p_user);
#endif
