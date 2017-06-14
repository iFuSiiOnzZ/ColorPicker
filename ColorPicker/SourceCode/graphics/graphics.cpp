#include "graphics.h"

#ifndef CLAMP_INT_COLOR
    #define CLAMP_INT_COLOR(x) (((x) > (255)) ? (255) : (((x) < (0)) ? (0) : (x)))
#endif

void CGraphicsManager::ClearBuffer(offscreen_buffer_t * Buffer, float r, float g, float b)
{
    unsigned int *Dest = ((unsigned int *)Buffer->Memory);
    unsigned int ClearColor = MakeColor(r, g, b);

    for (int i = 0; i < Buffer->Height * Buffer->Width; ++i)
    {
        *Dest++ = ClearColor;
    }
}

void CGraphicsManager::DrawRectangle(offscreen_buffer_t * Buffer, float sx, float sy, float ex, float ey, float r, float g, float b)
{
    int MinX = (int)(sx + 0.5f);
    int MinY = (int)(sy + 0.5f);
    int MaxX = (int)(ex + 0.5f);
    int MaxY = (int)(ey + 0.5f);

    if (MinX < 0) MinX = 0;
    if (MinY < 0) MinY = 0;

    if (MaxX > Buffer->Width) MaxX = Buffer->Width;
    if (MaxY > Buffer->Height) MaxY = Buffer->Height;


    unsigned int Color = MakeColor(r, g, b);
    unsigned char *Row = ((unsigned char *)Buffer->Memory + MinX * Buffer->BytesPerPixel + MinY * Buffer->Pitch);

    for (int Y = MinY; Y < MaxY; ++Y)
    {
        unsigned int *Pixel = (unsigned int *)Row;
        for (int X = MinX; X < MaxX; ++X)
        {
            *Pixel++ = Color;
        }

        Row += Buffer->Pitch;
    }
}

void CGraphicsManager::PutPixel(offscreen_buffer_t *Buffer, float x, float y, int r, int g, int b)
{
    int xx = (int)(x + 0.5f);
    int yy = (int)(y + 0.5f);


    if (xx >= Buffer->Width)
    {
        return;
    }

    if (yy >= Buffer->Height)
    {
        return;
    }

    unsigned char *Row = ((unsigned char *)Buffer->Memory + xx * Buffer->BytesPerPixel + yy * Buffer->Pitch);
    *((unsigned int *)Row) = MakeColor(r, g, b);
}

unsigned int CGraphicsManager::MakeColor(float r, float g, float b)
{
    int rr = (int)(r * 255);
    int gg = (int)(g * 255);
    int bb = (int)(b * 255);

    rr = CLAMP_INT_COLOR(rr);
    gg = CLAMP_INT_COLOR(gg);
    bb = CLAMP_INT_COLOR(bb);

    return rr << 16 | gg << 8 | bb << 0;
}

unsigned int CGraphicsManager::MakeColor(int r, int g, int b)
{
    return r << 16 | g << 8 | b << 0;
}