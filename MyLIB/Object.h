#ifndef OBJECT_H
#define OBJECT_H

namespace MyLib{

    class Object
    {
    public:
        void* operator new (unsigned int size) throw();
        void operator delete (void* p);
        void* operator new[] (unsigned int size) throw();
        void operator delete[] (void* p);
        virtual ~Object() = 0; //ָ���麯����ռ��4���ֽڵ�ָ�룩

    };
}




#endif // OBJECT_H
