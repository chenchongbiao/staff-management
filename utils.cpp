#include "utils.h"

//改变字体颜色
void color(short x)
{
    if(x>=0 && x<=15)//参数在0-15的范围颜色
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
    else
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);  //默认的颜色白色
}
// gbk编码转换为utf8编码
void gbk_to_utf8(char *word)
{

    //定义输入长度，宽字符长度，utf-8长度
    int  in_size,wide_size,utf8_size;

    //定义宽字符串与utf-8字符串
    wchar_t * wide_string;
    char * utf8_string;

    //定义输入值并获取其长度
    char input_string[25]={0};
    strcpy(input_string, word);
    in_size= strlen(input_string);


    /*映射一个字符串到一个宽字符（unicode）的字符串。由该函数映射的字符串没必要是多字节字符组。
       CP_ACP：ANSI代码页（简体中文Windows操作系统中，ANSI 编码代表 GBK 编码）*/
    //先获取宽字符串长度并创建，再以实际值执行函数
    wide_size=MultiByteToWideChar(CP_ACP, 0, input_string, in_size, NULL, 0);
    wide_string = (wchar_t * ) malloc(wide_size*sizeof(wchar_t));
    MultiByteToWideChar(CP_ACP, 0, input_string, in_size, wide_string, wide_size);


    /*把宽字符串转换成指定的新的字符串，如ANSI，UTF8等，新字符串不必是多字节字符集。
       CP_UTF8：使用UTF-8转换*/
    utf8_size = WideCharToMultiByte(CP_UTF8, 0, wide_string, wide_size, NULL, 0, NULL, NULL);
    utf8_string = (char * ) malloc(utf8_size);
    WideCharToMultiByte(CP_UTF8, 0, wide_string, wide_size, utf8_string, utf8_size, NULL, NULL);


    printf("转换前：%s \n", input_string);
    printf("转换后：%s",utf8_string);

    free(wide_string);
    free(utf8_string);

}
// 输入整型变量
int input_int(char *info,int &data)
{
	printf("\t\t请输入%s：",info);
	fflush(stdin);
	scanf("%d",&data);
	return 1;
}

// 输入字符型变量
int input_str(char *info,char *data)
{
	printf("\t\t请输入%s：",info);
	fflush(stdin);
	scanf("%s",data);
	return 1;
}
