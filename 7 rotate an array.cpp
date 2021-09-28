#include <bits/stdc++.h>
using namespace std;

//reversal algo

void reverseArray(int arr[], int start, int end)
{
    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

void leftRotate(int arr[], int d, int n)
{
    if (d == 0)
        return;
    d = d % n;

    reverseArray(arr, 0, d - 1);
    reverseArray(arr, d, n - 1);
    reverseArray(arr, 0, n - 1);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int d = 2;

    leftRotate(arr, d, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}

// Output :

// 3 4 5 6 7 1 2
// Time Complexity : O(n)

/*jugglling algo  // best
int gcd(int a, int b)
{
    if (b == 0)
        return a;
 
    else
        return gcd(b, a % b);
}
 
void leftRotate(int arr[], int d, int n)
{
    d = d % n;
    int g_c_d = gcd(d, n);
    for (int i = 0; i < g_c_d; i++) {
        int temp = arr[i];
        int j = i;
 
        while (1) {
            int k = j + d;
            if (k >= n)
                k = k - n;
 
            if (k == i)
                break;
 
            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;
    }
}
 
int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);

    leftRotate(arr, 2, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
Output : 

3 4 5 6 7 1 2 
Time complexity : O(n) 
Auxiliary Space : O(1)


*/

/*one by one method

void leftRotatebyOne(int arr[], int n)
{
    int temp = arr[0], i;
    for (i = 0; i < n - 2; i++)
        arr[i] = arr[i + 1];
 
    arr[n-1] = temp;
}
 
 
int main()
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    // Function calling
    for (int i = 0; i < 2; i++)
        leftRotatebyOne(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
 
    return 0;
}
Output : 
 

3 4 5 6 7 1 2 
Time complexity : O(n * d) 
Auxiliary Space : O(1)

*/
