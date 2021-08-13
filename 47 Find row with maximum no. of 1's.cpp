#include <bits/stdc++.h>
using namespace std;
int rowWithMax1s(vector<vector<int> > , int , int ) ;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
         for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
       
        auto ans = rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

 rowWithMax1s(vector<vector<int> > arr, int n, int m) {
		
	    int index=0;
	    int max=INT_MIN;
	    int sum=0;
	    for(int i=0;i<n;i++)
	    {
	       //  &sum;
	          sum=accumulate(arr[i].begin(),arr[i].end(),0);
	         //cout<<sum<<endl;
	        if(sum>max)
	        {
	            max=sum;
	            index=i+1;
	        }
	    }
	    if(max==0)
	    {
	        return -1;
	    }
	    return index;
	}


/*
5
4 4 
0 1 1 1
0 0 1 1
1 1 1 1
0 0 0 0


*/








/*
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n,m,i,j,maxx,k,pos;
	    cin>>n>>m;
	    int mat[n][m];
	    for(i=0;i<n;i++)
	        for(j=0;j<m;j++)
	            cin>>mat[i][j];
	   maxx=0;
	   for(i=0;i<n;i++){
	      k=(mat[i]+m)-upper_bound(mat[i],mat[i]+m,0) ;
	      if(k>maxx)
	      {
	          maxx=k;
	          pos=i;
	      }
	   }
	   cout<<pos<<endl;
	}
	return 0;
}
*/
