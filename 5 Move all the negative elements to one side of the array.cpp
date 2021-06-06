#include<bits/stdc++.h>
using namespace std;

//TC= O(n)
int main()
{
	int t; cin>>t;
	while(t--)
	{
		int n; cin>>n;
		int ka=0,k=0;
     int* arr=new int[n];
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
		if(arr[i]<ka)
		{
			swap(arr[k],arr[i]);
			k++;
		}
	}

	for(int i=0;i<n;i++)
	{
		cout<<arr[i]<<"  ";
	}
}
return 0;
}
/*
5
9
-12 11 -13 -5 6 -7 5 -3 -6
*/
