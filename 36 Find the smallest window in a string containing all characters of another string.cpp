#include<bits/stdc++.h>
using namespace std;

int main() {

	    string s,p;
	    cin>>s;
	    cin>>p;
	    string res="-1";
	    //if(s.size()==0||p.size()==0) cout<< " ";
	    unordered_map<char,int>fstr, fpat;
	    int i=0; int temp=0; 
	    int count=0;
	    int ans=INT_MAX;
	    for(int k=0; k<p.size(); k++)
	    {
	        fpat[p[k]]++;
	    }
	    for(int j=0; j<s.size(); j++)
	    {
	        if(fpat.count(s[j]))
	        {
	            fstr[s[j]]++;
	            if(fpat[s[j]]==fstr[s[j]])
	            count++; //checks chars of pattern visited in str
	        }//end of if
	        while(count==fpat.size() && i<=j)
	        {
	            temp=j-i+1;
	            if(ans>temp)
	            {
	                ans=temp;
	                res= s.substr(i,ans);
	            }
	            if(fpat.count(s[i]))
	            {
	                fstr[s[i]]--;
	                if(fstr[s[i]]<fpat[s[i]])
	                count--;
	            }
	            i++;
	        }//eofwhile
	        
	    }//eoffor
	    
	   cout<<res<<endl; 
}
	
	return 0;
}
