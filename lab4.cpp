#include "lab4.h";
#include "module1.h"; 
#include "module2.h"; 

HWND hWnd, button_1, button_2, g_static1, g_static2;

HINSTANCE g_hInstance;

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_COMMAND:
        if (HIWORD(wParam) == BN_CLICKED && (HWND)lParam == button_1) {

            SetWindowText(g_static1, dlg1(g_hInstance, hWnd).c_str());
        }
        if (HIWORD(wParam) == BN_CLICKED && (HWND)lParam == button_2) {

            SetWindowText(g_static2, dlg2(g_hInstance, hWnd).c_str());
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }
    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
    g_hInstance = hInstance;

    WNDCLASS wc = { };
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = L"mainMenu";

    RegisterClass(&wc);

    hWnd = CreateWindowEx(WS_EX_LEFT, L"mainMenu", L"main task", WS_OVERLAPPEDWINDOW, 500, 500, 300, 150, NULL, NULL, hInstance, NULL);
    button_1 = CreateWindowEx(0, L"BUTTON", L"Task 0", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 10, 10, 50, 20, hWnd, NULL, hInstance, NULL);
    button_2 = CreateWindowEx(0, L"BUTTON", L"Task 1", WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON, 180, 10, 50, 20, hWnd, NULL, hInstance, NULL);
    g_static1 = CreateWindowEx(0, L"Static", L"", WS_CHILD | WS_VISIBLE, 10, 35, 70, 20, hWnd, NULL, hInstance, NULL);
    g_static2 = CreateWindowEx(0, L"Static", L"", WS_CHILD | WS_VISIBLE, 180, 35, 70, 20, hWnd, NULL, hInstance, NULL);

    ShowWindow(hWnd, nCmdShow);

    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
