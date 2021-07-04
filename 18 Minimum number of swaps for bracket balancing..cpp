#include<bits/stdc++.h>
using namespace std;

int brac(string s, int n)
{
	  int left=0;
       int right=0;
       int swap=0;
       int imbalance=0;
   
       for(int i=0;i<n;i++)
       {
           if(s[i]==']')
           {
           	  right++;
           	  imbalance = right-left;
             
           }
           else
           {
              left++;
              if(imbalance>0)
              {
                 swap += imbalance;
                 imbalance--;
              }
           }
       }
     return swap;
 
}
int main() 
{
//   int t;
//   cin >>t;
//   while(t--)
//   {
   	  string s;
       cin >>s;
       int n=s.length();
       cout<<brac(s,n);
     
 //  }
   return 0;
}






/*
#include<bits/stdc++.h>
using namespace std;

int main() 
{
//   int t;
//   cin >>t;
//   while(t--)
//   {
   	  string s;
       cin >>s;
       int n=s.length();
       int left=0;
       int right=0;
       int swap=0;
       int imbalance=0;
   
       for(int i=0;i<n;i++)
       {
           if(s[i]=='[')
           {
              left++;
              if(imbalance>0)
              {
                 swap = swap + imbalance;
                 imbalance--;
              }
           }
           else
           {
               right++;
               imbalance = right-left;
           }
       }
       cout<<swap;
       cout<<endl;
 //  }
   return 0;
}

*/
