#include<bits/stdc++.h>
using namespace std;

 bool subArrayExists(int arr[], int n)
{
    set <int> s;//set declare
    int sum = 0;
    for(int i=0;i<n;i++)
    {
        sum = sum + arr[i];
        
        if(sum==0 || s.find(sum)!=s.end())
        {
            return true;
        }
        s.insert(sum);
    }
    return false;
}
 
int main()
{
    int arr[] = { -3, 2, 2, 1, 6 };
    int n = sizeof(arr) / sizeof(arr[0]);
    if (subArrayExists(arr, n))
        cout << "Found a subarray with 0 sum";
    else
        cout << "No Such Sub Array Exists!";
    return 0;
}




/*
bool subArrayExists(int arr[], int n)
{
    map<int, int> mp;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            return true;
        }
        sum += arr[i];
        if (mp[sum] != 0 || sum == 0)
        {
            return true;
        }
        mp[sum]++;
    }
    return false;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        if (subArrayExists(arr, n))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}

*/



/*TC=(O(N^2))


int main()
{
    int arr[] = {2, 3, 4,-9};
 
    int n = sizeof(arr)/sizeof(arr[0]);
 int s=0,f=0;
   for(int i=0;i<n;i++)
   {
     for(int j=i;j<n;j++)
     {
     	s+=arr[j];
     	if(s==0)
     	{
     		f=1; 
     		break;
		 }
		
	 }
	  
		 if(f==1)
		 {
		 	break;
		 }
   }
   if(f==1) cout<<"yes";
   else cout<<"no";
 
    return 0;
}
*/

