#include <bits/stdc++.h>
using namespace std;

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int *arr, int lo, int hi)
{
    int i = lo - 1;
    int pivot = arr[hi];

    for (int j = lo; j < hi; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[hi]);
    return i + 1;
}

void quicksort_rec(int *arr, int lo, int hi)
{
    if (lo < hi)
    {
        int pi = partition(arr, lo, hi);
        quicksort_rec(arr, lo, pi - 1);
        quicksort_rec(arr, pi + 1, hi);
    }
}

void quicksort_it(int *arr, int lo, int hi)
{
    int stack[hi - lo + 1];
    int top = -1; // intializing top of the stack

    stack[++top] = lo;
    stack[++top] = hi;

    // popping form stack till it is empty
    while (top >= 0)
    {
        hi = stack[top--];
        lo = stack[top--];

        int part = partition(arr, lo, hi);
        // gives the position from where we partition the list into left and right subarrays

        // if elements present on the left side of the pivot, then push left side to stack
        if (part - 1 > lo)
        {
            stack[++top] = lo;
            stack[++top] = part - 1;
        }

        // if elements present on the right side of the pivot, the push right side to stack
        if (part + 1 < hi)
        {
            stack[++top] = part + 1;
            stack[++top] = hi;
        }
    }
}

int main()
{
    int *arr;
    int n;
    cin >> n;
    arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    quicksort_it(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}