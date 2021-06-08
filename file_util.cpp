// �ļ�����
#include "file_util.h"
// ���û���Ϣ
bool read_users(USERS *p_users){
	char buffer[DIR_LEN_MAX + 1];				// ջ�������ڴ�ռ䣬���ڴ�������ļ���·���������ļ�λ�ڳ���ĸ�Ŀ¼�� 
	if (_getcwd(buffer,DIR_LEN_MAX) == NULL)	// ��õ�ǰ�����·��������ֵ��NULLʱ��ִ�гɹ� 
		return false;
	strcat(buffer,"\\users.dat");				// ���������ļ�������·��

	FILE* fp;									// �ļ�ָ�� 
	if((fp = fopen(buffer, "rb")) == NULL)		// �Զ����ƶ�������ʽ���ļ������ļ������ڣ�fopen��������NULL 
		return false;

	//���ļ�
	int record_count = 0;
	fread(&record_count, sizeof(int),1,fp);		// ���ļ��ж�4���ֽڣ� 
	if (feof(fp)){								// ����ļ���ĩβ�����ļ��������ݣ���ر��ļ��󷵻� 
		fclose(fp);
		return false;
	}

	if (record_count > USER_NUM_MAX)			// ����ļ��д�ŵ��û���Ϣ������USER_NUM_MAX����ֻ��ȡUSER_NUM_MAX���û���Ϣ 
		record_count = USER_NUM_MAX;

	p_users->length = 0;									// ��ʼ��p_users 
	for (int i = 0; i < record_count; i ++){				// ���ļ��ж� record_count�� 
		fread(&p_users->users[i], sizeof(USER), 1, fp);		// ÿ�ζ� sizeof(USER)�ֽڵ����ݣ���׷�ӵ�p_users 
		p_users->length ++;		
	}

	fclose(fp);			// �ر��ļ� 
	return true;
}

// д�û���Ϣ
bool write_users(USERS users){

	char buffer[DIR_LEN_MAX + 1];						// ��ջ�������ڴ�ռ䣬���ڴ�������ļ���·���������ļ�λ�ڳ���ĸ�Ŀ¼�� 
	if (_getcwd(buffer,DIR_LEN_MAX) == NULL)			// ��õ�ǰ�����·��������ֵ��NULLʱ��ִ�гɹ�
		return false;
	strcat(buffer,"\\users.dat");						// ���������ļ�������·��

	FILE* fp;											// �ļ�ָ�� 
	if((fp = fopen(buffer, "wb")) == NULL)				// �Զ�����д������ʽ���ļ������ļ������ڣ���ᴴ��һ�����ļ���������ʧ�ܣ�����NULL 
		return false;

	fwrite(&users.length,sizeof(int),1,fp);				// �ļ��û���д���ļ�����ʼλ�� 
	for (int i = 0; i < users.length; i ++)				// ���ļ������� users.length��
		fwrite(&users.users[i], sizeof(USER), 1, fp);	// ÿ��дһ���û�����Ϣ��ÿ��д�������ļ���ĩβ׷�� 

	fclose(fp);											// �ر��ļ� 
	return true;
}


// ��������Ϣ
bool read_dprts(DEPARTMENTS *p_dprts){
	char buffer[DIR_LEN_MAX + 1];				// ջ�������ڴ�ռ䣬���ڴ�������ļ���·���������ļ�λ�ڳ���ĸ�Ŀ¼�� 
	if (_getcwd(buffer,DIR_LEN_MAX) == NULL)	// ��õ�ǰ�����·��������ֵ��NULLʱ��ִ�гɹ� 
		return false;
	strcat(buffer,"\\dprts.dat");				// ���������ļ�������·��

	FILE* fp;									// �ļ�ָ�� 
	if((fp = fopen(buffer, "rb")) == NULL)		// �Զ����ƶ�������ʽ���ļ������ļ������ڣ�fopen��������NULL 
		return false;

	//���ļ�
	int record_count = 0;
	fread(&record_count, sizeof(int),1,fp);		// ���ļ��ж�4���ֽڣ� 
	if (feof(fp)){								// ����ļ���ĩβ�����ļ��������ݣ���ر��ļ��󷵻� 
		fclose(fp);
		return false;
	}

	if (record_count > DEPART_NUM_MAX)			// ����ļ��д�ŵ��û���Ϣ������USER_NUM_MAX����ֻ��ȡUSER_NUM_MAX���û���Ϣ 
		record_count = DEPART_NUM_MAX;

	p_dprts->length = 0;									// ��ʼ��p_users 
	for (int i = 0; i < record_count; i ++){				// ���ļ��ж� record_count�� 
		fread(&p_dprts->departments[i], sizeof(DEPARTMENT), 1, fp);		// ÿ�ζ� sizeof(DEPARTMENT)�ֽڵ����ݣ���׷�ӵ�p_dprts
		p_dprts->length ++;		
	}

	fclose(fp);			// �ر��ļ� 
	return true;
}

// д������Ϣ
bool write_dprts(DEPARTMENTS dprts){

	char buffer[DIR_LEN_MAX + 1];						// ��ջ�������ڴ�ռ䣬���ڴ�������ļ���·���������ļ�λ�ڳ���ĸ�Ŀ¼�� 
	if (_getcwd(buffer,DIR_LEN_MAX) == NULL)			// ��õ�ǰ�����·��������ֵ��NULLʱ��ִ�гɹ�
		return false;
	strcat(buffer,"\\dprts.dat");						// ���������ļ�������·��

	FILE* fp;											// �ļ�ָ�� 
	if((fp = fopen(buffer, "wb")) == NULL)				// �Զ�����д������ʽ���ļ������ļ������ڣ���ᴴ��һ�����ļ���������ʧ�ܣ�����NULL 
		return false;

	fwrite(&dprts.length,sizeof(int),1,fp);				// �ļ�������д���ļ�����ʼλ�� 
	for (int i = 0; i < dprts.length; i ++)				// ���ļ������� users.length��
		fwrite(&dprts.departments[i], sizeof(DEPARTMENT), 1, fp);	// ÿ��дһ���û�����Ϣ��ÿ��д�������ļ���ĩβ׷�� 
		
	fclose(fp);											// �ر��ļ� 
	return true;
}
