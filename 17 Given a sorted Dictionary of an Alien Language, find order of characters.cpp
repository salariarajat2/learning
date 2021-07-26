#include <bits/stdc++.h>
using namespace std;

//  Time Complexity: O(N + K), Space Compelxity: O(K)

void dfs(int i, vector<vector<int>> g, vector<int> &vis, string &ans)
{
    vis[i] = 1;
    for (auto it : g[i])
    {
        if (!vis[it])
        {
            dfs(it, g, vis, ans);
        }
    }
    char ch = i + 'a';
    ans = ch + ans;
}

string findOrder(vector<string> dict, int n, int k)
{
    vector<vector<int>> g(k);
    for (int i = 0; i < n - 1; i++)
    {
        string a = dict[i];
        string b = dict[i + 1];

        for (int j = 0; j < min(a.length(), b.length()); j++)
        {
            if (a[j] != b[j])
            {
                g[a[j] - 'a'].push_back(b[j] - 'a');
                break;
            }
        }
    }
    vector<int> vis(k, 0);
    string ans = "";
    for (int i = 0; i < k; i++)
    {
        if (!vis[i])
        {
            dfs(i, g, vis, ans);
        }
    }
    return ans;
}

int main()
{
    int N = 5, K = 4;
    vector<string> M{"baa", "abcd", "abca", "cab", "cad"};

    cout << "code is: " << findOrder(M, N, K);
    return 0;
}
