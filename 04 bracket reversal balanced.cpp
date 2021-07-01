#include <bits/stdc++.h>
using namespace std;

int countMinReversals(string expr)
{
    int len = expr.length();
    if (len % 2 != 0) {
        return -1;
    }
    int left_brace = 0, right_brace = 0;
    int ans=0;
    for (int i = 0; i < len; i++) {
        if (expr[i] == '{') {
            left_brace++;
        }
        else {
            if (left_brace == 0) {
                right_brace++;
            }
            else {
                left_brace--;
            }
        }
    }
    if(left_brace&1)
    {
    left_brace = (left_brace / 2)+1;	
	}else
	{
	left_brace = (left_brace / 2);
	}
	
	  if(right_brace&1)
    {
    right_brace= (right_brace / 2)+1;	
	}else
	{
	 right_brace = (right_brace / 2);
	}
    ans=left_brace+right_brace;
    return ans;
}
int main()
{
    string expr = "{{{{}}";
    cout << countMinReversals(expr);
    return 0;
}

//tc = O(n)
//sp= O(1)
