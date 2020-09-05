//Mouse process , Mouse hook
LRESULT DLLEXPORT __stdcall  CALLBACK MouseProc(
                            int nCode, 
                           WPARAM wParam, 
                            LPARAM lParam)
{
	if(nCode<0)
	{
		CallNextHookEx(hkb,nCode,wParam,lParam);
		_Count=0;
		return 0;
	}
	if(wParam==WM_LBUTTONDOWN)
	{
		_Count=0;
	}
	return CallNextHookEx(hm,nCode,wParam,lParam);
}