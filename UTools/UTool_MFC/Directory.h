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

            //TODO: ���Ŀ¼�Ƿ����
            static bool Exists(
                const string& path
            );

            //TODO: ����Ŀ¼������ DirectoryInfo
            static void Create(string path);

            //TODO�����ļ���Ŀ¼���������Ƶ���λ��
            static void Move(
                string sourceDirName,   // Ҫ�ƶ����ļ���Ŀ¼��·��
                string destDirName      // ָ�� sourceDirName ����λ�õ�·��
            );

            //TODO: ����Ŀ¼��C#���޴˷���
            static void Copy(
                string sourceDirName,   // Ҫ���Ƶ��ļ���Ŀ¼��·��
                string destDirName      // ָ�� sourceDirName ����λ�õ�·��
            );

            //TODO��ɾ��Ŀ¼
            static void Delete(string path, bool recursive);

            //TODO������ָ��Ŀ¼�������ļ������ơ�
            static vector<string>& GetFiles(string path, vector<string>& vStr);

            //TODO������ָ��Ŀ¼��������ָ������ģʽƥ����ļ������ơ�
            static vector<string>& GetFiles(string path, string searchPattern, vector<string>& vStr);
            
            //TODO����ȡָ��Ŀ¼�е���Ŀ¼�����ƣ�������·������
            static vector<string>& GetDirectories(
                string path,
                vector<string>& vStr
            );

            //TODO���ڵ�ǰĿ¼��ȡ��ָ������ģʽƥ���Ŀ¼�����飨�������ǵ�·������
            static vector<string>& GetDirectories(
                string path,
                string searchPattern,
                vector<string>& vStr
            );

            /// MFC ���
#ifdef __AFX_H__
#pragma message("Is MFC Program")


#endif
        };
    }
}

