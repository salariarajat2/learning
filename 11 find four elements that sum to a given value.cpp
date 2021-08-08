#include <bits/stdc++.h>
using namespace std;

//Time Complexity: O(n^3), Space Complexity: O(1)

void find4Numbers(int a[], int n, int X)
{
    int l, r;
    sort(a, a + n);

    for (int i = 0; i < n - 3; i++)
    {
        for (int j = i + 1; j < n - 2; j++)
        {
            l = j + 1;
            r = n - 1;

            while (l < r)
            {
                if (a[i] + a[j] + a[l] + a[r] == X)
                {
                     cout << a[i] << ", " << a[j] << ", " << a[l] << ", " << a[r]<<endl;
                    l++;
                    r--;
                }
                else if (a[i] + a[j] + a[l] + a[r] < X)
                    l++;
                else 
                    r--;
            } // end of while
        }     // end of inner for loop
    }         // end of outer for loop
}

int main()
{
    int a[] = {1, 4, 45, 6, 10, 12};
    int X = 21;
    int n = sizeof(a) / sizeof(a[0]);
    find4Numbers(a, n, X);
    return 0;
}
