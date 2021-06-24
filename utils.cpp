#include "utils.h"

//�ı�������ɫ
void color(short x)
{
    if(x>=0 && x<=15)//������0-15�ķ�Χ��ɫ
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
    else
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);  //Ĭ�ϵ���ɫ��ɫ
}
// gbk����ת��Ϊutf8����
void gbk_to_utf8(char *word)
{

    //�������볤�ȣ����ַ����ȣ�utf-8����
    int  in_size,wide_size,utf8_size;

    //������ַ�����utf-8�ַ���
    wchar_t * wide_string;
    char * utf8_string;

    //��������ֵ����ȡ�䳤��
    char input_string[25]={0};
    strcpy(input_string, word);
    in_size= strlen(input_string);


    /*ӳ��һ���ַ�����һ�����ַ���unicode�����ַ������ɸú���ӳ����ַ���û��Ҫ�Ƕ��ֽ��ַ��顣
       CP_ACP��ANSI����ҳ����������Windows����ϵͳ�У�ANSI ������� GBK ���룩*/
    //�Ȼ�ȡ���ַ������Ȳ�����������ʵ��ִֵ�к���
    wide_size=MultiByteToWideChar(CP_ACP, 0, input_string, in_size, NULL, 0);
    wide_string = (wchar_t * ) malloc(wide_size*sizeof(wchar_t));
    MultiByteToWideChar(CP_ACP, 0, input_string, in_size, wide_string, wide_size);


    /*�ѿ��ַ���ת����ָ�����µ��ַ�������ANSI��UTF8�ȣ����ַ��������Ƕ��ֽ��ַ�����
       CP_UTF8��ʹ��UTF-8ת��*/
    utf8_size = WideCharToMultiByte(CP_UTF8, 0, wide_string, wide_size, NULL, 0, NULL, NULL);
    utf8_string = (char * ) malloc(utf8_size);
    WideCharToMultiByte(CP_UTF8, 0, wide_string, wide_size, utf8_string, utf8_size, NULL, NULL);


    printf("ת��ǰ��%s \n", input_string);
    printf("ת����%s",utf8_string);

    free(wide_string);
    free(utf8_string);

}
// �������ͱ���
int input_int(char *info,int &data)
{
	printf("\t\t������%s��",info);
	fflush(stdin);
	scanf("%d",&data);
	return 1;
}

// �����ַ��ͱ���
int input_str(char *info,char *data)
{
	printf("\t\t������%s��",info);
	fflush(stdin);
	scanf("%s",data);
	return 1;
}
