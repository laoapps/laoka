//check weather it's V char
bool IsV(WPARAM value)
{
	if(value=='V')
	{
		return true;
	}
	else
	{
		return false;
	}
}
//check wether the vowel is aboved type?
bool IsAbovedVowel(WPARAM value,WPARAM value1)
{
	if((value=='A'&&value1=='E')||(value=='O'&&value1=='O')||(value=='I')||value=='W')
		return true;
	return false;
}
//Lao kip sign
bool IsLaoKipSign(int currentFontIndex)
{
	//Ctrl+K=Lao kip sing	
	PostMessageW(_CurrentThread,WM_CHAR,LAOKA_CHAR_VALUE[currentFontIndex][LaoKa_Char_IndexOf_LaoKipSign] ,0);
	return true;
}
//put Lao number
void InsertLaoNumber(WPARAM wParam,int curentFontIndex)
{
	switch(wParam)
	{
		case '0':
		{			
			//PostMessage(GetFocus(),WM_CHAR,VK_BACK,0);
			//
			keybd_event(VK_LEFT, VK_LEFT_SCAN,0,0);
			keybd_event(VK_LEFT, VK_LEFT_SCAN, KEYEVENTF_KEYUP, 0);
			//
			keybd_event(VK_BACK, VK_BACK_SCAN,0,0);
			keybd_event(VK_BACK, VK_BACK_SCAN, KEYEVENTF_KEYUP, 0);	
			//
			PostMessageW(GetFocus(),WM_CHAR,LAOKA_CHAR_VALUE[curentFontIndex][LaoKa_Char_IndexOf_Zero],0);
			//
			keybd_event(VK_RIGHT, VK_RIGHT_SCAN,0,0);
			keybd_event(VK_RIGHT, VK_RIGHT_SCAN, KEYEVENTF_KEYUP, 0);
		}
		break;
		case '1':
		{
			//PostMessage(GetFocus(),WM_CHAR,VK_BACK,0);
			//
			keybd_event(VK_LEFT, VK_LEFT_SCAN,0,0);
			keybd_event(VK_LEFT, VK_LEFT_SCAN, KEYEVENTF_KEYUP, 0);
			//
			keybd_event(VK_BACK, VK_BACK_SCAN,0,0);
			keybd_event(VK_BACK, VK_BACK_SCAN, KEYEVENTF_KEYUP, 0);	
			//
			PostMessageW(GetFocus(),WM_CHAR,LAOKA_CHAR_VALUE[curentFontIndex][LaoKa_Char_IndexOf_One],0);
			//
			keybd_event(VK_RIGHT, VK_RIGHT_SCAN,0,0);
			keybd_event(VK_RIGHT, VK_RIGHT_SCAN, KEYEVENTF_KEYUP, 0);
		}
		break;
		case '2':
		{
			//PostMessage(GetFocus(),WM_CHAR,VK_BACK,0);
			//
			keybd_event(VK_LEFT, VK_LEFT_SCAN,0,0);
			keybd_event(VK_LEFT, VK_LEFT_SCAN, KEYEVENTF_KEYUP, 0);
			//
			keybd_event(VK_BACK, VK_BACK_SCAN,0,0);
			keybd_event(VK_BACK, VK_BACK_SCAN, KEYEVENTF_KEYUP, 0);	
			//
			PostMessageW(GetFocus(),WM_CHAR,LAOKA_CHAR_VALUE[curentFontIndex][LaoKa_Char_IndexOf_Two],0);
			//
			keybd_event(VK_RIGHT, VK_RIGHT_SCAN,0,0);
			keybd_event(VK_RIGHT, VK_RIGHT_SCAN, KEYEVENTF_KEYUP, 0);
		}
		break;
		case '3':
		{
			//PostMessage(GetFocus(),WM_CHAR,VK_BACK,0);
			//
			keybd_event(VK_LEFT, VK_LEFT_SCAN,0,0);
			keybd_event(VK_LEFT, VK_LEFT_SCAN, KEYEVENTF_KEYUP, 0);
			//
			keybd_event(VK_BACK, VK_BACK_SCAN,0,0);
			keybd_event(VK_BACK, VK_BACK_SCAN, KEYEVENTF_KEYUP, 0);	
			//
			PostMessageW(GetFocus(),WM_CHAR,LAOKA_CHAR_VALUE[curentFontIndex][LaoKa_Char_IndexOf_Three],0);
			//
			keybd_event(VK_RIGHT, VK_RIGHT_SCAN,0,0);
			keybd_event(VK_RIGHT, VK_RIGHT_SCAN, KEYEVENTF_KEYUP, 0);
		}
		break;
		case '4':
		{
			//PostMessage(GetFocus(),WM_CHAR,VK_BACK,0);
			//
			keybd_event(VK_LEFT, VK_LEFT_SCAN,0,0);
			keybd_event(VK_LEFT, VK_LEFT_SCAN, KEYEVENTF_KEYUP, 0);
			//
			keybd_event(VK_BACK, VK_BACK_SCAN,0,0);
			keybd_event(VK_BACK, VK_BACK_SCAN, KEYEVENTF_KEYUP, 0);	
			//	
			PostMessageW(GetFocus(),WM_CHAR,LAOKA_CHAR_VALUE[curentFontIndex][LaoKa_Char_IndexOf_Four],0);
			//
			keybd_event(VK_RIGHT, VK_RIGHT_SCAN,0,0);
			keybd_event(VK_RIGHT, VK_RIGHT_SCAN, KEYEVENTF_KEYUP, 0);
		}
		break;
		case '5':
		{
			//PostMessage(GetFocus(),WM_CHAR,VK_BACK,0);
			//
			keybd_event(VK_LEFT, VK_LEFT_SCAN,0,0);
			keybd_event(VK_LEFT, VK_LEFT_SCAN, KEYEVENTF_KEYUP, 0);
			//
			keybd_event(VK_BACK, VK_BACK_SCAN,0,0);
			keybd_event(VK_BACK, VK_BACK_SCAN, KEYEVENTF_KEYUP, 0);	
			//
			PostMessageW(GetFocus(),WM_CHAR,LAOKA_CHAR_VALUE[curentFontIndex][LaoKa_Char_IndexOf_Five],0);
			//
			keybd_event(VK_RIGHT, VK_RIGHT_SCAN,0,0);
			keybd_event(VK_RIGHT, VK_RIGHT_SCAN, KEYEVENTF_KEYUP, 0);
		}
		break;
		case '6':
		{
			//PostMessage(GetFocus(),WM_CHAR,VK_BACK,0);
			//
			keybd_event(VK_LEFT, VK_LEFT_SCAN,0,0);
			keybd_event(VK_LEFT, VK_LEFT_SCAN, KEYEVENTF_KEYUP, 0);
			//
			keybd_event(VK_BACK, VK_BACK_SCAN,0,0);
			keybd_event(VK_BACK, VK_BACK_SCAN, KEYEVENTF_KEYUP, 0);	
			//
			PostMessageW(GetFocus(),WM_CHAR,LAOKA_CHAR_VALUE[curentFontIndex][LaoKa_Char_IndexOf_Six],0);
			//
			keybd_event(VK_RIGHT, VK_RIGHT_SCAN,0,0);
			keybd_event(VK_RIGHT, VK_RIGHT_SCAN, KEYEVENTF_KEYUP, 0);
		}
		break;
		case '7':
		{
			//PostMessage(GetFocus(),WM_CHAR,VK_BACK,0);
			//
			keybd_event(VK_LEFT, VK_LEFT_SCAN,0,0);
			keybd_event(VK_LEFT, VK_LEFT_SCAN, KEYEVENTF_KEYUP, 0);
			//
			keybd_event(VK_BACK, VK_BACK_SCAN,0,0);
			keybd_event(VK_BACK, VK_BACK_SCAN, KEYEVENTF_KEYUP, 0);	
			//
			PostMessageW(GetFocus(),WM_CHAR,LAOKA_CHAR_VALUE[curentFontIndex][LaoKa_Char_IndexOf_Seven],0);
			//
			keybd_event(VK_RIGHT, VK_RIGHT_SCAN,0,0);
			keybd_event(VK_RIGHT, VK_RIGHT_SCAN, KEYEVENTF_KEYUP, 0);
		}
		break;
		case '8':
		{
			//PostMessage(GetFocus(),WM_CHAR,VK_BACK,0);
			//
			keybd_event(VK_LEFT, VK_LEFT_SCAN,0,0);
			keybd_event(VK_LEFT, VK_LEFT_SCAN, KEYEVENTF_KEYUP, 0);
			//
			keybd_event(VK_BACK, VK_BACK_SCAN,0,0);
			keybd_event(VK_BACK, VK_BACK_SCAN, KEYEVENTF_KEYUP, 0);	
			//
			PostMessageW(GetFocus(),WM_CHAR,LAOKA_CHAR_VALUE[curentFontIndex][LaoKa_Char_IndexOf_Eight],0);
			//
			keybd_event(VK_RIGHT, VK_RIGHT_SCAN,0,0);			
			keybd_event(VK_RIGHT, VK_RIGHT_SCAN, KEYEVENTF_KEYUP, 0);
		}
		break;
		case '9':
		{
			//PostMessage(GetFocus(),WM_CHAR,VK_BACK,0);
			//
			keybd_event(VK_LEFT, VK_LEFT_SCAN,0,0);
			keybd_event(VK_LEFT, VK_LEFT_SCAN, KEYEVENTF_KEYUP, 0);
			//
			keybd_event(VK_BACK, VK_BACK_SCAN,0,0);
			keybd_event(VK_BACK, VK_BACK_SCAN, KEYEVENTF_KEYUP, 0);	
			//
			PostMessageW(GetFocus(),WM_CHAR,LAOKA_CHAR_VALUE[curentFontIndex][LaoKa_Char_IndexOf_Nine],0);
			//
			keybd_event(VK_RIGHT, VK_RIGHT_SCAN,0,0);
			keybd_event(VK_RIGHT, VK_RIGHT_SCAN, KEYEVENTF_KEYUP, 0);
		}
		break;
	}
}
//put lao mark sign at specified position
void InsertMarkSign()
{
	if(_MarkSign!=0)
	{
		Re_Index++;
		//set mark sign be side the closest consonant
		Re_LaoKa[Re_Index]=_MarkSign;
		_MarkSign=0;
	}
}
//put the extra sign  when vowel stay alone: example: x+Laovowel rule1
void VowelStayAtFirstRule1(int index,int currentFontType)
{
	if(index==0)	
		Re_LaoKa[index]=LAOKA_CHAR_VALUE[currentFontType][LaoKa_Char_IndexOf_ExtraSign];	
	Re_Index++;
}

//put the extra sign  when vowel stay alone: example: x+Laovowel rule2
void VowelStayAloneRule2(int index,int currentFontType)
{
	Re_LaoKa[index]=LAOKA_CHAR_VALUE[currentFontType][LaoKa_Char_IndexOf_ExtraSign];	
	Re_Index++;
}
//Check whether it is the other cosonant?
bool IsConsonant(WPARAM value)
{
	if(value=='A'||value=='E'||value=='I'||value=='O'||value=='U'||value=='W'||value=='Q') return false;		
	return true;
}
//Check whether it is the other Marksign?
bool IsMarkSign(WPARAM value)
{
	if(value=='F'||value=='J'||value=='Z'||value=='X') return true;
	return false;
}
//Check whether it is the other mark sign?
bool IsOtherSign(WPARAM value)
{
	if(value=='P'||value=='L')
		return true;	
	return false;
}
//Get the extra mark sign
WPARAM GetExtraMarkSign(WPARAM value,int currentFontType)
{
	if(value=='P')
		return LAOKA_CHAR_VALUE[currentFontType][LaoKa_Char_IndexOf_MarkAgain];
	else 
		return LAOKA_CHAR_VALUE[currentFontType][LaoKa_Char_IndexOf_MarkRedundant];
}
//Get the mark sign
WPARAM GetMarkSign(WPARAM value,int currentFontType)
{
	if(value=='F')
	{
		return LAOKA_CHAR_VALUE[currentFontType][LaoKa_Char_IndexOf_MarkOne];
	}
	else if(value=='J')
	{
		return LAOKA_CHAR_VALUE[currentFontType][LaoKa_Char_IndexOf_MarkTwo];	
	}
	else if(value=='Z')
	{
		return LAOKA_CHAR_VALUE[currentFontType][LaoKa_Char_IndexOf_MarkThree];
	}
	else if(value=='X')
	{
		return LAOKA_CHAR_VALUE[currentFontType][LaoKa_Char_IndexOf_MarkFour];
	}
	return 0;
}
//Take vowel to front of the word : AAY,AY,E,EE
void TakeVowelToFrontOfWord(int index)
{		
	int tempIndex=0;	
	WPARAM t[_Length];
	//Set default value to t[]
	for(int i=0;i<_Length;i++)
	{
		t[i]=0;
	}
	//Set value from Re_LaoKa[] to t[] and process reversing
	for(int i=0;i<_Length;i++)
	{
		if(Re_LaoKa[i]!=0)
		{
			if(tempIndex==0)
			{
				t[tempIndex]=Re_LaoKa[index];		
				tempIndex++;
				Re_LaoKa[index]=0;
				i=-1;
			}
			else 
			{				
				t[tempIndex]=Re_LaoKa[i];				
				tempIndex++;
			}			
		}
	}	
	//Set reversed value from t[] to Re_Laoka[]
	for(int i=0;i<_Length;i++)
	{
		Re_LaoKa[i]=t[i];
	}
}



//Skip laoka word while process input Lao word, UNICODE_MODE=true;
void SkipLaoString(int size)
{
	for(int i=0;i<size;i++)
	{
		keybd_event(VK_LEFT, VK_LEFT_SCAN,0,0);
		keybd_event(VK_LEFT, VK_LEFT_SCAN, KEYEVENTF_KEYUP, 0);
	}
}
