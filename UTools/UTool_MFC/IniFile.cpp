#include "StdAfx.h"
//#include "ini_include.h"
#include "IniFile.h"
#include "Cast.h"

using std::string;
using std::exception;
using UTools::IniFile;
using UTools::Cast;

IniFile::IniFile()
{
}


IniFile::IniFile(string iniFilePath)
{
    m_IniFilePath = iniFilePath;
}

IniFile::~IniFile()
{
}

bool IniFile::SetIniFilePath(string path)
{
    m_IniFilePath = path;
    return true;
}

string IniFile::GetString(string app, string key, int maxSize)
{
    char* tmp = new char[maxSize];
    GetPrivateProfileString(app.c_str(), key.c_str(), NULL, tmp, maxSize, m_IniFilePath.c_str());
    string rtn(tmp);
    delete[] tmp;
    return rtn;
}

char* IniFile::GetPchar(const char* app, const char* key, int maxSize, char* dest)
{
    GetPrivateProfileString(app, key, NULL, dest, maxSize, m_IniFilePath.c_str());

    return dest;
}

unsigned int IniFile::GetInt(string app, string key, unsigned int defaultVal = UINT_MAX)
{
    unsigned int rtn = GetPrivateProfileInt(app.c_str(), key.c_str(), defaultVal, m_IniFilePath.c_str());
    if (rtn == defaultVal)
    {
        string msg = "读取到错误的值，为";
        msg += Cast::int2string(rtn, 10);
        msg += '\n';
        exception e(msg.c_str());
        throw e;
    }

    return rtn;
}

bool IniFile::GetBool(string app, string key)
{
    return GetBool(app.c_str(), key.c_str());
}

bool IniFile::GetBool(const char* app, const char* key)
{
    BOOL rtn = GetPrivateProfileInt(app, key, 2, m_IniFilePath.c_str());

    if (rtn == TRUE)
    {
        return true;
    }
    else if (rtn == FALSE)
    {
        return false;
    }
    else
    {
        string msg = "读取到错误的值，为";
        msg += Cast::int2string(rtn, 10);
        msg += '\n';
        exception e(msg.c_str());
        throw e;
    }
}
