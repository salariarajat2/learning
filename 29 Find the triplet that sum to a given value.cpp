#include<bits/stdc++.h>
using namespace std;

//using sorting TC= O(n^2) SC- O(1)

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, x;
    cin >> m >> x;
    int a[m];
    for (int i = 0; i < m; i++)
        cin >> a[i];

    sort(a, a + m);
    int ans = 0;
    for (int i = 0; i < m - 2; i++)
    {
        int l = i + 1;
        int r = m - 1;
        while (l < r)
        {
            if (a[i] + a[l] + a[r] == x)
            {
                ans = 1;
                break;
            }
            else if (a[i] + a[l] + a[r] < x)
            {
                l++;
            }
            else
                r--;
        }
    }
    cout << ans;
    return 0;
}

/* 
6 7 
3 2 6 
5 3 1 
0 1 5 
1 5 -3 
1 2 -2 
3 4 -2 
2 4 3 
0
*/



/*
// using set ->  TC= O(n^2) SC- O(n)
int main()
{
    	int m,x;

	cin>>m>>x;
	int a[m];
	for(int i=0;i<m;i++)   cin>>a[i];

    for (int i = 0; i < m; i++)
    {
        unordered_set<int> s;
        int cur = x - a[i];
        for (int j = i + 1; j < m; j++)
        {

            if (s.find(cur-a[j]) != s.end())
            {
                cout <<"yes";
                break;
            }
            s.insert(a[j]);
        }
    }

}

*/






/*  TC= O(n^3) SC- O(1)
 for (int i = 0; i < m; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            for (int k = j + 1; k < m; k++)
            {
                if (arr[i] + arr[j] + arr[k] == x)
                {
                    cout << "1";
                }
            }
        }
    }
	*/
	
	
