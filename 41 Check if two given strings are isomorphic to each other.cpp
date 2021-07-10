
#include<bits/stdc++.h>
using namespace std;

#define MAX_CHARS 256

bool areIsomorphic(string str1, string str2)
{
    if(str1.size()!=str2.size()){
        return 0;
    }
    int temp1[256]={0};
    int temp2[256]={0};
    
    for(int i=0;i<str1.length();i++)
    {
        temp1[str1[i]]++;
        temp2[str2[i]]++;
        
       /* for(auto it: temp1)
        {
        	cout<<it;
		}
		
		 for(auto it1: temp2)
        {
        	cout<<it1;
		}
        cout<<endl;*/
        
        if(temp1[str1[i]]==temp2[str2[i]])//compare the frequency of str1 elements with str2 elements 
            continue;
        else
            return false;
    }
    return true;
    
}

int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        cout<<areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}



/*




// C++ program to check if two strings are isomorphic
#include<iostream>
#include<string.h>

using namespace std;
#define MAX_CHARS 256

bool areIsomorphic(string, string);

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        cout<<areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}// } Driver Code Ends


// This function returns true if str1 and str2 are ismorphic
// else returns false
#include<bits/stdc++.h>
bool areIsomorphic(string str1, string str2)
{
    
    // Your code here
    
    int n1=str1.length();
    int n2=str2.length();
    
    
    if(n1!=n2)
    return false;
    
    unordered_map<char,char> m;
    bool* taken=new bool[26]();
    
    for(int i=0;i<n1;i++)
    {
        
        char ch1=str1[i],ch2=str2[i];
        
        if(m[ch1]==0)
        {
            if(!taken[ch2-'a'])
            {
                m[ch1]=ch2;
                taken[ch2-'a']=true;
            }
            
            else return false;
        }
        
        else if(m[ch1]!=ch2)
        return false;
        
        
    }
    
    return true;
    
}































bool areIsomorphic(string, string);

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        cout<<areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}

bool areIsomorphic(string str1, string str2)
{
    if(str1.length()!=str2.length())
        return false;
    else{
        int n=str1.length();
        map<char,int> m1,m2;
        map<char,char> mapp;
        for(int i=0;i<n;i++)
        {
            if(m1.find(str1[i])==m1.end())
                if(m2.find(str2[i])==m2.end())
                    {
                        m1[str1[i]]=1;
                        m2[str2[i]]=1;
                        mapp[str1[i]]=str2[i];
                    }
                else
                    return false;
            else{
                if(mapp[str1[i]]!=str2[i])
                    return false;
            }
        }
        
    }
    return true;
    // Your code here
    
}*/
