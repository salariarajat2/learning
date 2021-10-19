#include <bits/stdc++.h>
using namespace std;

//TC = O(n^2), SC = O(1)

void print(char *str, int s, int e)
{
    for (int i = s; i <= e; i++)
    {
        cout << str[i];
    }
}

int longestPalSubstr(char *s)
{
    int max = 1;
    int start, high, low;
    for (int i = 1; i < strlen(s); i++)
    {
        low = i - 1, high = i;
        while (low >= 0 and high < strlen(s) and s[low] == s[high])
        {
            if (high - low + 1 > max)
            {
                max = high - low + 1;
                start = low;
            }
            low--;
            high++;
        }

        low = i - 1, high = i + 1;
        while (low >= 0 and high < strlen(s) and s[low] == s[high])
        {
            if (high - low + 1 > max)
            {
                max = high - low + 1;
                start = low;
            }
            low--;
            high++;
        }
    }
    print(s, start, start + max - 1);
    return max;
}

int main()
{
    char str[] = "aaaabbaa";
    cout << "\nLength is: " << longestPalSubstr(str) << endl;
    return 0;
}

/*

//TC = O(n^2), SC = O(n^2) 

void printSubStr(string str, int low, int high)
{
    for (int i = low; i <= high; ++i)
        cout << str[i];
}

int longestPalSubstr(string s)
{
    int n = s.length();
    bool dp[n][n];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++)
        dp[i][i] = true;

    int start = 0, max = 1;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            dp[i][i + 1] = true;
            start = i;
            max = 2;
        }
    }

    for (int k = 3; k <= n; k++)
    {
        for (int i = 0; i < n - k + 1; i++)
        {
            int j = i + k - 1;
            if (dp[i + 1][j - 1] and s[i] == s[j])
            {
                dp[i][j] = true;
                if (k > max)
                {
                    start = i;
                    max = k;
                }
            }
        }
    }
    printSubStr(s, start, start + max - 1);

    return max;
}

int main()
{
    string str = "forgeeksskeegfor";
    cout << "\nLength is: "
         << longestPalSubstr(str);
    return 0;
}

*/

/*

//TC = O(n^3), SC = O(1) 

int longestPalSubstr(string str)
{
    int n = str.size(), maxLength = 1, start = 0;

    for (int i = 0; i < str.length(); i++)
    {
        for (int j = i; j < str.length(); j++)
        {
            int flag = 1;

            for (int k = 0; k < (j - i + 1) / 2; k++)
                if (str[i + k] != str[j - k])
                    flag = 0;

            if (flag && (j - i + 1) > maxLength)
            {
                start = i;
                maxLength = j - i + 1;
            }
        }
    }

    cout << "Longest palindrome substring is: ";
    printSubStr(str, start, start + maxLength - 1);

    return maxLength;
}


*/