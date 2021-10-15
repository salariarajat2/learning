#include <bits/stdc++.h>
using namespace std;

//TC = O(n), SC= O(1)

int main()
{
    string str = "rajatsalaria";
    reverse(str.begin(), str.end());
    cout << str;
    return 0;
}

/*

    int s = str.size();
    for(int i=s;i>=0;i--)
    {
        cout<<str[i];
    }

Time Complexity: O(n), Space Complexity: O(n)
*/
