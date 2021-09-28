#include <bits/stdc++.h>
using namespace std;
//TC O(n)
int minJumps(int arr[], int n)
{
	int sum = arr[0];
	int steps = arr[0];
	int jump = 1;
	if (n == 1)
		return 0;
	else if (arr[0] == 0)
		return -1;
	else
	{
		for (int i = 1; i < n; i++)
		{
			if (i == n - 1)
				return jump;
			sum = max(sum, arr[i] + i);
			steps--;
			if (steps == 0)
			{
				jump++;
				if (i >= sum)
				{
					return -1;
				}
				steps = sum - i;
			}
		}
	}
	return 0;
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
		cout << minJumps(arr, n);
	}
	return 0;
}

/*
1 6 1 4 3 2 6 7 ans 2


Tc = O(n^2), SC = O (n)


int minJumps(int arr[], int n, int *dp)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (dp[j] != INT_MAX and (arr[j] + j >= i))
            {
                if (dp[j] + 1 < dp[i])
                    dp[i] = dp[j] + 1;
            }
        }
    }
    if (dp[n - 1] != INT_MAX)
        return dp[n - 1];
    else
        return -1;
}
int main()
{
    int n = 6;
    int *arr = new int[n];
    int dp[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        dp[i] = INT_MAX;
    }
    dp[0] = 0;
    // memset(dp, INT_MAX, sizeof(dp));
    cout << minJumps(arr, n, dp);
}
*/
