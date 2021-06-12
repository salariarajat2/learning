#include <bits/stdc++.h>
using namespace std;


int findLongestConseqSubseq(int arr[], int N)
{
    priority_queue<int, vector<int>, greater<int> > pq;
    
    for (int i = 0; i < N; i++)   pq.push(arr[i]);    // adding element from array to PriorityQueue
    
    int prev = pq.top();
    pq.pop();
    int c = 1, max = 1;
    while (!pq.empty()) {
      
        if (pq.top() - prev > 1) {
          
            c = 1;          
            prev = pq.top();//  Update the previous position with the current peek And remove it
            pq.pop();
        }

        else if (pq.top() - prev == 0) {

            prev = pq.top();
            pq.pop();
        }
 
        else {
        	
            c++;
            prev = pq.top();
            pq.pop();
        }
 
        if (max < c) {
      
            max = c;
        }
    }
    return max;
}

int main()
{
    int arr[] = { 1, 9, 3, 10, 4, 20, 2 };
    int n = 7;

    cout << "Length of the Longest consecutive subsequence "
            "is "
         << findLongestConseqSubseq(arr, n);
    return 0;
}









/*

int longestConsecSubseq(int arr[],int n){
    
    set<int> s;
    int res = 1;
    for(int i=0; i<n; i++){
        s.insert(arr[i]);
	}
	
	for(int i=0; i<n; i++){
	    
	    if(s.find(arr[i]-1) == s.end()){
	        int c = 1;
	        while(s.find(arr[i]+c) != s.end()){
	            c++;
	        }
	        res = max(res,c);
	    }
	}
	return res;
}


//Check if this element is the starting point of a subsequence. To check this, simply look for arr[i] - 1 in the hash,
 if not found, then this is the first element a subsequence and the find() poinitng to the s.end(), hence the condition satisfied.
//If this element is the first element, then count the number of elements in the consecutive starting with this element. 
Iterate from arr[i] + 1 till the last element that can be found.
//If the count is more than the previous longest subsequence found, then update this.


int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0; i<n; i++){
	        cin>>arr[i];
	    }
	    
	    cout<<longestConsecSubseq(arr,n)<<"\n";
	}
	return 0;
}



int findLongestConseqSubseq(int arr[], int n)
{
    int ans = 0, count = 0;
    sort(arr, arr + n);

    vector<int> v;
    v.push_back(arr[0]);
    for (int i = 1; i < n; i++) 
    {
        if (arr[i] != arr[i - 1])
            v.push_back(arr[i]);
    }
    for (int i = 0; i < v.size(); i++) 
    {
        if (i > 0 && v[i] == v[i - 1] + 1)
            count++;
        
        else
            count = 1;

        ans = max(ans, count);
    }
    return ans;
}

int main()
{
    int arr[] = { 1, 2, 2, 3 };
    int n = sizeof arr / sizeof arr[0];
    cout << "Length of the Longest contiguous subsequence "
            "is "
         << findLongestConseqSubseq(arr, n);
    return 0;
}

*/
