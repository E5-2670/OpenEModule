/**************************************************************************

Copyright:OpenEModule Team

Author: 

Date:2020-03-21

Description:OpenEModule DeBug Entry

**************************************************************************/

#include <stdio.h>
#include "../Include/window.h"
#pragma comment(lib,"../bin/Win32/Debug/Lib/OpenEModule.lib")



void Debug();

//��ڵ�
int main()
{
	//��Ҫ�޸Ĵ˴�����
#ifdef _DEBUG
	Debug();
#endif
	return 0;
}


//��������������Դ���
#ifdef _DEBUG
void Debug()
{
	/* ö���Ӵ���EX����
	HWND* arrhWnd = NULL;
	DWORD nNum = 0;
	nNum = Window_EnumChildEx((HWND)659458, &arrhWnd, TEXT("Button"));
	printf("���ؽ������:%d \n", nNum);
	for (int i = 0; i < nNum; i++)
	{
		printf("%d\n", arrhWnd[i]);
	}

	LocalFree(arrhWnd);
	*/

	/*����_������ö������
	HWND* arrhWnd = NULL;
	DWORD nNum = 0;
	nNum = Window_FindEx(NULL, &arrhWnd, TEXT("#32770"), NULL);
	printf("���ؽ������:%d \n", nNum);

	for (int i = 0; i < nNum; i++)
	{
		printf("%d\n", arrhWnd[i]);
	}
	*/

	system("pause");

}
#endif