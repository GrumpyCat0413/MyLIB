#include "Exception.h"
#include <cstring>
#include <cstdlib>

namespace MyLib
{
    void Exception::init(const char *message, const char *file, int line)
    {
        //参数message是一个指针，指向的字符串 有可能 在栈上、堆上、全局数据区，没法控制指向的字符串的声明周期.
        //所以说这样是不安全的（m_message = message）,可能被释放，所以需要拷贝一份信息.
        m_message = strdup(message);//字符串复制一份到堆空间，m_message指向对空间的字符串

        if(file != NULL)
        {
            char sl[16] = {0};
            itoa(line,sl,10);
            m_location = static_cast<char*>(malloc(strlen(file)+strlen(sl)+2));
            m_location = strcpy(m_location,file);
            m_location = strcat(m_location,":");
            m_location = strcat(m_location,sl);
        }
        else
        {
            m_location = NULL;
        }

    }

Exception::Exception(const char* message)
{
    init(message,NULL,0);
}

Exception::Exception(const char *file, int line)
{
    init(NULL,file,line);
}

Exception::Exception(const char *message, const char *file, int line)
{
    init(message,file,line);
}

//拷贝构造函数
Exception::Exception(const Exception &e)
{
    //指向的都是一段独立的堆空间
    m_message = strdup(e.m_message);
    m_location = strdup(e.m_location);
}

Exception& Exception::operator =(const Exception& e)
{
    if(this != &e)//不是自赋值
    {
        free(m_message);
        free(m_location);

        //深拷贝
        m_message = strdup(e.m_message);
        m_location = strdup(e.m_location);
    }

    return *this;
}


const char* Exception::message() const
{
    return m_message;
}
const char* Exception::location() const
{
    return m_location;
}

Exception::~Exception()
{
    free(m_message);
    free(m_location);
}

}
