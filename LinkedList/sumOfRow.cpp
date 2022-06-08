#include<bits/stdc++.h>
using namespace std;


int main()
{
    int s[3][3], i, j, sum = 0;
    cout<<"Enter the matrix element : ";
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            scanf("%d", &s[i][j]);
        }
    }
    printf("Sum of row of matrix is : \n");
    for (i = 0; i < 3; i++)
    {
        sum = 0;
        for (j = 0; j < 3; j++)
        {
            sum += s[i][j];
        }
        printf("sum of Row %d is %d\n", i, sum);
    }

    return 0;
}