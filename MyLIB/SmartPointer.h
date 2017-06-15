#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H

#include "Object.h"

namespace MyLib{

    template <typename T>
    class SmartPointer : public Object    //�̳ж��㸸��Object
    {
    protected:
        T* m_pointer;
    public:
        SmartPointer(T* p = NULL)
        {
            m_pointer = p;
        }
                                                        //ͬһƬ�ѿռ� ֻ����һ��ָ��ָ��
        SmartPointer(const SmartPointer<T>& obj)        //�������캯��
        {
            m_pointer = obj.m_pointer;  //����ǰ�����ָ��ָ�� obj������ָ�Ķѿռ� ����ʱ����ѿռ�������ָ��
            const_cast<SmartPointer<T>&>(obj).m_pointer = NULL;//����ǿ������ת�� ��obj�����ָ���ÿ�
        }

        SmartPointer<T>& operator= (const SmartPointer<T>& obj)     //��ֵ���캯��
        {
            if( this != &obj)//�жϵ�ǰ�Ƿ�Ϊ�Ը�ֵ
            {
                delete m_pointer;//�ͷŵ�ǰָ����ָ��Ķѿռ�

                m_pointer = obj.m_pointer;
                const_cast<SmartPointer<T>&>(obj).m_pointer = NULL;
            }

            return *this;//֧�������ĸ�ֵ
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
