#pragma once

#define DllExport   __declspec( dllexport )

// ���ӿ���
class DllExport ILock
{
public:
    ILock();
    virtual ~ILock();

    virtual void Lock() const = 0;
    virtual void UnLock() const = 0;
};

// �����������
class DllExport Mutex : public ILock
{
public:
    Mutex();
    ~Mutex();

    virtual void Lock() const;
    virtual void UnLock() const;

private:
    HANDLE m_mutex;
};

// �ٽ�������
class DllExport CriSection : public ILock
{
public:
    CriSection();
    ~CriSection();

    virtual void Lock() const;
    virtual void UnLock() const;

private:
    CRITICAL_SECTION m_critclSection;
};


// ��
class DllExport CMyLock
{
public:
    CMyLock(const ILock&);
    ~CMyLock();

private:
    const ILock& m_lock;
};



