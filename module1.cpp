#include "framework.h"
#include "module1.h"

static std::wstring line;

static INT_PTR CALLBACK Work1(HWND hDlg, UINT iMessage, WPARAM wParam, LPARAM lParam) {

	switch (iMessage) {

	case WM_COMMAND:

		if (LOWORD(wParam) == IDOK) {

			wchar_t szText[256] = {};
			GetDlgItemText(hDlg, IDC_EDIT1, szText, 256);
			line = std::wstring(szText);

			EndDialog(hDlg, 1);
		}
		break;

	case WM_CLOSE:
		EndDialog(hDlg, IDCANCEL);
		break;
	}

	return 0;
}

std::wstring dlg1(HINSTANCE g_hInstance, HWND hWnd) {

	DialogBoxW(g_hInstance, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, Work1);
	return line.c_str();
}