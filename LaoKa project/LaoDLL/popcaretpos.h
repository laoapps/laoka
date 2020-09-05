/*DWORD dwCaretID = GetWindowThreadProcessId(GetFocus(),NULL);
DWORD dwCurrentID = GetWindowThreadProcessId(GetForegroundWindow(),NULL);
if (AttachThreadInput(dwCurrentID,dwCaretID,TRUE))
{
GUITHREADINFO lpgui;
PGUITHREADINFO pgui;
lpgui.cbSize = sizeof(GUITHREADINFO);
GetGUIThreadInfo(dwCaretID,&pgui);
RECT caret_rect = lpgui.rcCaret;
}*/
#include "pop.h"