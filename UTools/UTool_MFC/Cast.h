#pragma once

#define DllExport   __declspec( dllexport )

typedef unsigned char byte;

namespace UTools
{
    using std::string;

    namespace Cast
    {
        // int -> string
        DllExport string IntToString(int Value, int Radix);
        DllExport inline string IntToString(int Value);

        // string -> char[]
        DllExport char* StringToNewCharArray(const string& str);

        // byte[4] -> float
        DllExport float ByteArrayToFloat(const byte Src[4]);

        // float -> byte[4]
        DllExport byte* FloatToByteArray(float Src, byte Dst[4]);



        /// MFC Ïà¹Ø
#ifdef __AFX_H__
#pragma message("Is MFC Program")

        // CString -> char[]
        DllExport char* CStringAToCharArray(const CStringA& csSrc, char* szDst, size_t count);

        
        // CString -> string
        DllExport string& CStringToString(
            const CString& src,
            string& dest
        );

        // CString -> string
        DllExport string& CStringToNewString(
            const CString& src
        );


        // CByteArray -> float
        DllExport float CByteArrayToFloat(const CByteArray& Src);

        // float -> CByteArray
        DllExport CByteArray& FloatToCByteArray(float Src, CByteArray& Dst);


#endif
    };
}


