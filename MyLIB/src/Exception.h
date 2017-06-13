#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <cstdlib>

namespace MyLib {

#define THROW_EXCEPTION(e, m) (throw e(m, __FILE__, __LINE__))


//为顶层 抽象父类
class Exception
{
protected:
    char* m_message;        // 异常信息
    char* m_location;       //发生异常地点

    void init(const char* message, const char* file, int line);  //辅助初始化
public:
    Exception(const char* message);
    Exception(const char* file, int line);
    Exception(const char* message, const char* file, int line);
    Exception(const Exception& e);
    Exception& operator= (const Exception& e);

    virtual const char* message() const;
    virtual const char* location() const;

    virtual ~Exception() = 0;//纯虚析构函数 等待子类来完成
    //但凡定义了 析构函数，不管这个析构函数是不是纯虚函数，必须提供实现

};

//计算异常
class ArithmeticException : public Exception
{
public:
    ArithmeticException():Exception(NULL){}
    ArithmeticException(const char* message):Exception(message){}
    ArithmeticException(const char* file,int line):Exception(file,line){}
    ArithmeticException(const char* message,const char* file, int line):Exception(message,file,line){}

    ArithmeticException(const ArithmeticException& e):Exception(e){}
    ArithmeticException& operator= (const ArithmeticException& e)
    {
        Exception::operator =(e);

        return *this;
    }
};

//空指针异常
class NullPointerException:public Exception
{
public:
    NullPointerException():Exception(NULL){}
    NullPointerException(const char* message):Exception(message){}
    NullPointerException(const char* file,int line):Exception(file,line){}
    NullPointerException(const char* message,const char* file, int line):Exception(message,file,line){}

    NullPointerException(const NullPointerException& e):Exception(e){}
    NullPointerException& operator= (const NullPointerException& e)
    {
        Exception::operator =(e);

        return *this;
    }
};

//越界异常
class IndexOutOfBoundsException:public Exception
{
public:
    IndexOutOfBoundsException():Exception(NULL){}
    IndexOutOfBoundsException(const char* message):Exception(message){}
    IndexOutOfBoundsException(const char* file,int line):Exception(file,line){}
    IndexOutOfBoundsException(const char* message,const char* file, int line):Exception(message,file,line){}

    IndexOutOfBoundsException(const IndexOutOfBoundsException& e):Exception(e){}
    IndexOutOfBoundsException& operator= (const IndexOutOfBoundsException& e)
    {
        Exception::operator =(e);

        return *this;
    }
};


//内存不足异常
class NoEnoughMemoryException:public Exception
{
public:
    NoEnoughMemoryException():Exception(NULL){}
    NoEnoughMemoryException(const char* message):Exception(message){}
    NoEnoughMemoryException(const char* file,int line):Exception(file,line){}
    NoEnoughMemoryException(const char* message,const char* file, int line):Exception(message,file,line){}

    NoEnoughMemoryException(const NoEnoughMemoryException& e):Exception(e){}
    NoEnoughMemoryException& operator= (const NoEnoughMemoryException& e)
    {
        Exception::operator =(e);

        return *this;
    }
};

//参数错误异常
class InvalidParameterException:public Exception
{
public:
    InvalidParameterException():Exception(NULL){}
    InvalidParameterException(const char* message):Exception(message){}
    InvalidParameterException(const char* file,int line):Exception(file,line){}
    InvalidParameterException(const char* message,const char* file, int line):Exception(message,file,line){}

    InvalidParameterException(const InvalidParameterException& e):Exception(e){}
    InvalidParameterException& operator= (const InvalidParameterException& e)
    {
        Exception::operator =(e);

        return *this;
    }
};

}
#endif // EXCEPTION_H
