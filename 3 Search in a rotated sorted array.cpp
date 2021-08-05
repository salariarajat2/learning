#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(log n), Space Complexity: O(1)

   int search(vector<int> nums, int target) {
        int low=0;
        int high=nums.size()-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(nums[mid] == target) return mid;
            else if(nums[mid] >= nums[low])
            {
                if(nums[low] <= target and target <= nums[mid]) high =mid-1;
                else low=mid+1;
            }
            else{
                if(nums[mid] <=target and nums[high] >= target) low = mid+1;
                else high =mid-1;
            }
        }
        return -1;
    }

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin>>nums[i];

cout<<search(nums,x);

    return 0;
}



/*
7 0
4 5 6 7 0 1 2 

ans- 4

*/
