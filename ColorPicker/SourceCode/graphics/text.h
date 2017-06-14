#pragma once
#include <Windows.h>

struct CText
{
    static void CreateText(const char *FontName = "Times New Roman");
    static void PrintText(HDC hdcSurface, int x, int y, char * Text, unsigned int Color);
};