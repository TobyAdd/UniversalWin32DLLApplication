#include <windows.h>
#define GAME_WINDOW "Geometry Dash"
#define HMENU_EXIT 1
#define HMENU_MESSAGEBOX 2
#define HMENU_ABOUT 3
#define BUTTON_EXAMPLE 4
#define CHECKBOX_TOGGLE 5

HINSTANCE HModule;
HWND WNDHWND;
HWND GameHWND;
HWND CheckBox1;

LRESULT CALLBACK DLLWindowProc(HWND, UINT, WPARAM, LPARAM);

BOOL RegisterWindowClass(wchar_t szClassName[]) {
    WNDCLASSEX wc;
    wc.hInstance = HModule;
	wc.lpszClassName = (LPCSTR)"MainClass";
    wc.lpszClassName = (LPCSTR)szClassName;
    wc.lpfnWndProc = DLLWindowProc;
    wc.style = CS_DBLCLKS;
    wc.cbSize = sizeof(WNDCLASSEX);
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.lpszMenuName = NULL;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hbrBackground = (HBRUSH)COLOR_BACKGROUND;
    if (!RegisterClassEx (&wc))
		return 0;
}

HMENU CreateWindowMenu() {
	HMENU hMenu;
	hMenu = CreateMenu();
	HMENU hMenuPopup;
    if(hMenu==NULL)
        return FALSE;
    hMenuPopup = CreatePopupMenu();
	AppendMenu(hMenuPopup, MF_STRING, HMENU_EXIT, (LPCSTR)"Exit");
    AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hMenuPopup, (LPCSTR)"File"); 

    hMenuPopup = CreatePopupMenu();
    AppendMenu(hMenuPopup, MF_STRING, HMENU_ABOUT, (LPCSTR)"About"); 
    AppendMenu(hMenu, MF_POPUP, (UINT_PTR)hMenuPopup, (LPCSTR)"Help"); 
	return hMenu;
}

void AddWidgets(HWND hwnd) {
    CreateWindowA("static", "Hello world! (Text)", WS_VISIBLE | WS_CHILD, 5, 5, 140, 20, hwnd, NULL, NULL, NULL);
    CreateWindowA("edit", "Some text", WS_VISIBLE | WS_CHILD, 5, 30, 200, 20, hwnd, NULL, NULL, NULL);
    CreateWindowA("button", "Example Button", WS_VISIBLE | WS_CHILD | ES_CENTER, 5, 55, 300, 60, hwnd, (HMENU)BUTTON_EXAMPLE, NULL, NULL);
    CheckBox1 = CreateWindowA("button", "Checkbox", BS_CHECKBOX | WS_VISIBLE | WS_CHILD | BS_AUTOCHECKBOX, 5, 120, 120, 20, hwnd, (HMENU)CHECKBOX_TOGGLE, NULL, NULL);
}


