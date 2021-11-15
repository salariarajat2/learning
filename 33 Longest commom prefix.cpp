#include<bits/stdc++.h>/*
using namespace std;

int main()
{
    int nooftestcases;
    cin>>nooftestcases;

    while(nooftestcases--){
        int n;
        cin>>n;
        string a[n];
        for(int i=0;i<n;i++) cin>>a[i];

        string s = a[0];

        for(int i=1;i<n;i++){
            string s2 = a[i];
            string ans = "";
            int j=0,k=0;

            while(j<s2.length() && k <s.length()){
                if(s[k] == s2[j]){
                    ans+=s[k];
                }
                else
                    break;

                j++,k++;
            }
            s=ans;
        }
        if(s==""){
            cout<<"-1"<<endl;
        }
        else
            cout<<s<<endl;
    }
}
*/
#include <algorithm>
using namespace std;

int main() {    
            
                  int n;
                   cin>>n;
                    vector<string>v;
                    for(int i=0;i<n;i++)
                    {   string s;
                        cin>>s;
                        v.push_back(s);
                    }
                    if(v.size()==1)
                        cout<<v[0];
                    else{
                    	
                    sort(v.begin(),v.end());
                    int i=0;
                    string s1=v[0];
                    string s2=v[v.size()-1];
                    if(s1==s2)
                    cout<<s1;
                    else{
                    int count=0;
                    while(s1[i]==s2[i])
                    {   
					count++;
					i++;
					}
                    if(count==0)
                        cout<<-1;
                    else
                    {
					for(int i=0;i<count;i++)
                    {   
					cout<<s1[i];
					}
                    }
					}
					}
                    cout<<endl;
                
	//code
	return 0;
}
