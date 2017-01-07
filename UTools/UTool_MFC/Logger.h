#pragma once
#define DllExport   __declspec( dllexport )

//#include <>

namespace UTools
{
    namespace Log
    {
        using std::string;

        enum Level
        {
            Info,
            Warning,
            Error,
            Info_NoDis,
            Warning_NoDis,
            Error_NoDis
        };

        // 日志基类
        class DllExport Logger
        {
        public:
            Logger();
            virtual ~Logger();

            virtual void print(Level _Level, const char * _Format, ...) = 0;
        };


        // DebugView 输出
        class DllExport LogTrace : public Logger
        {
        public:
            LogTrace();
            ~LogTrace();

            virtual void print(Level _Level, const char * _Format, ...);
        };


        // 控制台输出类
        class DllExport LogCMD : public Logger
        {
        public:
            LogCMD();
            ~LogCMD();

            virtual void print(Level _Level, const char * _Format, ...);
            void printPercent(size_t current, size_t total, float step);
        };


        // 文件输出类
        class DllExport LogFile : public Logger
        {
        public:
            LogFile();
            LogFile(string _FilePath);
            ~LogFile();

            virtual void print(Level _Level, const char * _Format, ...);

        protected:
            void CheckPath();       // 检查存储路径是否与当前日期相符
            void GetTime();         // 获取当前真实时间
            bool CheckTime();       // 判断当前真实时间是否与（上一次）存储路径相符


            FILE* m_fp;
            string m_rootPath;  // 日志存储根路径
            int m_year;         // （上一次）日志存储路径年
            int m_month;        // （上一次）日志存储路径月
            int m_day;          // （上一次）日志存储路径日
            
            tm m_time;          // 当前时间


            string m_i;
        };

    }
}
