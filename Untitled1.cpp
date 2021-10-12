#include <bits/stdc++.h>
using namespace std;

class base{
	public:
void func(int arr[], int n)
{
    sort(arr, arr+n);// 5 11 12 14 31 
    int* ans=new int(n);
    int mid = (n-1)/2;
 
    int j = 1, i = 1;
    ans[mid] = arr[0];
    for (i = 1; i <= mid; i++)
    {
        ans[mid+i] = arr[j++];
        ans[mid-i] = arr[j++];
    }
 
    if (n%2 == 0) ans[mid+i] = arr[j];
 
 
    for (i = 0 ; i < n; i++)  cout << ans[i] << " ";
 
    cout << endl;
}		};

int main()
{
	int t; cin>>t;
	while(t--)
	{
		int n; cin>>n;
		int* arr=new int(n);
        for(int i=0;i<n;i++)  cin>>arr[i];
    base ob;
    ob.func(arr, n);
		
	}
    return 0;
}
/*

2
4 
1 3 2 5 4
5
11 12 31 14 5

*/

