#pragma once

#include "graphics\graphics.h"
#include <vector>

class CUserColors
{
    private:
        std::vector<color_t> m_PickedColors;

    public:

        inline void pushColor(color_t c)
        {
            m_PickedColors.push_back(c);
        }

        inline void pushColor(int r, int g, int b)
        {
            color_t c = { r, g, b };
            m_PickedColors.push_back(c);
        }

        inline void popColor()
        {
            if (m_PickedColors.size())
            {
                m_PickedColors.erase(m_PickedColors.begin() + (m_PickedColors.size() - 1));
            }
        }

        inline  void clear()
        {
            m_PickedColors.clear();
        }

        void showColors(offscreen_buffer_t *Buffer, CGraphicsManager *GraphicsManager, float WndWidth, float WndHeight)
        {
            for (size_t i = 0; i < m_PickedColors.size(); ++i)
            {
                float w = 300.0f;
                float h = (WndHeight / (float)m_PickedColors.size());

                float sx = WndWidth - w - 10.0f;
                float sy = i * h + 10.0f;

                float ex = WndWidth - 10.0f;
                float ey = i * h + h - 10.0f;

                float r = m_PickedColors[i].r / 255.0f;
                float g = m_PickedColors[i].g / 255.0f;
                float b = m_PickedColors[i].b / 255.0f;

                GraphicsManager->DrawRectangle(Buffer, sx, sy, ex, ey, r, g, b);
            }
        }
};