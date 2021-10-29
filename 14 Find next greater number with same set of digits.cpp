#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long i, n;
    cin >> n;
    long long a[n];
    for (i = 0; i < n; i++)
        cin >> a[i];
    next_permutation(a, a + n);
    for (i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

/*
void findNextGreater(char number[], int n)
{
    int i, j, l;
    for (i = n - 2; i >= 0; i--)
    {
        if (number[i] < number[i + 1])
            break;
        if (i == -1)
        {
            cout << "Next number is not possible";
            return;
        }
    }

    for (l = n - 1; l > i; l--)
    {
        if (number[l] > number[i])
        {
            break;
        }
    }
    swap(number[i], number[l]);
    reverse(number + i + 1, number + n);
    cout << number;
    return;
}

int main()
{
    char number[] = "12345986";
    int n = strlen(number);
    cout << "The next number with same set of digits is ";
    findNextGreater(number, n);
    return 0;
}
*/
