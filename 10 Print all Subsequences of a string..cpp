#include <bits/stdc++.h>
using namespace std;

void printSubsequence(string t, int i, int n,string input)
{
 if(i==n)
 {
 	cout<<t<<endl;
 }
 else
 {
 	printSubsequence(t,i+1,n,input);//element not included
 	
 	t+=input[i];//element included
 	printSubsequence(t,i+1,n,input);
 	
 }
}
int main()
{
    string input = "acd";
    printSubsequence("",0,input.length(),input);
 
    return 0;
}

