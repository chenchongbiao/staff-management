// 文件访问
#include "file_util.h"
// 读用户信息
bool read_users(USERS *p_users){
	char buffer[DIR_LEN_MAX + 1];				// 栈中申请内存空间，用于存放数据文件的路径，数据文件位于程序的根目录下 
	if (_getcwd(buffer,DIR_LEN_MAX) == NULL)	// 获得当前程序的路径，函数值非NULL时，执行成功 
		return false;
	strcat(buffer,"\\users.dat");				// 构建数据文件完整的路径

	FILE* fp;									// 文件指针 
	if((fp = fopen(buffer, "rb")) == NULL)		// 以二进制读操作方式打开文件，若文件不存在，fopen函数返回NULL 
		return false;

	//读文件
	int record_count = 0;
	fread(&record_count, sizeof(int),1,fp);		// 从文件中读4个字节， 
	if (feof(fp)){								// 如果文件是末尾，即文件中无数据，则关闭文件后返回 
		fclose(fp);
		return false;
	}

	if (record_count > USER_NUM_MAX)			// 如果文件中存放的用户信息数超过USER_NUM_MAX，则只读取USER_NUM_MAX个用户信息 
		record_count = USER_NUM_MAX;

	p_users->length = 0;									// 初始化p_users 
	for (int i = 0; i < record_count; i ++){				// 从文件中读 record_count次 
		fread(&p_users->users[i], sizeof(USER), 1, fp);		// 每次读 sizeof(USER)字节的数据，并追加到p_users 
		p_users->length ++;		
	}

	fclose(fp);			// 关闭文件 
	return true;
}

// 写用户信息
bool write_users(USERS users){

	char buffer[DIR_LEN_MAX + 1];						// 在栈中申请内存空间，用于存放数据文件的路径，数据文件位于程序的根目录下 
	if (_getcwd(buffer,DIR_LEN_MAX) == NULL)			// 获得当前程序的路径，函数值非NULL时，执行成功
		return false;
	strcat(buffer,"\\users.dat");						// 构建数据文件完整的路径

	FILE* fp;											// 文件指针 
	if((fp = fopen(buffer, "wb")) == NULL)				// 以二进制写操作方式打开文件，若文件不存在，则会创建一个空文件，若创建失败，返回NULL 
		return false;

	fwrite(&users.length,sizeof(int),1,fp);				// 文件用户数写入文件的起始位置 
	for (int i = 0; i < users.length; i ++)				// 在文件中依次 users.length次
		fwrite(&users.users[i], sizeof(USER), 1, fp);	// 每次写一个用户的信息，每次写都是在文件的末尾追加 

	fclose(fp);											// 关闭文件 
	return true;
}


// 读部门信息
bool read_dprts(DEPARTMENTS *p_dprts){
	char buffer[DIR_LEN_MAX + 1];				// 栈中申请内存空间，用于存放数据文件的路径，数据文件位于程序的根目录下 
	if (_getcwd(buffer,DIR_LEN_MAX) == NULL)	// 获得当前程序的路径，函数值非NULL时，执行成功 
		return false;
	strcat(buffer,"\\dprts.dat");				// 构建数据文件完整的路径

	FILE* fp;									// 文件指针 
	if((fp = fopen(buffer, "rb")) == NULL)		// 以二进制读操作方式打开文件，若文件不存在，fopen函数返回NULL 
		return false;

	//读文件
	int record_count = 0;
	fread(&record_count, sizeof(int),1,fp);		// 从文件中读4个字节， 
	if (feof(fp)){								// 如果文件是末尾，即文件中无数据，则关闭文件后返回 
		fclose(fp);
		return false;
	}

	if (record_count > DEPART_NUM_MAX)			// 如果文件中存放的用户信息数超过USER_NUM_MAX，则只读取USER_NUM_MAX个用户信息 
		record_count = DEPART_NUM_MAX;

	p_dprts->length = 0;									// 初始化p_users 
	for (int i = 0; i < record_count; i ++){				// 从文件中读 record_count次 
		fread(&p_dprts->departments[i], sizeof(DEPARTMENT), 1, fp);		// 每次读 sizeof(DEPARTMENT)字节的数据，并追加到p_dprts
		p_dprts->length ++;		
	}

	fclose(fp);			// 关闭文件 
	return true;
}

// 写部门信息
bool write_dprts(DEPARTMENTS dprts){

	char buffer[DIR_LEN_MAX + 1];						// 在栈中申请内存空间，用于存放数据文件的路径，数据文件位于程序的根目录下 
	if (_getcwd(buffer,DIR_LEN_MAX) == NULL)			// 获得当前程序的路径，函数值非NULL时，执行成功
		return false;
	strcat(buffer,"\\dprts.dat");						// 构建数据文件完整的路径

	FILE* fp;											// 文件指针 
	if((fp = fopen(buffer, "wb")) == NULL)				// 以二进制写操作方式打开文件，若文件不存在，则会创建一个空文件，若创建失败，返回NULL 
		return false;

	fwrite(&dprts.length,sizeof(int),1,fp);				// 文件部门数写入文件的起始位置 
	for (int i = 0; i < dprts.length; i ++)				// 在文件中依次 users.length次
		fwrite(&dprts.departments[i], sizeof(DEPARTMENT), 1, fp);	// 每次写一个用户的信息，每次写都是在文件的末尾追加 
		
	fclose(fp);											// 关闭文件 
	return true;
}
