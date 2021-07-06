#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<char, char> mp;
    mp[')'] = '(';
    mp[']'] = '[';
    mp['}'] = '{';
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        stack<char> st;
        cin >> s;
        int flag = 0;
        for (char b : s)
        {
            if (b == '(' || b == '{' || b == '[')
                st.push(b);
            else
            {
                if (!st.empty() and mp[b] == st.top())
                    st.pop();
                else
                {
                    flag = 1;
                    break;
                }
            }
        }

        if (!flag and st.empty())
            cout << "YES" << endl;
        else
            cout << "NO " << endl;
    }
    return 0;
}