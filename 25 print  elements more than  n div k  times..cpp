#include <bits/stdc++.h>
using namespace std;

//TC = O(N), SC = O(n)

void morethanNbyK(int arr[], int n, int k)
{
    int x = n / k;
    cout << x << endl;
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
        mp[arr[i]]++;

    for (auto it : mp)
    {
        if (it.second > x)
            cout << it.first << " " << it.second << endl;
    }
}

int main()
{
    int arr[] = {1, 1, 2, 2, 3, 5, 4, 2, 2, 3, 1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;
    system("cls");
    morethanNbyK(arr, n, k);

    return 0;
}

/*  TC = O(N^2)

void moreThanNdK(int *arr,int n,int k)
{
    int x = n/k;
    int *temp = new int[n];
    for(int i=0;i<n;i++)
    {
        temp[i] = 0;
    }

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;i<n;i++)
        {
            if(arr[i]==arr[j])
            {
                temp[i] += 1;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(temp[i]>x)
        {
            cout<<arr[i]<<" ";
        }
    }
}

int main()
{
    cout << "First Test\n";
    int arr1[] = {4, 5, 6, 7, 8, 4, 4, 5, 5, 5, 5};
    int size = sizeof(arr1) / sizeof(arr1[0]);
    int k = 3;
    moreThanNdK(arr1, size, k);
}

*/
