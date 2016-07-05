#pragma once
#define DllExport   __declspec( dllexport )


namespace UTools
{
    namespace Log
    {
        class DllExport Logger
        {
        public:
            Logger();
            virtual ~Logger();

            virtual void print(const char * _Format, ...) = 0;
        };


        class DllExport LogTrace : public Logger
        {
        public:
            LogTrace();
            ~LogTrace();

            virtual void print(const char * _Format, ...);
        };

        class DllExport LogFile : public Logger
        {
        public:
            LogFile();
            LogFile(std::string _FilePath);
            ~LogFile();

            virtual void print(const char * _Format, ...);

        protected:
            FILE* m_fp;
        };
    }
}
