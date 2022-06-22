#include <windows.h> 

void SetColor(unsigned short ForeColor, unsigned short BackGroundColor)//????//?څ// 
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);//??? 
    SetConsoleTextAttribute(handle, ForeColor + BackGroundColor * 0x10);//
   ////0=?  1=?  2=?  3=??  4=?  5=?  6=?  7=? 
    //////8= ?  9 = ?  10 = ?  11 = ??  12 = ?  13 = ?  14 = ? 15 = ?
}
