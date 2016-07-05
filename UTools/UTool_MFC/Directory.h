#pragma once

#define DllExport   __declspec( dllexport )

namespace UTools
{
    namespace IO
    {
        using std::string;
        using std::vector;

        class Directory
        {
        public:
            Directory();
            ~Directory();

            //TODO: 检测目录是否存在
            static bool Exists(
                const string& path
            );

            //TODO: 创建目录，返回 DirectoryInfo
            static void Create(string path);

            //TODO：将文件或目录及其内容移到新位置
            static void Move(
                string sourceDirName,   // 要移动的文件或目录的路径
                string destDirName      // 指向 sourceDirName 的新位置的路径
            );

            //TODO: 复制目录；C#中无此方法
            static void Copy(
                string sourceDirName,   // 要复制的文件或目录的路径
                string destDirName      // 指向 sourceDirName 的新位置的路径
            );

            //TODO：删除目录
            static void Delete(string path, bool recursive);

            //TODO：返回指定目录中所有文件的名称。
            static vector<string>& GetFiles(string path, vector<string>& vStr);

            //TODO：返回指定目录中所有与指定搜索模式匹配的文件的名称。
            static vector<string>& GetFiles(string path, string searchPattern, vector<string>& vStr);
            
            //TODO：获取指定目录中的子目录的名称（包括其路径）。
            static vector<string>& GetDirectories(
                string path,
                vector<string>& vStr
            );

            //TODO：在当前目录获取与指定搜索模式匹配的目录的数组（包括它们的路径）。
            static vector<string>& GetDirectories(
                string path,
                string searchPattern,
                vector<string>& vStr
            );

            /// MFC 相关
#ifdef __AFX_H__
#pragma message("Is MFC Program")


#endif
        };
    }
}

