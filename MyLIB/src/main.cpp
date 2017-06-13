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





    return 0;
}

