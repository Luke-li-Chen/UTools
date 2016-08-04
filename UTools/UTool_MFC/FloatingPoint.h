#pragma once
#define DllExport   __declspec( dllexport )

typedef unsigned char byte;

namespace UTools
{
    namespace FloatingPoint
    {
        DllExport float SingalNaN(void);    // ��������NaN (Signaling NaN)
        DllExport float SingalQNaN(void);
        DllExport float SingalPINF(void);   // ����������
        DllExport float SingalNINF(void);   // ���ظ�����
        DllExport float SingalNZero(void);  // ���ظ���

        DllExport double DoubleNaN(void);   // ��������NaN
        DllExport double DoublePINF(void);  // ����������
        DllExport double DoubleNINF(void);  // ���ظ�����
        DllExport double DoubleNZero(void); // ���ظ���


        /// MFC ���
#ifdef __AFX_H__
#pragma message("Is MFC Program")
#endif
    };
}

// P:Positive ��
// N:Negative ��

// С�����ֵ����λ����ȡֵ��ʾ��NaN�����ͣ�Ϊ'is_quiet'���λ��
// ������� A = 1��������� quiet NaN����� A Ϊ�㡢����С�����ַ��㣬���� signaling NaN��

/*

��ӡ�����

        |    printf    |   cout
NaN     |   1.#QNAN0   |  1.#QNAN
PINF    |   1.#INF00   |  1.#INF    _finite()����0
NINF    |  -1.#INF00   | -1.#INF    _finite()����0
NZero   |  -0.000000   |  -0  


_finite() �����ܷ���ȷ�ж������������
//val = log((double)-1);  // -1.#IND00


*/

