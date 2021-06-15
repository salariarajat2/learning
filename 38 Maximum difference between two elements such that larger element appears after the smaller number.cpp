#include <bits/stdc++.h>
using namespace std;

// Time Complexity : O(n) 
//Auxiliary Space : O(1)

int maxDiff(int arr[], int arr_size)
{
     int max_diff = arr[1] - arr[0];
     int min_element = arr[0];
     for(int i = 1; i < arr_size; i++)
     {    
       if (arr[i] - min_element > max_diff)                            
       max_diff = arr[i] - min_element;
        
       if (arr[i] < min_element)
       min_element = arr[i];                    
     }
      
     return max_diff;
}
 
int main()
{
  int arr[] = {1, 2, 90, 10, 110};
  int n = sizeof(arr) / sizeof(arr[0]);
   
  // Function calling
  cout << "Maximum difference is " << maxDiff(arr, n);
 
  return 0;
}


/*

 
 The function assumes that there are
   at least two elements in array. The
   function returns a negative value if the
   array is sorted in decreasing order and 
   returns 0 if elements are equal 
   
int maxDiff (int arr[], int n)
{
    // Initialize diff, current sum and max sum
    int diff = arr[1]-arr[0];
    int curr_sum = diff;
    int max_sum = curr_sum;
 
    for(int i=1; i<n-1; i++)
    {
        // Calculate current diff
        diff = arr[i+1]-arr[i];
 
        // Calculate current sum
        if (curr_sum > 0)
        curr_sum += diff;
        else
        curr_sum = diff;
 
        // Update max sum, if needed
        if (curr_sum > max_sum)
        max_sum = curr_sum;
    }
 
    return max_sum;
}
int main()
{
  int arr[] = {80, 2, 6, 3, 100};
  int n = sizeof(arr) / sizeof(arr[0]);
   
  // Function calling
  cout << "Maximum difference is " << maxDiff(arr, n);
 
  return 0;
}












Time Complexity : O(n^2) 
Auxiliary Space : O(1)

int maxDiff(int arr[], int arr_size)
{    
  int max_diff = arr[1] - arr[0];
  for (int i = 0; i < arr_size; i++)
  {
    for (int j = i+1; j < arr_size; j++)
    {    
      if (arr[j] - arr[i] > max_diff)
        max_diff = arr[j] - arr[i];
    }
  }        
  return max_diff;
}
int main()
{
  int arr[] = {1, 2, 90, 10, 110};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << "Maximum difference is " << maxDiff(arr, n);
 
  return 0;
}



*/



