#include <iostream>
#include "Exception.h"
#include "Object.h"
#include "SmartPointer.h"

using namespace std;
using namespace MyLib;

class TestSP//��������ָ��
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


class Test : public Object  //�ڴ��С��12�ֽ�,4+4+4���麯����
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
    //nsp++; //���ܹ���ָ��++������
    cout << sp.isNull() << endl;//1
    cout << nsp.isNull()<<endl;//0

    try
    {
        //throw Exception("test",__FILE__,__LINE__);
        //THROW_EXCEPTION(NullPointerException,"test");//�ӳ�����������������Գ������κθ�����Ҫ����ĵط�
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
    catch(const Exception& e)//����������
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

