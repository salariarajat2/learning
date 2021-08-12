#include <bits/stdc++.h>
using namespace std;
double eps = 1e-7;

//Time Complexity: O(n * log(10^d), Space Complexity: O(1)

double fun(double mid, int n)
{
    double result = 1;
    for (int i = 0; i < n; i++)
    {
        result *= mid;
    }
    return result;
}

int main()
{
    double x;
    cin >> x;
    int nth;
    cin >> nth;
    double low = 0, high = x, mid;
    while (high - low > eps)
    {
        mid = (high + low) / 2;
        if (fun(mid, nth) < x)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }
    cout << setprecision(10) << low << endl;
    cout << pow(x, 1.0 / nth);
}


//pth root of number N with D decimal accuracy   TC = O(p * log(N * (10^d)))
