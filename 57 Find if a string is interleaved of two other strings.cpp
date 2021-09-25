#include <bits/stdc++.h>
using namespace std;

// TC = O(n^2) , SC= O(n^2)

int dp[1001][1001];

int func(string A, string B, string C, int a, int b, int c)
{
    if (c == 0)
        return 1;
    if (dp[a][b] != -1)
        return dp[a][b];

    int aa, bb;
    aa = bb = 0;
    if (a - 1 >= 0 and A[a - 1] == C[c - 1])
        aa = func(A, B, C, a - 1, b, c - 1);
    if (b - 1 >= 0 and B[b - 1] == C[c - 1])
        bb = func(A, B, C, a, b - 1, c - 1);
    return dp[a][b] = aa or bb;
}
bool isInterleave(string A, string B, string C)
{
    int a = A.length();
    int b = B.length();
    int c = C.length();

    if (a + b != c)
        return 0;
    dp[a][b];
    memset(dp, -1, sizeof(dp));
    return func(A, B, C, a, b, c);
}

int main()
{
    string A = "XY", B = "X", C = "XXY";
    cout<<isInterleave(A,B,C);
}
// Output: 1
