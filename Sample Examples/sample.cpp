#include<bits/stdc++.h>

using namespace std;

class A
{
    public:
    void f1()
    {
        cout<<"Class A";
    }
};

class B:public A
{
    public:
    void f1()
    {
        cout<<"Class B";
    }
};


int main()
{

    A a;
    a.f1();
    A b = a;
    b.f1();

    B c;
    A &d = c;
    d.f1();


    return 0;
}