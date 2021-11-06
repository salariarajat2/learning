#include <bits/stdc++.h>
using namespace std;

//TC = O(exponential), SC = O(1)

int func(int i, int j, string s, char a[6][6], int n, int idx)
{
    int found = 0;
    if (i >= 0 and j >= 0 and i < 6 and j < 6 and s[idx] == a[i][j])
    {
        char temp = s[idx];
        a[i][j] = '0';
        idx++;
        if (idx == n)
            found = 1;
        else
        {
            found += func(i + 1, j, s, a, n, idx);
            found += func(i - 1, j, s, a, n, idx);
            found += func(i, j + 1, s, a, n, idx);
            found += func(i, j - 1, s, a, n, idx);
        }
        a[i][j] = temp;
    }
    return found;
}

int main()
{
    char a[6][6] = {{'D', 'D', 'D', 'G', 'D', 'D'},
                    {'B', 'B', 'D', 'E', 'B', 'S'},
                    {'B', 'S', 'K', 'E', 'B', 'K'},
                    {'D', 'D', 'D', 'D', 'D', 'E'},
                    {'D', 'D', 'D', 'D', 'D', 'E'},
                    {'D', 'D', 'D', 'D', 'D', 'G'}};
    string str = "GEEKS";
    int ans = 0;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            ans += func(i, j, str, a, str.size(), 0);
        }
    }
    cout << ans; //2
}