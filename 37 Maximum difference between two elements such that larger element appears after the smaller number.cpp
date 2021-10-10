#include <bits/stdc++.h>
using namespace std;

// Time Complexity : O(n)
//Auxiliary Space : O(1)

int maxDiff(int arr[], int arr_size)
{
  int max_diff = arr[1] - arr[0];
  int min_element = arr[0];
  for (int i = 1; i < arr_size; i++)
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
  cout << "Maximum difference is " << maxDiff(arr, n);

  return 0;
}





/*
// Time Complexity : O(n ^ 2), Auxiliary Space : O(1)

int maxDiff(int arr[], int arr_size)
{
  int max_diff = arr[1] - arr[0];
  for (int i = 0; i < arr_size; i++)
  {
    for (int j = i + 1; j < arr_size; j++)
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
