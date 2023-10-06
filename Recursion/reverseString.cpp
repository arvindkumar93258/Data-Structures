// 1. Write a function to reverse a string. The input string is given as array of characters.
//  You must do this by modifying the input array in-place with O(n) time

#include <iostream>
using namespace std;
void reverseString(char arr[], int start, int end)
{
    if (start < end)
    {
        char temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        reverseString(arr, start + 1, end - 1);
    }
}

void reverse(char arr[], int length)
{

    return reverseString(arr, 0, length - 1);
}
void print(char arr[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << " " << arr[i];
    }
}

int main()
{
    char arr[] = {'a'};
    print(arr, 1);
    reverse(arr, 1);
    print(arr, 1);

    return 0;
}
