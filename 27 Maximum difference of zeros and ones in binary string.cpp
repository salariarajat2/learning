#include <bits/stdc++.h>
using namespace std;

//TC = O(n), SC = O(1)

int maxSubstring(string s)
{
    int max = INT_MIN, max_until = 0;
    for (int i = 0; i < s.length(); i++)
    {
        int x = (s[i] == '0') ? 1 : -1;
        max_until += x;
        if (max < max_until)
            max = max_until;
        if (max_until < 0)
            max_until = 0;
    }
    return max;
}

int main()
{
    string s = "11000010001";
    cout << maxSubstring(s);
    return 0;
}

/*
ans = 6
*/
