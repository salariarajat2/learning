#include<bits/stdc++.h>
using namespace std;

//Time Complexity: O(log n), Space Complexity: O(1)

int floorSqrt(int x)
{
    if (x == 0 || x == 1)
        return x;

    int start = 1, end = x, ans;
    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (mid * mid == x)
            return mid-1;

        if (mid * mid < x)
        {
            start = mid + 1;
            ans = mid;
        }
        else
            end = mid - 1;
    }
    return ans;
}

int main()
{
    int x =25;
    cout << floorSqrt(x) << endl;
    return 0;
}







/*
Time Complexity: O(v n), Space Complexity: O(1)

int countSquares(int N)
{
    int a = sqrt(N);
    if (a * a == N)
        return a - 1;
    else
        return a;
}
    
    
   //  or
     
     
int countSquares(int N)
{
    int c = 0;
    for (int i = 1; i < sqrt(N); i++)
    {
        if (i * i < N)
            c++;
    }
    return c;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        cout << countSquares(N) << endl;
    }
    return 0;
}
*/
