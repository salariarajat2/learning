#include<bits/stdc++.h>
using namespace std;

bool check(string a,string b,int i,int j)
{
    if(a[i]=='\0'&&b[j]=='\0')return true;
    if(a[i]=='*'&&a[i+1]!='\0'&&b[j]=='\0')return false;
    if(a[i]=='?'||a[i]==b[j])return check(a,b,i+1,j+1);
    if(a[i]=='*')return check(a,b,i+1,j)||check(a,b,i,j+1);
    
    return false;
}
int main() 
{
   int t;
   string a,b;
   cin >>t;
   while(t--)
   {
       cin >>a>>b;
       bool ans = check(a,b,0,0);
       if(ans)cout<<"Yes"<<endl;
       else cout<<"No"<<endl;
   }
}



/*

int main() {
	
	int t;
	cin>>t;
	while(t--){
	    
	    
	    string s1;
	    string s2;
	    cin>>s1;
	    cin>>s2;
	    
	    int m=s1.size();
	    int n=s2.size();
	    int dp[n+1][m+1];
	    
	    memset(dp,0,sizeof(dp));
	    
	    dp[0][0]=1;
	    
	    for(int i=1;i<=m;i++){
	        if(s1[i-1]=='*'){
	            dp[0][i]=dp[0][i-1];
	    }
	    }
	    for(int i=1;i<=n;i++){
	        for(int j=1;j<=m;j++){
	            if(s1[j-1]==s2[i-1] || s1[j-1]=='?'){
	                dp[i][j]=dp[i-1][j-1];
	            }
	            else if(s1[j-1]=='*'){
	                dp[i][j]=dp[i-1][j] || dp[i][j-1];
	            }
	            else if(s1[j-1]!=s2[i-1]){
	                dp[i][j]=0;
	            }
	        }
	    }
	    
	    if(dp[n][m]){
	        cout<<"Yes"<<endl;
	    }
	        else{
	            cout<<"No"<<endl;
	        }
	    
	
}
return 0;
}*/
