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

        // ��־����
        class DllExport Logger
        {
        public:
            Logger();
            virtual ~Logger();

            virtual void print(Level _Level, const char * _Format, ...) = 0;
        };


        // DebugView ���
        class DllExport LogTrace : public Logger
        {
        public:
            LogTrace();
            ~LogTrace();

            virtual void print(Level _Level, const char * _Format, ...);
        };


        // ����̨�����
        class DllExport LogCMD : public Logger
        {
        public:
            LogCMD();
            ~LogCMD();

            virtual void print(Level _Level, const char * _Format, ...);
            void printPercent(size_t current, size_t total, float step);
        };


        // �ļ������
        class DllExport LogFile : public Logger
        {
        public:
            LogFile();
            LogFile(string _FilePath);
            ~LogFile();

            virtual void print(Level _Level, const char * _Format, ...);

        protected:
            void CheckPath();       // ���洢·���Ƿ��뵱ǰ�������
            void GetTime();         // ��ȡ��ǰ��ʵʱ��
            bool CheckTime();       // �жϵ�ǰ��ʵʱ���Ƿ��루��һ�Σ��洢·�����


            FILE* m_fp;
            string m_rootPath;  // ��־�洢��·��
            int m_year;         // ����һ�Σ���־�洢·����
            int m_month;        // ����һ�Σ���־�洢·����
            int m_day;          // ����һ�Σ���־�洢·����
            
            tm m_time;          // ��ǰʱ��


            string m_i;
        };

    }
}
