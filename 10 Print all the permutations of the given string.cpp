#include <bits/stdc++.h>
using namespace std;

void permute(string a, int l, int r)
{
    if (l == r)
        cout << a << endl;
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(a[l], a[i]);
            permute(a, l + 1, r);
            swap(a[l], a[i]); //backtracking
        }
    }
}

int main()
{
    string str = "ABCD";
    permute(str, 0, str.length() - 1);
    return 0;
}


/*
void permute(string a)
{
    sort(a.begin(),a.end());
    cout<<a<<endl;
    while(next_permutation(a.begin(),a.end()))
    {
        cout<<a<<endl;
    }
}
*/