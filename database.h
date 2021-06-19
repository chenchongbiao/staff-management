#ifndef __DATABASE_H__
#define __DATABASE_H__

sqlite3 *db = NULL;  						// 数据库连接 
char dbname[] = "staffManagement.db";		// 数据库名称

//int exec_sql(sqlite3 *db,DATABASE *datainfo); 
// notOpen = sqlite3_open(dbname, &db);// 打开数据库 接返回不为0则打开失败 
/*该例程打开一个指向 SQLite 数据库文件的连接，返回一个用于其他 SQLite 程序的数据库连接对象。

如果 filename 参数是 NULL 或 ':memory:'，那么 sqlite3_open() 将会在 RAM 中创建一个内存数据库，

这只会在 session 的有效时间内持续。如果文件名 filename 不为 NULL，那么 sqlite3_open() 将使用这个参数值尝试打开数据库文件。

如果该名称的文件不存在，sqlite3_open() 将创建一个新的命名为该名称的数据库文件并打开。*/

// 创建表语句 
// char *sql = "CREATE TABLE if not exists [student](\
			  [stu_id] VARCHAR(20) NOT NULL DEFAULT NULL, \
			  [name] VARCHAR(20) NOT NULL DEFAULT NULL, \
			  [elec] DOUBLE(3, 1) NOT NULL, \
			  [expe] DOUBLE(3, 1) NOT NULL, \
			  [requ] DOUBLE(3, 1) NOT NULL, \
			  [sum] DOUBLE(3, 1) NOT NULL);";

/* 查询数据表 */
// char *sql = "select * from admin";
// sqlite3_get_table( db , sql , &tableData , &rowCount , &columnCount , &errorInfo ); 
/*SQL 命令由 sql 参数提供，可以由多个 SQL 命令组成。

在这里，第一个参数 sqlite3 是打开的数据库对象，sqlite_callback 是一个回调，data 作为其第一个参数，

errmsg 将被返回用来获取程序生成的任何错误。

sqlite3_exec() 程序解析并执行由 sql 参数所给的每个命令，直到字符串结束或者遇到错误为止。*/	


// sqlite3_close(db); //关闭数据库

/*
该例程关闭之前调用 sqlite3_open() 打开的数据库连接。所有与连接相关的语句都应在连接关闭之前完成。

如果还有查询没有完成，sqlite3_close() 将返回 SQLITE_BUSY 禁止关闭的错误消息。
*/

#endif


