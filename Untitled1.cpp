#include<bits/stdc++.h>
using namespace std;


int main() {
    int n,q,m,a,b,s=0;
    cin>>n>>q;
    int* arr[n];
    while(n--)
    {
    	int num; cin>>num;
    	arr[s]=new int[num];
    	for(int i=0;i<num;i++)
    	{
    		cin>>arr[s][i];
		}
		s++;
	}
    while(q--)
    {
        cin>>a>>b;
        cout<<arr[a][b]<<endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    return 0;
}
/*
2 2
3 1 5 4
5 1 2 8 9 3
0 1
1 3
*/
