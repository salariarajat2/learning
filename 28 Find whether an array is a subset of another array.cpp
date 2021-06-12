#include <bits/stdc++.h>
using namespace std;
//third approach ->TC= O(n) SC- O(n)
bool isSubset(int m,int n,int arr1[],int arr2[])
{
    unordered_map<int,int> mp;
    for(int i=0;i<m;i++) mp[arr1[i]]++;
    
    for(int i=0;i<n;i++)
    {
        if(mp.find(arr2[i])==mp.end())
        {
            return false;
        }
    }
    return true;
}

int main() {
	int t,m,n;
	cin>>t;
	while(t--)
	{
	cin>>m>>n;
	int arr1[m],arr2[n];
	for(int i=0;i<m;i++)   cin>>arr1[i];
	for(int i=0;i<n;i++)   cin>>arr2[i];

	if(isSubset(m,n,arr1,arr2))    cout<<"Yes"<<endl;
	else cout<<"No";

}
return 0;
}
	/*
5
6 4	
11 1 13 21 3 7
11 3 7 1
*/

//ist approach   two for loop-> TC= O(n^2) SC- O(1)

//2ns approach   sorting and binary search, sorting and two pointer-> TC- O(nlogn)  SC-> O(1)


