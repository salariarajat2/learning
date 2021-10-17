#include <bits/stdc++.h>
using namespace std;

//TC = o(n), SC = O(1)

bool areRotations(string a, string b, string res)
{
    int n = a.length(), m = b.length(), l = res.length();
    if ((n + m) != l)
        return false;
    int i = 0, j = 0, k = 0;
    while (k < l)
    {
        if (i < n and res[k] == a[i])
            i++;
        else if (j < m and res[k] == b[j])
            j++;
        else
            break;
        k++;
    }

    if (i < n or j < m)
        return false;
    return true;
}

int main()
{
    string str1 = "XY", str2 = "12", str3 = "X1Y2";
    cout << areRotations(str1, str2, str3);
}