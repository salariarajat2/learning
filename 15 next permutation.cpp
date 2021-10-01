#include <bits/stdc++.h>
using namespace std;

// TC = O(N), SC = O(1)

void nextPermutation(int N, vector<int> arr)
{
	int n = arr.size(), idx, l;

	for (idx = n - 2; idx >= 0; idx--)
	{
		if (arr[idx] < arr[idx + 1])
		{
			break;
		}
	}

	if (idx < 0)
	{
		reverse(arr.begin(), arr.end());
	}
	else
	{
		for (l = n - 1; l > idx; l--)
		{
			if (arr[l] > arr[idx])
			{
				break;
			}
		}
		swap(arr[idx], arr[l]);
		reverse(arr.begin() + idx + 1, arr.end());
	}

	for (int u : arr)
		cout << u << " ";
	cout << "\n";
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int N;
		cin >> N;
		vector<int> arr(N);
		for (int i = 0; i < N; i++)
			cin >> arr[i];
		nextPermutation(N, arr);
	}
	return 0;
}
/*
6 6
1 2 3 6 5 4
*/

/*
int main()
 {
	ll t;
	cin>>t;
	while(t--){
	    ll i,n,pos=-1,temp,f=0;
	    cin>>n;
	    ll a[n];
	    for(i=0;i<n;i++)    
	        cin>>a[i];
	    next_permutation(a,a+n);
	    for(i=0;i<n;i++){
	        cout<<a[i]<<" ";
	    }
	    cout<<endl;
	}
	return 0;
}
	 

*/
