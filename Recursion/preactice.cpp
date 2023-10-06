// 1. WAP to print a name n-times
// 2. WAp to find factorial of a number using recursion
// 3. WAP to find fibonacci number at given position
// 4. WAP to reverse an array using recursion
// 5. WAP to check a string is palindrome or not using recursion

#include <iostream>
using namespace std;
void nPrint(int n)
{
    if (n == 0)
    {
        return;
    }
    cout << "\nName : Arvind";
    return nPrint(n - 1);
}

int fact(int num)
{
    if (num < 0)
    {
        cout << "Invalid num to find factorial!!";
        return 01;
    }
    if (num == 0 || num == 1)
    {
        return 1;
    }
    return num * fact(num - 1);
}


int main()
{

    return 0;
}
