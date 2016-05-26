#pragma once



namespace UTools
{
    using std::string;

    class __declspec(dllexport) Cast
    {
    public:
        Cast();
        ~Cast();

        // int -> string
        static string int2string(int Value, int Radix);
        static inline string int2string(int Value);

        // string -> char[]
        static char* string2NewPchar(const string& str);

#ifdef __AFX_H__
#pragma message("Is MFC Program")

        static CString add(CString src);

#endif
    };
}


