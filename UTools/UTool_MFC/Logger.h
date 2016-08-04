#pragma once
#define DllExport   __declspec( dllexport )


namespace UTools
{
    namespace Log
    {
        enum Level
        {
            Info,
            Warning,
            Error,
            Info_NoDis,
            Warning_NoDis,
            Error_NoDis
        };
        class DllExport Logger
        {
        public:
            Logger();
            virtual ~Logger();

            virtual void print(Level _Level, const char * _Format, ...) = 0;
        };


        class DllExport LogTrace : public Logger
        {
        public:
            LogTrace();
            ~LogTrace();

            virtual void print(Level _Level, const char * _Format, ...);
        };

        class DllExport LogFile : public Logger
        {
        public:
            LogFile();
            LogFile(std::string _FilePath);
            ~LogFile();

            virtual void print(Level _Level, const char * _Format, ...);

        protected:
            FILE* m_fp;
        };
    }
}
