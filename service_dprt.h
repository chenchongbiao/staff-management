#ifndef __SERVICE_DPRT_H__ 
#define __SERVICE_DPRT_H__ 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mapper_dprt.h"
#include "struct.h"
#include "utils.h" 


//================================================����Ա����=========================================================
// ��Ӳ���
bool admin_save_dapart(sqlite3 *db,DATABASE *datainfo);
// ɾ������
bool admin_delete_dapart(sqlite3 *db,DATABASE *datainfo);
// �޸Ĳ���
bool admin_udpate_dapart(sqlite3 *db,DATABASE *datainfo);
// ���Ҳ���
bool admin_select_dapart(sqlite3 *db,DATABASE *datainfo);
// ������Ϣ����
bool dapart_info(sqlite3 *db,DATABASE *datainfo);
//================================================����Ա��������=========================================================





#endif
