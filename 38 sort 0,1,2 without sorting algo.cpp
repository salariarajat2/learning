#include <bits/stdc++.h>
using namespace std;

void sort012(int a[], int n)
{
    int aa = 0, b = 0, c = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
            aa++;
        else if (a[i] == 1)
            b++;
        else
            c++;
    }

    int i = 0;

    while (aa--)
    {
        a[i] = 0;
        i++;
    }
    while (b--)
    {
        a[i] = 1;
        i++;
    }

    while (c--)
    {
        a[i] = 2;
        i++;
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
    sort012(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i]<<" ";
    }

    return 0;
}