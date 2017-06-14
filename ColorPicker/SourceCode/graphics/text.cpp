#include "text.h"
#include <string.h>

HFONT hfontTimes = nullptr;
LOGFONTA logfont = { 0 };     

void CText::CreateText(const char *FontName)
{
    logfont.lfHeight = 18;
    logfont.lfWidth = 0;

    logfont.lfEscapement = 0;
    logfont.lfOrientation = 0;

    logfont.lfWeight = FW_BOLD;
    logfont.lfItalic = FALSE;

    logfont.lfUnderline = FALSE;
    logfont.lfStrikeOut = FALSE;

    logfont.lfCharSet = DEFAULT_CHARSET;
    logfont.lfOutPrecision = OUT_DEFAULT_PRECIS;
    logfont.lfClipPrecision = CLIP_DEFAULT_PRECIS;

    logfont.lfQuality = DEFAULT_QUALITY;
    logfont.lfPitchAndFamily = DEFAULT_PITCH | FF_DONTCARE;

    strcpy_s(logfont.lfFaceName, LF_FACESIZE, (char *) FontName);
    hfontTimes = CreateFontIndirectA(&logfont);
}

void CText::PrintText(HDC hdcSurface, int x, int y, char * Text, unsigned int Color)
{
    SetTextColor(hdcSurface, Color);
    ExtTextOutA(hdcSurface, x, y, 0, NULL, Text, (unsigned int) strlen(Text), NULL);
}
