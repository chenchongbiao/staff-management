#include <string.h>
#include "mapper_user.h"


///////////////////////////////////添加用户/////////////////////////////////////////////
int save_user(USERS *p_users,USER user)
{
	if (p_users->length >= USER_NUM_MAX) // 用户已满 
		return 0; 
	// 添加至线性表结尾
	p_users->users[p_users->length++] = user;
	return 1; 
}
///////////////////////////////////删除用户/////////////////////////////////////////////
///////////////////////////////////修改用户/////////////////////////////////////////////
int update_user(USERS *p_users,USER user)
{
    int index = select_user_by_username(*p_users,user.user_name);
    if (index < 0 || index >= p_users->length)
    	return 0;
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
