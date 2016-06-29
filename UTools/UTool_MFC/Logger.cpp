#include "StdAfx.h"
#include "Logger.h"

using std::string;

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

void LogTrace::print(const char * Format, ...)
{
    const size_t bufSize = 1024 * 32;
    va_list args;

    char buf[bufSize] = { 0 };
    va_start(args, Format);
    _vsnprintf(buf, bufSize, Format, args);
    va_end(args);

    OutputDebugString(buf);
}




LogFile::LogFile()
{
    time_t t = time(nullptr);
    char tmp[64];
    strftime(tmp, sizeof(tmp), "%Y-%m-%dT%X", localtime(&t));
    printf("%s\n", tmp);

    m_fp = nullptr;
    //m_fp = fopen();
}

LogFile::LogFile(string _FilePath)
{
}

LogFile::~LogFile()
{
    if (m_fp != nullptr)
    {
        fclose(m_fp);
    }
}

void LogFile::print(const char * _Format, ...)
{
}

