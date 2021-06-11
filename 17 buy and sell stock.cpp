#include<bits/stdc++.h>
using namespace std;

int main()
 {
	
	int t;
	cin >> t;
	for(int q=0;q<t;q++)
	{
	    int n;
	    cin >> n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    {
	        cin >> arr[i];
	    }
	  
	  int flag=0;
	    int buy=0,sell=0,i=0;
	    while(i<n-1)
	    {
	        if(arr[i]<=arr[i+1] )
	            sell++;
	        else
	        {
	            if(sell-buy>0)
	            {
	                cout << "(" << buy << " " << sell << ") ";
	                flag=1;
	            }
	           buy=i+1;
	           sell=i+1;
	        }
	       i++;
	    }
	   if(sell-buy>0)
	   {
	        cout << "(" << buy << " " << sell << ") ";
	        flag=1;
	   }
	   if(flag==0)
	    cout << "No Profit";
	    cout << endl;
	}
	return 0;
}


/*




void get(int arr[],int n)
{
    int i=0,a=0,b=0;
    while(i<n-1)
    {
        while(i<n-1&& arr[i+1]<=arr[i])
        {
            i++;
        }
        if(i==n-1)
        break;
        a=i++;   cout<<a<<endl;
         while(i<n&& arr[i-1]<=arr[i])
        {
            i++;
        }
        b=i-1; cout<<b<<endl;
        cout<<"("<<a<<" "<<b<<")"<<" ";
    }
    if(a==0&&b==0)
    cout<<"No Profit";
}
int main()
 {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    get(a,n);
	    cout<<endl;
	}
	return 0;
}


/*

void maxProfit(vector<int>& arr) {
        
        int cprice=INT_MAX;
        int profit=0;
        int start,final;
        for(int i=0;i<arr.size();i++)
        {
            if(arr[i]<cprice)
            {
                cprice=arr[i];
                start=i+1;
            }
            else if(arr[i]-cprice>profit)
            {
                profit=arr[i]-cprice;
                final=i+1;
            }
        }
        
        cout<<"buy the stock on day  "<<start<<"  sell the stock on day  "<<final<<"  the maximum profit is  "<< profit<<endl;
        
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i=0; i<n; i++){
	        cin>>arr[i];
	    }
	    
	   
	    maxProfit(arr);
	}
	return 0;
}
/*
7
100 180 260 310 40 535 695


5
4 2 2 2 4
*/
