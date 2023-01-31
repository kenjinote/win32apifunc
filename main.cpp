#pragma comment(lib,"comctl32")
#pragma comment(linker, "/opt:nowin98")
#include <windows.h>
#include <commctrl.h>

CHAR szClassName[]="window";
HWND hTree;

LPTSTR szTopItem[] = {TEXT("ウィンドウ") , TEXT("コントロール") , TEXT("リソース"), TEXT("ユーザー入力"),NULL};

LPTSTR szWindowingItem[] = {TEXT("ウィンドウ"),TEXT("ウィンドウ クラス"),TEXT("ウィンドウ ステーション/デスクトップ"),TEXT("ウィンドウ プロシージャ"),TEXT("ウィンドウ プロパティ"),TEXT("ダイアログボックス"),TEXT("タイマー"),TEXT("マルチ ドキュメント インターフェイス"),TEXT("メッセージ/メッセージ キュー"),NULL};
LPTSTR szWindowItem[] = {TEXT("AdjustWindowRect"),TEXT("AdjustWindowRectEx"),TEXT("AllowSetForegroundWindow"),TEXT("AnimateWindow"),TEXT("AnyPopup"),TEXT("ArrangeIconicWindows"),TEXT("BeginDeferWindowPos"),TEXT("BringWindowToTop"),TEXT("CascadeWindows"),TEXT("ChildWindowFromPoint"),TEXT("ChildWindowFromPointEx"),TEXT("CloseWindow"),TEXT("CreateWindow"),TEXT("CreateWindowEx"),TEXT("DeferWindowPos"),TEXT("DestroyWindow"),TEXT("EndDeferWindowPos"),TEXT("EnumChildProc"),TEXT("EnumChildWindows"),TEXT("EnumTaskWindows"),TEXT("EnumThreadWindows"),TEXT("EnumThreadWndProc"),TEXT("EnumWindows"),TEXT("EnumWindowsProc"),TEXT("FindWindow"),TEXT("FindWindowEx"),TEXT("GetAltTabInfo"),TEXT("GetAncestor"),TEXT("GetClientRect"),TEXT("GetDesktopWindow"),TEXT("GetForegroundWindow"),TEXT("GetGUIThreadInfo"),TEXT("GetLastActivePopup"),TEXT("GetLayout"),TEXT("GetNextWindow"),TEXT("GetParent"),TEXT("GetProcessDefaultLayout"),TEXT("GetSysModalWindow"),TEXT("GetTitleBarInfo"),TEXT("GetTopWindow"),TEXT("GetWindow"),TEXT("GetWindowInfo"),TEXT("GetWindowModuleFileName"),TEXT("GetWindowPlacement"),TEXT("GetWindowRect"),TEXT("GetWindowTask"),TEXT("GetWindowText"),TEXT("GetWindowTextLength"),TEXT("GetWindowThreadProcessId"),TEXT("IsChild"),TEXT("IsIconic"),TEXT("IsWindow"),TEXT("IsWindowUnicode"),TEXT("IsWindowVisible"),TEXT("IsZoomed"),TEXT("LockSetForegroundWindow"),TEXT("MoveWindow"),TEXT("OpenIcon"),TEXT("RealChildWindowFromPoint"),TEXT("RealGetWindowClass"),TEXT("SetForegroundWindow"),TEXT("SetLayeredWindowAttributes"),TEXT("SetLayout"),TEXT("SetParent"),TEXT("SetProcessDefaultLayout"),TEXT("SetSysModalWindow"),TEXT("SetWindowPlacement"),TEXT("SetWindowPos"),TEXT("SetWindowText"),TEXT("ShowOwnedPopups"),TEXT("ShowWindow"),TEXT("ShowWindowAsync"),TEXT("TileWindows"),TEXT("UpdateLayeredWindow"),TEXT("WindowFromPoint"),TEXT("WinMain"),NULL};
LPTSTR szWindowClassItem[] ={TEXT("GetClassInfo"),TEXT("GetClassInfoEx"),TEXT("GetClassLong"),TEXT("GetClassLongPtr"),TEXT("GetClassName"),TEXT("GetClassWord"),TEXT("GetWindowLong"),TEXT("GetWindowLongPtr"),TEXT("GetWindowWord"),TEXT("RegisterClass"),TEXT("RegisterClassEx"),TEXT("SetClassLong"),TEXT("SetClassLongPtr"),TEXT("SetClassWord"),TEXT("SetWindowLong"),TEXT("SetWindowLongPtr"),TEXT("SetWindowWord"),TEXT("UnregisterClass"),NULL};
LPTSTR szWindowStationAndDesktopItem[]={TEXT("CloseDesktop"),TEXT("CreateWindowStation"),TEXT("CloseWindowStation"),TEXT("GetProcessWindowStation"),TEXT("GetUserObjectInformation"),TEXT("SetUserObjectInformation"),TEXT("CreateDesktop"),TEXT("EnumWindowStationProc"),TEXT("EnumWindowStations"),TEXT("EnumDesktopProc"),TEXT("EnumDesktops"),TEXT("EnumDesktopWindows"),TEXT("GetThreadDesktop"),TEXT("OpenDesktop"),TEXT("SetThreadDesktop"),TEXT("SetProcessWindowStation"),TEXT("OpenInputDesktop"),TEXT("SwitchDesktop"),TEXT("OpenWindowStation"),NULL};
LPTSTR szWindowProcedureItem[]={TEXT("CallWindowProc"),TEXT("DefWindowProc"),TEXT("WindowProc"),NULL};
LPTSTR szWindowPropertyItem[]={TEXT("EnumProps"),TEXT("EnumPropsEx"),TEXT("GetProp"),TEXT("PropEnumProc"),TEXT("PropEnumProcEx"),TEXT("RemoveProp"),TEXT("SetProp"),NULL};
LPTSTR szWindowDialogBoxItem[]={TEXT("CreateDialog"),TEXT("CreateDialogIndirect"),TEXT("CreateDialogIndirectParam"),TEXT("CreateDialogParam"),TEXT("DefDlgProc"),TEXT("DialogBox"),TEXT("DialogBoxIndirect"),TEXT("DialogBoxIndirectParam"),TEXT("DialogBoxParam"),TEXT("DialogProc"),TEXT("EndDialog"),TEXT("GetDialogBaseUnits"),TEXT("GetDlgCtrlID"),TEXT("GetDlgItem"),TEXT("GetDlgItemInt"),TEXT("GetDlgItemText"),TEXT("GetNextDlgGroupItem"),TEXT("GetNextDlgTabItem"),TEXT("IsDialogMessage"),TEXT("MapDialogRect"),TEXT("MessageBox"),TEXT("MessageBoxEx"),TEXT("MessageBoxIndirect"),TEXT("SendDlgItemMessage"),TEXT("SetDlgItemInt"),TEXT("SetDlgItemText"),NULL};
LPTSTR szWindowTimerItem[]={TEXT("KillTimer"),TEXT("QueryPerformanceCounter"),TEXT("QueryPerformanceFrequency"),TEXT("SetTimer"),TEXT("TimerProc"),NULL};
LPTSTR szWindowMultiDocumentItem[]={TEXT("CreateMDIWindow"),TEXT("DefFrameProc"),TEXT("DefMDIChildProc"),TEXT("TranslateMDISysAccel"),NULL};
LPTSTR szWindowMessageAndMessageQueueItem[]={TEXT("BroadcastSystemMessage"),TEXT("DispatchMessage"),TEXT("GetInputState"),TEXT("GetMessage"),TEXT("GetMessageExtraInfo"),TEXT("GetMessagePos"),TEXT("GetMessageTime"),TEXT("GetQueueStatus"),TEXT("InSendMessage"),TEXT("InSendMessageEx"),TEXT("PeekMessage"),TEXT("PostAppMessage"),TEXT("PostMessage"),TEXT("PostQuitMessage"),TEXT("PostThreadMessage"),TEXT("RegisterWindowMessage"),TEXT("ReplyMessage"),TEXT("SendMessage"),TEXT("SendMessageCallback"),TEXT("SendMessageTimeout"),TEXT("SendNotifyMessage"),TEXT("SendAsyncProc"),TEXT("SetMessageExtraInfo"),TEXT("SetMessageQueue"),TEXT("TranslateMessage"),TEXT("WaitMessage"),NULL};

LPTSTR szControlItem[] = {TEXT("エディットコントロール"),TEXT("コンボボックス"),TEXT("スクロール バー"),TEXT("ボタン"),TEXT("リストボックス"),TEXT("リッチ エディット コントロール"),NULL};
LPTSTR szControlEditBoxItem[] = {TEXT("EditWordBreakProc"),NULL};
LPTSTR szControlComboBoxItem[]={TEXT("DlgDirListComboBox"),TEXT("DlgDirSelectComboBox"),TEXT("DlgDirSelectComboBoxEx"),TEXT("GetComboBoxInfo"),NULL};
LPTSTR szControlScrollBarItem[]={TEXT("EnableScrollBar"),TEXT("GetScrollBarInfo"),TEXT("GetScrollInfo"),TEXT("GetScrollPos"),TEXT("GetScrollRange"),TEXT("ScrollDC"),TEXT("ScrollWindow"),TEXT("ScrollWindowEx"),TEXT("SetScrollInfo"),TEXT("SetScrollPos"),TEXT("SetScrollRange"),TEXT("ShowScrollBar"),NULL};
LPTSTR szControlButtonItem[]={TEXT("CheckDlgButton"),TEXT("CheckRadioButton"),TEXT("IsDlgButtonChecked"),NULL};
LPTSTR szControlListBoxItem[]={TEXT("DlgDirList"),TEXT("DlgDirSelect"),TEXT("DlgDirSelectEx"),TEXT("GetListBoxInfo"),NULL};
LPTSTR szControlRichEditControlItem[]={TEXT("CreateTextServices"),TEXT("EditStreamCallback"),TEXT("EditWordBreakProcEx"),NULL};

LPTSTR szResourceItem[]={TEXT("アイコン"),TEXT("カーソル"),TEXT("キャレット"),TEXT("メニュー"),TEXT("文字列の操作"),TEXT("リソース"),TEXT("バージョン情報"),NULL};
LPTSTR szResourceIconItem[]={TEXT("CopyIcon"),TEXT("CreateIcon"),TEXT("CreateIconFromResource"),TEXT("CreateIconFromResourceEx"),TEXT("CreateIconIndirect"),TEXT("DestroyIcon"),TEXT("DrawIcon"),TEXT("DrawIconEx"),TEXT("DuplicateIcon"),TEXT("ExtractAssociatedIcon"),TEXT("ExtractIcon"),TEXT("ExtractIconEx"),TEXT("GetIconInfo"),TEXT("LoadIcon"),TEXT("LookupIconIdFromDirectory"),TEXT("LookupIconIdFromDirectoryEx"),NULL};
LPTSTR szResourceCursorItem[]={TEXT("ClipCursor"),TEXT("CopyCursor"),TEXT("CreateCursor"),TEXT("DestroyCursor"),TEXT("GetClipCursor"),TEXT("GetCursor"),TEXT("GetCursorInfo"),TEXT("GetCursorPos"),TEXT("LoadCursor"),TEXT("LoadCursorFromFile"),TEXT("SetCursor"),TEXT("SetCursorPos"),TEXT("SetSystemCursor"),TEXT("ShowCursor"),NULL};
LPTSTR szResourceCaretItem[]={TEXT("CreateCaret"),TEXT("DestroyCaret"),TEXT("GetCaretBlinkTime"),TEXT("GetCaretPos"),TEXT("HideCaret"),TEXT("SetCaretBlinkTime"),TEXT("SetCaretPos"),TEXT("ShowCaret"),NULL};
LPTSTR szResourceMenuItem[]={TEXT("AppendMenu"),TEXT("CheckMenuItem"),TEXT("CheckMenuRadioItem"),TEXT("CreateMenu"),TEXT("CreatePopupMenu"),TEXT("DeleteMenu"),TEXT("DestroyMenu"),TEXT("DrawMenuBar"),TEXT("EnableMenuItem"),TEXT("EndMenu"),TEXT("GetMenu"),TEXT("GetMenuBarInfo"),TEXT("GetMenuCheckMarkDimensions"),TEXT("GetMenuDefaultItem"),TEXT("GetMenuInfo"),TEXT("GetMenuItemCount"),TEXT("GetMenuItemID"),TEXT("GetMenuItemInfo"),TEXT("GetMenuItemRect"),TEXT("GetMenuState"),TEXT("GetMenuString"),TEXT("GetSubMenu"),TEXT("GetSystemMenu"),TEXT("HiliteMenuItem"),TEXT("InsertMenu"),TEXT("InsertMenuItem"),TEXT("IsMenu"),TEXT("LoadMenu"),TEXT("LoadMenuIndirect"),TEXT("MenuItemFromPoint"),TEXT("ModifyMenu"),TEXT("RemoveMenu"),TEXT("SetMenu"),TEXT("SetMenuDefaultItem"),TEXT("SetMenuInfo"),TEXT("SetMenuItemBitmaps"),TEXT("SetMenuItemInfo"),TEXT("TrackPopupMenu"),TEXT("TrackPopupMenuEx"),NULL};
LPTSTR szResourceStringItem[]={TEXT("AnsiLower"),TEXT("AnsiLowerBuff"),TEXT("AnsiNext"),TEXT("AnsiPrev"),TEXT("AnsiToOem"),TEXT("AnsiToOemBuff"),TEXT("AnsiUpper"),TEXT("AnsiUpperBuff"),TEXT("CharLower"),TEXT("CharLowerBuff"),TEXT("CharNext"),TEXT("CharNextExA"),TEXT("CharPrev"),TEXT("CharToOem"),TEXT("CharPrevExA"),TEXT("CharToOemBuff"),TEXT("CharUpper"),TEXT("CharUpperBuff"),TEXT("CompareString"),TEXT("FoldString"),TEXT("GetStringTypeA"),TEXT("GetStringTypeEx"),TEXT("GetStringTypeW"),TEXT("IsCharAlpha"),TEXT("IsCharAlphaNumeric"),TEXT("IsCharLower"),TEXT("IsCharUpper"),TEXT("LoadString"),TEXT("lstrcat"),TEXT("lstrcmp"),TEXT("lstrcmpi"),TEXT("lstrcpy"),TEXT("lstrcpyn"),TEXT("lstrlen"),TEXT("OemToAnsi"),TEXT("OemToAnsiBuff"),TEXT("OemToChar"),TEXT("OemToCharBuff"),TEXT("wsprintf"),TEXT("wvsprintf"),NULL};
LPTSTR szResourceResourceItem[]={TEXT("BeginUpdateResource"),TEXT("CopyImage"),TEXT("EndUpdateResource"),TEXT("EnumResLangProc"),TEXT("EnumResNameProc"),TEXT("EnumResourceLanguages"),TEXT("EnumResourceNames"),TEXT("EnumResourceTypes"),TEXT("EnumResTypeProc"),TEXT("FindResource"),TEXT("FindResourceEx"),TEXT("FreeResource"),TEXT("LoadResource"),TEXT("LoadImage"),TEXT("LockResource"),TEXT("SizeofResource"),TEXT("UnlockResource"),TEXT("UpdateResource"),NULL};
LPTSTR szResourceVersionItem[]={TEXT("GetFileVersionInfo"),TEXT("GetFileVersionInfoSize"),TEXT("VerFindFile"),TEXT("VerInstallFile"),TEXT("VerLanguageName"),TEXT("VerQueryValue"),NULL};

LPTSTR szUserInputItem[]={TEXT("キーボードアクセラレータ"),TEXT("キーボード入力"),TEXT("コモンダイアログボックスライブラリ"),TEXT("マウス入力"),NULL};
LPTSTR szUserInputKeyboardAcceleratorItem[]={TEXT("CopyAcceleratorTable"),TEXT("CreateAcceleratorTable"),TEXT("DestroyAcceleratorTable"),TEXT("LoadAccelerators"),TEXT("TranslateAccelerator"),NULL};
LPTSTR szUserInputKeyboardInputItem[]={TEXT("ActivateKeyboardLayout"),TEXT("BlockInput"),TEXT("EnableWindow"),TEXT("GetActiveWindow"),TEXT("GetAsyncKeyState"),TEXT("GetFocus"),TEXT("GetKBCodePage"),TEXT("GetKeyboardLayout"),TEXT("GetKeyboardLayoutList"),TEXT("GetKeyboardLayoutName"),TEXT("GetKeyboardState"),TEXT("GetKeyNameText"),TEXT("GetKeyState"),TEXT("GetLastInputInfo"),TEXT("IsWindowEnabled"),TEXT("keybd_event"),TEXT("LoadKeyboardLayout"),TEXT("MapVirtualKeyEx"),TEXT("MapVirtualKey"),TEXT("OemKeyScan"),TEXT("RegisterHotKey"),TEXT("SendInput"),TEXT("ToAscii"),TEXT("ToAsciiEx"),TEXT("ToUnicode"),TEXT("ToUnicodeEx"),TEXT("UnregisterHotKey"),TEXT("SetActiveWindow"),TEXT("SetFocus"),TEXT("SetKeyboardState"),TEXT("UnloadKeyboardLayout"),TEXT("VkKeyScan"),TEXT("VkKeyScanEx"),NULL};
LPTSTR szUserInputCommonDialogBoxLibraryItem[]={TEXT("CCHookProc"),TEXT("CFHookProc"),TEXT("ChooseColor"),TEXT("ChooseFont"),TEXT("CommDlgExtendedError"),TEXT("FindText"),TEXT("FRHookProc"),TEXT("GetFileTitle"),TEXT("GetOpenFileName"),TEXT("GetSaveFileName"),TEXT("OFNHookProc"),TEXT("OFNHookProcOldStyle"),TEXT("PagePaintHook"),TEXT("PageSetupDlg"),TEXT("PageSetupHook"),TEXT("PrintDlg"),TEXT("PrintDlgEx"),TEXT("PrintHookProc"),TEXT("ReplaceText"),TEXT("SetupHookProc"),NULL};
LPTSTR szUserInputMouseInputItem[]={TEXT("DragDetect"),TEXT("GetCapture"),TEXT("GetDoubleClickTime"),TEXT("GetMouseMovePointsEx"),TEXT("mouse_event"),TEXT("ReleaseCapture"),TEXT("SetCapture"),TEXT("SetDoubleClickTime"),TEXT("SwapMouseButton"),TEXT("TrackMouseEvent"),TEXT("_TrackMouseEvent"),NULL};

LRESULT CALLBACK WndProc(HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam)
{
	int iCount = 0;
	int i,j,k;
    switch (msg){
	case WM_CREATE:
		InitCommonControls();
		
		hTree = CreateWindowEx(WS_EX_CLIENTEDGE , WC_TREEVIEW , 0 ,
			WS_CHILD | WS_VISIBLE | WS_BORDER | WS_VSCROLL |
			TVS_HASBUTTONS | TVS_HASLINES | TVS_LINESATROOT ,
			0 , 0 , 10 , 10 , hWnd , (HMENU)1 ,
			((LPCREATESTRUCT)lParam)->hInstance , NULL
			);
		
		for (i=0 ; szTopItem[i] ; i++) {
			TVINSERTSTRUCT tvi;
			tvi.hParent = TVI_ROOT;
			tvi.hInsertAfter = TVI_LAST;
			tvi.item.mask = TVIF_TEXT;
			tvi.item.pszText = szTopItem[i];
			HTREEITEM hTreeItem = TreeView_InsertItem(hTree , &tvi);
			switch(i){
			case 0:
				for(j=0;szWindowingItem[j];j++){
					tvi.hParent = hTreeItem;
					tvi.item.pszText=szWindowingItem[j];
					HTREEITEM hTreeItem = TreeView_InsertItem(hTree,&tvi);
					switch(j){
					case 0:for(k=0;szWindowItem[k];k++){tvi.hParent = hTreeItem;tvi.item.pszText=szWindowItem[k];TreeView_InsertItem(hTree,&tvi);}break;
					case 1:for(k=0;szWindowClassItem[k];k++){tvi.hParent = hTreeItem;tvi.item.pszText=szWindowClassItem[k];TreeView_InsertItem(hTree,&tvi);}break;
					case 2:for(k=0;szWindowStationAndDesktopItem[k];k++){tvi.hParent = hTreeItem;tvi.item.pszText=szWindowStationAndDesktopItem[k];TreeView_InsertItem(hTree,&tvi);}break;
					case 3:for(k=0;szWindowProcedureItem[k];k++){tvi.hParent = hTreeItem;tvi.item.pszText=szWindowProcedureItem[k];TreeView_InsertItem(hTree,&tvi);}break;
					case 4:for(k=0;szWindowPropertyItem[k];k++){tvi.hParent = hTreeItem;tvi.item.pszText=szWindowPropertyItem[k];TreeView_InsertItem(hTree,&tvi);}break;
					case 5:for(k=0;szWindowDialogBoxItem[k];k++){tvi.hParent = hTreeItem;tvi.item.pszText=szWindowDialogBoxItem[k];TreeView_InsertItem(hTree,&tvi);}break;
					case 6:for(k=0;szWindowTimerItem[k];k++){tvi.hParent = hTreeItem;tvi.item.pszText=szWindowTimerItem[k];TreeView_InsertItem(hTree,&tvi);}break;
					case 7:for(k=0;szWindowMultiDocumentItem[k];k++){tvi.hParent = hTreeItem;tvi.item.pszText=szWindowMultiDocumentItem[k];TreeView_InsertItem(hTree,&tvi);}break;
					case 8:for(k=0;szWindowMessageAndMessageQueueItem[k];k++){tvi.hParent = hTreeItem;tvi.item.pszText=szWindowMessageAndMessageQueueItem[k];TreeView_InsertItem(hTree,&tvi);}break;
					}
				}
				break;
			case 1:
				for(j=0;szControlItem[j];j++){
					tvi.hParent = hTreeItem;
					tvi.item.pszText=szControlItem[j];
					HTREEITEM hTreeItem = TreeView_InsertItem(hTree,&tvi);
					switch(j){
					case 0:for(k=0;szControlEditBoxItem[k];k++){tvi.hParent = hTreeItem;tvi.item.pszText=szControlEditBoxItem[k];TreeView_InsertItem(hTree,&tvi);}break;
					case 1:for(k=0;szControlComboBoxItem[k];k++){tvi.hParent = hTreeItem;tvi.item.pszText=szControlComboBoxItem[k];TreeView_InsertItem(hTree,&tvi);}break;
					case 2:for(k=0;szControlScrollBarItem[k];k++){tvi.hParent = hTreeItem;tvi.item.pszText=szControlScrollBarItem[k];TreeView_InsertItem(hTree,&tvi);}break;
					case 3:for(k=0;szControlButtonItem[k];k++){tvi.hParent = hTreeItem;tvi.item.pszText=szControlButtonItem[k];TreeView_InsertItem(hTree,&tvi);}break;
					case 4:for(k=0;szControlListBoxItem[k];k++){tvi.hParent = hTreeItem;tvi.item.pszText=szControlListBoxItem[k];TreeView_InsertItem(hTree,&tvi);}break;
					case 5:for(k=0;szControlRichEditControlItem[k];k++){tvi.hParent = hTreeItem;tvi.item.pszText=szControlRichEditControlItem[k];TreeView_InsertItem(hTree,&tvi);}break;
					}
				}
				break;
			case 2:
				for(j=0;szResourceItem[j];j++){
					tvi.hParent = hTreeItem;
					tvi.item.pszText=szResourceItem[j];
					HTREEITEM hTreeItem = TreeView_InsertItem(hTree,&tvi);
					switch(j){
					case 0:for(k=0;szResourceIconItem[k];k++){tvi.hParent = hTreeItem;tvi.item.pszText=szResourceIconItem[k];TreeView_InsertItem(hTree,&tvi);}break;
					case 1:for(k=0;szResourceCursorItem[k];k++){tvi.hParent = hTreeItem;tvi.item.pszText=szResourceCursorItem[k];TreeView_InsertItem(hTree,&tvi);}break;
					case 2:for(k=0;szResourceCaretItem[k];k++){tvi.hParent = hTreeItem;tvi.item.pszText=szResourceCaretItem[k];TreeView_InsertItem(hTree,&tvi);}break;
					case 3:for(k=0;szResourceMenuItem[k];k++){tvi.hParent = hTreeItem;tvi.item.pszText=szResourceMenuItem[k];TreeView_InsertItem(hTree,&tvi);}break;
					case 4:for(k=0;szResourceStringItem[k];k++){tvi.hParent = hTreeItem;tvi.item.pszText=szResourceStringItem[k];TreeView_InsertItem(hTree,&tvi);}break;
					case 5:for(k=0;szResourceResourceItem[k];k++){tvi.hParent = hTreeItem;tvi.item.pszText=szResourceResourceItem[k];TreeView_InsertItem(hTree,&tvi);}break;
					case 6:for(k=0;szResourceVersionItem[k];k++){tvi.hParent = hTreeItem;tvi.item.pszText=szResourceVersionItem[k];TreeView_InsertItem(hTree,&tvi);}break;
					}
				}
				break;
			case 3:
				for(j=0;szUserInputItem[j];j++){
					tvi.hParent = hTreeItem;
					tvi.item.pszText=szUserInputItem[j];
					HTREEITEM hTreeItem = TreeView_InsertItem(hTree,&tvi);
					switch(j){
					case 0:for(k=0;szUserInputKeyboardAcceleratorItem[k];k++){tvi.hParent = hTreeItem;tvi.item.pszText=szUserInputKeyboardAcceleratorItem[k];TreeView_InsertItem(hTree,&tvi);}break;
					case 1:for(k=0;szUserInputKeyboardInputItem[k];k++){tvi.hParent = hTreeItem;tvi.item.pszText=szUserInputKeyboardInputItem[k];TreeView_InsertItem(hTree,&tvi);}break;
					case 2:for(k=0;szUserInputCommonDialogBoxLibraryItem[k];k++){tvi.hParent = hTreeItem;tvi.item.pszText=szUserInputCommonDialogBoxLibraryItem[k];TreeView_InsertItem(hTree,&tvi);}break;
					case 3:for(k=0;szUserInputMouseInputItem[k];k++){tvi.hParent = hTreeItem;tvi.item.pszText=szUserInputMouseInputItem[k];TreeView_InsertItem(hTree,&tvi);}break;
					}
				}
				break;
			}
			
		}		
		return 0;
	case WM_SETFOCUS:
		SetFocus(hTree);
		break;
	case WM_SIZE:
		MoveWindow(hTree , 0 , 0 , LOWORD(lParam) , HIWORD(lParam) , FALSE);
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return(DefWindowProc(hWnd,msg,wParam,lParam));
    }
    return (0L);
}

int WINAPI WinMain(HINSTANCE hinst,HINSTANCE hPreInst,
                   LPSTR pCmdLine,int nCmdShow)
{
    HWND hWnd;
    MSG msg;
    WNDCLASS wndclass;
    if(!hPreInst){
        wndclass.style=CS_HREDRAW|CS_VREDRAW;
        wndclass.lpfnWndProc=WndProc;
        wndclass.cbClsExtra=0;
        wndclass.cbWndExtra=0;
        wndclass.hInstance =hinst;
        wndclass.hIcon=NULL;
        wndclass.hCursor=LoadCursor(NULL,IDC_ARROW);
        wndclass.hbrBackground=(HBRUSH)(COLOR_WINDOW+1);
        wndclass.lpszMenuName=NULL;
        wndclass.lpszClassName=szClassName;
        if(!RegisterClass(&wndclass))
            return FALSE;
    }
    hWnd=CreateWindow(szClassName,
        "Windows 32bit API",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        NULL,
        NULL,
        hinst,
        NULL);
    ShowWindow(hWnd,nCmdShow);
    UpdateWindow(hWnd);
    while (GetMessage(&msg,NULL,0,0)){
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return (msg.wParam);
}



