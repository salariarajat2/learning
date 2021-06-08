#include <bits/stdc++.h>
using namespace std;

//TC O(n)

int kadane(int *arr,int n){
    
    int max_global,max_current;
    max_global=max_current=arr[0];
    
    for(int i=1; i<n; i++){
        
        max_current = max(arr[i], max_current+arr[i]);
        
        if(max_current>max_global){
            max_global = max_current;
        }
    }
    return max_global;
    
}

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
	    
	    cout<<kadane(arr,n)<<"\n";
	}
	return 0;
}





/*

 int s=a[0];
	    int cur=a[0];
	    
	    for(int i=1;i<n;i++)
	    {
	        if(cur+a[i]<a[i]) cur=a[i];
	        else
	        cur+=a[i];
	        s=max(s,cur);
	        // if(cur<0) cur=0;
	    }
	    cout<<s;




        int ma=INT_MIN;
	    int max_till_here=0;
	    for(int i=0;i<n;i++)
	    {
	        max_till_here=max_till_here+a[i];
	        
	        if(max_till_here>ma)   ma=max_till_here;
	        if(max_till_here<0)   max_till_here=0;
	    }
	    cout<<ma<<"\n";
	    
	    
	    
	    
	    
	     int n;
	    cin>>n;
	    vector<int> v(n);
	    for(int i=0;i<n;i++){
	        cin>>v[i];
	    }
	    int mxSofar = v[0];
	    int sm = 0;
	    for(int i=0;i<n;i++){
	        sm = sm + v[i];
	        if(sm>mxSofar){
	            mxSofar = sm;
	        }
	        if(sm < 0){
	            sm = 0;
	        }
	    }
	    cout<<mxSofar<<endl;
	    */




















