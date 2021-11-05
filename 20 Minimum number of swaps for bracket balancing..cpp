#include <bits/stdc++.h>
using namespace std;

//TC = O(N), SC = O(N)

int brac(string s)
{
   int n = s.length();
   if (n & 1)
      return -1;
   else
   {
      stack<char> st;
      int c = 0, c1 = 0;
      for (int i = 0; i < n; i++)
      {
         if (s[i] == '{')
         {
            st.push(s[i]);
            c1++;
         }
         else if (s[i] == '}' and !st.empty() and st.top() == '{')
         {
            st.pop();
            c1--;
         }
         else
         {
            c++;
         }
      }
      if (c & 1)
         c = (c / 2) + 1;
      else
         c = c / 2;
      if (c1 & 1)
         c1 = (c1 / 2) + 1;
      else
         c1 = c1 / 2;

      return c + c1;
   }
}

int main()
{
   string s;
   cin >> s;
   cout << brac(s);
}

/*
int brac(string s, int n)
{
   int left = 0;
   int right = 0;
   int swap = 0;
   int imbalance = 0;

   for (int i = 0; i < n; i++)
   {
      if (s[i] == ']')
      {
         right++;
         imbalance = right - left;
      }
      else
      {
         left++;
         if (imbalance > 0)
         {
            swap += imbalance;
            imbalance--;
         }
      }
   }
   return swap;
}



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
