//define export type
#define DLLEXPORT __declspec(dllexport)
#pragma data_seg(".SHARDAT")
static HHOOK hkb=NULL;
static HHOOK hm=NULL;
static WPARAM LAOKA_CHAR_VALUE [10][100];
static HINSTANCE hins;
//define current index of font type
DLLEXPORT int LAOKA_CURRENT_FONT_INDEX=1;
DLLEXPORT bool UNICODE_MODE=true;
DLLEXPORT bool SETUNICODEMODE(bool unicodeMode);
DLLEXPORT int USEFONTTYPE(int fontType);
static int _Count=0;
CONST int _Length=15;
static WPARAM Re_LaoKa[_Length];
static WPARAM temp[_Length]  ;
static int Re_Index=0;
bool  _IsRule2=true;
static WPARAM _MarkSign=0;
static HWND _CurrentThread=NULL;
static int _realCount=0;
bool _UseExtraSign=false;
static bool _skip=false;
BOOL  _UseHV=false;
UINT VK_BACK_SCAN;
UINT VK_LEFT_SCAN;
UINT VK_RETURN_SCAN;
UINT VK_RIGHT_SCAN;

//define index of font type
#define LAOKA_UNICODE_FONT_INDEX 0
#define LAOKA_2000_FONT_INDEX 1
//define 2 dimension array of laoka's char value
BOOL __declspec(dllexport)__stdcall installhook();
BOOL __declspec(dllexport)__stdcall   UnHook();
LRESULT __declspec(dllexport)__stdcall  CALLBACK MouseProc(
                            int nCode, 
                           WPARAM wParam, 
                            LPARAM lParam);
LRESULT __declspec(dllexport)__stdcall  CALLBACK KeyboardProcUnicode_UnicodeFont(
                            int nCode, 
                           WPARAM wParam, 
                            LPARAM lParam);
LRESULT __declspec(dllexport)__stdcall  CALLBACK KeyboardProcUnicode_2000Font(
                            int nCode, 
                           WPARAM wParam, 
                            LPARAM lParam);
LRESULT __declspec(dllexport)__stdcall  CALLBACK KeyboardProcSimple_UnicodeFont(
                            int nCode, 
                           WPARAM wParam, 
                            LPARAM lParam);
LRESULT __declspec(dllexport)__stdcall  CALLBACK KeyboardProcSimple_2000Font(
                            int nCode, 
                           WPARAM wParam, 
                            LPARAM lParam);
bool IsV(WPARAM value);
bool IsAbovedVowel(WPARAM value,WPARAM value1);
bool IsLaoKipSign(int currentFontIndex);
void InsertLaoNumber(WPARAM wParam,int curentFontIndex);
void InsertMarkSign();
void VowelStayAtFirstRule1(int index,int currentFontType);
void VowelStayAloneRule2(int index,int currentFontType);
bool IsConsonant(WPARAM value);
bool IsMarkSign(WPARAM value);
bool IsOtherSign(WPARAM value);
WPARAM GetExtraMarkSign(WPARAM value,int currentFontType);
WPARAM GetMarkSign(WPARAM value,int currentFontType);
void TakeVowelToFrontOfWord(int index);
int ConvertLaoKaToLaoUnicode(WPARAM value[]);
int ConvertLaoKaToLao2000(WPARAM value[]);
void SkipLaoString(int size);
class CLaoDLLApp : public CWinApp
{
public:
	CLaoDLLApp();
public:
	virtual BOOL InitInstance();
	DECLARE_MESSAGE_MAP()
};
#pragma data_seg()