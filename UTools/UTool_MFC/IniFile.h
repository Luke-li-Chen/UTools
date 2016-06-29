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

        bool SetIniFilePath(string path);       // 设置ini文件路径

        string GetString(string app, string key, int maxSize);     // 读取字符串
        char* GetPchar(const char* app, const char* key, int maxSize, char* dest);
        unsigned int GetInt(string app, string key, unsigned int defaultVal);     // 读取整数
        bool GetBool(string app, string key);                   // 读取BOOL值
        bool GetBool(const char* app, const char* key);

        // 设置字符串
        // 设置整数
        // 设置BOOL值

    protected:
        string m_IniFilePath;    // ini 文件路径
    };
}
