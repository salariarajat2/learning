#include <bits/stdc++.h>
using namespace std;

























/*
const int n= 1e5+10;
int h[n];
  int main()
  {
  	int n;
  	cin>>n;
  	int a;
  	for(int i=0;i<n;i++)
  	{
  		int a;
  		cin>>a;
  		h[a]++;
	}
	  int c;
	  cin>>c;
	  for(int j=0;j<c;j++) 
	  {
	  	cout<<"enter the value whose frequency you want ot see";
	    cin>>a;
	  cout<<endl<<h[a]<<endl;	
	  }
  	
  }







const int N=1e5+10;
long long fact[N];
int main()
{
	int n,h,a;
	cin>>n;
	fact[0] = fact[1] = 1;
for(int i=2;i<=n;i++)
{
	fact[i]=fact[i-1] * i;
}

for(int j=0;j<2;j++)
{
	cin>>a>>h;
	cout<<(fact[a]) % h<<endl;
}
}



int main()
{
	int n;
	cin>>n;
	int m;
	cin>>m;
	long long fact=1;
for(int i=2;i<=n;i++)
{
	fact=(fact*i);
}
cout<<fact;
}















// Complete the makeAnagram function below.
int makeAnagram(string a, string b) {
    int ans=0;
        int c1[26]={0};
        int c2[26]={0};
 
    
        for(int i=0;i<a.size();i++)  c1[a[i]-'a']++;
        
//           for(int i=0;i<26;i++)
//           cout<<c1[i];
        
        //cout<<endl;
   
       for(int i=0;i<b.size();i++) c2[b[i]-'a']++;
   
   
//           for(int i=0;i<26;i++)
//           cout<<c2[i];
        
    
        for(int i=0;i<26;i++)
            if(c1[i]!=c2[i])
			{
				ans+=abs(c1[i]-c2[i]);
				cout<<ans;
				  cout<<endl;
			}
         
}

int main()
{
    makeAnagram("cde","abc");
    return 0;
}*/
