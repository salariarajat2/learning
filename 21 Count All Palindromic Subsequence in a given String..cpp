#include <bits/stdc++.h>
using namespace std;

//TC = O(N*N), SC = O(N*N)

int dp[1001][1001];
int mod = 1e9 + 7;
long long int count(string &s, int i, int j)
{
  if (i > j)
    return 0;
  if (i == j)
    return 1;
  if (dp[i][j] != -1)
    return dp[i][j];
  if (s[i] == s[j])
    return dp[i][j] = (1 + count(s, i + 1, j) + count(s, i, j - 1)) % mod;
  else
    return dp[i][j] = (mod + count(s, i + 1, j) + count(s, i, j - 1) - count(s, i + 1, j - 1)) % mod;
}
long long int countPS(string str)
{
  //Your code here
  int n = str.size();
  memset(dp, -1, sizeof(dp));
  return count(str, 0, n - 1);
}
