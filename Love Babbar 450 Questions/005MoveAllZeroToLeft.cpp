#include <bits/stdc++.h>
using namespace std;

void sortNegativrPositive(vector<int> &arr, int n)
{

    // -12, 1, -1, 10, -2, 5
    // low =0, high = n-1
    /*
    case 1:

    */
    int low = 0, high = n - 1;
    while (low <= high)
    {
        if (arr[low] < 0 && arr[high] < 0)
        {
            high--;
        }
        else if (arr[low] < 0 && arr[high] > 0)
        {
            low++;
            high--;
        }
        else if (arr[low] > 0 && arr[high] < 0)
        {
            swap(arr[low], arr[high]);
            low++;
            high--;
        }
        else
        {
            high--;
        }
    }
    cout << "\nNow Array is : ";
    for (auto i : arr)
    {
        cout << " " << i;
    }
}

void printArray(vector<int> &arr, int n)
{
    cout << "\n Array is : ";
    for (auto i : arr)
    {
        cout << " " << i;
    }
}

int main()
{
    int t;
    cin >> t; // number of test cases

    while (t--)
    {
        int n;
        cin >> n; // number of elements in the array
        vector<int> arr;
        for (int i = 0; i < n; i++)
        {
            int temp;
            cin >> temp;
            arr.push_back(temp);
        }
        printArray(arr, n);
        sortNegativrPositive(arr, n);
    }

    return 0;
}