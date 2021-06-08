#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int size)
{
   for (int i = size-1; i>=0; i--)
   cout << arr[i] << " ";
 
   cout << endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6,7,8,9,10};
    int n=sizeof(arr)/sizeof(arr[0]);
    printArray(arr, n);
    return 0;
}
//TC = O(n);


/*
int rev(int arr[],int start,int end)
{
	if(start>=end)
	return 0;
	
	int temp=arr[start];
	arr[start]=arr[end];
	arr[end]= temp;
	
	rev(arr,start+1,end-1);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
     int n=sizeof(arr)/sizeof(arr[0]);
   // printArray(arr, 6);
    rev(arr,0,n-1);

     for(int i=0;i<n;i++)
     {
     	cout<<arr[i]<<" ";
	 }
    return 0;
}
*/
