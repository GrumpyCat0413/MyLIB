#include "Object.h"
#include <cstdlib>
#include <iostream>
using namespace std;
namespace MyLib
{

    void* Object::operator new (unsigned int size) throw()//异常规格说明：当前new不会抛出任何异常，失败后返回一个空值
    {
        cout<<"Object::operator new"<< size <<endl;
        return malloc(size);
    }

    void Object::operator delete (void* p)
    {
        cout<<"Object::operator delete"<< p <<endl;
        free(p);
    }

    void* Object::operator new[] (unsigned int size) throw()
    {
        return malloc(size);
    }

    void Object::operator delete[] (void* p)
    {
        free(p);
    }

    Object::~Object()
    {

    }


}


