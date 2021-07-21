#include<bits/stdc++.h>
using namespace std;

//Time Complexity: O(v n), Space Complexity: O(1)

string FirstNonRepeating(string A)
{
    vector<int> vis(26, 0);
    string ans = "";
    vector<char> vv;
    int a = A.length();

    for (int i = 0; i < a; i++)
    {
        if (!vis[A[i] - 'a'])
        {
            vv.push_back(A[i]);
        }

        vis[A[i] - 'a']++;
        int f = 0;
        int m = vv.size();
        for (int i = 0; i < m; i++)
        {
            if (vis[vv[i] - 'a'] == 1)
            {
                ans.push_back(vv[i]);
                f = 1;
                break;
            }
        }
        if (f == 0)
            ans.push_back('#');
    }
    return ans;
}

int main()
{
    string a; cin>>a;
    cout<<FirstNonRepeating(a);

}
