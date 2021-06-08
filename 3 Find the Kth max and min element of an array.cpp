#include<bits/stdc++.h>
using namespace std;

//TC= O(n+k logn) using priority queue
int main()
{
	int t; cin>>t;
	while(t--)
	{
		int n; cin>>n;
     int* arr=new int[n];
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	int k; cin>>k;
	//min heap concept
	priority_queue<int,vector<int>,greater<int> > p;
	for(int i=0;i<n;i++)
	{
		p.push(arr[i]);
	}
	int ans,i=1;
	while(!p.empty())
	{
		if(i==k)
		{
			ans=p.top();
			break;
		}
		i++;
		p.pop();
		
	}
	cout<<ans;
	
	
	
}
return 0;
}
	
	
	
	

/*
TC= O(nlogn) using sorting



int main()
{
	int t; cin>>t;
	while(t--)
	{
		int n; cin>>n;
     int* arr=new int[n];
	
	for(int i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	sort(arr,arr+n);
	int k;
	cin>>k;
	cout<<arr[k-1]<<endl;
	}


return 0;
}
/*
3
6
7 10 4 3 20 15
3

5
1 10 4 20 15
4

*/
