#include <bits/stdc++.h>
using namespace std;

int merge(int arr[], int temp[], int left, int mid, int right)
{
	int i, j, k;
	int inv_count = 0;

	i = left; /* i is index for left subarray*/
	j = mid;  /* j is index for right subarray*/
	k = left; /* k is index for resultant merged subarray*/
	while ((i <= mid - 1) && (j <= right))
	{
		if (arr[i] <= arr[j])
		{
			temp[k++] = arr[i++];
		}
		else
		{
			temp[k++] = arr[j++];
			inv_count = inv_count + (mid - i);
		}
	}

	while (i <= mid - 1)
		temp[k++] = arr[i++];
	while (j <= right)
		temp[k++] = arr[j++];
	for (i = left; i <= right; i++)
		arr[i] = temp[i];

	return inv_count;
}

int _mergeSort(int arr[], int temp[], int left, int right)
{
	int mid, inv_count = 0;
	if (right > left)
	{
		mid = (right + left) / 2;
		inv_count += _mergeSort(arr, temp, left, mid);
		inv_count += _mergeSort(arr, temp, mid + 1, right);
		inv_count += merge(arr, temp, left, mid + 1, right);
	}
	return inv_count;
}

int mergeSort(int arr[], int array_size)
{
	int temp[array_size];
	return _mergeSort(arr, temp, 0, array_size - 1);
}

int main()
{
	
		int N;
		cin >> N;
		int arr[N];
		for (int j = 0L; j < N; j++)
		{
			cin >> arr[j];
		}
	   cout<<	mergeSort(arr, N);
	
	return 0;
}

/*
5
5
1 20 6 4 5 
ans 5
*/




/*using stl


int getInvCount(int arr[],int n)
{
    multiset<int> set1;
    set1.insert(arr[0]);
  
    int invcount = 0; // Initialize result
  
    multiset<int>::iterator itset1;
  
    for (int i=1; i<n; i++)
    {
       
        set1.insert(arr[i]);
  
        itset1 = set1.upper_bound(arr[i]);
  
        cout<<distance(itset1, set1.end())<<endl;
        invcount += distance(itset1, set1.end());
    }
  
    return invcount;
}
*/




/*
 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    void convertt(long long arr[], long long n){
        long long i, temp[n];
        
        for(i=0;i<n;i++){
            temp[i]=arr[i];
        }
        
        sort(temp, temp+n);
        
        for(i=0;i<n;i++){
            arr[i]=lower_bound(temp, temp+n, arr[i]) - temp + 1 ;
        }
    }
    
    long long getSum(long long BIT[], long long idx){
        long long sum=0;
        while(idx > 0){
            sum+=BIT[idx];
            idx-=idx&-idx;
        }
        return sum;
    }
    
    void updateBIT(long long BIT[], long long n, long long idx, long long value){
        while(idx <= n){
            BIT[idx]+=value;
            idx+=idx&-idx;
        }
    }
    
    long long int inversionCount(long long arr[], long long n)
    {
        long long i,count=0;
        convertt(arr, n);
        long long BIT[n+1]={0};
        for(i=n-1;i>=0;i--){
            count+=getSum(BIT, arr[i]-1);
            updateBIT(BIT, n, arr[i], 1);
        }
        return count;
}
};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
*/

