#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int t;
    cin >>t;
    while(t--){
	string s;
	cin >>s;
	int ct = 0;
	int len = s.length();
	for(int i=0;i<len;i++)
	{
	    if(i%2==0&&s[i]=='0')ct++;
	    // cout<<"i and ct first "<<i<<" "<<ct<<endl;
	    if(i%2==1&&s[i]=='1')ct++;
	   // cout<<"i and ct"<<i<<" "<<ct<<endl;
	}
	cout<<ct<<" " <<len<<endl;
	cout<<min(ct,len-ct)<<endl;
    }
	return 0;
}
