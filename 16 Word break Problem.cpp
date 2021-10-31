#include <bits/stdc++.h>
using namespace std;

//TC = O(N^2), SC = O(N)

unordered_map<string, int> dp;

int func(string s, vector<string> &aa)
{
    int n = s.size();
    if (n == 0)
        return 1;
    if (dp[s] != 0)
        return dp[s];

    for (int i = 1; i <= n; i++)
    {
        int flag = 0;
        string a = s.substr(0, i);
        for (int j = 0; j < aa.size(); j++)
        {
            if (a.compare(aa[j]) == 0)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1 and func(s.substr(i, n), aa) == 1)
            return dp[s] = 1;
    }
    return dp[s] = -1;
}

bool wordBreak(string a, vector<string> &dictionary)
{
    if (func(a, dictionary) == 1)
        return true;
    else
        return false;
}

int main()
{

    vector<string> dictionary = {"mobile", "samsung", "sam", "sung", "man",
                                 "mango", "icecream", "and", "go", "i",
                                 "like", "ice", "cream"};

    wordBreak("ilikesamsung", dictionary) ? cout << "Yes\n" : cout << "No\n";

    wordBreak("iiiiiiii", dictionary) ? cout << "Yes\n" : cout << "No\n";

    wordBreak("", dictionary) ? cout << "Yes\n" : cout << "No\n";
    wordBreak("ilikelikeimangoiii", dictionary) ? cout << "Yes\n" : cout << "No\n";

    wordBreak("samsungandmango", dictionary) ? cout << "Yes\n" : cout << "No\n";

    wordBreak("samsungandmangok", dictionary) ? cout << "Yes\n" : cout << "No\n";

    return 0;
}
