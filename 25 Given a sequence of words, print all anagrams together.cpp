#include<bits/stdc++.h>
using namespace std;

int main()
 {
	    int n;
	    cin>>n;
	    vector<string>words(n);
	    for(int i=0;i<n;i++)
	    {
	        cin>>words[i];
	    }
	    unordered_map<string,int>m;
	    for(int i=0;i<words.size();i++)
	    {
	        sort(words[i].begin(),words[i].end());
	        m[words[i]]++;
	    }
	    for(auto it=m.begin();it!=m.end();it++)
	    {
	        cout<<(*it).second<<" ";
	    }
	    cout<<endl;
	
	return 0;
}
