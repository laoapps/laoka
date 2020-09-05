//#include "tooltip.h"
//Key board process when key is pressed; Use for Hook
//# include "tooltip.h"
LRESULT __declspec(dllexport)__stdcall  CALLBACK KeyboardProcSimple_UnicodeFont(
                            int nCode, 
                           WPARAM wParam, 
                            LPARAM lParam)
{		
	
	/*POINT pt;
	GetCursorPos(&pt);
	CString strx;
	CString stry;
	strx.Format(_T("%d"),pt.x);
	stry.Format(_T("%d"),pt.y);
	mpop->showModaless(strx,stry);return 0;
	if(hins==NULL) return 0;
	_CurrentThread=GetFocus();*/

	//*Set switch on/off*/
	/************/
	//press control twice
	/************/
	
	if (HC_ACTION==nCode)
	{	
		//return 0 when ctrl alt shift btn was press
		if(GetAsyncKeyState(VK_CONTROL)!=0||GetAsyncKeyState(VK_LSHIFT)!=0||GetAsyncKeyState(VK_RSHIFT)!=0)
			return 0;

		


		// add value WPARAM once! press not with l/r shift or control key, and Caplock key must be activated
		if(((wParam>=0x41 ) &&(wParam<=0x5a))&&((wParam<=0x61)&&(wParam<=0x7a)))
		{		
			if(GetAsyncKeyState((int)wParam)==0)
				return 1;
			_CurrentThread=GetFocus();
			temp[_Count]=wParam;
			_Count++;			
			//IDD_DIALOG1::show
			/*POINT p;
			GetCaretPos(&p);
			LONG x=p.x;
			LONG y=p.y;
			TCHAR  str[255];
			_stprintf_s(str, _T("point x is %d y is:%d"), p.x,p.y);
			CToolTip m_ToolTip;
			CWnd* _m_cwnd;
			_m_cwnd=CWnd::FromHandle(GetDesktopWindow());
			//_m_cwnd->Attach(GetDesktopWindow());
			m_ToolTip.Create(_m_cwnd);
			
			m_ToolTip.SetText(str);
			m_ToolTip.Show(p);*/
		}
		else if(wParam==VK_BACK)
		{		
			_CurrentThread=GetFocus();
			temp[_Count-1]=0;
			_Count--;		
			if(_Count<0)
			{
				_Count=0;
				return 0;
			}
			return 1;
		}
		else if(wParam!=VK_SPACE)
			return 0;


		if(nCode<0)
		{
			CallNextHookEx(hkb,nCode,wParam,lParam);
			_Count=0;
			return 0;
		}
		if((wParam==VK_SPACE/*||wParam==VK_RETURN*/))
		{				
				if(_Count<=0)
					return 0;
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
							
					for(int i=0;i<=sizeRelaoKa;i++)			
					{					
						if(Re_LaoKa[i]!=0)
						{
							//POST MESSAGE WILL BE PROCESSED FIRST THEN KEYBOARD EVENT
							PostMessageW(_CurrentThread,WM_CHAR,Re_LaoKa[i],lParam);					
						}
					}	
					PostMessageW(_CurrentThread,WM_CHAR,0x200B,lParam);	
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
					for(int i=0;i<_Length;i++)
					{
						Re_LaoKa[i]=0;
						temp[i]=0;
					}
				}
			return 1;
		}
		else 
			return 1;
	
}
LRESULT RetVal = CallNextHookEx(hkb, nCode, wParam, lParam );
return  RetVal;

}