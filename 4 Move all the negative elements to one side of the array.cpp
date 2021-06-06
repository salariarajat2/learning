#include <bits/stdc++.h>
using namespace std;
//TC = O(n)

int main() {
	int t;
	cin >>t;
	for(int z=0;z<t;z++)
	{
	    int n;
	    cin >>n;
	    int arr[n];
	    int c1=0,c2=0,c3=0;
	    for(int i=0;i<n;i++)
	    {
	        cin >> arr[i];
	        if(arr[i]==0)
	            c1++;
	       else if(arr[i]==1)
	            c2++;
	            else
	                c3++;
	    }
	    while(c1--)
	        {cout << 0 << " ";}
	    while(c2--)
	        {cout << 1 << " ";}
	   while(c3--)
	        {cout << 2 << " ";}
	        cout << endl;
	   
	    
	}
	return 0;
}
/*
5
5
0 2 1 2 0
0 0 1 2 2
3
0 0 1
0 0 1
9
1 2 0 0 0 2 1 2 1 
0 0 0 1 1 1 2 2 2
*/

/*
#include <bits/stdc++.h>
using namespace std;
 
void sort012(int a[], int arr_size)
{
    int lo = 0;
    int hi = arr_size - 1;
    int mid = 0;

    while (mid <= hi) {
        switch (a[mid]) {
 
        case 0:
            swap(a[lo++], a[mid++]);
            break;
 
        case 1:
            mid++;
            break;
 
        case 2:
            swap(a[mid], a[hi--]);
            break;
        }
    }
}
 
void printArray(int arr[], int arr_size)
{
    for (int i = 0; i < arr_size; i++)
        cout << arr[i] << " ";
}
int main()
{
    int arr[] = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
 
    sort012(arr, n);
 
    cout << "array after segregation ";
 
    printArray(arr, n);
 
    return 0;
}*/
