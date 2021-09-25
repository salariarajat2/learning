#include <bits/stdc++.h>
using namespace std;

// TC = O(r*r*c) , SC= O(c)

int kad(vector<int> ans, int n)
{
    int max = INT_MIN;
    int unt = 0;
    for (int i = 0; i < n; i++)
    {
        unt += ans[i];
        if (unt > max)
            max = unt;
        if (unt < 0)
            unt = 0;
    }
    return max;
}
int maximumSumRectangle(int r, int c, vector<vector<int>> m)
{
    // code here
    int ma = INT_MIN;
    for (int i = 0; i < r; i++)
    {
        vector<int> ans(c);
        for (int j = i; j < r; j++)
        {
            for (int k = 0; k < c; k++)
            {
                ans[k] += m[j][k];
            }
            ma = max(ma, kad(ans, c));
        }
    }
    return ma;
}

int main()
{
    int R = 4, C = 5;
    vector<vector<int>> M = {{1, 2, -1, -4, -20},
                             {-8, -3, 4, 2, 1},
                             {3, 8, 10, 1, 3},
                             {-4, -1, 1, 7, -6}};
    cout << maximumSumRectangle(R, C, M);
}
// Output: 29
