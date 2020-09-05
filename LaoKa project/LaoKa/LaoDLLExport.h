//define export type
#define DLLIMPORT __declspec(dllimport)
//define current index of font type
DLLIMPORT int LAOKA_CURRENT_FONT_INDEX;
DLLIMPORT bool UNICODE_MODE;
DLLIMPORT bool SETUNICODEMODE(bool unicodeMode);
DLLIMPORT int USEFONTTYPE(int fontType);
//DLLIMPORT void createPop(HWND h);
//DLLIMPORT void destroyPop();