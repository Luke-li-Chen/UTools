#pragma once
#define DllExport   __declspec( dllexport )

namespace UTools
{
    using std::string;

    class DllExport IniFile
    {
    public:
        IniFile();
        IniFile(string path);
        ~IniFile();

        bool SetIniFilePath(string path);       // ����ini�ļ�·��

        string GetString(string app, string key, int maxSize);     // ��ȡ�ַ���
        char* GetPchar(const char* app, const char* key, int maxSize, char* dest);
        unsigned int GetInt(string app, string key, unsigned int defaultVal);     // ��ȡ����
        bool GetBool(string app, string key);                   // ��ȡBOOLֵ
        bool GetBool(const char* app, const char* key);

        // �����ַ���
        // ��������
        // ����BOOLֵ

    protected:
        string m_IniFilePath;    // ini �ļ�·��
    };
}
