#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t; cin>>t;
	while(t--)
	{
			int n;
	cin>>n;
	n*=n;
	vector<int> arr(n);

		for(int j=0;j<n;j++)
		{
			cin>>arr[j];
		}
		
		sort(arr.begin(),arr.end());
		for(auto it:arr)
		{
			if(n%int(it)==0) cout<<endl;
			
			cout<<it<<"  ";
		}
		int k;
		
		cin>>k;
		
		cout<<arr[k-1]<<endl;
	}

	


}
/*
4
16 28 60 64 
22 41 63 91
27 50 87 93 
36 78 87 94 

4
10 20 30 40 
15 25 35 45
24 29 37 48 
32 33 39 50




int kthSmallest(int mat[MAX][MAX], int n, int k)
{
   priority_queue<int,vector<int>,greater<int>>pq;
   int i,j;
   for(i=0;i<n;i++){
       for(j=0;j<n;j++){
           pq.push(mat[i][j]);
       }
   }
  for(i=0;i<k-1;i++){
      pq.pop();
  }

   return pq.top();
}




int kthSmallest(int mat[MAX][MAX], int n, int k)
{
   vector<int>rix;
   int i,j;
   for(i=0;i<n;i++){
       for(j=0;j<n;j++){
           rix.push_back(mat[i][j]);
       }
   }
   sort(rix.begin(),rix.end());
   return rix[k-1];
}


*/



