#include <bits/stdc++.h>
using namespace std;

//TC = O(n), sc= O(1)

void func(vector<int> &arr, int a, int b)
{
    int n = arr.size();
    int low = 0, high = n - 1;

    for (int i = 0; i <= high; i++)
    {
        if (arr[i] < a)
            swap(arr[i], arr[low++]);
        else if (arr[i] > b)
        {
            swap(arr[i], arr[high--]);
            i--;
        }
    }

    for (auto it : arr)
    {
        cout << it << " ";
    }
}

int main()
{

    int n, a, b;
    cin >> n >> a >> b;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    func(arr, a, b);

    return 0;
}
/*
5 3 4
6 3 2 1 5
*/