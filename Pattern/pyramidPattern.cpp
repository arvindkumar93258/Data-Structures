#include <iostream>

using namespace std;


void pyramid1(int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            cout<<"* ";
        }
        cout<<""<<endl;
    }
}


void pyramid2(int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=n-i; j>0; j--)
        {
            cout<<"  ";
            
        }
        for(int k=0; k<i; k++)
        {
            cout<<"* ";
        }
        cout<<"\n";
    }
}

void pyramid3(int n)
{
 for(int i=0; i<n; i++)
    {
        for(int j=n-i; j>0; j--)
        {
            cout<<" ";
            
        }
        for(int k=0; k<i; k++)
        {
            cout<<"*";
        }
        cout<<"\n";
        
    }
}

void pyramid4(int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=n-i; j>0; j--)
        {
        cout<<" ";
        }
        for(int k=0; k<i; k++)
        {
            cout<<"* ";
        }
        cout<<""<<endl;
    }
}

/*void pyramid5(int n)
{
    for(int i=1; i<n; i++)
    {
        
        for(int j=n-i; j>1; j--)
        {
        cout<<" ";
        }
        for(int j=1; j<2i-1; j++)
        {
            cout<<"*";
        }
        for(int j=n-i; j>1; j--)
        {
        cout<<"";
        }
        cout<<"\n";
    }
}

*/


void pyramid6(int n)
{
    for(int i=1; i<n; i++)
    {
        for(int j=1; j<=i; j++)
        {
            cout<<i<<" ";
        }
        cout<<""<<endl;
    }
}



void pyramid7(int n)
{
    int num=1;
    for(int i=1; i<n; i++)
    {
        for(int j=1; j<=i; j++)
        {
            cout<<num<<" ";
            num=num+1;
        }
        cout<<""<<endl;
    }
}




void pyramid8(int n)
{
    int num=65;
    for(int i=1; i<n; i++)
    {
        char ch = char(num);
        for(int j=1; j<=i; j++)
        {
            cout<<ch<<" ";
        }
        num+=1;
        cout<<"\n";
    }
}


void pyramid9(int n)
{
    int num=65;
    char ch= char(num);
    for(int i=1; i<n; i++)
    {
        for(int j=1; j<=i; j++)
        {
            cout<<ch<<" ";
            num+=1;
        }
        cout<<"\n";
    }
}
int main()
{
    cout<<"Pyramid structure 1\n";

    pyramid1(6);
    
    cout<<"pyramid structure 2\n";
    pyramid2(6);
    
    cout<<"Pyramid structure 3\n";
    pyramid3(6);
    
    
    cout<<"Pyramid structure 4\n";
    pyramid4(6);
    
    cout<<"Pyramid structure 5\n";
   // pyramid5(10);
   
    cout<<"Pyramid structure 6\n";
    pyramid6(8);
   
   
    cout<<"Pyramid structure 7\n";
    pyramid7(8);
   
    cout<<"Pyramid structure 8\n";
    pyramid8(8);
    
    
    cout<<"Pyramid structure 9\n";
    pyramid9(8);
    
    
    
    cout<<"\n";
    return 0;
}



/*

Pyramid structure 1
* 
* * 
* * * 
* * * * 
* * * * * 


Pyramid structure 2
      * 
                * * 
              * * * 
            * * * * 
          * * * * * 
        * * * * * * 
      * * * * * * * 
    * * * * * * * * 
  * * * * * * * * * 
* * * * * * * * * * 

Pyramid structure 3

  * 
       * * 
      * * * 
     * * * * 
    * * * * * 
Pyramid structure 4


 *
  ***
 *****
*******
Pyramid structure 5

1 
2 2 
3 3 3 
4 4 4 4 
5 5 5 5 5 

Pyramid structure 6

1 
2 3 
4 5 6 
7 8 9 10 
11 12 13 14 15 

Pyramid structure 7

A 
B B 
C C C 
D D D D 
E E E E E 

Pyramid structure 8

A 
B B 
C C C 
D D D D 
E E E E E 

Pyramid structure 9

A 
B C 
D E F 
G H I J 
K L M N O 



*/