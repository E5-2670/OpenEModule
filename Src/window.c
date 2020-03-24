#include "../Include/window.h"

BOOL Window_Redraw(HWND hWnd, BOOL bClearBackground)
{
	return InvalidateRect(hWnd,NULL,bClearBackground);
}

LONG Window_HideTaskbarIcon(HWND hWnd)
{
	//SetLastError(0);
	return SetWindowLong(hWnd,-8,GetDesktopWindow());
}

BOOL Window_Response(HWND hWnd)
{
	return SendMessageTimeout(hWnd, NULL, NULL, NULL,SMTO_ABORTIFHUNG,128,NULL);
}

BOOL Window_GetCaretPos(LPPOINT lpPoint)
{
	return GetCaretPos(lpPoint);
}


LPTSTR Window_GetClassName(HWND hWnd)
{
	LPTSTR lpClassName = LocalAlloc(LMEM_ZEROINIT, 50);
	if (GetClassName(hWnd, lpClassName, 50))
		return lpClassName;
	else
		return NULL;
}

void Window_LoopClose(LPTSTR lpClassName, LPTSTR lpWindowName)
{
	HWND hWnd;
	while (hWnd = FindWindow(lpClassName, lpWindowName))
	{
		PostMessage(hWnd, 16, 0, 0);
	}
}

HWND Window_SetParent(HWND hWndChild, HWND hWndNewParent)
{
	return SetParent(hWndChild, hWndNewParent);
}

BOOL Window_EmbedDesktop(HWND hWnd)
{
	RECT rect;
	HWND hWndNewParent = SetParent(hWnd, NULL);
	GetWindowRect(hWnd, &rect);
	MoveWindow(hWnd,rect.left, rect.top, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), TRUE);
	return hWndNewParent;
}

BOOL Window_FullScreen(HWND hWnd)
{
	RECT rect;
	GetWindowRect(hWnd, &rect);
	DWORD width = GetSystemMetrics(SM_CXSCREEN) - rect.left + rect.right - GetSystemMetrics(SM_CXSCREEN);
	DWORD height = GetSystemMetrics(SM_CYSCREEN) - rect.top + rect.bottom - GetSystemMetrics(SM_CYSCREEN);
	if ((width > (GetSystemMetrics(SM_CXSCREEN) - 50)) && (height > (GetSystemMetrics(SM_CYSCREEN) - 50)))
		return TRUE;
	else
		return FALSE;
}

BOOL Window_GetCursorPos(HWND hWnd,PRECT pRect)
{
	DWORD idThread;
	GUITHREADINFO gui;
	gui.cbSize = 48;
	if (hWnd == NULL)
		idThread = GetCurrentThreadId();
	else
		idThread = GetWindowThreadProcessId(hWnd, NULL);
	gui.cbSize = sizeof(GUITHREADINFO);
	BOOL bRet = GetGUIThreadInfo(idThread, &gui);
	pRect->left = gui.rcCaret.left;
	pRect->top = gui.rcCaret.top;
	pRect->right = gui.rcCaret.right;
	pRect->bottom = gui.rcCaret.bottom;
	return bRet;
}

BOOL Window_InScreen(HWND hWnd, BOOL bAutoCorrection)
{
	RECT rect;
	GetWindowRect(hWnd, &rect);
	if (rect.left < 0 || rect.top < 0 || rect.left > GetSystemMetrics(SM_CXSCREEN) || rect.top > GetSystemMetrics(SM_CYSCREEN))
	{
		if (bAutoCorrection)
			MoveWindow(hWnd, 50, 50, rect.right - rect.left, rect.bottom - rect.top, TRUE);
		return FALSE;
	}
	return TRUE;

}

BOOL CALLBACK EnumChildProc(HWND hwnd, LPARAM lParam);
int Window_EnumChildEx(HWND hWndParent, HWND** phWndChild, LPCTSTR ClassName)
{
	DWORD nNum = 0;
	if (hWndParent == 0)
		return 0;
	//申请内存存放参数
	void* pMem = LocalAlloc(LMEM_ZEROINIT, 12);
	if (pMem == NULL)
		return -1;
	*phWndChild = LocalAlloc(LMEM_ZEROINIT, 500 * sizeof(HWND));

	if (phWndChild == NULL)
	{
		LocalFree(pMem);
		return -1;
	}
	*((DWORD*)pMem) = 0;				//数量
	*((HWND*)pMem + 1) = *phWndChild;		//结果指针
	*((LPCTSTR*)pMem + 8) = ClassName;	//过滤类名
	EnumChildWindows(hWndParent, (WNDENUMPROC)EnumChildProc, pMem);
	nNum = *((DWORD*)pMem);
	LocalFree(pMem);					//释放参数内存
	return nNum;


}

BOOL CALLBACK EnumChildProc(HWND hwnd, LPARAM lParam)
{
	//LPCTSTR ClassName = Window_GetClassName(hWndParent);//窗口类名
	//LPCTSTR ClassName2 = *((LPCTSTR*)lParam + 4);//过滤类名

	if (*((LPCTSTR*)lParam + 8) == NULL)
	{
		*(*((HWND**)lParam + 1) + *((int*)lParam)) = hwnd;
		*((int*)lParam) += 1;
	}
	else
	{
		if (!strcmp(*((LPCTSTR*)lParam + 8), Window_GetClassName(hwnd)))
		{
			*(*((HWND**)lParam + 1) + *((int*)lParam)) = hwnd;
			*((int*)lParam) += 1;
		}
	}
	
	return TRUE;

}


int Window_GetDlgCtrlID(HWND hWnd)
{
	return GetDlgCtrlID(hWnd);
}

int Window_GetDlgItem(HWND hDlg,int nIDDlgItem)
{
	return GetDlgItem(hDlg,nIDDlgItem);
}

HANDLE Window_GetThreadHandle(HWND hWnd)
{
	return OpenThread(2032639, FALSE, GetWindowThreadProcessId(hWnd, NULL));
}

BOOL Window_SetTransparentColor(HWND hWnd,COLORREF crKey)
{
	SetWindowLong(hWnd, -20, 524288);
	return SetLayeredWindowAttributes(hWnd, crKey, 255, 1);

}


HWND Window_SetActive(HWND hWnd)
{
	//关键API的使用::AttachThreadInput，这个API是连接两个线程的，使其共享输入焦点，键盘状态等等。
	AttachThreadInput(GetWindowThreadProcessId(hWnd, 0), GetCurrentThreadId(), TRUE);
	HWND hWndRet = SetActiveWindow(hWnd);
	AttachThreadInput(GetWindowThreadProcessId(hWnd, 0), GetCurrentThreadId(), FALSE);
	return hWndRet;
}

BOOL Window_OpenIcon(HWND hWnd)
{
	return (OpenIcon(hWnd));
}

BOOL Window_Stick(HWND hWnd,BOOL Active)
{
	if (Active)
		Active = 0;
	else
		Active = SWP_NOACTIVATE;

	return SetWindowPos(hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | Active);
}

BOOL Window_Close(HWND hWnd)
{
	if (PostMessage(hWnd, 16, 0, 0))
	{
		return !IsWindow(hWnd);
	}
	else
	{
		return FALSE;
	}
}

int Window_FindEx(HWND hWndParent,HWND** phWndChild,LPCTSTR lpszClass,LPCTSTR lpszWindow)
{
	DWORD nNum = 0;
	*phWndChild = LocalAlloc(LMEM_ZEROINIT, 500 * sizeof(HWND));
	if (phWndChild == NULL)
		return -1;
	
	HWND hWnd = FindWindowEx(hWndParent, NULL, lpszClass, lpszWindow);

	while (hWnd)
	{
		*(*(HWND**)phWndChild + nNum) = hWnd;
		nNum++;
		hWnd = FindWindowEx(hWndParent, hWnd, lpszClass, lpszWindow);
	}
	return nNum;
}

BOOL Window_Flash(HWND hWnd, BOOL bInvert)
{
	return FlashWindow(hWnd, bInvert);
}

BOOL Window_FlashEx(HWND hWnd, PFLASHWINFO pfwi)
{
	return FlashWindowEx(hWnd, pfwi);
}
