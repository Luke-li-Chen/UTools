#include "StdAfx.h"
#include "FloatingPoint.h"

using namespace UTools;

using std::string;
using std::numeric_limits;

#include <bitset>
using std::bitset;

float FloatingPoint::SingalNaN(void)
{
    unsigned long nan[1] = { 0x7FC00001 };
    return *(float*)nan;
}

float FloatingPoint::SingalQNaN(void)
{
    unsigned long nan[1] = { 0x7F800001 };
    return *(float*)nan;
}

float FloatingPoint::SingalPINF(void)
{
    return numeric_limits<float>::infinity();
}


float FloatingPoint::SingalNINF(void)
{
    return -numeric_limits<float>::infinity();
}


float FloatingPoint::SingalNZero(void)
{
    unsigned long nZero[1] = { 0x80000000 };
    return *(float*)nZero;
}


double FloatingPoint::DoubleNaN(void)
{
    unsigned long nan[2] = { 0x00000001, 0x7ff80000 };
    return *(double*)nan;
}


double FloatingPoint::DoublePINF(void)
{
    return numeric_limits<double>::infinity();
}


double FloatingPoint::DoubleNINF(void)
{
    return -numeric_limits<double>::infinity();
}


double FloatingPoint::DoubleNZero(void)
{
    unsigned long nZero[2] = { 0x00000000, 0x80000000 };
    return *(double*)nZero;
}



#if 0
// 自拼方式实现：

float FloatingPoint::SingalPINF(void)
{
    unsigned long pInf[1] = { 0x7F800000 };
    return *(float*)pInf;
}
// Release 配置下循环运行 100,000,000 次，
// STL 方式耗时   237 ms.
// 自己拼方式耗时 353 ms.


float FloatingPoint::SingalNINF(void)
{
    unsigned long nInf[1] = { 0xFF800000 };
    return *(float*)nInf;
}
// Release 配置下循环运行 100,000,000 次，
// STL 方式耗时   249 ms.
// 自己拼方式耗时 281 ms.


double FloatingPoint::DoublePINF(void)
{
    unsigned long pInf[2] = { 0x00000000 ,0x7ff00000 };
    return *(double*)pInf;
}
// Release 配置下循环运行 100,000,000 次，
// STL 方式耗时   261 ms.
// 自己拼方式耗时 994 ms.


double FloatingPoint::DoubleNINF(void)
{
    unsigned long nInf[2] = { 0x00000000, 0xfff00000 };
    return *(double*)nInf;
}


float FloatingPoint::SingalNaN(void)
{
    // 使用 STL
    return numeric_limits<float>::signaling_NaN();
}
// Release 配置下循环运行 100,000,000 次，
// STL 方式耗时  15355 ms.
// 自己拼方式耗时  224 ms.


double FloatingPoint::DoubleNaN(void)
{
    // 使用 STL
    return numeric_limits<double>::signaling_NaN();
}
// Release 配置下循环运行 100,000,000 次，
// STL 方式耗时  14967 ms.
// 自己拼方式耗时  842 ms.


#endif


double GenerateNaN(void)
{
    unsigned long nan[2] = { 0xFFFFFFFF, 0x7FFFFFFF };

    return *(double*)nan;
}


//bitset<32> b("01111111100000000000000000000001");
////            01234567012345670123456701234567

//UINT u = b.to_ulong();
//printf("%u\n", u);
//printf("%x\n", u);

//UINT u = *(UINT*)(&val);

//unsigned long nan[1] = { 0x7F800000 };

//float val2 = *(float*)nan;

//printf("%d\n", memcmp(&val, &val2, 4));
//memcpy(&val, &u, 4);


//printf("%f\n", val);
//printf("%x\n", u);



