//C++ program to solve fractional-Knapsack using Max-heap concepts
#include <bits/stdc++.h>

using namespace std;

//max-heapifying at the given index
void max_heapify(vector<pair<int, int>> &arr, int size, int index)
{
    int leftIndex = 2 * index + 1;
    int rightIndex = 2 * index + 2;

    //for storing the index having the profit/weight ratio
    int maxIndex = index;

    //leftIndex have higher profit/weight ratio than index
    if (leftIndex < size && (arr[index].first / arr[index].second) < (arr[leftIndex].first / arr[leftIndex].second))
    {
        maxIndex = leftIndex;
    }

    //rightIndex have higher profit/weight ratio than maxIndex
    if (rightIndex < size && (arr[maxIndex].first / arr[maxIndex].second) < (arr[rightIndex].first / arr[rightIndex].second))
    {
        maxIndex = rightIndex;
    }

    if (maxIndex != index)
    {
        swap(arr[maxIndex], arr[index]);
        max_heapify(arr, size, maxIndex);
    }
}

//function to building max-heap
void buildMaxHeap(vector<pair<int, int>> &arr, int size)
{
    //calling the max-heapify from the last node having child
    for (int i = size / 2; i >= 0; i--)
    {
        max_heapify(arr, size, i);
    }
}


//function to extract maximumItem remaining in max-heap having highest profit/weight ratio from the max-heap
pair<int, int> extract_max(vector<pair<int, int>> &arr, int size)
{
    pair<int, int> result;

    if (size > 0)
    {
        result = arr[0];
    }
    swap(arr[0], arr[size - 1]);
    max_heapify(arr, size - 1, 0);
    return result;
}

//main greedy function to solve the problem
int fractionalKnapsack(vector<pair<int, int>> &arr, int size, int W)
{
    //building max-heap
    buildMaxHeap(arr, size);

    

    pair<int, int> item;

    //profit varialbe declaration
    int profit = 0;

    //loop for putting as much as possible items in the bag of size w
    while (size > 0 && W > 0)
    {
        item = extract_max(arr, size);

        // If adding Item won't overflow, add it completely
        if (W >= item.second)
        {
            W -= item.second;
            profit += item.first;
        }
        // If we can't add current Item, add fractional part
        // of it
        else
        {
            profit += item.first * ((double)W / (double)item.second);
            break;
        }
        size-=1;
    }

    //returning the final profit 
    return profit;
}

int main()
{

    int W = 5; //    Weight of knapsack
    vector<pair<int, int>> arr = {{60, 10}};

    // size of vector
    int size = arr.size();

    //function call to get maximum profit for given bag-size W
    cout<<"Maximum profit we can gain is  = "<<fractionalKnapsack(arr, size, W);

    return 0;
}