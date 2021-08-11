#include <bits/stdc++.h>
using namespace std;

//Time Complexity:O(log k)

int kth(int arr1[], int m, int arr2[], int n, int k)
{

    if (k > (m + n) || k < 1)
        return -1;

    if (m > n)
        return kth(arr2, n, arr1, m, k);

    if (m == 0)
        return arr2[k - 1];

    if (k == 1)
        return min(arr1[0], arr2[0]);

    int i = min(m, k / 2), j = min(n, k / 2);

    if (arr1[i - 1] > arr2[j - 1])

        return kth(arr1, m, arr2 + j, n - j, k - j);
    else

        return kth(arr1 + i, m - i, arr2, n, k - i);
}

int main()
{
    int arr1[5] = {2, 3, 6, 7, 9};
    int arr2[4] = {1, 4, 8, 10};
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int n = sizeof(arr2) / sizeof(arr2[0]);
    int k = 5;

    cout<<kth(arr1, m, arr2, n, k);

}

/*
//Time Complexity:O(log m+ log n)
int kth(int *arr1, int *arr2, int *end1, int *end2, int k)
{
    if (arr1 == end1)
        return arr2[k];
    if (arr2 == end2)
        return arr1[k];
    int mid1 = (end1 - arr1) / 2;
    int mid2 = (end2 - arr2) / 2;
    if (mid1 + mid2 < k)
    {
        if (arr1[mid1] > arr2[mid2])
            return kth(arr1, arr2 + mid2 + 1, end1, end2,
                k - mid2 - 1);
        else
            return kth(arr1 + mid1 + 1, arr2, end1, end2,
                k - mid1 - 1);
    }
    else
    {
        if (arr1[mid1] > arr2[mid2])
            return kth(arr1, arr2, arr1 + mid1, end2, k);
        else
            return kth(arr1, arr2, end1, arr2 + mid2, k);
    }
}

int main()
{
    int arr1[5] = {2, 3, 6, 7, 9};
    int arr2[4] = {1, 4, 8, 10};

    int k = 5;
    cout << kth(arr1, arr2, arr1 + 5, arr2 + 4,  k - 1);
    return 0;
} 

*/






/*
// Time Complexity: O(k), Auxiliary Space: O(1)


int aa(vector<int> a, vector<int> b, int n, int m, int k)
{
    int i = 0, j = 0, x = 0;

    while (i < n and j < m)
    {
        if (a[i] < b[j])
        {
            x++;
            if (x == k)
                return a[i];
            i++;
        }
        else
        {
            x++;
            if (x == k)
                return b[j];
            j++;
        }
    }

    while (i < n)
    {
        x++;
        if (x == k)
            return a[i];
        i++;
    }
    while (j < m)
    {
        x++;
        if (x == k)
            return b[j];
        j++;
    }
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a;
    vector<int> b;
    for (int i = 0; i < n; i++)
    {
        int digit;
        cin >> digit;
        a.push_back(digit);
    }
    for (int i = 0; i < m; i++)
    {
        int digit;
        cin >> digit;
        b.push_back(digit);
    }
    cout << aa(a, b, a.size(), b.size());

    return 0;
}
*/

/*
//basic using extra array
//Time Complexity: O(n), Auxiliary Space : O(m + n) 


int kth(int arr1[], int arr2[], int m, int n, int k)
{
    int sorted1[m + n];
    int i = 0, j = 0, d = 0;
    while (i < m && j < n)
    {
        if (arr1[i] < arr2[j])
            sorted1[d++] = arr1[i++];
        else
            sorted1[d++] = arr2[j++];
    }
    while (i < m)
        sorted1[d++] = arr1[i++];
    while (j < n)
        sorted1[d++] = arr2[j++];
    return sorted1[k - 1];
}

*/
