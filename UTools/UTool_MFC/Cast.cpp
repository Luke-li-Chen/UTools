#include "StdAfx.h"
#include "Cast.h"

using UTools::Cast;
using std::string;

Cast::Cast()
{
}


Cast::~Cast()
{
}

string Cast::int2string(int Value, int Radix)
{
    char tmp[12] = { 0 };
    _itoa(Value, tmp, Radix);
    string rtn(tmp);

    return rtn;
}

inline string Cast::int2string(int Value)
{
    using std::to_string;

    string rtn = to_string((long long)Value);

    return rtn;
}

char* Cast::string2NewPchar(const string& str)
{
    size_t size = str.size() + 1;
    char* p = new char[size];
    //strcpy(p, str.c_str());
    //char p[5];
    //strcpy_s(p, str.c_str());
    strncpy(p, str.c_str(), size);

    return p;
}

CString Cast::add(CString src)
{
    return src + _T("23336666");
}
