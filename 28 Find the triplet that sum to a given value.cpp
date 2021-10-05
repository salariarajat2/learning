#include<bits/stdc++.h>
using namespace std;

//using sorting and two pointer apporach TC= O(n^2) SC- O(1)

bool sum_equal(int m, int n, int *arr)
{
    sort(arr, arr + m);

    for (int i = 0; i < m - 2; i++)
    {
        int low = i + 1;
        int high = m - 1;
        while (low < high)
        {
            if (arr[i] + arr[low] + arr[high] == n)
                return true;
            else if (arr[i] + arr[low] + arr[high] < n)
                low++;
            else
                high--;
        }
    }
    return false;
}

int main()
{
    int m, x;
    cin >> m >> x;
    int a[m];
    for (int i = 0; i < m; i++)
        cin >> a[i];

    cout << sum_equal(m, x, a);
}




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
	
	
