#include <bits/stdc++.h>
using namespace std;

int findMissingUtil(int arr[], int low, int high, int diff)
{
    if (high <= low)
        return INT_MAX;

    int mid = low + (high - low) / 2;

    if (arr[mid + 1] - arr[mid] != diff)
        return (arr[mid] + diff);

    if (mid > 0 && arr[mid] - arr[mid - 1] != diff)
        return (arr[mid - 1] + diff);

    if (arr[mid] == arr[0] + mid * diff)
        return findMissingUtil(arr, mid + 1, high, diff);

    return findMissingUtil(arr, low, mid - 1, diff);
}

int findMissing(int arr[], int n)
{
    int diff = (arr[n - 1] - arr[0]) / n;

    return findMissingUtil(arr, 0, n - 1, diff);
}

int main()
{
    int arr[] = {2, 4, 8, 10, 12, 14};//only for single element missing
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "The missing element is " << findMissing(arr, n);
    return 0;
}






/*


int inSequence(int A, int B, int C){

    if(!C) return A==B;
    
    int res = (B-A)/C;
    
    return ((B-A)%C ==0 && res>=0);
}

int main(){

    int A, B, C;
    cin>>A>>B>>C;
    cout<<aa(A, B, C)<<endl;
return 0;
} 
*/
