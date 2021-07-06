#include<iostream>
#include<cstring>
using namespace std;
 int dp[35][35];
int cps(string &s,int i,int j)
{
    if(i>j)
    return 0;
    if(i==j)
    return 1;
    if(dp[i][j]!=-1)//memorization part that is dynammic programming
    return dp[i][j];
    if(s[i]==s[j])
    return dp[i][j]=1+cps(s,i,j-1)+cps(s,i+1,j);
    else
    return dp[i][j]=cps(s,i+1,j)+cps(s,i,j-1)-cps(s,i+1,j-1);
}
int main()
{
	string s;
	cin>>s;
	int n=s.length();
  memset(dp,-1,sizeof(dp));
   cout<<cps(s,0,s.length()-1);
} 



