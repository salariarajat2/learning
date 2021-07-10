#include<bits/stdc++.h>
using namespace std;
vector<string> final;
void generate(string &s,int open,int close)
{
	
	if(open==0 && close==0)
	{
		final.push_back(s);
		return;
	}
	if(open>0)
	{
		s.push_back('(');
		generate(s,open-1,close);
		s.pop_back();
	}
	if(close>0)
	{
		if(open<close)
		{
			s.push_back(')');
			generate(s,open,close-1);
			s.pop_back();
		}
	}	
}

int main()
{
	string a;
	int aa,b; cin>>aa>>b;
generate(a,aa,b);
for(auto it:final)
cout<<it<<endl;
    return 0;
}


