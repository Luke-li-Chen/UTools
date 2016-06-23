#include "StdAfx.h"
#include "Cast.h"

using namespace UTools;
using std::string;


string Cast::IntToString(int Value, int Radix)
{
    char tmp[12] = { 0 };
    _itoa(Value, tmp, Radix);
    string rtn(tmp);

    return rtn;
}

string Cast::IntToString(int Value)
{
    using std::to_string;

    string rtn = to_string((long long)Value);

    return rtn;
}

char* Cast::StringToNewCharArray(const string& Str)
{
    size_t size = Str.size() + 1;
    char* p = new char[size];
    strncpy(p, Str.c_str(), size);

    return p;
}

char* Cast::CStringAToCharArray(const CStringA& Src, char* Dst, size_t Count)
{
    strncpy(Dst, (LPSTR)(LPCTSTR)Src, Count);

    return Dst;
}

float Cast::ByteArrayToFloat(const byte Src[4])
{
    float rst;
    memcpy(&rst, Src, 4);

    return rst;
}

byte* Cast::FloatToByteArray(float Src, byte Dst[4])
{
    memcpy(Dst, &Src, 4);
    return Dst;
}

float Cast::CByteArrayToFloat(const CByteArray& Src)
{
    byte b[4];
    for (int i = 0; i < 4; i++)
    {
        b[i] = Src.GetAt(i);
    }

    float rst;
    memcpy(&rst, b, 4);

    return rst;
}

CByteArray& Cast::FloatToCByteArray(float Src, CByteArray& Dst)
{
    byte b[4];
    memcpy(b, &Src, 4);

    for (int i = 0; i < 4; i++)
    {
        Dst.SetAt(i, b[i]);
    }

    return Dst;
}
