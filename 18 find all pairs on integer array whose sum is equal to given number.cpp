#include <bits/stdc++.h>
using namespace std;

class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
    	
        int ans = 0;
        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++){
            mp[arr[i]]++;
        }
        for(int i = 0; i < n; i++){
            if(mp.count(k - arr[i])){
                mp[arr[i]]--;//freaquecy of ith element decreses by 1
                ans += mp[k - arr[i]];//frequency of element who make pair with ith element to give complete sum like 5
            }
        }
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}
/*
49 50
48 24 99 51 33 39 29 83 74 72 22 46 40 51 67 37 78 76 26 28 76 25 10 65 64 47 34 88 26 49 86 73 73 36 75 5 26 4 39 99 27 12 97 67 63 15 3 92 90
7
*/
/*
int getPairsCount(int arr[], int n, int sum)
{
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
        m[arr[i]]++;
 
    int twice_count = 0;
    for (int i = 0; i < n; i++) {
        twice_count += m[sum - arr[i]];
        if (sum - arr[i] == arr[i])
            twice_count--;
    }
    return twice_count / 2;
}*/











/*
Time Complexity: O(n2) 
Auxiliary Space: O(1)
 
int getPairsCount(int arr[], int n, int sum)
{
    int count = 0; // Initialize result
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] + arr[j] == sum)
                count++;
 
    return count;
}
int main()
{
    int arr[] = { 1, 5, 7, -1, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 6;
    cout << "Count of pairs is "
         << getPairsCount(arr, n, sum);
    return 0;
}
*/

