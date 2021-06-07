#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int k,n;
	    cin>>k>>n;
	    vector<int> v(n);
	    double sm = 0;
	    for(int i=0;i<n;i++){
	        cin>>v[i];
	        sm +=v[i];
	    }
	    sort(v.begin(),v.end());
        int ans = v[n-1] - v[0];
        int mn = v[0]+k;
        int mx = v[n-1]-k;
        if(mn>mx) swap(mn,mx);
	    for(int i=1;i<n-1;i++){
	       int add = v[i] +k;
	       int sub = v[i] -k;
	       if(sub >= mn || add<=mx)continue;
	       if (mx - sub <= add - mn) mn = sub; 
           else mx = add; 
	    }
	    ans = min(ans,mx-mn);
	    cout<<ans<<endl;
	}
	return 0;
}









/*
int main() {
	int t;
	cin>>t;
	while(t--){
	    int k,n;
	    cin>>k>>n;
	    vector<int>v(n);
	    for(int i=0;i<n;i++) cin>>v[i];
	    sort(v.begin(),v.end());
	    
	    int start = 0;
	    int end = n-1;
	    if(k>=v[end]-v[start]){
	        cout<<v[end]-v[start]<<endl;
	        continue;
	    }
	    int ans = INT_MAX;
	    int mn = v[start]+k;
	    int mx = v[end]-k;
	    if(mn>mx) swap(mn,mx);
	    ans = min(ans,mx-mn); 
	    start++;end--;
	    while(start<=end){
           int add = v[start]+k;
           int sub = v[start]-k;
           if(sub>=mn || add<=mx){start++; continue;}
           int diff1 = abs(mn-sub);
           int diff2 = abs(mx-add);
           if(diff1 < diff2) mn = sub;
           else mx = add;
           start++;
	    }
	    ans = mx-mn;
	    cout<<ans<<endl;
	}
	return 0;
}






int mindif(int *a,int n,int k)
{
    int b=a[n-1]-a[0];
    if(b<k)
    {
        return b;
    }
    else
    {
        a[0]=a[0]+k;
        a[n-1]=a[n-1]-k;
        for(int i=1;i<n-1;i++)
        {
            if(a[i]+k<=a[n-1])
            {
                a[i]+=k;
            }
            else if(a[i]-k>=a[0])
            {
                a[i]-=k;
            }
            else 
            {
                if(abs(a[0]-(a[i]-k))<=abs(a[n-1]-(a[i]+k)))
                a[i]-=k;
                else 
                a[i]+=k;
            }
        }
        int mn=INT_MAX;int mx=INT_MIN;
        for(int i=0;i<n;i++)
        {
            mn=min(a[i],mn);
            mx=max(a[i],mx);
        }
        return mx-mn;
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>k>>n;
        int *a=new int[n];
        for(int i=0;i<n;i++)
        cin>>a[i];
        sort(a,a+n);
        int ans=mindif(a,n,k);
        cout<<ans<<"\n";
    }
	//code
	return 0;
}

*/
