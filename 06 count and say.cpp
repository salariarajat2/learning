#include <bits/stdc++.h>
using namespace std;

//TC = O(n*s), SC = (1)

string countnndSay(int n)
{
    if (n == 1)
        return "1";
    if (n == 2)
        return "11";
    string s = "11";
    for (int i = 3; i <= n; i++)
    {
        int c = 1;
        string t = "";
        for (int j = 1; j <= s.length(); j++)
        {
            if (s[j] != s[j - 1])
            {
                t += to_string(c);//tmp += cnt + '0';
                t += s[j - 1];
                c = 1;
            }
            else
            {
                c++;
            }
        }
        s = t;
    }
    return s;
}

int main()
{
    int N = 6;
    cout << countnndSay(N) << endl;
    return 0;
}






/*

//TC = O(n*s), SC = (n)

string func(string res)
{
    unordered_map<char, int> mp;
    string ans = "";
    for (int i = 0; i <= res.length(); i++)
    {
        if (mp.find(res[i]) == mp.end() and i > 0)
        {
            auto it = mp.find(res[i - 1]);
            ans += to_string(it->second) + it->first;
            mp.clear();
        }
        mp[res[i]]++;
    }
    return ans;
}

string countnndSay(int n)
{
    string res = "1";
    for (int i = 2; i <= n; i++)
    {
        res = func(res);
    }
    return res;
}

int main()
{
    int N = 6;
    cout << countnndSay(N) << endl;
    return 0;
}

*/