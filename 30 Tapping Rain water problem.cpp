#include <iostream>
using namespace std;

//TC=O(n) , sc=O(1)

int a(int n, int *arr)
{

	int ma=0, mr=0, left=0,right=n-1,sum=0;
	
	while(left <= right)
	{
		if(ma < mr)
		{
			if(arr[left] > ma) ma=arr[left];
			
			else  sum+= (ma - arr[left]);
			
			left++;
		}
		
		else{
			
			if(arr[right] > mr) mr=arr[right];
			else sum +=  (mr - arr[right]);
			
			right--;
		}
		
	}
	return sum;
}

int main()
{
    int arr[] = {3,0,0,2,0,4}; //ans 10
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum water that can be accumulated is "<< a(n, arr);
}







/*
//two pointer approach TC=O(n) , sc=O(1)

int maxWater(int arr[], int n)
{
    int left = 0, right = n-1, l_max = 0, r_max = 0;

    int result = 0;
    while (left <= right)
    {
 
      if(r_max <= l_max)
      {
        result += max(0, r_max-arr[right]);
        r_max = max(r_max, arr[right]);
        right -= 1;
      }
      else
      { 
        result += max(0, l_max-arr[left]);
        l_max = max(l_max, arr[left]);
        left += 1;
      }
    }
    return result;
}

*/








/*
//precomputation or hashing-> TC=O(N) and SC=O(N)

int findWater(int arr[], int n)
{
    int left[n], right[n], water = 0;

    left[0] = arr[0];
    right[n - 1] = arr[n - 1];

    for (int i = 1; i < n; i++)
        left[i] = max(left[i - 1], arr[i]);

    for (int i = n - 2; i >= 0; i--)
        right[i] = max(right[i + 1], arr[i]);

    for (int i = 0; i < n; i++)
        water += min(left[i], right[i]) - arr[i];
        
    return water;
}

*/






// approach 1 : Two for loops
//TC: O(n^2), SC: O(1)

/*
int maxWater(int arr[], int n)
{

    int res = 0;

    for (int i = 1; i < n - 1; i++)
    {

        int left = arr[i];
        for (int j = 0; j < i; j++)
            left = max(left, arr[j]);

        int right = arr[i];
        for (int j = i + 1; j < n; j++)
            right = max(right, arr[j]);

        res = res + (min(left, right) - arr[i]);
    }

    return res;
}

int main()
{
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << maxWater(arr, n);

    return 0;
}
*/

