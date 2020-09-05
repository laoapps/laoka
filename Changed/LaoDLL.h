#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"	
#include "popcreator.h"
#include "LaoKaFont2000.h"
#include "LaoKaFontUnicode.h"
#include "LaoKaCharIndex.h"
#include "LaoDLLExport.h"
#include "Convert2Unicode.h"
#include "Convert22000.h"
#include "Switch.h"
#include "KBHOOKSIMPLE_UNICODE.h"
#include "KBHOOKSIMPLE_2000.h"
#include "KBHOOKUNICODE_UNICODE.h"
#include "KBHOOKUNICODE_2000.h"
#include "MouseHOOK.h"
#include "ProcessLaoKa.h"

//DEFINE FUNCTION
#pragma data_seg(".SHARDAT")
DLLEXPORT bool SETUNICODEMODE(bool unicodeMode)
{
	UNICODE_MODE=unicodeMode;	
	//FlushFileBuffers(hins);
	return UNICODE_MODE;
}
DLLEXPORT int USEFONTTYPE(int fontType)
{
	LAOKA_CURRENT_FONT_INDEX=fontType;	
	//FlushFileBuffers(hins);
	return LAOKA_CURRENT_FONT_INDEX;
}

VOID static INIT_LAO_CHAR_UNICODE()
{
	//index @ Unicode font type
	//Init value of LaoKa_char_value @ Unicode font type index
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf__L]=LaoKa_Unicode__L;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_A]=LaoKa_Unicode_A;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_AA]=LaoKa_Unicode_AA;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_AAY]=LaoKa_Unicode_AAY;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_AE]=LaoKa_Unicode_AE;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_AW]=LaoKa_Unicode_AW;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_AY]=LaoKa_Unicode_AY;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_B]=LaoKa_Unicode_B;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_C]=LaoKa_Unicode_C;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_D]=LaoKa_Unicode_D;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_E]=LaoKa_Unicode_E;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_EE]=LaoKa_Unicode_EE;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_Eight]=LaoKa_Unicode_Eight;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_ExtraSign]=LaoKa_Unicode_ExtraSign;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_F]=LaoKa_Unicode_F;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_FH]=LaoKa_Unicode_FH;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_Five]=LaoKa_Unicode_Five;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_Four]=LaoKa_Unicode_Four;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_G]=LaoKa_Unicode_G;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_H]=LaoKa_Unicode_H;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_HH]=LaoKa_Unicode_HH;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_HM]=LaoKa_Unicode_HM;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_HN]=LaoKa_Unicode_HN;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_I]=LaoKa_Unicode_I;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_II]=LaoKa_Unicode_II;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_J]=LaoKa_Unicode_J;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_K]=LaoKa_Unicode_K;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_KH]=LaoKa_Unicode_KH;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_L]=LaoKa_Unicode_L;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_LaoKipSign]=LaoKa_Unicode_LaoKipSign;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_M]=LaoKa_Unicode_M;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_MarkAgain]=LaoKa_Unicode_MarkAgain;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_MarkFour]=LaoKa_Unicode_MarkFour;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_MarkOne]=LaoKa_Unicode_MarkOne;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_MarkRedundant]=LaoKa_Unicode_MarkRedundant;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_MarkThree]=LaoKa_Unicode_MarkThree;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_MarkTwo]=LaoKa_Unicode_MarkTwo;	
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_N]=LaoKa_Unicode_N;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_NG]=LaoKa_Unicode_NG;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_NH]=LaoKa_Unicode_NH;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_Nine]=LaoKa_Unicode_Nine;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_O]=LaoKa_Unicode_O;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_OH]=LaoKa_Unicode_OH;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_One]=LaoKa_Unicode_One;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_OO]=LaoKa_Unicode_OO;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_OW]=LaoKa_Unicode_OW;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_P]=LaoKa_Unicode_P;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_PH]=LaoKa_Unicode_PH;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_PHH]=LaoKa_Unicode_PHH;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_Q]=LaoKa_Unicode_Q;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_R]=LaoKa_Unicode_R;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_S]=LaoKa_Unicode_S;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_Seven]=LaoKa_Unicode_Seven;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_Six]=LaoKa_Unicode_Six;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_T]=LaoKa_Unicode_T;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_TH]=LaoKa_Unicode_TH;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_THH]=LaoKa_Unicode_THH;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_Three]=LaoKa_Unicode_Three;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_Two]=LaoKa_Unicode_Two;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_U]=LaoKa_Unicode_U;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_UU]=LaoKa_Unicode_UU;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_V]=LaoKa_Unicode_V;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_W]=LaoKa_Unicode_W;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_WW]=LaoKa_Unicode_WW;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_Y]=LaoKa_Unicode_Y;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_Zero]=LaoKa_Unicode_Zero;
}
VOID static INIT_LAO_CHAR_2000()
{
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf__L]=LaoKa_2000__L;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_A]=LaoKa_2000_A;	
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_AA]=LaoKa_2000_AA;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_AAY]=LaoKa_2000_AAY;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_AE]=LaoKa_2000_AE;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_AW]=LaoKa_2000_AW;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_AY]=LaoKa_2000_AY;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_B]=LaoKa_2000_B;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_C]=LaoKa_2000_C;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_D]=LaoKa_2000_D;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_E]=LaoKa_2000_E;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_EE]=LaoKa_2000_EE;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_Eight]=LaoKa_2000_Eight;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_ExtraSign]=LaoKa_2000_ExtraSign;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_F]=LaoKa_2000_F;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_FH]=LaoKa_2000_FH;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_Five]=LaoKa_2000_Five;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_Four]=LaoKa_2000_Four;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_G]=LaoKa_2000_G;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_H]=LaoKa_2000_H;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_HH]=LaoKa_2000_HH;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_HM]=LaoKa_2000_HM;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_HN]=LaoKa_2000_HN;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_I]=LaoKa_2000_I;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_II]=LaoKa_2000_II;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_J]=LaoKa_2000_J;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_K]=LaoKa_2000_K;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_KH]=LaoKa_2000_KH;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_L]=LaoKa_2000_L;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_LaoKipSign]=LaoKa_2000_LaoKipSign;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_M]=LaoKa_2000_M;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_MarkAgain]=LaoKa_2000_MarkAgain;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_MarkFour]=LaoKa_2000_MarkFour;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_MarkOne]=LaoKa_2000_MarkOne;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_MarkRedundant]=LaoKa_2000_MarkRedundant;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_MarkThree]=LaoKa_2000_MarkThree;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_MarkTwo]=LaoKa_2000_MarkTwo;	
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_N]=LaoKa_2000_N;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_NG]=LaoKa_2000_NG;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_NH]=LaoKa_2000_NH;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_Nine]=LaoKa_2000_Nine;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_O]=LaoKa_2000_O;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_OH]=LaoKa_2000_OH;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_One]=LaoKa_2000_One;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_OO]=LaoKa_2000_OO;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_OW]=LaoKa_2000_OW;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_P]=LaoKa_2000_P;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_PH]=LaoKa_2000_PH;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_PHH]=LaoKa_2000_PHH;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_Q]=LaoKa_2000_Q;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_R]=LaoKa_2000_R;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_S]=LaoKa_2000_S;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_Seven]=LaoKa_2000_Seven;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_Six]=LaoKa_2000_Six;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_T]=LaoKa_2000_T;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_TH]=LaoKa_2000_TH;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_THH]=LaoKa_2000_THH;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_Three]=LaoKa_2000_Three;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_Two]=LaoKa_2000_Two;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_U]=LaoKa_2000_U;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_UU]=LaoKa_2000_UU;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_V]=LaoKa_2000_V;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_W]=LaoKa_2000_W;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_WW]=LaoKa_2000_WW;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_Y]=LaoKa_2000_Y;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_Zero]=LaoKa_2000_Zero;
}
VOID static INIT_LAOKA_CHAR_VALUE()
{
	//index @ Unicode font type
	//Init value of LaoKa_char_value @ Unicode font type index
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf__L]=LaoKa_Unicode__L;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_A]=LaoKa_Unicode_A;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_AA]=LaoKa_Unicode_AA;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_AAY]=LaoKa_Unicode_AAY;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_AE]=LaoKa_Unicode_AE;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_AW]=LaoKa_Unicode_AW;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_AY]=LaoKa_Unicode_AY;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_B]=LaoKa_Unicode_B;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_C]=LaoKa_Unicode_C;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_D]=LaoKa_Unicode_D;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_E]=LaoKa_Unicode_E;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_EE]=LaoKa_Unicode_EE;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_Eight]=LaoKa_Unicode_Eight;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_ExtraSign]=LaoKa_Unicode_ExtraSign;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_F]=LaoKa_Unicode_F;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_FH]=LaoKa_Unicode_FH;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_Five]=LaoKa_Unicode_Five;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_Four]=LaoKa_Unicode_Four;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_G]=LaoKa_Unicode_G;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_H]=LaoKa_Unicode_H;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_HH]=LaoKa_Unicode_HH;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_HM]=LaoKa_Unicode_HM;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_HN]=LaoKa_Unicode_HN;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_I]=LaoKa_Unicode_I;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_II]=LaoKa_Unicode_II;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_J]=LaoKa_Unicode_J;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_K]=LaoKa_Unicode_K;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_KH]=LaoKa_Unicode_KH;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_L]=LaoKa_Unicode_L;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_LaoKipSign]=LaoKa_Unicode_LaoKipSign;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_M]=LaoKa_Unicode_M;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_MarkAgain]=LaoKa_Unicode_MarkAgain;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_MarkFour]=LaoKa_Unicode_MarkFour;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_MarkOne]=LaoKa_Unicode_MarkOne;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_MarkRedundant]=LaoKa_Unicode_MarkRedundant;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_MarkThree]=LaoKa_Unicode_MarkThree;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_MarkTwo]=LaoKa_Unicode_MarkTwo;	
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_N]=LaoKa_Unicode_N;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_NG]=LaoKa_Unicode_NG;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_NH]=LaoKa_Unicode_NH;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_Nine]=LaoKa_Unicode_Nine;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_O]=LaoKa_Unicode_O;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_OH]=LaoKa_Unicode_OH;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_One]=LaoKa_Unicode_One;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_OO]=LaoKa_Unicode_OO;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_OW]=LaoKa_Unicode_OW;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_P]=LaoKa_Unicode_P;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_PH]=LaoKa_Unicode_PH;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_PHH]=LaoKa_Unicode_PHH;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_Q]=LaoKa_Unicode_Q;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_R]=LaoKa_Unicode_R;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_S]=LaoKa_Unicode_S;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_Seven]=LaoKa_Unicode_Seven;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_Six]=LaoKa_Unicode_Six;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_T]=LaoKa_Unicode_T;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_TH]=LaoKa_Unicode_TH;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_THH]=LaoKa_Unicode_THH;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_Three]=LaoKa_Unicode_Three;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_Two]=LaoKa_Unicode_Two;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_U]=LaoKa_Unicode_U;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_UU]=LaoKa_Unicode_UU;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_V]=LaoKa_Unicode_V;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_W]=LaoKa_Unicode_W;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_WW]=LaoKa_Unicode_WW;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_Y]=LaoKa_Unicode_Y;
	LAOKA_CHAR_VALUE[LAOKA_UNICODE_FONT_INDEX][LaoKa_Char_IndexOf_Zero]=LaoKa_Unicode_Zero;

	//Index @ 2000 font type
	//Init value of LaoKa_char_value @ 2000 font type index
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf__L]=LaoKa_2000__L;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_A]=LaoKa_2000_A;	
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_AA]=LaoKa_2000_AA;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_AAY]=LaoKa_2000_AAY;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_AE]=LaoKa_2000_AE;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_AW]=LaoKa_2000_AW;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_AY]=LaoKa_2000_AY;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_B]=LaoKa_2000_B;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_C]=LaoKa_2000_C;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_D]=LaoKa_2000_D;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_E]=LaoKa_2000_E;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_EE]=LaoKa_2000_EE;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_Eight]=LaoKa_2000_Eight;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_ExtraSign]=LaoKa_2000_ExtraSign;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_F]=LaoKa_2000_F;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_FH]=LaoKa_2000_FH;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_Five]=LaoKa_2000_Five;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_Four]=LaoKa_2000_Four;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_G]=LaoKa_2000_G;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_H]=LaoKa_2000_H;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_HH]=LaoKa_2000_HH;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_HM]=LaoKa_2000_HM;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_HN]=LaoKa_2000_HN;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_I]=LaoKa_2000_I;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_II]=LaoKa_2000_II;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_J]=LaoKa_2000_J;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_K]=LaoKa_2000_K;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_KH]=LaoKa_2000_KH;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_L]=LaoKa_2000_L;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_LaoKipSign]=LaoKa_2000_LaoKipSign;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_M]=LaoKa_2000_M;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_MarkAgain]=LaoKa_2000_MarkAgain;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_MarkFour]=LaoKa_2000_MarkFour;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_MarkOne]=LaoKa_2000_MarkOne;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_MarkRedundant]=LaoKa_2000_MarkRedundant;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_MarkThree]=LaoKa_2000_MarkThree;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_MarkTwo]=LaoKa_2000_MarkTwo;	
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_N]=LaoKa_2000_N;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_NG]=LaoKa_2000_NG;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_NH]=LaoKa_2000_NH;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_Nine]=LaoKa_2000_Nine;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_O]=LaoKa_2000_O;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_OH]=LaoKa_2000_OH;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_One]=LaoKa_2000_One;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_OO]=LaoKa_2000_OO;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_OW]=LaoKa_2000_OW;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_P]=LaoKa_2000_P;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_PH]=LaoKa_2000_PH;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_PHH]=LaoKa_2000_PHH;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_Q]=LaoKa_2000_Q;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_R]=LaoKa_2000_R;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_S]=LaoKa_2000_S;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_Seven]=LaoKa_2000_Seven;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_Six]=LaoKa_2000_Six;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_T]=LaoKa_2000_T;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_TH]=LaoKa_2000_TH;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_THH]=LaoKa_2000_THH;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_Three]=LaoKa_2000_Three;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_Two]=LaoKa_2000_Two;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_U]=LaoKa_2000_U;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_UU]=LaoKa_2000_UU;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_V]=LaoKa_2000_V;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_W]=LaoKa_2000_W;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_WW]=LaoKa_2000_WW;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_Y]=LaoKa_2000_Y;
	LAOKA_CHAR_VALUE[LAOKA_2000_FONT_INDEX][LaoKa_Char_IndexOf_Zero]=LaoKa_2000_Zero;
}
#pragma data_seg()
