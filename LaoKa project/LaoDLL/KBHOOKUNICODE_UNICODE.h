//Key board process when key is pressed; Use for Hook
LRESULT __declspec(dllexport)__stdcall  CALLBACK KeyboardProcUnicode_UnicodeFont(
                            int nCode, 
                           WPARAM wParam, 
                            LPARAM lParam)
{		
	//BlockInput(true);
	if(hins==NULL) return 0;
if (((DWORD)lParam & 0x40000000) &&(HC_ACTION==nCode))
{	
	if(wParam==VK_CONTROL)
	{
		_countSwitch++;
		_current_T=CTime::GetCurrentTime();		
		if(_countSwitch>=2)
		{
			int _preDate=_previous_T.GetDayOfWeek();
			int _preHour=_previous_T.GetHour();
			int _preMin=_previous_T.GetMinute();
			int _preSecond=_previous_T.GetSecond();

			int _curDate=_current_T.GetDayOfWeek();
			int _curHour=_current_T.GetHour();
			int _curMin=_current_T.GetMinute();
			int _curSecond=_current_T.GetSecond();
			if(_preDate==_curDate&&_preHour==_curHour&&_preMin==_curMin)
			{
				//current = 0->1 /pre=58->59 => _t=-2 && -58
				//current = 2->59 /pre=0->57 ==> _t=2
				int _t=_curSecond-_preSecond;				
				if(_t<=2||_t<=-58)
				{
					if(_isSwitchOn)
					_isSwitchOn=false;				
					else
					_isSwitchOn=true;
					_countSwitch=0;
				}
			}	
		}
		_previous_T=_current_T;
	}
	if(!_isSwitchOn)
		return 0;
	KBDLLHOOKSTRUCT *pkbhs = (KBDLLHOOKSTRUCT *) lParam;	
	MessageBoxW(HWND_DESKTOP,(LPCWSTR)"code:"+pkbhs->vkCode,(LPCWSTR)"Text here",MB_OK);
if(pkbhs->vkCode!=VK_SPACE)
		return 1;
	// add value WPARAM once! press not with l/r shift or control key, and Caplock key must be activated
	if(((wParam>=0x41 ) &&(wParam<=0x5a))&&((wParam<=0x61)&&(wParam<=0x7a))&&GetAsyncKeyState(VK_CONTROL)==0&&GetAsyncKeyState(VK_LSHIFT)==0&&GetAsyncKeyState(VK_RSHIFT)==0)
	{
		_CurrentThread=GetFocus();
		temp[_Count]=wParam;
		_Count++;			
	}
	else if(wParam==VK_BACK)
	{		
		_CurrentThread=GetFocus();
		temp[_Count-1]=0;
		_Count--;		
		if(_Count<0)
			_Count=0;
	}
	else
	{
		_CurrentThread=GetFocus();
		//
		if(GetAsyncKeyState(VK_CONTROL)!=0&&wParam=='K')	
		{
			IsLaoKipSign(LAOKA_UNICODE_FONT_INDEX);
			_Count=0;		
		}		
		else if(wParam==VK_LEFT ||wParam==VK_RIGHT||wParam==VK_UP ||wParam==VK_DOWN)
			_Count=0;
		else
		{
			//Insert Lao number
			if(GetKeyState(VK_CAPITAL)!=0&&GetAsyncKeyState(VK_SHIFT)==0)
				InsertLaoNumber(wParam,LAOKA_UNICODE_FONT_INDEX);
		}		
		//release
		//release when user pressed non alphabet character!
		//wParam=VK_SPACE;
		//_Count--;
		//_skip=true;
	}
	if(nCode<0)
	{
		CallNextHookEx(hkb,nCode,wParam,lParam);
		_Count=0;
		return 0;
	}
	if((wParam==VK_SPACE||wParam==VK_RETURN)&&_Count>0)
		{				
			BlockInput(false);
			_realCount=_Count;
			for(int i=0;i<_Length;i++)
			{
				Re_LaoKa[i]=0;				
			}
			if(_Count>0&&_CurrentThread==GetFocus())
			{
				ConvertLaoKaToLaoUnicode(temp);	
				// Put Lao strings
				int sizeRelaoKa=0;
				//measure size of Re_LaoKa
				for(int i=0;i<_Length;i++)
				{
					if(Re_LaoKa[i]!=0)
					{
						sizeRelaoKa++;
					}
				}				
				//Release lao characters																
					//SKIP LAO STRING
				SkipLaoString(sizeRelaoKa);
				for(int i=0;i<=_realCount;i++)
				{
					keybd_event(VK_BACK, VK_BACK_SCAN,0,0);
					keybd_event(VK_BACK, VK_BACK_SCAN, KEYEVENTF_KEYUP, 0);				
				}
												
				for(int i=0;i<=sizeRelaoKa;i++)			
				{					
					if(Re_LaoKa[i]!=0)
					{
						//POST MESSAGE WILL BE PROCESSED FIRST THEN KEYBOARD EVENT
						PostMessageW(_CurrentThread,WM_CHAR,Re_LaoKa[i],lParam);					
					}
				}				
				//RETURN TO END OF LAO STRING
				for(int i=0;i<sizeRelaoKa;i++)
				{
					keybd_event(VK_RIGHT, VK_RIGHT_SCAN,0,0);
					keybd_event(VK_RIGHT, VK_RIGHT_SCAN, KEYEVENTF_KEYUP, 0);
				}
				//When press Enter key
				if(wParam==VK_RETURN)
				{					
					//PostMessage(_CurrentThread,WM_CHAR,VK_RETURN,lParam);
					keybd_event(VK_RETURN, VK_RETURN_SCAN,0,0);
					keybd_event(VK_RETURN, VK_RETURN_SCAN, KEYEVENTF_KEYUP, 0);
				}
				//release resources
				for(int i=0;i<_Length;i++)
				{
					Re_LaoKa[i]=0;
					temp[i]=0;
				}		
				_Count=0;
				Re_Index=0;
				_MarkSign=0;
				_realCount=0;				
			}
			else
			{
				//Release when current thread is changed!
				/*for(int i=0;i<_Length;i++)
				{
					Re_LaoKa[i]=0;
					temp[i]=0;
				}*/
			}
		
		}
}
//BlockInput(true);
return 0;
/*LRESULT RetVal = CallNextHookEx(hkb, nCode, wParam, lParam );
return  RetVal;*/

}