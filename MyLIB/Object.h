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
        virtual ~Object() = 0; //指向虚函数表（占用4个字节的指针）

    };
}




#endif // OBJECT_H
