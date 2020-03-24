#pragma once
#include <windows.h>

/*
函数名:Window_Redraw (窗口_重画)
功能:重画目标窗口
参数:hWnd 要重画的窗口句柄
	bClearBackground 是否清除背景
返回值:非零表示成功，零表示失败
*/
#ifndef DLL
BOOL Window_Redraw(HWND hWnd, BOOL bClearBackground);
#else
__declspec(dllexport) BOOL Window_Redraw(HWND hWnd, BOOL bClearBackground);
#endif

/*
函数名:Window_HideTaskbarIcon (窗口_隐藏任务按钮)
功能:隐藏指定窗口在任务栏的图标
参数 : hWnd 要隐藏图标的窗口句柄(必须为有任务栏图标的窗口)
返回值 : 非零表示成功，零表示失败
*/
#ifndef DLL
LONG Window_HideTaskbarIcon(HWND hWnd);
#else
__declspec(dllexport) LONG Window_HideTaskbarIcon(HWND hWnd);
#endif

/*
函数名:Window_Response (窗口_是否响应)
功能:检测窗口是否有效且能及时响应
参数 : hWnd 要检测的窗口句柄
返回值 : BOOL
*/
#ifndef DLL
BOOL Window_Response(HWND hWnd);
#else
__declspec(dllexport) BOOL Window_Response(HWND hWnd);
#endif

/*
函数名:Window_GetCaretPos (窗口_取光标坐标)
功能:将插入标记的位置(按客户区坐标)信息拷贝到指定的POINT结构中,
如果应用程序从不拥有插入符号的线程中调用GetCaretPos，则GetCaretPos失败,错误值为ERROR_ACCESS_DENIED。
参数 : lpPoint 传出的结构指针
返回值 : BOOL
*/
#ifndef DLL
BOOL Window_GetCaretPos(LPPOINT lpPoint);
#else
__declspec(dllexport) BOOL Window_GetCaretPos(LPPOINT lpPoint);
#endif

/*
函数名:Window_EnumChildEx (窗口_枚举所有子窗口EX)
功能:枚举指定句柄下的所有子窗口句柄,将符合条件的子窗口句柄传回给调用者
使用后请手动释放 phWndChild
参数 :	hWndParent 父窗口的句柄，其子窗口将被枚举，如果此参数为NULL，则此函数等效于EnumWindows。
		phWndChild 返回的子窗口句柄指针，应声明一个HWND*指针(无需开辟空间)，传入该指针的地址
		ClassName  要过滤的类名，如果此参数为NULL，则返回所有可能的结果
返回值 : 成功返回子窗口句柄数目,内部内存分配失败返回-1(一般不会出现这种情况)
*/
#ifndef DLL
int Window_EnumChildEx(HWND hWndParent, HWND** phWndChild, LPCTSTR ClassName);
#else
__declspec(dllexport) int Window_EnumChildEx(HWND hWndParent, HWND** phWndChild, LPCTSTR ClassName);
#endif

/*
函数名:Window_GetClassName (窗口_取类名)
功能:取指定窗口句柄的窗口类名
参数 : hWnd 要取类名的窗口句柄
返回值 : 成功返回字符串指针,失败返回NULL
*/

#ifndef DLL
LPTSTR Window_GetClassName(HWND hWnd);
#else
__declspec(dllexport) LPTSTR Window_GetClassName(HWND hWnd);
#endif

/*
函数名:Window_LoopClose (窗口_循环关闭)
功能:循环关闭符合条件的窗口
参数:	lpClassName 窗口类名(可空)
		lpWindowName 窗口标题(可空)
返回值: 无
*/
#ifndef DLL
void Window_LoopClose(LPTSTR lpClassName, LPTSTR lpWindowName);
#else
__declspec(dllexport) void Window_LoopClose(LPTSTR lpClassName, LPTSTR lpWindowName);
#endif

/*
函数名:Window_SetParent (窗口_置父)
功能:指定一个窗口的新父
参数:	hWndChild 子窗口的句柄
		hWndNewParent hWndChild的新父
返回值 : 成功返回前一个父窗口的句柄,失败返回NULL
*/
#ifndef DLL
HWND Window_SetParent(HWND hWndChild, HWND hWndNewParent);
#else
__declspec(dllexport) HWND Window_SetParent(HWND hWndChild, HWND hWndNewParent);
#endif

/*
函数名:Window_EmbedDesktop (窗口_嵌入桌面)
功能:将一个窗口嵌入桌面,并设置为屏幕大小
参数:	hWnd 要嵌入桌面的窗口句柄
返回值 : 成功返回桌面句柄,失败返回NULL
*/
#ifndef DLL
BOOL Window_EmbedDesktop(HWND hWnd);
#else
__declspec(dllexport) BOOL Window_EmbedDesktop(HWND hWnd);
#endif

/*
函数名:Window_FullScreen (窗口_是否全屏)
功能:检测一个窗口是否覆盖了整个屏幕区域
参数:	hWnd 要检测的窗口句柄
返回值 : 逻辑型
*/
#ifndef DLL
BOOL Window_FullScreen(HWND hWnd);
#else
__declspec(dllexport) BOOL Window_FullScreen(HWND hWnd);
#endif

/*
函数名:Window_GetCursorPos (窗口_取光标位置)
功能:取以客户端坐标表示的插入符的边界矩形
	使用该命令时,需要保证被取光标位置的编辑框 [拥有输入焦点] 否则命令将会失败
参数:	hWnd 要检测的窗口句柄
		pRect 光标矩形,left为x,top为y
返回值 : 逻辑型
*/
#ifndef DLL
BOOL Window_GetCursorPos(HWND hWnd,PRECT pRect);
#else
__declspec(dllexport) BOOL Window_GetCursorPos(HWND hWnd,PRECT pRect);
#endif

/*
函数名:Window_InScreen (窗口_是否在屏幕内) !!!自动校正貌似存在问题
功能:检测指定窗口是否在屏幕内
参数:	hWnd 要检测的窗口句柄
		bAutoCorrection 是否自动校正
返回值 : 逻辑型
*/
#ifndef DLL
BOOL Window_InScreen(HWND hWnd, BOOL bAutoCorrection);
#else
__declspec(dllexport) BOOL Window_InScreen(HWND hWnd, BOOL bAutoCorrection);
#endif


/*
函数名:Window_GetDlgCtrlID (窗口_取控件ID)
功能:根据窗口句柄取出窗口控件的ID
参数:	hWnd 控件句柄
返回值 : 成功返回控件ID,失败返回0
*/
#ifndef DLL
int Window_GetDlgCtrlID(HWND hWnd);
#else
__declspec(dllexport) int Window_GetDlgCtrlID(HWND hWnd);
#endif


/*
函数名:Window_GetDlgItem (窗口_控件ID取句柄)
功能:在指定的对话框中检索控件的句柄
参数:	hWnd 控件句柄
返回值 : 成功返回指定控件的窗口句柄,失败返回NULL
*/
#ifndef DLL
int Window_GetDlgItem(HWND hDlg, int nIDDlgItem);
#else
__declspec(dllexport) int Window_GetDlgItem(HWND hDlg, int nIDDlgItem);
#endif

/*
函数名:Window_GetThreadHandle (窗口_句柄取线程句柄)
功能:打开目标窗口线程,取得伪句柄,用完请手动关闭
参数:	hWnd 要打开线程的窗口句柄
返回值 : 成功返回线程句柄,失败返回NULL
*/
#ifndef DLL
HANDLE Window_GetThreadHandle(HWND hWnd);
#else
__declspec(dllexport) HANDLE Window_GetThreadHandle(HWND hWnd);
#endif

/*
函数名:Window_SetTransparentColor (窗口_置透明颜色)
功能:透明窗口指定的底色
参数:	hWnd 要置透明的窗口句柄
返回值 : 逻辑型
*/
#ifndef DLL
BOOL Window_SetTransparentColor(HWND hWnd, COLORREF crKey);
#else
__declspec(dllexport) BOOL Window_SetTransparentColor(HWND hWnd, COLORREF crKey);
#endif

/*
函数名:Window_SetActive (窗口_激活)
功能:激活指定窗口
参数:	hWnd 要激活的窗口句柄
返回值 : 成功返回原先活动窗口的句柄,失败返回NULL
*/
#ifndef DLL
HWND Window_SetActive(HWND hWnd);
#else
__declspec(dllexport) HWND Window_SetActive(HWND hWnd);
#endif

/*
函数名:Window_OpenIcon (窗口_还原)
功能:将最小化的(图标)窗口恢复到其先前的大小和位置,然后激活窗口
参数:	hWnd 要还原的窗口句柄
返回值 : 逻辑型
*/
#ifndef DLL
BOOL Window_OpenIcon(HWND hWnd);
#else
__declspec(dllexport) BOOL Window_OpenIcon(HWND hWnd);
#endif

/*
函数名:Window_Stick (窗口_置顶) !!!测试好像无效果
功能:设置窗口在最顶端
参数:	hWnd 要置顶的窗口句柄
返回值 : 逻辑型
*/
#ifndef DLL
BOOL Window_Stick(HWND hWnd, BOOL Active);
#else
__declspec(dllexport) BOOL Window_Stick(HWND hWnd, BOOL Active);
#endif

/*
函数名:Window_Close (窗口_关闭)
功能:通过发送消息的方式关闭窗口
参数:	hWnd 要关闭的窗口句柄
返回值 : 成功返回TRUE，窗口句柄无效或失败返回FALSE
*/
#ifndef DLL
BOOL Window_Close(HWND hWnd);
#else
__declspec(dllexport) BOOL Window_Close(HWND hWnd);
#endif



/*
函数名:Window_FindEx (窗口_按类名枚举)
功能:封装了FindWindowEx函数，与精易模块有一定区别
参数:	hWndParent 要搜索其子窗口的父窗口的句柄。如果hwndParent为NULL，则该函数使用桌面窗口作为父窗口。
		phWndChild 返回的子窗口句柄指针，应声明一个HWND*指针(无需开辟空间)，传入该指针的地址
		lpszClass  窗口类名，不可以为NULL
		lpszWindow 窗口标题，如果此参数为NULL，则所有窗口名称均匹配。
返回值 : 成功返回TRUE，窗口句柄无效或失败返回FALSE
*/
#ifndef DLL
int Window_FindEx(HWND hWndParent, HWND** phWndChild, LPCTSTR lpszClass, LPCTSTR lpszWindow);
#else
__declspec(dllexport) int Window_FindEx(HWND hWndParent, HWND** phWndChild, LPCTSTR lpszClass, LPCTSTR lpszWindow);
#endif

/*
函数名:Window_FindEx (窗口_闪动)
功能:闪烁指定的窗口一次。它不会更改窗口的活动状态。
参数:	hWnd 要闪动的窗口句柄
		bInvert 如果此参数为TRUE，则窗口从一种状态闪烁到另一种状态。如果为FALSE，则窗口将返回其原始状态（活动或不活动）。
当最小化应用程序且此参数为TRUE时，任务栏窗口按钮将闪烁活动/不活动。如果为FALSE，则任务栏窗口按钮将不活动地闪烁，这意味着它不会更改颜色。
它会闪烁，就好像正在重绘一样，但不会为用户提供视觉上的反转提示。
返回值 : 返回值指定在调用FlashWindow函数之前窗口的状态 。如果在调用之前将窗口标题绘制为活动窗口，则返回值为非零。否则，返回值为零。
*/

#ifndef DLL
BOOL Window_Flash(HWND hWnd, BOOL bInvert);
#else
__declspec(dllexport) BOOL Window_Flash(HWND hWnd, BOOL bInvert);
#endif




