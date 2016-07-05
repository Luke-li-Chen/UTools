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

            __int64 GetSize(const char* FilePath);
        };
    }
}



