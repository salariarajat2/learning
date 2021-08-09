#include <bits/stdc++.h>
using namespace std;

// A Divide-and-Conquer approach to find the pivot (highest) element in
// a sorted rotated array - returns the index of the pivot -> O(log N)

int aa(int arr[], int low, int high, int lowerBound, int upperBound)
{
    int mid = low + (high - low) / 2;

    if (mid == lowerBound)
    {
        if (mid == upperBound)
        {
            // Only 1 element
            return mid;
        }
        else if (arr[mid] >= arr[mid + 1])
        {
            // Pivot is the greater element
            return mid;
        }
    }
    else if (mid == upperBound)
    {
        if (arr[mid] >= arr[mid - 1])
        {
            // Pivot is the greater element
            return mid;
        }
    }
    else
    {
        if (arr[mid] >= arr[mid + 1] && arr[mid] >= arr[mid - 1])
        {
            // Mid value is the pivot
            return mid;
        }
        else if (arr[mid] > arr[high])
        {
            // The Pivot is in the second half
            return aa(arr, mid + 1, high, lowerBound, upperBound);
        }
        else if (arr[mid] < arr[high])
        {
            // The Pivot is in the first half
            return aa(arr, low, mid - 1, lowerBound, upperBound);
        }
    }

    return -1;
}
int main()
{
    int arr[] = {11,12,16,1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Length of lis is " << aa(arr, 0,n-1,0,n-1);

    return 0;
}
