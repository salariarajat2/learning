#include <bits/stdc++.h>
using namespace std;

//for arrays fo arrays

int a(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int res = 0;

        int temp = arr[i];

        while (temp > 0)
        {
            int r = temp % 10;

            temp /= 10;

            res = (res * 10) + r;
        }
        if (res != arr[i])
            return 0;
    }
    return 1;
}

int main()
{
 
        int n;
        cin >> n;
        int i, arr[n];
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << a(arr, n);

}




//for single elements
/*
void palindrome(int arr[], int n)
{
	int flag = 0;
	for (int i = 0; i <= n / 2 && n != 0; i++) {

	
		if (arr[i] != arr[n - i - 1]) {
			flag = 1;
			break;
		}
	}

	if (flag == 1)
		cout << "Not Palindrome";
	else
		cout << "Palindrome";
}

int main()
{
	int arr[] = { 1, 2, 2, 1, 1 };
	int n = sizeof(arr) / sizeof(arr[0]);

	palindrome(arr, n);
	return 0;
}
*/






















/*

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> v(n);
	    for(int i=0;i<n;i++){
	        cin>>v[i];
	    }
	    int start = 0;
	    int end = n-1;
	    int cnt = 0;
	    while(start < end){
	        if(v[start] == v[end]){
                start++;
                end--;
	        }
	        if(v[start]>v[end]){
	            v[end-1] = v[end-1]+v[end];
	            end--;
	            cnt++;
	            continue;
	        }
	        else if(v[start]<v[end]){
	            v[start+1] = v[start+1]+v[start];
	            start++;
	            cnt++;
	            continue;
	        }
	    }
	    cout<<cnt<<endl;
	}
	return 0;
}
*/
