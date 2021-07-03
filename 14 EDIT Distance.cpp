#include <bits/stdc++.h>
using namespace std;

//edit distance
//Time Complexity: O(m x n) , Auxiliary Space: O(m x n)

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

 
int main()
{
    string str1 = "rajat";
    string str2 = "salaria";
 
    cout << editDist(str1, str2, str1.length(),str2.length());
 
    return 0;
}

/*

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
