#include <bits/stdc++.h>
using namespace std;

//TC = O(n)

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

/*
5
5
0 2 1 2 0
0 0 1 2 2
3
0 0 1
0 0 1
9
1 2 0 0 0 2 1 2 1 
0 0 0 1 1 1 2 2 2
*/

/*
#include <bits/stdc++.h>
using namespace std;
 
void sort012(int a[], int arr_size)
{
    int lo = 0;
    int hi = arr_size - 1;
    int mid = 0;

    while (mid <= hi) {
        switch (a[mid]) {
 
        case 0:
            swap(a[lo++], a[mid++]);
            break;
 
        case 1:
            mid++;
            break;
 
        case 2:
            swap(a[mid], a[hi--]);
            break;
        }
    }
}
 
void printArray(int arr[], int arr_size)
{
    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
}
int main()
{
    int arr[] = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    sort012(arr, n);
 
    cout << "array after segregation ";
 
    printArray(arr, n);
 
    return 0;
}*/
