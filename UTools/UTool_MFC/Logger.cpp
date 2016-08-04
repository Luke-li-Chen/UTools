#include "StdAfx.h"
#include "Logger.h"

using std::string;
using namespace UTools::Log;

Logger::Logger()
{
}


Logger::~Logger()
{
}


LogTrace::LogTrace()
{
}

LogTrace::~LogTrace()
{
}

void LogTrace::print(Level _Level, const char * _Format, ...)
{
    const size_t bufSize = 1024 * 32;
    va_list args;

    char buf[bufSize] = { 0 };
    va_start(args, _Format);
    _vsnprintf(buf, bufSize, _Format, args);
    va_end(args);

    switch (_Level)
    {
    case UTools::Log::Info:
        OutputDebugString("Info: ");
        break;
    case UTools::Log::Warning:
        OutputDebugString("Warning: ");
        break;
    case UTools::Log::Error:
        OutputDebugString("Error: ");
        break;
    default:
        break;
    }

    OutputDebugString(buf);
}




LogFile::LogFile()
    :m_fp(nullptr)
{
    time_t t = time(nullptr);
    char tmp[64];
    strftime(tmp, sizeof(tmp), "%Y-%m-%dT%X", localtime(&t));
    printf("%s\n", tmp);

    m_fp = nullptr;
    //m_fp = fopen();
}

LogFile::LogFile(string _FilePath)
    :m_fp(nullptr)
{
}

LogFile::~LogFile()
{
    if (m_fp != nullptr)
    {
        fclose(m_fp);
    }
}

void LogFile::print(Level _Level, const char * _Format, ...)
{
}

