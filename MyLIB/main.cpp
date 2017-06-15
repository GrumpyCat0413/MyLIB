#include <iostream>
#include "Exception.h"
#include "Object.h"
#include "SmartPointer.h"

using namespace std;
using namespace MyLib;

class TestSP//测试智能指针
{
public:
    TestSP()
    {
        cout << "TestSP" << endl;
    }
    ~TestSP()
    {
        cout << "~TestSP" << endl;
    }
};


class Test : public Object  //内存大小：12字节,4+4+4（虚函数）
{
public:
    int i;
    int j;

};

class Child : public Test  //12+4
{
public:
    int k;
};


int main()
{
    cout << "Hello World!" << endl;

    SmartPointer<TestSP> sp = new TestSP();//TestSP
    SmartPointer<TestSP> nsp;

    nsp = sp;
    //nsp++; //不能够做指针++的运算
    cout << sp.isNull() << endl;//1
    cout << nsp.isNull()<<endl;//0

    try
    {
        //throw Exception("test",__FILE__,__LINE__);
        //THROW_EXCEPTION(NullPointerException,"test");//扔出子类对象，子类对象可以出现在任何父类需要对象的地方
        THROW_EXCEPTION(ArithmeticException,"test");
    }
    catch(const ArithmeticException& e)
    {
        cout<<"catch(const ArithmeticException& e)"<<endl;

        cout<< e.message()<<endl;
        cout<< e.location()<<endl;

    }
    catch(const NullPointerException& e)
    {
        cout<<"catch(const NullPointerException& e)"<<endl;

        cout<< e.message()<<endl;
        cout<< e.location()<<endl;

    }
    catch(const IndexOutOfBoundsException& e)
    {
        cout<<"catch(const IndexOutOfBoundsException& e)"<<endl;

        cout<< e.message()<<endl;
        cout<< e.location()<<endl;

    }
    catch(const NoEnoughMemoryException& e)
    {
        cout<<"catch(const NoEnoughMemoryException& e)"<<endl;

        cout<< e.message()<<endl;
        cout<< e.location()<<endl;

    }
    catch(const InvalidParameterException& e)
    {
        cout<<"catch(const InvalidParameterException& e)"<<endl;

        cout<< e.message()<<endl;
        cout<< e.location()<<endl;

    }
    catch(const Exception& e)//父类放在最后
    {
        cout<<"catch(const Exception& e)"<<endl;

        cout<< e.message()<<endl;
        cout<< e.location()<<endl;

    }

    Object* obj1 = new Test();
    Object* obj2 = new Child();

    cout << "obj1 = "<< obj1 <<endl;
    cout << "obj2 = "<< obj2 <<endl;
    delete obj1;
    delete obj2;




    return 0;
}

