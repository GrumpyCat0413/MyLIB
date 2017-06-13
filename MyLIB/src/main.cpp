#include <iostream>
#include "Exception.h"


using namespace std;
using namespace MyLib;

int main()
{
    cout << "Hello World!" << endl;

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





    return 0;
}

