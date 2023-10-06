#include <stdio.h>
#include <iostream>
using namespace std;

class Factorial
{

public:
    int fact(int num)
    {
        if (num < 0)
        {
            cout << "Factorial of -ve number can not be find!";
            return -1;
        }
        if (num == 0 || num == 1)
        {
            return num;
        }
        return num * fact(num - 1);
    }
};

int main()
{

    Factorial f;
    cout << " Factorial of 5: " << f.fact(10);

    return 0;
}
