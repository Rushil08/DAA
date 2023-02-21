//write code for finding the subarray with maximum sum using the divide and conquer approach.

#include <iostream>
using namespace std;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int max(int a, int b, int c)
{
    return max(max(a, b), c);
}

int max_crossing_sum(int arr[], int lo, int mid, int hi)
{
    int sum = 0;
    int left_sum = INT_MIN;
    for (int i = mid; i >= lo; i--)
    {
        sum += arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }

    sum = 0;
    int right_sum = INT_MIN;
    for (int i = mid + 1; i <= hi; i++)
    {
        sum += arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }

    return left_sum + right_sum;
}

int max_subarray_sum(int arr[], int lo, int hi)
{
    if (lo == hi)
        return arr[lo];

    int mid = lo + ((hi - lo) / 2);

    return max(max_subarray_sum(arr, lo, mid),
               max_subarray_sum(arr, mid + 1, hi),
               max_crossing_sum(arr, lo, mid, hi));
}

int main()
{
    int arr[] = {-2, -3, 4, -1, -2,1,5,-3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max_sum = max_subarray_sum(arr, 0, n - 1);
    cout << "Maximum contiguous sum is " << max_sum;
    return 0;
}