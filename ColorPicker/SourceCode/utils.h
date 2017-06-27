#pragma once

#include <string>

struct CUtils
{
    template <typename T> static std::string toHex(T Value, size_t TypeSize = sizeof(T))
    {
        #define TO_HEX(i) ((i) <= 9 ? '0' + (i) : 'A' - 10 + (i))
        std::string r;

        for (size_t i = 0, j =  0; i < TypeSize; ++i, j += 8)
        {
            size_t v = Value >> j;
            if(!v) break;

            r.push_back(TO_HEX((v >> 4) & 0x0F));
            r.push_back(TO_HEX((v >> 0) & 0x0F));
        }

        #undef TO_HEX
        return r.size()? r : "00";
    }

    template <typename T> static T GoldenRatio(T Value)
    {
        return (T)(Value * 1.618033);
    }
};

