#include <bits/stdc++.h>
using namespace std;

vector<int> aa(vector<int> arr, int n)
{
    vector<int> a;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == i + 1)
        {
            a.push_back(arr[i]);
        }
    }
    return a;
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {

        cin>>a[i];
    }
    vector<int> ans = aa(a, n);
    for (auto i : ans)
    {
        cout << i << " ";
    }
}



/*

5
15 2 45 12 7


*/
