#include <bits/stdc++.h>
using namespace std;
 
string countnndSay(int n)
{

    if (n == 1)      return "1";
    if (n == 2)      return "11";
 
    string str = "11"; 
    for (int i = 3; i<=n; i++)
    {
	    str += '$';
        int len = str.length();
 
        int cnt = 1; 
        string  tmp = ""; 

        for (int j = 1; j < len; j++)
        {
            if (str[j] != str[j-1])
            {
                tmp += cnt + '0';//to_string(cnt)//print count or frequency of variable
                
                tmp += str[j-1];//print the variable
          
                cnt = 1;
            }
            else cnt++;
        }
        //cout<<tmp<<endl;
        str = tmp;
    }
 
    return str;
}


int main()
{
    int N = 6;
    cout << countnndSay(N) << endl;
    return 0;
}



Input: n = 4
Output: "1211"
Explanation:
countAndSay(1) = "1"
countAndSay(2) = say "1" = one 1 = "11"
countAndSay(3) = say "11" = two 1's = "21"
countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"