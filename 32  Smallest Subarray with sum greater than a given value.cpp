#include <bits/stdc++.h>
using namespace std;


int main() {

	int i,j,n,t,k;
	cin >> t;
	while(t--)
	{
	    cin >> n;
	    cin >> k;
	    vector<int> A;
	    for(i=0;i<n;i++)
	    {
	        int temp;
	        cin >> temp;
	        A.push_back(temp);
	    }
	    i=0;j=0;
	    int sum  = 0;
	    int len = INT_MAX;
	    while(i<n&&j<n)
	    {
	        while(j<n&&sum+A[j]<=k)
	            {sum += A[j++];}
	        
	        len = min(len,j-i+1);
	        sum -= A[i++];
	    }
	    cout << len << endl;
	}
	return 0;
}
/*

5
6
51
1 4 45 6 0 19
ans 3
*/

/*


int main() 
{
    long long int t,n,x;
    cin >>t;
    while(t--)
    {
        cin >>n>>x;
        vector <long long int> a(n);
        for(int i=0;i<n;i++)cin >>a[i];
        long long int start=0,end=0,mini=n+1,sum=0;
        
        while(end<n)
        {
            while(sum<=x&&end<n)
            {
                sum = sum + a[end];
                end++;
            }
            
            while(sum>x&&start<n)
            {
                if(end-start<mini)mini = end-start;
                
                sum = sum - a[start];
                start++;
            }
        }
        cout<<mini<<endl;
    }
}
*/









/*
//TC- O(n^2)  . SC=O(1)

int main()
{
   
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
          cin>>arr[i];
        }

        int diff = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int sum=0;
            for (int j = i; j < n; j++)
            {
                sum += arr[j];
                if (sum > x)
                {
                    diff = min(diff, j-i + 1);
                }
            }
        }

        cout << diff;
    
    return 0;
}

*/
