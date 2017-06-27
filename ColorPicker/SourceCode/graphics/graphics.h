#pragma once

typedef struct offscreen_buffer_t
{
    void *Memory;

    int Width;
    int Height;

    int Pitch;
    int BytesPerPixel;
} offscreen_buffer_t;

typedef struct color_t
{
    unsigned int r, g, b, a;
} color_t;

struct CGraphicsManager
{
    static void DrawRectangle(offscreen_buffer_t *Buffer, float sx, float sy, float ex, float ey, float r, float g, float b);

    static void PutPixel(offscreen_buffer_t *Buffer, float x, float y, int r, int g, int b);
    static void ClearBuffer(offscreen_buffer_t *Buffer, float r, float g, float b);

    static unsigned int MakeColor(float r, float g, float b);
    static unsigned int MakeColor(int r, int g, int b);
};