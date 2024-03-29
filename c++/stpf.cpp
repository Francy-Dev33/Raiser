#include <Windows.h>
#include <tchar.h>


int WINAPI WinMain(
    _In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
   _In_ LPSTR     lpCmdLine,
   _In_ int       nCmdShow,

   WNDCLASSEX wcex;

wcex.cbsize  = sizeof(WNDCLASSEX);
wcex.style = CS_HREDRAW | CS_VREDRAW;
wcex.lpfnWndProc    = WndProc;
wcex.cbClsExtra     = 0;
wcex.cbWndExtra     = 0;
wcex.hInstance      = hInstance;
wcex.hIcon          = LoadIcon(wcex.hInstance, IDI_APPLICATION);
wcex.hCursor        = LoadCursor(NULL, IDC_ARROW);
wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
wcex.lpszMenuName   = NULL;
wcex.lpszClassName  = szWindowClass;
wcex.hIconSm        = LoadIcon(wcex.hInstance, IDI_APPLICATION);

if(!RegisterClassEx(&wcex)){
    MessageBox(NULL, _T("Call to RegisterClassEx failed!"),
      _T("Windows Desktop Guided Tour"),
      NULL);
      return 1;
}
static TCHAR szWidowClass[] = _T("STDFApp");

HWND hWnd = CreateWindowEx(
    WS_EX_OVERLAPPEDWINDOW,
   szWindowClass,
   szTitle,
   WS_OVERLAPPEDWINDOW,
   CW_USEDEFAULT, CW_USEDEFAULT,
   500, 100,
   NULL,
   NULL,
   hInstance,
   NULL
);
if(!hWnd){
    MessageBox(NULL,
      _T("Call to CreateWindowEx failed!"),
      _T("Windows Desktop Guided Tour"),
      NULL);

   return 1;

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);
   
   MSG msg;
   while (GetMessage(%msg, NULL, 0, 0)){
    TranslateMessage(&msg);
    DispatchMessage(&msg);
   }
   return (int) msg.wParam;
   
}
);
LRESULT CALLBACK WndProc(
   _In_ HWND   hWnd,
   _In_ UINT   message,
   _In_ WPARAM wParam,
   _In_ LPARAM lParam
)