#include <bits/stdc++.h>
using namespace std;

// Floyd's Tortoise and Hare O(n)

int findDuplicate(int *nums)
{
    int tortoise = nums[0];
    int hare = nums[0];
    do
    {
        tortoise = nums[tortoise];
        hare = nums[nums[hare]];
    } while (tortoise != hare);

    tortoise = nums[0];
    while (tortoise != hare)
    {
        tortoise = nums[tortoise];
        hare = nums[hare];
    }

    return hare;
}

int main()
{
    int n;
    cin >> n;
    int *nums = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << findDuplicate(nums);
}

/*
//TC O(n), SC = O(n)

int main()
{
    int n;
    cin >> n;
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        mp[a]++;
    }

    for (auto it : mp)
    {
        if (it.second > 1)
        {
            cout << it.first << " ";
        }
    }
}




void printRepenumsting(vector<int> nums, int size)
{
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        nums[nums[i] % n] = nums[nums[i] % n] + n;
    }
    for (int i = 0; i < n; i++)
    {

        if (nums[i] >= n * 2) //if(nums[i]/n >1)
        {
            cout << i;
            //	break;
        }
    }
}





// using sorting duplicates in O(nlogn) time

int findDuplicate(int *nums, int n)
{
    sort(nums, nums + n);
    for (int i = 0; i < n - 1; i++)
    {
        if (nums[i] == nums[i + 1])
            return nums[i];
    }
    return -1;
}




// brute force TC O(n ^ 2)


int findDuplicate(int *nums, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (nums[i] == nums[j])
                return nums[i];
        }
    }
    return -1;
}

*/
