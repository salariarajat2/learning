#include <bits/stdc++.h>
using namespace std;

// TC = (n * (2^n))

vector<vector<int>> solve(vector<int> v, int n)
{
    vector<vector<int>> ans;
    int total_combination = (1 << n);
    for (int i = 0; i < total_combination; i++)
    {
        vector<int> single_subset;
        for (int j = 0; j < v.size(); j++)
        {
            if ((i & (1 << j)))
            {
                single_subset.push_back(v[j]);
            }
        }
        ans.push_back(single_subset);
    }
    return ans;
}

int main() //Main Function
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    auto a = solve(v, n);

    for (auto aa : a)
    {
        for (auto i : aa)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}

/*

3
2 4 5


ans= 

2
4
2 4
5
2 5
4 5
2 4 5
*/
