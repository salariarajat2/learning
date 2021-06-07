#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main()
 {
    ll t,n,m,k,i;
	cin>>t;
	while(t--)
	{
	    ll a,b,c;
	    cin>>a>>b>>c;
	    ll j[a],g[b],h[c];
	    map<int,int> mp;
	    for(i=0;i<a;i++)
	    {
	        cin>>j[i];
	        if(mp[j[i]]==0)
	        mp[j[i]]++;
	    }
	    
	    for(i=0;i<b;i++)
	    {
	        cin>>g[i]; 
	        if(mp[g[i]]==1)
	        mp[g[i]]++;
	    }
	    
	    for(i=0;i<c;i++)
	    {
	        cin>>h[i];
	        if(mp[h[i]]==2)
	        mp[h[i]]++;
	    }
	    int flag=0;
	    for(auto itr=mp.begin();itr!=mp.end();itr++)
	    {
	        if(itr->second==3)
	        {
	            flag=1;
	            cout<<itr->first<<" ";    
	        }
	        
	    }
	    if(flag==0)
	    cout<<-1;
	    cout<<endl;
	    
	    
	}
	return 0;
}

/*
2
8 5 8
1 5 10 10 10 20 40 80
6 7 20 80 100
3 4 15 20 30 70 80 120



*/

/*
using vectors


int main(){
    int t;
    cin >> t;
    while(t--)
    {
        int n1,n2,n3,flag = 0;
        cin >> n1 >> n2 >> n3;
        vector<int> A;
        vector<int> B;
        vector<int> C;
        vector<int> D;
        for(int i = 0; i<n1; i++)
        {
            int x;
            cin >> x;
            A.push_back(x);
        }
        for(int i = 0; i<n2; i++)
        {
            int x;
            cin >> x;
            B.push_back(x);
        }
        for(int i = 0; i<n3; i++)
        {
            int x;
            cin >> x;
            C.push_back(x);
        }
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        sort(C.begin(),C.end());
        for(int i = 0,j=0,k=0;i<n1&&j<n2&&k<n3;)
        {
            if(A[i] == B[j] && B[j] == C[k])
            {
                D.push_back(A[i]);
                i++;
                j++;
                k++;
            }
            else if(A[i] <= B[j] && A[i] <= C[k])
                i++;
            else if(B[j] <= A[i] && B[j] <= C[k]) 
                j++;
            else if(C[k] <= B[j] && C[k] <= A[i])
                k++;
        }
        if(!D.empty())
        {
            for(int l : D)
                cout << l << " ";
            cout << endl;    
        }
        else 
        cout << "-1" << endl;
    }
	return 0;
}
*/








