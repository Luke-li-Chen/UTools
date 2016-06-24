#pragma once
#define DllExport   __declspec( dllexport )

typedef unsigned char byte;

namespace UTools
{
    namespace FloatingPoint
    {
        DllExport float SingalNaN(void);    // 返回信令NaN (Signaling NaN)
        DllExport float SingalQNaN(void);
        DllExport float SingalPINF(void);   // 返回正无穷
        DllExport float SingalNINF(void);   // 返回负无穷
        DllExport float SingalNZero(void);  // 返回负零

        DllExport double DoubleNaN(void);   // 返回信令NaN
        DllExport double DoublePINF(void);  // 返回正无穷
        DllExport double DoubleNINF(void);  // 返回负无穷
        DllExport double DoubleNZero(void); // 返回负零


        /// MFC 相关
#ifdef __AFX_H__
#pragma message("Is MFC Program")
#endif
    };
}

// P:Positive 正
// N:Negative 负

// 小数部分的最高位，其取值表示了NaN的类型，为'is_quiet'标记位。
// 即，如果 A = 1，则该数是 quiet NaN；如果 A 为零、其余小数部分非零，则是 signaling NaN。

/*

打印结果：

        |    printf    |   cout
NaN     |   1.#QNAN0   |  1.#QNAN
PINF    |   1.#INF00   |  1.#INF    _finite()返回0
NINF    |  -1.#INF00   | -1.#INF    _finite()返回0
NZero   |  -0.000000   |  -0  


_finite() 函数能否正确判断无穷大量存疑
//val = log((double)-1);  // -1.#IND00


*/

