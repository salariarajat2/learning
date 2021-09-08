#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n), Auxiliary Space: O(1)

int carassembly(int a[][4], int t[][4], int *e, int *x)
{
    int first, second;
    first = e[0] + a[0][0];
    second = e[1] + a[1][0];

    for (int i = 1; i < 4; i++)
    {
        int one = min(a[0][i] + first, second + t[1][i] + a[0][i]);
        int two = min(a[1][i] + second, first + a[1][i] + t[0][i]);

        first = one;
        second = two;
    }
    return min(first + x[0], second + x[1]);
}

int main()
{
    int a[][4] = {{4, 5, 3, 2}, {2, 10, 1, 4}};
    int t[][4] = {{0, 7, 4, 5}, {0, 9, 2, 8}};
    int e[] = {10, 12}, x[] = {18, 7};

    cout << carassembly(a, t, e, x);
}

/*

Time Complexity: O(n), Auxiliary Space: O(n)

int carassembly(int a[][4], int t[][4], int *e, int *x)
{
    int first[4], second[4];
    first[0] = e[0] + a[0][0];
    second[0] = e[1] + a[1][0];

    for (int i = 1; i < 4; i++)
    {
        first[i] = min(a[0][i] + first[i - 1], second[i - 1] + t[1][i] + a[0][i]);
        second[i] = min(a[1][i] + second[i - 1], first[i - 1] + a[1][i] + t[0][i]);
    }
    return min(first[3] + x[0], second[3] + x[1]);
}
*/
