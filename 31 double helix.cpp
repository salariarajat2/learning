#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int m;
    cin >> m;
    int arr1[m];
    for (int i = 0; i < m; i++)
    {
        cin >> arr1[i];
    }

    int s1=0,s2=0,i=0,j=0,ma=0;
    while(i<n and j<m)
    {
        if(arr[i] < arr1[j]) s1+=arr[i++];
        else if(arr1[j] < arr[i]) s2+=arr1[j++];
        else{
            ma+=max(s1,s2)+arr[i];
            s1=s2=0;
            i++,j++;

        }
    }
    while(i<n) s1+=arr[i++];
    while(j<m) s2+=arr1[j++];
    ma+=max(s1,s2);
    cout<<ma;
}


/*
13 3 5 7 9 20 25 30 40 55 56 57 60 62
11 1 4 7 11 14 25 44 47 55 57 100

ans= 450

*/
