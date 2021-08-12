#include <bits/stdc++.h>
using namespace std;

//Time Complexity: O(n log n)

void mergeInPlace(int a[], int l, int m, int r)
{
    int mx = max(a[m], a[r]) + 1;
 
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r && k <= r) {
 
        int e1 = a[i] % mx;
        int e2 = a[j] % mx;
        if (e1 <= e2) {
            a[k] += (e1 * mx);
            i++;
            k++;
        }
        else {
            a[k] += (e2 * mx);
            j++;
            k++;
        }
    }
 
    while (i <= m) {
        int el = a[i] % mx;
        a[k] += (el * mx);
        i++;
        k++;
    }
 
    while (j <= r) {
        int el = a[j] % mx;
        a[k] += (el * mx);
        j++;
        k++;
    }

    for (int i = l; i <= r; i++)
        a[i] /= mx;
}
 
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
 
        int m = l + (r - l) / 2;
 
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        mergeInPlace(arr, l, m, r);
    }
}

int main()
{
    int nums[] = { 12, 11, 13, 5, 6, 7 };
    int nums_size = sizeof(nums) / sizeof(nums[0]);
 
    mergeSort(nums, 0, nums_size - 1);
 
    for (int i = 0; i < nums_size; i++) {
        cout << nums[i] << " ";
    }
    return 0;
}
 



















/*
//Time Complexity: O(log n*nlog n)

int nextGap(int gap)
{
    if (gap <= 1)
        return 0;

    return (int)ceil(gap / 2.0);
}

void inPlaceMerge(int nums[], int start, int end)
{
    int gap = end - start + 1;

    for (gap = nextGap(gap);
         gap > 0; gap = nextGap(gap))
    {
        for (int i = start; i + gap <= end; i++)
        {
            int j = i + gap;
            if (nums[i] > nums[j])
                swap(nums[i], nums[j]);
        }
    }
}

void mergeSort(int nums[], int s, int e)
{
    if (s == e)
        return;
    int mid = (s + e) / 2;
    mergeSort(nums, s, mid);
    mergeSort(nums, mid + 1, e);

    inPlaceMerge(nums, s, e);
}

int main()
{
    int nums[] = {12, 11, 13, 5, 6, 7};
    int nums_size = sizeof(nums) / sizeof(nums[0]);

    mergeSort(nums, 0, nums_size);

    for (int i = 0; i < nums_size; i++)
    {
        cout << nums[i] << " ";
    }
    return 0;
}
*/
