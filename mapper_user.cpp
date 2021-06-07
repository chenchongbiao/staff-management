#include <string.h>
#include "mapper_user.h"


///////////////////////////////////添加用户/////////////////////////////////////////////
///////////////////////////////////删除用户/////////////////////////////////////////////
///////////////////////////////////修改用户/////////////////////////////////////////////
int update_user(USERS *p_users,USER user)
{
    int index = select_user_by_username(*p_users,user.user_name);
    if (index < 0 || index >= p_users->length)
    	return false;
    p_users->users[index] = user;
	return 1; 
}
//////////////////////////////////查找用户/////////////////////////////////////////////// 

// 通过用户名查找 
int select_user_by_username(USERS users,char *p_username)
{
	int i;
	for (int = 0; i < users.length; i++)
	{
		if (strcmp(users.users[i].user_name ,p_username) == 0)	// 用户名一致
		{
			return i;		// 返回索引位置 
		} 
	} 
	return -1;
}
