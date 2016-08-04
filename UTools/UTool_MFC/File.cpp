#include "StdAfx.h"
#include "File.h"

using std::string;
using UTools::IO::File;

File::File()
{
}


File::~File()
{
}

__int64 UTools::IO::File::GetSize(const char* FilePath)
{
    FILE* fp = fopen(FilePath, "rb");
    if (fp == nullptr)
    {
        return 0;
    }
    
    _fseeki64(fp, 0, SEEK_END);
    __int64 size = _ftelli64(fp);

    fclose(fp);

    return size;
}

bool UTools::IO::File::Exist(const char * FilePath)
{
    if ((_access(FilePath, 0)) != -1)
    {
        return true;
    }

    return false;
}

bool UTools::IO::File::Delete(const char * FilePath)
{
    if (remove(FilePath) == 0)
    {
        return true;
    }
    return false;
}
