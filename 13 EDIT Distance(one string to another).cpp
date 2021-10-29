#include <bits/stdc++.h>
using namespace std;

//Time Complexity: O(m x n) , Auxiliary Space: O(m x n)

int dp[1001][1001];

int editDist(string a, string b, int n, int m)
{
    if (n == -1)
        return m + 1;
    if (m == -1)
        return n + 1;
    if (dp[n][m] != -1)
        return dp[n][m];
    if (a[n] == b[m])
        return dp[n][m] = editDist(a, b, n - 1, m - 1);

    return dp[n][m] = 1 + min(editDist(a, b, n - 1, m - 1), min(editDist(a, b, n, m - 1), editDist(a, b, n - 1, m)));
}

int main()
{
    string str1 = "rajat";
    string str2 = "salaria";
    int n = str1.length();
    int m = str2.length();
    dp[n][m];
    memset(dp, -1, sizeof(dp));
    cout << editDist(str1, str2, str1.length() - 1, str2.length() - 1);

    return 0;
}
/*
int editDist(string str1, string str2, int m, int n)
{
  int dp[m+1][n+1];
  
  for(int i=0;i<=m;i++)
  {
  	for(int j=0;j<=n;j++)
  	{
  		 if(i==0) dp[i][j]=j;
         else if(j==0) dp[i][j]=i;
         
         else if(str1[i-1]==str2[j-1]) dp[i][j] = dp[i-1][j-1];
         
         else dp[i][j]= 1 + min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
	  }
  }
 return dp[m][n];
}


//TC=O(3^m) 
 
int editDist(string str1, string str2, int m, int n)
{
    if (m == 0)
        return n;
 
    if (n == 0)
        return m;

    if (str1[m - 1] == str2[n - 1])
        return editDist(str1, str2, m - 1, n - 1);     
 
    return 1 + min(editDist(str1, str2, m, n - 1),min(editDist(str1, str2, m - 1, n),editDist(str1, str2, m - 1, n - 1)));
}
*/
