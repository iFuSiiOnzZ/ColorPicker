#pragma once

#include <string>
#include <Windows.h>

typedef struct file_in_memory
{
    void *Memory;
    size_t Size;
} file_in_memory;

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

struct CFileUtils
{
    static file_in_memory GetFileContent(const char * FileName)
    {
        file_in_memory f = { 0 };
        struct stat st = { 0 };
        FILE *pFile = NULL;

        if (!stat((const char *)FileName, &st) && !fopen_s(&pFile, (const char *)FileName, "rb"))
        {
            f.Size = st.st_size;
            f.Memory = malloc(f.Size);

            fread(f.Memory, f.Size, 1, pFile);
            fclose(pFile);
        }

        return f;
    }

    static void ReleaseFileContent(file_in_memory * File)
    {
        if (!File->Size) return;
        File->Size = 0;

        free(File->Memory);
        File->Memory = NULL;
    }
};