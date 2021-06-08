#include <bits/stdc++.h>
using namespace std;
//linear search

int main() {
	int T, i, N;
	cin >> T;
	
	while(T--) {
//		int Max=-1, Min=9999999;
        int Max,Min;
	    //int Max=INT_MIN, Min=INT_MAX;
		cin >> N;
		int a[N];
		cin >> a[0];
		Min = a[0];
		Max = a[0];
		for(i=1; i<N; i++) {
			cin >> a[i];
			Min = (Min<a[i]) ? Min : a[i];
			Max = (Max>a[i]) ? Max : a[i];
		}
		cout << Min << " " << Max << endl;
	}
	return 0;
}

/*
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    sort(arr,arr+n);
	    
	    cout<<arr[0]<<" "<<arr[n-1]<<endl;
	}
	return 0;
}*/
