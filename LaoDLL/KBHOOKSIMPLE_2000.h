//Key board process when key is pressed; Use for Hook
LRESULT __declspec(dllexport)__stdcall  CALLBACK KeyboardProcSimple_2000Font(
                            int nCode, 
                           WPARAM wParam, 
                            LPARAM lParam)
{		
	if(hins==NULL) return 0;
if (((DWORD)lParam & 0x40000000) &&(HC_ACTION==nCode))
{	
	// add value WPARAM once! press not with l/r shift or control key, and Caplock key must be activated
	if(((wParam>=0x41 ) &&(wParam<=0x5a))&&((wParam<=0x61)&&(wParam<=0x7a))&&GetAsyncKeyState(VK_CONTROL)==0&&GetKeyState(VK_CAPITAL)!=0&&GetAsyncKeyState(VK_LSHIFT)==0&&GetAsyncKeyState(VK_RSHIFT)==0)
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
			IsLaoKipSign(LAOKA_2000_FONT_INDEX);
			_Count=0;		
		}		
		else if(wParam==VK_LEFT ||wParam==VK_RIGHT||wParam==VK_UP ||wParam==VK_DOWN)
			_Count=0;
		else
		{
			//Insert Lao number
			if(GetKeyState(VK_CAPITAL)!=0&&GetAsyncKeyState(VK_SHIFT)==0)
				InsertLaoNumber(wParam,LAOKA_2000_FONT_INDEX);
		}		
		//release
		//release when user pressed non alphabet character!
		wParam=VK_SPACE;
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
			_realCount=_Count;
			for(int i=0;i<_Length;i++)
			{
				Re_LaoKa[i]=0;				
			}
			if(_Count>0&&_CurrentThread==GetFocus())
			{
				ConvertLaoKaToLao2000(temp);	
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
				for(int i=0;i<=_realCount;i++)
				{	
					PostMessage(_CurrentThread,WM_CHAR,VK_BACK,lParam)	;
				}								
				for(int i=0;i<=sizeRelaoKa;i++)			
				{					
					if(Re_LaoKa[i]!=0)
					{
						//POST MESSAGE WILL BE PROCESSED FIRST THEN KEYBOARD EVENT
						PostMessageW(_CurrentThread,WM_CHAR,Re_LaoKa[i],lParam);					
					}
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
LRESULT RetVal = CallNextHookEx(hkb, nCode, wParam, lParam );
return  RetVal;

}