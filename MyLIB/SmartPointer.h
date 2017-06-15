#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H

#include "Object.h"

namespace MyLib{

    template <typename T>
    class SmartPointer : public Object    //继承顶层父类Object
    {
    protected:
        T* m_pointer;
    public:
        SmartPointer(T* p = NULL)
        {
            m_pointer = p;
        }
                                                        //同一片堆空间 只能有一个指针指向
        SmartPointer(const SmartPointer<T>& obj)        //拷贝构造函数
        {
            m_pointer = obj.m_pointer;  //将当前对象的指针指向 obj对象所指的堆空间 ，此时这个堆空间有两个指针
            const_cast<SmartPointer<T>&>(obj).m_pointer = NULL;//利用强制类型转换 将obj对象的指针置空
        }

        SmartPointer<T>& operator= (const SmartPointer<T>& obj)     //赋值构造函数
        {
            if( this != &obj)//判断当前是否为自赋值
            {
                delete m_pointer;//释放当前指针所指向的堆空间

                m_pointer = obj.m_pointer;
                const_cast<SmartPointer<T>&>(obj).m_pointer = NULL;
            }

            return *this;//支持连续的赋值
        }

        T* operator-> ()
        {
            return m_pointer;
        }

        T& operator* ()
        {
            return *m_pointer;
        }

        bool isNull()
        {
            return (m_pointer == NULL);
        }

        T* get()
        {
            return m_pointer;
        }

        ~SmartPointer()
        {
            delete m_pointer;
        }
    };

}


#endif // SMARTPOINTER_H
