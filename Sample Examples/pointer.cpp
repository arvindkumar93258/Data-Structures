#include<bits/stdc++.h>
using namespace std;


class A
{
    public:
    int a;
    void show()
    {
        cout<<"Base class A\n";
    }
};
class B: public A
{
   
};
class D: public A
{
   
};
class E: public B, public D
{
    
};


class b
{
    public:
    b()
    {
        cout<<"Constructing base class b";
    }
    ~b()
    {
        cout<<"Destructing base class";
    }
};
class d: public b
{
    public:
    d()
    {
        cout<<"Constructing derived class d";
    }
    ~d()
    {
        cout<<"Destructing derived class d";
    }
};

int main()
{

    // int a=10;
    // int *ptr = &a;
    // printf("%d, %d", ptr, *ptr);

    //E e;
    //e.show();

    d* derived = new d();
    b* bptr = derived;
    delete(bptr);

    


    return 0;
}