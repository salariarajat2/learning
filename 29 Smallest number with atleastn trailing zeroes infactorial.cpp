#include <bits/stdc++.h>
using namespace std;

//Time Complexity: O(log n), Space Complexity: O(1)


bool check(int mid, int n)
{
    int f = 5, count = 0;
    while (f <= mid)
    {
        count += mid / f;
        f *= 5;
    }
    return (count >= n);
}

int aa(int n)
{
	if(n==0) return 1;
	
    if (n == 1) return 5;

    int low = 0, high = n * 5;

    while (low < high)
    {
        int mid = (low + high) / 2;

        if (check(mid, n))
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }

    return low;
}

int main()
{
        int n;
        cin >> n;
        cout << aa(n) << endl;
    
    return 0;
}

