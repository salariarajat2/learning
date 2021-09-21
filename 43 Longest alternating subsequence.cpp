#include <bits/stdc++.h>
using namespace std;

// TC = O(n) , SC= O(1)

int AlternatingaMaxLength(vector<int> &aa)
{
    int a = 1, b = 1;
    for (int i = 1; i < aa.size(); i++)
    {
        if (aa[i] > aa[i - 1])
        {
            a = b + 1;
        }
        else if (aa[i - 1] > aa[i])
        {
            b = a + 1;
        }
    }
    return max(a, b);
}

int main()
{
    vector<int> nums = {1, 17, 5, 10, 13, 15, 10, 5, 16, 8};
    cout << AlternatingaMaxLength(nums);
}

/*
ans = 7
*/
