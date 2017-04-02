#include "StdAfx.h"
#include "Logger.h"
#include "Cast.h"
#include <direct.h>

using std::string;
using namespace UTools::Log;
using namespace UTools::Cast;

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
    const size_t BUF_SIZE = 1024 * 1024;
    va_list args;

    char buf[BUF_SIZE] = { 0 };
    va_start(args, _Format);
    _vsnprintf(buf, BUF_SIZE, _Format, args);
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
    : m_fp(nullptr)
{
    time_t t = time(nullptr);
    char tmp[64];
    strftime(tmp, sizeof(tmp), "%Y-%m-%dT%X", localtime(&t));
    printf("%s\n", tmp);

    m_fp = nullptr;
    //m_fp = fopen();
}

LogFile::LogFile(string _FilePath)
    : m_fp(nullptr)
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

void UTools::Log::LogFile::CheckPath()
{
    GetTime();

    if (CheckTime())
    {
        return;
    }

    fflush(m_fp);
    fclose(m_fp);

    if ((m_time.tm_year != m_year) || (m_time.tm_mon != m_month))
    {
        string newPath = m_rootPath + IntToString(m_year) + "-" + IntToString(m_month);
        mkdir(newPath.c_str());

    }

}

void UTools::Log::LogFile::GetTime()
{
    time_t t = time(nullptr);
    tm* timeNow = localtime(&t);

    memcpy(&m_time, timeNow, sizeof(tm));   // 以防timeNow指向的内存被释放
}

bool UTools::Log::LogFile::CheckTime()
{
    if ((m_time.tm_year == m_year) && 
        (m_time.tm_mon  == m_month) && \
        (m_time.tm_mday == m_day))
    {
        return true;
    }
    else
    {
        return false;
    }
}

UTools::Log::LogCMD::LogCMD()
{
}

UTools::Log::LogCMD::~LogCMD()
{
}

void UTools::Log::LogCMD::print(Level _Level, const char * _Format, ...)
{
}

void UTools::Log::LogCMD::printPercent(size_t current, size_t total, float step)
{
    static float threshold = 0.0;
    float percent;


    percent = (float)current / total;
    percent *= 100;

    if (percent >= threshold)
    {
        printf("%f%%\n", percent);
        threshold += step;
    }
}
