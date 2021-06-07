#include <bits/stdc++.h>
using namespace std;
  
//TC O(n)

void printRepenumsting(vector<int> nums, int size)
{
    int n = nums.size();
    
    for (int i = 0; i < n; i++) {
        nums[nums[i] % n]= nums[nums[i] % n] + n;
    }
    for (int i = 0; i < n; i++) {
    
    		 if (nums[i] >= n * 2)  //if(nums[i]/n >1)
		 {
            cout << i;
		//	break;
		}
    }
}

void printRepeating(vector<int> arr, int size)
{
    int i;
    cout << "The repeating elements are:" << endl;
    for (i = 0; i < size; i++) {
        if (arr[abs(arr[i])] >= 0)
        {
            arr[abs(arr[i])] = -arr[abs(arr[i])];
		}
       
        else
            cout << abs(arr[i]) << " ";
    }
}
int main()
{
    // { 1 2 3 1 3 6 6 };
    int n; cin>>n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin>>nums[i];
    printRepeating(nums,n);
    return 0;
}

/*

    
    */




/*
Floyd's Tortoise and Hare O(n)

 public int findDuplicate(int[] nums) {
    // Find the intersection point of the two runners.
    int tortoise = nums[0];
    int hare = nums[0];
    do {
      tortoise = nums[tortoise];
      hare = nums[nums[hare]];
    } while (tortoise != hare);

    // Find the "entrance" to the cycle.
    tortoise = nums[0];
    while (tortoise != hare) {
      tortoise = nums[tortoise];
      hare = nums[hare];
    }

    return hare;
  }


*/



/*
using sorting
// duplicates in O(nlogn) time

#include <bits/stdc++.h>
using namespace std;
int findDuplicate(int *nums, int n) {
    sort(nums, nums + n);
    for (int i = 0; i < n - 1; i++) {
        if (nums[i] == nums[i + 1])
            return nums[i];
}
    return -1;
}
int main() {
 
    int nums[] = {1, 3, 4, 2, 2};
    int n = sizeof(nums) / sizeof(nums[0]);
    cout<<findDuplicate(nums, n)<<endl;
    return 0;
}

*/





/*
brute force TC  O(n^2)

#include <bits/stdc++.h>
using namespace std;

int findDuplicate(int *nums, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] == nums[j])
                return nums[i];
        }
    }
    return -1;
}

int main() {
    int nums[] = {1, 3, 4, 2, 2};
    int n = sizeof(nums) / sizeof(nums[0]);
    cout<<findDuplicate(nums, n)<<endl;
    return 0;
}

*/
