#include <bits/stdc++.h>
using namespace std;

int answer(int arr[], int n, int k)
{
    // less than equals to k
    int count = 0;
    for (int i = 0; i < n; ++i)
        if (arr[i] <= k)
            ++count;

    // Find unwanted elements in current
    // window of size 'count'
    int bad = 0;
    for (int i = 0; i < count; ++i)
        if (arr[i] > k)
            ++bad;

    // Initialize answer with 'bad' value of
    // current window
    int ans = bad;
    for (int i = 0, j = count; j < n; ++i, ++j)
    {

        // Decrement count of previous window
        if (arr[i] > k)
            --bad;

        // Increment count of current window
        if (arr[j] > k)
            ++bad;

        // Update ans if count of 'bad'
        // is less in current window
        ans = min(ans, bad);
    }
    return ans;
}

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int size;
        cin >> size;
        int i, arr[size], k;
        for (i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
        cin >> k;
        cout << answer(arr, size, k);
        cout << endl;
    }
}
/*
5 3
2 1 5 6 3
*/

/*

int main() 
{
	long long int t,n,k;
	cin >>t;
	while(t--)
	{
	    cin >>n;
	    vector <long long int> a(n);
	    for(int i=0;i<n;i++)cin >>a[i];
	    cin >>k;
	    long long int ct = 0;
	    long long int bad = 0;
	    for(int i=0;i<n;i++)
	    {
	        if(a[i]<=k)ct++;
	    }
	    for(int i=0;i<ct;i++)
	    {
	        if(a[i]>k)bad++;
	    }
	    long long int ans = bad;
	    int i,j;
	    for(i=0,j=ct;j<n;i++,j++)
	    {
	        if(a[i]>k)bad--;//shifting the sliding window
	        if(a[j]>k)bad++;
	        
	        ans = min(ans,bad);
	    }
	    cout<<ans<<endl;
	}
}


*/
















