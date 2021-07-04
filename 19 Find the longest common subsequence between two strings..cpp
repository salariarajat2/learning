#include <bits/stdc++.h>
using namespace std;

//Time complexity O(2^n)

int lcs( char *X, char *Y, int m, int n ) //  int lcs( char X[], char Y[], int m, int n ) 
{ 
    if (m == 0 || n == 0) 
        return 0; 
    if (X[m-1] == Y[n-1]) 
        return 1 + lcs(X, Y, m-1, n-1); 
    else
        return max(lcs(X, Y, m, n-1), lcs(X, Y, m-1, n)); 
} 


int main() 
{ 
    char X[] = "AGGTAB"; 
    char Y[] = "GXTXAYB"; 
    
    int m = strlen(X); 
    int n = strlen(Y); 
    
    cout<<"Length of LCS is "<< lcs( X, Y, m, n ) ; 
    
    return 0; 
} 


/*
//using DP, Time Complexity O(mn)

int lcs(char *a,char *b,int m,int n)
{
   
   int dp[m+1][n+1],i,j;
   for(i=0;i<=m;i++)
   {
   	for(j=0;j<=n;j++)
   	{
   		if(i==0 or j==0) dp[i][j]=0;
   		
   		else if(a[i-1]==b[j-1]) dp[i][j]=  1+dp[i-1][j-1];
		   
		   else dp[i][j]=max (dp[i-1][j],dp[i][j-1]); 
	   }
	   
   }
   
   return dp[m][n];
   
}
*/
