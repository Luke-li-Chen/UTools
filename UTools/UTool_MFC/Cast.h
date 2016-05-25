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

        static CString add(CString src);
    };
}


