#ifndef __SERVICE_COUNT_H__
#define __SERVICE_COUNT_H__
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "struct.h"
#include "service_count.h"
#include "mapper_dprt.h"
#include "mapper_user.h" 
#include "sqlite3.h"

/*
=====================================================����Ա����=============================================================

============================================================================================================================
*/
// ���Ա�ͳ��Ա��
bool count_by_sex(sqlite3 *db,DATABASE *datainfo);
// ������ͳ��Ա��
bool count_by_dprt(sqlite3 *db,DATABASE *datainfo);
// ��ѧ��ͳ��Ա��
bool count_by_edu(sqlite3 *db,DATABASE *datainfo);

//================================================����Ա��������=========================================================

/*
=====================================================���ž������=============================================================

============================================================================================================================
*/

// ���Ա�ͳ��Ա��
bool count_by_sex(sqlite3 *db,DATABASE *datainfo,USER *user);
// ������ͳ��Ա��
bool count_by_dprt(sqlite3 *db,DATABASE *datainfo,USER *user);
// ��ѧ��ͳ��Ա��
bool count_by_edu(sqlite3 *db,DATABASE *datainfo,USER *user);
//================================================���ž����������=========================================================

void count_bound();

#endif
