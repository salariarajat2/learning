#include<bits/stdc++.h>
using namespace std;

//using sorting
//Time Complexity: O(n log n), Space Complexity: O(n)


int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int x;
    cin >> x;
  
  sort(arr,arr+n);
  for(int i=0;i<n;i++)
  {
  	int idx=upper_bound(arr+i+1,arr+n,x+arr[i]) - arr -1;  // int idx = lower_bound(arr + i + 1, arr + n, x + arr[i]) - arr ;
        if (arr[idx] - arr[i] == x)
        {
  		cout<<"true";
  		return 0;
	  }
  }
  cout<<"false";
}

/*
6
5 20 3 2 98 8
78
*/


/*using set or maps
//Time Complexity: O(n), Space Complexity: O(n)

bool aa(int *arr, int n, int x)
{

    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        if (mp[x + arr[i]])
        {
            return true;
        }
    }
    return false;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int x;
    cin >> x;
    
    if(aa(arr,n,x)) cout<<"true";
    else cout<<"false";
}






int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int x;
    cin >> x;
    set<int> mp;
    for (int i = 0; i < n; i++)
    {
        mp.insert(arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        int y = arr[i] + x;
        if (mp.count(y))
        {
            cout << "true";
            return 0;
        }
    }
    cout << "false";
}
/*
6
5 20 3 2 98 8
78
*/







/* two for loops
//Time Complexity: O(n^2), Space Complexity: O(1)

int main()
{
    int a;
    cin >> a;
    int arr[a];
    for (int i = 0; i < a; i++)
    {
        cin >> arr[i];
    }

    int x;
    int ans = 0;
    cin >> x;
    for (int i = 0; i < a; i++)
    {
        int y = x + arr[i];
        for (int j = 0; j < a; j++)
        {
            if (arr[j] == y)
            {
                ans = 1;
                break;
            }
        }
    }
    if (ans)
        cout << "true";
    else
        cout << "false";
}
*/


