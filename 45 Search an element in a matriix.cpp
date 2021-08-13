#include <bits/stdc++.h>
using namespace std;


	int matSearch (vector <vector <int>> &matrix, int N, int M, int target)
	{
	    int i,j,m,n;
        m=matrix.size();//     m=N;
        n=matrix[0].size();//n=M;
        cout<<"m "<< m<<"  n "<<n<<endl;
        for(i=0;i<m;i++){
            if(matrix[i][n-1] >= target){
        
                if(binary_search(matrix[i].begin(), matrix[i].end(), target)){
                return 1;
            }
        }}
        return 0;
	}

int main ()
{
        int n, m; cin >> n >> m;
        vector <vector <int>> arr (n, vector <int> (m));
        for (int i=0;i<n;i++)
            for (int j=0;j<m;j++)
                cin >> arr[i][j];
                
        int x; cin >> x;
        cout <<matSearch (arr, n, m, x) << endl;
    
} 






/*
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    int n,m,i,j,x,f=0;
	    cin>>n>>m;
	    int a[n][m];
	    for(i=0;i<n;i++)
	        for(j=0;j<m;j++)
	            cin>>a[i][j];
	    cin>>x;
	    i=0,j=m-1;
	    while(i<n && j>=0){
	        if(a[i][j]==x){
	            f=1;
	            break;
	        }
	        else if(a[i][j]>x){
	            j--;
	        }
	        else{
	            i++;
	        }
	    }
	    cout<<f<<endl;
	}
	return 0;
}











int search(int mat[4][4], int n, int x)
{
    if (n == 0)
        return -1;
     
    //traverse through the matrix
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        //if the element is found
        if(mat[i][j] == x)
        {
            cout<<"Element found at ("<<
                        i << ", " << j << ")\n";
            return 1;
        }
    }
  
    cout << "n Element not found";
  */ 
