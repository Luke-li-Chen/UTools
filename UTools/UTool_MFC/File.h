#pragma once
#define DllExport   __declspec( dllexport )


namespace UTools
{
    namespace IO
    {
        class DllExport File
        {
        public:
            File();
            ~File();

            static __int64 GetSize(const char* FilePath);
            static bool Exist(const char* FilePath);
            static bool Delete(const char* FilePath);
        };
    }
}



