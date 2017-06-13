#include "Exception.h"
#include <cstring>
#include <cstdlib>

namespace MyLib
{
    void Exception::init(const char *message, const char *file, int line)
    {
        //����message��һ��ָ�룬ָ����ַ��� �п��� ��ջ�ϡ����ϡ�ȫ����������û������ָ����ַ�������������.
        //����˵�����ǲ���ȫ�ģ�m_message = message��,���ܱ��ͷţ�������Ҫ����һ����Ϣ.
        m_message = strdup(message);//�ַ�������һ�ݵ��ѿռ䣬m_messageָ��Կռ���ַ���

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

//�������캯��
Exception::Exception(const Exception &e)
{
    //ָ��Ķ���һ�ζ����Ķѿռ�
    m_message = strdup(e.m_message);
    m_location = strdup(e.m_location);
}

Exception& Exception::operator =(const Exception& e)
{
    if(this != &e)//�����Ը�ֵ
    {
        free(m_message);
        free(m_location);

        //���
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
