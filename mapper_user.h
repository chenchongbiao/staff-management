#ifndef __MAPPER_USER_H__
#define __MAPPER_USER_H__ 

///////////////////////////////////添加用户/////////////////////////////////////////////
///////////////////////////////////删除用户/////////////////////////////////////////////
///////////////////////////////////修改用户/////////////////////////////////////////////
int update_user(USERS *p_users,USER user);
//////////////////////////////////查找用户/////////////////////////////////////////////// 

// 通过用户名查找 
int select_user_by_username(USERS users,char *p_username);
#endif
