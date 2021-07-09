#include<bits/stdc++.h>
using namespace std;


 string cutst(string s)
{
    int l=s.length();
    int i=0;
    sort(s.begin(),s.end()-1);
    
    while(s[i]!='\0')
    {
        if(s[i]==s[i+1])
        s.erase(i,1);
        
        else
        {i++;
    }
    }
    return s;
}


int main() 
{
int n,i,j;
cin>>n;
string str;
int x;
	
	while(n--)
	{
	    cin>>str;
	    str=cutst(str);
	    cout<<str<<endl;
	    
	    
	}
}
	
