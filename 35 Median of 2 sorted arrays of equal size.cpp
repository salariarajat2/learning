#include <bits/stdc++.h>
using namespace std;

// TC = O(min(logn,logm)), SC = O(1)

double Median(vector<int> &A, vector<int> &B)
{
    int n = A.size();
    int m = B.size();
    if (n > m)
        return Median(B, A);

    int start = 0;
    int end = n;
    int realmidinmergedarray = (n + m + 1) / 2;

    while (start <= end)
    {
        int mid = (start + end) / 2;
        int leftAsize = mid;
        int leftBsize = realmidinmergedarray - mid;
        int leftA = (leftAsize > 0) ? A[leftAsize - 1] : INT_MIN;
        int leftB = (leftBsize > 0) ? B[leftBsize - 1] : INT_MIN;
        int rightA = (leftAsize < n) ? A[leftAsize] : INT_MAX;
        int rightB = (leftBsize < m) ? B[leftBsize] : INT_MAX;

        if (leftA <= rightB and leftB <= rightA)
        {
            if ((m + n) % 2 == 0)
                return (max(leftA, leftB) + min(rightA, rightB)) / 2.0;
            return max(leftA, leftB);
        }
        else if (leftA > rightB)
        {
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    return 0.0;
}

int main()
{
    vector<int> arr1 = {-5, 3, 6, 12, 15};
    vector<int> arr2 = {-12, -10, -6, -3, 4, 10};
    cout << "Median of the two arrays are" << endl;
    cout << Median(arr1, arr2);
    return 0;
}

/*

// TC = O(m+n) , SC = O(1)

int getMedian(int ar1[], int ar2[], int n, int m)
{
    int i = 0;
    int j = 0;
    int count;
    int m1 = -1, m2 = -1;

    if ((m + n) % 2 == 1)
    {
        for (count = 0; count <= (n + m) / 2; count++)
        {
            if (i != n && j != m)
            {
                m1 = (ar1[i] > ar2[j]) ? ar2[j++] : ar1[i++];
            }
            else if (i < n)
            {
                m1 = ar1[i++];
            }
            else
            {
                m1 = ar2[j++];
            }
        }
        return m1;
    }
    else
    {
        for (count = 0; count <= (n + m) / 2; count++)
        {
            m2 = m1;
            if (i != n && j != m)
            {
                m1 = (ar1[i] > ar2[j]) ? ar2[j++] : ar1[i++];
            }
            else if (i < n)
            {
                m1 = ar1[i++];
            }
            else
            {
                m1 = ar2[j++];
            }
        }
        return (m1 + m2) / 2;
    }
}

*/

/*

//TC = O((n+m)log(m+n)) , SC = O(n+m)
combine both array then sort and find median

*/

/*
// Time Complexity : O(logn) recursion //same array size 
 
int median(int arr[], int n)
{
    if (n%2 == 0)
        return (arr[n/2] + arr[n/2-1])/2;
    else
        return arr[n/2];
}

int getMedian(int ar1[], int ar2[], int n)
{
    if (n <= 0)
        return -1;
    if (n == 1)
        return (ar1[0] + ar2[0])/2;
    if (n == 2)
        return (max(ar1[0], ar2[0]) + min(ar1[1], ar2[1])) / 2;
 
    int m1 = median(ar1, n); 
    int m2 = median(ar2, n); 
 
    if (m1 == m2)
        return m1;
 
    
    if (m1 < m2)
    {
        if (n % 2 == 0)  return getMedian(ar1 + n/2 - 1, ar2, n - n/2 +1);
        
        return getMedian(ar1 + n/2, ar2, n - n/2);
    }
 
    if (n % 2 == 0)   return getMedian(ar2 + n/2 - 1, ar1, n - n/2 + 1);
    
    return getMedian(ar2 + n/2, ar1, n - n/2);
}
 
int main()
{
    int ar1[] = {1, 2, 3, 6};
    int ar2[] = {4, 6, 8, 10};
    int n1 = sizeof(ar1)/sizeof(ar1[0]);
    int n2 = sizeof(ar2)/sizeof(ar2[0]);
    if (n1 == n2)
        printf("Median is %d", getMedian(ar1, ar2, n1));
    else
        printf("Doesn't work for arrays of unequal size");
    return 0;
}

*/
