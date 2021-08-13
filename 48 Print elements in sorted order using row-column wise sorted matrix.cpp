#include<bits/stdc++.h>
using namespace std;


void sortedMatrix(int N, vector<vector<int>> mat) {
        int arr[N*N];
        int count=0;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                arr[count++]=mat[i][j];
            }
        }
        count=0;
        
        sort(arr,arr+N*N);
        
        for(int i=0;i<N*N;i++)
        {
        	if(i%N==0) cout<<endl;
          cout<<arr[i]<<"  ";
        }
       
    }

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> v(N, vector<int>(N));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) cin >> v[i][j];
         sortedMatrix(N, v);
        
        }
    }






/*
int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        int N;
        cin >> N;
        int m[N][N];
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                cin >> m[j][k];
            }
        }
        qsort(m, N * N, sizeof(int),
                   [](const void *a, const void *b) -> int {
                       int arg1 = *static_cast<const int *>(a);
                       int arg2 = *static_cast<const int *>(b);
                       if (arg1 < arg2) return -1;
                       if (arg1 > arg2) return 1;
                       return 0;
                   });
        for (int j = 0; j < N * N; ++j) {
        		if(j%N==0)  cout<<endl;
            cout << m[0][j] << " ";
        }
        cout << endl;
    }
}



int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n][n], b[n*n];
	    int count = 0;
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            cin>>a[i][j];
	            b[count] = a[i][j];
	            count++;
	        }
	    }
	    sort(b,b+(n*n));
	    for(int i=0;i<n*n;i++)
	    {
	    	if(i%n==0)  cout<<endl;
	    	
	        cout<<b[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}

3
4
10 20 30 40
15 25 35 45 
27 29 37 48 
32 33 39 50



3
3
1 5 3
2 8 7
4 6 9
*/






