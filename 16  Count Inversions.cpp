#include <bits/stdc++.h>
using namespace std;

int merge(int arr[], int temp[], int left, int mid, int right)
{
    int i, j, k;
    int inv_count = 0;

    i = left; /* i is index for left subarray*/
    j = mid;  /* j is index for right subarray*/
    k = left; /* k is index for resultant merged subarray*/
    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            inv_count = inv_count + (mid - i);
        }
    }

    while (i <= mid - 1)
        temp[k++] = arr[i++];
    while (j <= right)
        temp[k++] = arr[j++];
    for (i = left; i <= right; i++)
        arr[i] = temp[i];

    return inv_count;
}

int _mergeSort(int arr[], int temp[], int left, int right)
{
    int mid, inv_count = 0;
    if (right > left)
    {
        mid = (right + left) / 2;
        inv_count += _mergeSort(arr, temp, left, mid);
        inv_count += _mergeSort(arr, temp, mid + 1, right);
        inv_count += merge(arr, temp, left, mid + 1, right);
    }
    return inv_count;
}

int main()
{

    int N;
    cin >> N;
    int arr[N];
    for (int j = 0L; j < N; j++)
    {
        cin >> arr[j];
    }
    int temp[N];
    cout << _mergeSort(arr, temp, 0, N - 1);
    return 0;
}

/*
5
5
1 20 6 4 5 
ans 5
*/

/*using stl


int getInvCount(int arr[],int n)
{
    multiset<int> set1;
    set1.insert(arr[0]);
  
    int invcount = 0; // Initialize result
  
    multiset<int>::iterator itset1;
  
    for (int i=1; i<n; i++)
    {
       
        set1.insert(arr[i]);
  
        itset1 = set1.upper_bound(arr[i]);
  
        cout<<distance(itset1, set1.end())<<endl;
        invcount += distance(itset1, set1.end());
    }
  
    return invcount;
}
*/
