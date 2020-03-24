#pragma once
#include <windows.h>

/*
������:Window_Redraw (����_�ػ�)
����:�ػ�Ŀ�괰��
����:hWnd Ҫ�ػ��Ĵ��ھ��
	bClearBackground �Ƿ��������
����ֵ:�����ʾ�ɹ������ʾʧ��
*/
#ifndef DLL
BOOL Window_Redraw(HWND hWnd, BOOL bClearBackground);
#else
__declspec(dllexport) BOOL Window_Redraw(HWND hWnd, BOOL bClearBackground);
#endif

/*
������:Window_HideTaskbarIcon (����_��������ť)
����:����ָ����������������ͼ��
���� : hWnd Ҫ����ͼ��Ĵ��ھ��(����Ϊ��������ͼ��Ĵ���)
����ֵ : �����ʾ�ɹ������ʾʧ��
*/
#ifndef DLL
LONG Window_HideTaskbarIcon(HWND hWnd);
#else
__declspec(dllexport) LONG Window_HideTaskbarIcon(HWND hWnd);
#endif

/*
������:Window_Response (����_�Ƿ���Ӧ)
����:��ⴰ���Ƿ���Ч���ܼ�ʱ��Ӧ
���� : hWnd Ҫ���Ĵ��ھ��
����ֵ : BOOL
*/
#ifndef DLL
BOOL Window_Response(HWND hWnd);
#else
__declspec(dllexport) BOOL Window_Response(HWND hWnd);
#endif

/*
������:Window_GetCaretPos (����_ȡ�������)
����:�������ǵ�λ��(���ͻ�������)��Ϣ������ָ����POINT�ṹ��,
���Ӧ�ó���Ӳ�ӵ�в�����ŵ��߳��е���GetCaretPos����GetCaretPosʧ��,����ֵΪERROR_ACCESS_DENIED��
���� : lpPoint �����Ľṹָ��
����ֵ : BOOL
*/
#ifndef DLL
BOOL Window_GetCaretPos(LPPOINT lpPoint);
#else
__declspec(dllexport) BOOL Window_GetCaretPos(LPPOINT lpPoint);
#endif

/*
������:Window_EnumChildEx (����_ö�������Ӵ���EX)
����:ö��ָ������µ������Ӵ��ھ��,�������������Ӵ��ھ�����ظ�������
ʹ�ú����ֶ��ͷ� phWndChild
���� :	hWndParent �����ڵľ�������Ӵ��ڽ���ö�٣�����˲���ΪNULL����˺�����Ч��EnumWindows��
		phWndChild ���ص��Ӵ��ھ��ָ�룬Ӧ����һ��HWND*ָ��(���迪�ٿռ�)�������ָ��ĵ�ַ
		ClassName  Ҫ���˵�����������˲���ΪNULL���򷵻����п��ܵĽ��
����ֵ : �ɹ������Ӵ��ھ����Ŀ,�ڲ��ڴ����ʧ�ܷ���-1(һ�㲻������������)
*/
#ifndef DLL
int Window_EnumChildEx(HWND hWndParent, HWND** phWndChild, LPCTSTR ClassName);
#else
__declspec(dllexport) int Window_EnumChildEx(HWND hWndParent, HWND** phWndChild, LPCTSTR ClassName);
#endif

/*
������:Window_GetClassName (����_ȡ����)
����:ȡָ�����ھ���Ĵ�������
���� : hWnd Ҫȡ�����Ĵ��ھ��
����ֵ : �ɹ������ַ���ָ��,ʧ�ܷ���NULL
*/

#ifndef DLL
LPTSTR Window_GetClassName(HWND hWnd);
#else
__declspec(dllexport) LPTSTR Window_GetClassName(HWND hWnd);
#endif

/*
������:Window_LoopClose (����_ѭ���ر�)
����:ѭ���رշ��������Ĵ���
����:	lpClassName ��������(�ɿ�)
		lpWindowName ���ڱ���(�ɿ�)
����ֵ: ��
*/
#ifndef DLL
void Window_LoopClose(LPTSTR lpClassName, LPTSTR lpWindowName);
#else
__declspec(dllexport) void Window_LoopClose(LPTSTR lpClassName, LPTSTR lpWindowName);
#endif

/*
������:Window_SetParent (����_�ø�)
����:ָ��һ�����ڵ��¸�
����:	hWndChild �Ӵ��ڵľ��
		hWndNewParent hWndChild���¸�
����ֵ : �ɹ�����ǰһ�������ڵľ��,ʧ�ܷ���NULL
*/
#ifndef DLL
HWND Window_SetParent(HWND hWndChild, HWND hWndNewParent);
#else
__declspec(dllexport) HWND Window_SetParent(HWND hWndChild, HWND hWndNewParent);
#endif

/*
������:Window_EmbedDesktop (����_Ƕ������)
����:��һ������Ƕ������,������Ϊ��Ļ��С
����:	hWnd ҪǶ������Ĵ��ھ��
����ֵ : �ɹ�����������,ʧ�ܷ���NULL
*/
#ifndef DLL
BOOL Window_EmbedDesktop(HWND hWnd);
#else
__declspec(dllexport) BOOL Window_EmbedDesktop(HWND hWnd);
#endif

/*
������:Window_FullScreen (����_�Ƿ�ȫ��)
����:���һ�������Ƿ񸲸���������Ļ����
����:	hWnd Ҫ���Ĵ��ھ��
����ֵ : �߼���
*/
#ifndef DLL
BOOL Window_FullScreen(HWND hWnd);
#else
__declspec(dllexport) BOOL Window_FullScreen(HWND hWnd);
#endif

/*
������:Window_GetCursorPos (����_ȡ���λ��)
����:ȡ�Կͻ��������ʾ�Ĳ�����ı߽����
	ʹ�ø�����ʱ,��Ҫ��֤��ȡ���λ�õı༭�� [ӵ�����뽹��] ���������ʧ��
����:	hWnd Ҫ���Ĵ��ھ��
		pRect ������,leftΪx,topΪy
����ֵ : �߼���
*/
#ifndef DLL
BOOL Window_GetCursorPos(HWND hWnd,PRECT pRect);
#else
__declspec(dllexport) BOOL Window_GetCursorPos(HWND hWnd,PRECT pRect);
#endif

/*
������:Window_InScreen (����_�Ƿ�����Ļ��) !!!�Զ�У��ò�ƴ�������
����:���ָ�������Ƿ�����Ļ��
����:	hWnd Ҫ���Ĵ��ھ��
		bAutoCorrection �Ƿ��Զ�У��
����ֵ : �߼���
*/
#ifndef DLL
BOOL Window_InScreen(HWND hWnd, BOOL bAutoCorrection);
#else
__declspec(dllexport) BOOL Window_InScreen(HWND hWnd, BOOL bAutoCorrection);
#endif


/*
������:Window_GetDlgCtrlID (����_ȡ�ؼ�ID)
����:���ݴ��ھ��ȡ�����ڿؼ���ID
����:	hWnd �ؼ����
����ֵ : �ɹ����ؿؼ�ID,ʧ�ܷ���0
*/
#ifndef DLL
int Window_GetDlgCtrlID(HWND hWnd);
#else
__declspec(dllexport) int Window_GetDlgCtrlID(HWND hWnd);
#endif


/*
������:Window_GetDlgItem (����_�ؼ�IDȡ���)
����:��ָ���ĶԻ����м����ؼ��ľ��
����:	hWnd �ؼ����
����ֵ : �ɹ�����ָ���ؼ��Ĵ��ھ��,ʧ�ܷ���NULL
*/
#ifndef DLL
int Window_GetDlgItem(HWND hDlg, int nIDDlgItem);
#else
__declspec(dllexport) int Window_GetDlgItem(HWND hDlg, int nIDDlgItem);
#endif

/*
������:Window_GetThreadHandle (����_���ȡ�߳̾��)
����:��Ŀ�괰���߳�,ȡ��α���,�������ֶ��ر�
����:	hWnd Ҫ���̵߳Ĵ��ھ��
����ֵ : �ɹ������߳̾��,ʧ�ܷ���NULL
*/
#ifndef DLL
HANDLE Window_GetThreadHandle(HWND hWnd);
#else
__declspec(dllexport) HANDLE Window_GetThreadHandle(HWND hWnd);
#endif

/*
������:Window_SetTransparentColor (����_��͸����ɫ)
����:͸������ָ���ĵ�ɫ
����:	hWnd Ҫ��͸���Ĵ��ھ��
����ֵ : �߼���
*/
#ifndef DLL
BOOL Window_SetTransparentColor(HWND hWnd, COLORREF crKey);
#else
__declspec(dllexport) BOOL Window_SetTransparentColor(HWND hWnd, COLORREF crKey);
#endif

/*
������:Window_SetActive (����_����)
����:����ָ������
����:	hWnd Ҫ����Ĵ��ھ��
����ֵ : �ɹ�����ԭ�Ȼ���ڵľ��,ʧ�ܷ���NULL
*/
#ifndef DLL
HWND Window_SetActive(HWND hWnd);
#else
__declspec(dllexport) HWND Window_SetActive(HWND hWnd);
#endif

/*
������:Window_OpenIcon (����_��ԭ)
����:����С����(ͼ��)���ڻָ�������ǰ�Ĵ�С��λ��,Ȼ�󼤻��
����:	hWnd Ҫ��ԭ�Ĵ��ھ��
����ֵ : �߼���
*/
#ifndef DLL
BOOL Window_OpenIcon(HWND hWnd);
#else
__declspec(dllexport) BOOL Window_OpenIcon(HWND hWnd);
#endif

/*
������:Window_Stick (����_�ö�) !!!���Ժ�����Ч��
����:���ô��������
����:	hWnd Ҫ�ö��Ĵ��ھ��
����ֵ : �߼���
*/
#ifndef DLL
BOOL Window_Stick(HWND hWnd, BOOL Active);
#else
__declspec(dllexport) BOOL Window_Stick(HWND hWnd, BOOL Active);
#endif

/*
������:Window_Close (����_�ر�)
����:ͨ��������Ϣ�ķ�ʽ�رմ���
����:	hWnd Ҫ�رյĴ��ھ��
����ֵ : �ɹ�����TRUE�����ھ����Ч��ʧ�ܷ���FALSE
*/
#ifndef DLL
BOOL Window_Close(HWND hWnd);
#else
__declspec(dllexport) BOOL Window_Close(HWND hWnd);
#endif



/*
������:Window_FindEx (����_������ö��)
����:��װ��FindWindowEx�������뾫��ģ����һ������
����:	hWndParent Ҫ�������Ӵ��ڵĸ����ڵľ�������hwndParentΪNULL����ú���ʹ�����洰����Ϊ�����ڡ�
		phWndChild ���ص��Ӵ��ھ��ָ�룬Ӧ����һ��HWND*ָ��(���迪�ٿռ�)�������ָ��ĵ�ַ
		lpszClass  ����������������ΪNULL
		lpszWindow ���ڱ��⣬����˲���ΪNULL�������д������ƾ�ƥ�䡣
����ֵ : �ɹ�����TRUE�����ھ����Ч��ʧ�ܷ���FALSE
*/
#ifndef DLL
int Window_FindEx(HWND hWndParent, HWND** phWndChild, LPCTSTR lpszClass, LPCTSTR lpszWindow);
#else
__declspec(dllexport) int Window_FindEx(HWND hWndParent, HWND** phWndChild, LPCTSTR lpszClass, LPCTSTR lpszWindow);
#endif

/*
������:Window_FindEx (����_����)
����:��˸ָ���Ĵ���һ�Ρ���������Ĵ��ڵĻ״̬��
����:	hWnd Ҫ�����Ĵ��ھ��
		bInvert ����˲���ΪTRUE���򴰿ڴ�һ��״̬��˸����һ��״̬�����ΪFALSE���򴰿ڽ�������ԭʼ״̬����򲻻����
����С��Ӧ�ó����Ҵ˲���ΪTRUEʱ�����������ڰ�ť����˸�/��������ΪFALSE�������������ڰ�ť���������˸������ζ�������������ɫ��
������˸���ͺ��������ػ�һ����������Ϊ�û��ṩ�Ӿ��ϵķ�ת��ʾ��
����ֵ : ����ֵָ���ڵ���FlashWindow����֮ǰ���ڵ�״̬ ������ڵ���֮ǰ�����ڱ������Ϊ����ڣ��򷵻�ֵΪ���㡣���򣬷���ֵΪ�㡣
*/

#ifndef DLL
BOOL Window_Flash(HWND hWnd, BOOL bInvert);
#else
__declspec(dllexport) BOOL Window_Flash(HWND hWnd, BOOL bInvert);
#endif



