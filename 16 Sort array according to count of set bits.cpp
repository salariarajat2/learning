#include <bits/stdc++.h>
using namespace std;

//Time Complexity: O(v n), Space Complexity: O(1)


static bool bi(int a, int b)
{
    return __builtin_popcount(a) > __builtin_popcount(b);
}
void aa(int arr[], int n)
{
    stable_sort(arr, arr + n, bi);
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
    aa(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}



/*
9
5 2 3 9 4 6 7 15 32
15 7 5 3 9 6 2 4 32
*/

/*
int count_1(int a)
{
    int ct = 0;
    while (a)
    {
        a = a & (a - 1);
        ct++;
    }
    return ct;
}
bool compare(int a, int b)
{
    int c1 = count_1(a);
    int c2 = count_1(b);

    if (c1 <= c2)
        return false;
    return true;
}

void aa(int arr[], int n)
{
    stable_sort(arr, arr + n, compare);
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
    aa(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
*/





/*
bool comp(const pair<int, int> &a, const pair<int, int> &b)
{
    return a.second > b.second;
}
int main()
{

    int n, i;
    cin >> n;
    int a[n];
    vector<pair<int, int>> vec;
    for (i = 0; i < n; i++)
        cin >> a[i];
    for (i = 0; i < n; i++)
    {
        vec.push_back(make_pair(a[i], __builtin_popcount(a[i])));
    }
    stable_sort(vec.begin(), vec.end(), comp);
    for (auto x : vec)
    {
        cout << x.first << " ";
    }
    cout << endl;
    return 0;
}
*/
