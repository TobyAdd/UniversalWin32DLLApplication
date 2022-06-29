#include "dllmain.h"

DWORD WINAPI ThreadProc(LPVOID lpParam) {
    MSG messages;
	RegisterWindowClass((wchar_t*)"MainClass");
	GameHWND = FindWindow(0, GAME_WINDOW);
	WNDHWND = CreateWindowEx(0, (LPCSTR)"MainClass",(LPCSTR)reinterpret_cast<wchar_t*>(lpParam), WS_EX_PALETTEWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 400, 300, GameHWND, CreateWindowMenu(), HModule, NULL);
    ShowWindow(WNDHWND, SW_SHOWNORMAL);
    while (GetMessage (&messages, NULL, 0, 0)) {
		TranslateMessage(&messages);
        DispatchMessage(&messages);
    }
    return 1;
}

LRESULT CALLBACK DLLWindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
    switch (message)
    {
		case WM_COMMAND:
            switch(wParam) {
				case HMENU_EXIT:
				    SendMessage(hwnd, WM_CLOSE, 0, 0);
				break;
				case HMENU_MESSAGEBOX:
				    MessageBoxA(hwnd, "Test", "MessageBox", 0);
				break;
                case HMENU_ABOUT:
				    MessageBoxA(hwnd, "CheatMenu Example by TobyAdd", "About", 0);
				break;
                case BUTTON_EXAMPLE:
				    MessageBoxA(hwnd, "Button clicked", "Test", 0);
				break;
                case CHECKBOX_TOGGLE:
                    if (IsDlgButtonChecked(hwnd, CHECKBOX_TOGGLE))
                    {
                        MessageBox(hwnd, "Checked", "Test",0);
                    } else {
                        MessageBox(hwnd, "Unchecked", "Test",0);
                    }
				break;
				}
            break;
        case WM_CREATE:
            AddWidgets(hwnd);
            break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hwnd, message, wParam, lParam);
    }
    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
	if(ul_reason_for_call == DLL_PROCESS_ATTACH) {
		HModule = hModule;
		CreateThread(0, NULL, ThreadProc, (LPVOID)"Example", NULL, NULL);
	}
	return TRUE;
}