#include <bits/stdc++.h>
using namespace std;

//TC = O(nk) , SC = O(nk)

int productSubSeqCount(vector<int> &arr, int k)
{
    int n = arr.size();
    int dp[k + 1][n + 1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            dp[i][j] = dp[i][j - 1]; // number of subsequence using j-1 terms

            if (arr[j - 1] <= i && arr[j - 1] > 0)
                dp[i][j] += dp[i / arr[j - 1]][j - 1] + 1; // number of subsequence using 1 to j-1 terms and j-th term
        }
    }

    return dp[k][n];
}

// Driver code
int main()
{
    vector<int> A;
    A.push_back(1);
    A.push_back(2);
    A.push_back(3);
    A.push_back(4);
    int k = 10;
    cout << productSubSeqCount(A, k) << endl;
}

