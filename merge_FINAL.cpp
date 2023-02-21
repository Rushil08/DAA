#include <bits/stdc++.h>
using namespace std;

void merge(int *arr, int lo, int mid, int hi)
{
    int n = mid - lo + 1;
    int m = hi - mid;

    int arr1[n], arr2[m];

    for (int i = 0; i < n; i++)
    {
        arr1[i] = arr[lo + i];
    }
    for (int i = 0; i < m; i++)
    {
        arr2[i] = arr[mid + 1 + i];
    }

    int p = 0, q = 0, r = lo;
    while (p < n && q < m)
    {
        if (arr1[p] <= arr2[q])
        {
            arr[r] = arr1[p];
            p++;
            r++;
        }
        else
        {
            arr[r] = arr2[q];
            q++;
            r++;
        }
    }

    while (p < n)
    {
        arr[r] = arr1[p];
        p++;
        r++;
    }

    while (q < m)
    {
        arr[r] = arr2[q];
        q++;
        r++;
    }
}

void merge_sort_rec(int *arr, int lo, int hi)
{
    if (lo < hi)
    {
        int mid = lo + ((hi - lo) / 2);
        merge_sort_rec(arr, lo, mid);
        merge_sort_rec(arr, mid + 1, hi);
        merge(arr, lo, mid, hi);
    }
}

void merge_sort_it(int *arr, int n)
{
    int size; // current size of the subarrays to be merged
    int left; // indicates the start of each pair

    for (size = 1; size <= n - 1; size = size * 2)
    {
        for (left = 0; left < n - 1; left += 2 * size)
        {
            int mid = left + size - 1;
            int right = min(left + 2 * size - 1, n - 1);
            merge(arr, left, mid, right);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // merge_sort_rec(arr,0,n-1);
    merge_sort_it(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}