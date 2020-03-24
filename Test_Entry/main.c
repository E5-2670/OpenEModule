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

//入口点
int main()
{
	//不要修改此处代码
#ifdef _DEBUG
	Debug();
#endif
	return 0;
}


//请在这里输入测试代码
#ifdef _DEBUG
void Debug()
{
	/* 枚举子窗口EX例程
	HWND* arrhWnd = NULL;
	DWORD nNum = 0;
	nNum = Window_EnumChildEx((HWND)659458, &arrhWnd, TEXT("Button"));
	printf("返回结果数量:%d \n", nNum);
	for (int i = 0; i < nNum; i++)
	{
		printf("%d\n", arrhWnd[i]);
	}

	LocalFree(arrhWnd);
	*/

	/*窗口_按类名枚举例程
	HWND* arrhWnd = NULL;
	DWORD nNum = 0;
	nNum = Window_FindEx(NULL, &arrhWnd, TEXT("#32770"), NULL);
	printf("返回结果数量:%d \n", nNum);

	for (int i = 0; i < nNum; i++)
	{
		printf("%d\n", arrhWnd[i]);
	}
	*/

	system("pause");

}
#endif