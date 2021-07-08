#include <bits/stdc++.h>

using namespace std;

// Complete the makeAnagram function below.
int m(string a, string b) {
   int res=0;

   int c1[26]={0};
   int c2[26]={0};
   
   for(int i=0;i<a.length();i++)
   {
       c1[a[i]-'a']++;
   }
   cout<<endl;
    for(int i=0;i<26;i++)
   {
       cout<<c1[i];
   }
   cout<<endl;
   for(int i=0;i<b.length();i++)
   {
       c1[b[i]-'a']++;
   }
    for(int i=0;i<26;i++)
   {
       cout<<c1[i];
   }
   cout<<endl;
   for(int i=0;i<26;i++)
   {
       if(c1[i]!=c2[i])
       {
           res+=abs(c1[i]-c2[i]);
       }
   }
   return res;
         
}

int main()
{
    cout<<m("cde","abc");
    return 0;
}
