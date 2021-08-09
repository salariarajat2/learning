#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pi pair<int, int>
#define vi vector<int>
#define vli vector<long>
#define mp make_pair
#define pb push_back
#define FOR(i,a,b) for(int i=(a),i<b;i++)

//without division
//Time Complexity: O(n), Space Complexity: O(n)

vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
{

    vector<long long int> a(n), b(n);
    a[0] = 1;
    b[n - 1] = 1;
    for (int i = 1; i < n; i++)
    {
        a[i] = a[i - 1] * nums[i - 1];
    }

    for (int i = n - 2; i >= 0; i--)
    {
        b[i] = b[i + 1] * nums[i + 1];
    }
    for (int i = 0; i < n; i++)
    {
        nums[i] = a[i] * b[i];
    }
    return nums;
}




/* with division
//Time Complexity: O(n), Space Complexity: O(n)

vector<long long int> productExceptSelf(vector<long long int> &nums, int n)
{

    long long int m = 1;
    for (int i = 0; i < n; i++)
    {
        m *= nums[i];
    }

    for (int i = 0; i < n; i++)
    {
        nums[i] = int(m / nums[i]);
    }
    return nums;
}
*/


/*

void aa(vector<long long int> &arr, int n)
{
    vector<long long int> res(n, 1);
    long long int temp = 1;
    for (int i = 0; i < n; i++)
    {
        res[i] = temp;
        temp = temp * arr[i];
    }
    temp = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        res[i] = res[i] * temp;
        temp = temp * arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << res[i] << " ";
    }
}

int main()
{
    int n;
    cin >> n;
    vector<long long int> arr(n), vec(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    aa(arr, n);
    return 0;
}

*/
