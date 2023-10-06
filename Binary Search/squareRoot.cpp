#include <bits/stdc++.h>
using namespace std;

class BinarySearch
{
public:
    long long int squareRoot(long long int x)
    {
        if (x == 1 || x == 0)
        {
            return x;
        }
        long long int start = 1;
        long long int end = x / 2;
        long long mid;
        cout << "start: " << start << " mid: " << mid << " end: " << end << endl;
        long long ans;

        while (start <= end)
        {
            mid = (start + end) / 2;
            long long int square = mid * mid;
            if (square == x)
            {
                return mid;
            }
            else if (square <= x)
            {
                start = mid + 1;
                ans = mid;
            }
            else
            {
                end = mid - 1;
            }
            cout << "start: " << start << " mid: " << mid << " end: " << end << endl;
        }
        // cout << "Result is : " << mid;
        return ans;
    }
    double squareRoot(double x, int precision)
    {
        int ans = 0;
        if (x == 1 || x == 0)
        {
            return x;
        }

        int start = 0, end = x / 2;
        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            long long square = mid * mid;
            if (square == int(x))
            {
                ans = mid;
                break;
            }
            if (square <= int(x))
            {
                ans = mid;
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        double result = ans;
        float increment = 0.1;
        for (int i = 0; i < precision; i++)
        {
            while (result * result <= x)
            {
                result += increment;
            }
            result -= increment;
            increment /= 10;
        }
        return result;
    }
};

int main()
{

    BinarySearch bs;
    long long result = bs.squareRoot(2);
    cout << "Result is: " << result;
    double result1 = bs.squareRoot(2, 3);
    cout << "Result is: " << result1;

    return 0;
}
