#include<bits/stdc++.h>
using namespace std;


int median(vector<vector<int>> &a, int r, int c){

        int mn=a[0][0],mx=a[0][c-1];
        for(int i=1;i<r;i++)
        {
            mn=min(mn,a[i][0]);
            mx=max(mx,a[i][c-1]);
        }
        //cout<<"min"<<mn<<"  max"<<mx<<"\t";
        int des=(r*c+1)/2;
        //cout<<"des  "<<des<<endl;
     while(mn<mx)
        {
            int place=0;
            int mid=(mx+mn)/2;//int mid=mn+(mx-mn)/2;
            //cout<<"mid  "<<mid<<"\t";
            for(int i=0;i<r;i++){
            place+=upper_bound(a[i].begin(),a[i].end(),mid)-a[i].begin();
                }
            //cout<<"place  "<<place<<"\t";
            if(place<des)
            mn=mid+1;
            else
            mx=mid;
            //cout<<"min"<<mn<<"  max"<<mx<<endl;
		
           
        }
        return mn;
    }
     

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        cout<<median(matrix, r, c)<<endl;        
    }
    return 0;
}





/*

       

























int a[1000][1000];
int n,m;
int findMedian()
{
    int min = INT_MAX, max = INT_MIN;
    for (int i=0; i<n; i++)
    {
        if (a[i][0] < min)
            min = a[i][0];
        if (a[i][m-1] > max)
            max = a[i][m-1];
    }
 
    int desired = (n * m + 1) / 2;
    while (min < max)
    {
        int mid = min + (max - min) / 2;
        int place = 0;
        for (int i = 0; i < n; ++i)
            place += upper_bound(a[i], a[i]+m, mid) - a[i];
        if (place < desired)
            min = mid + 1;
        else
            max = mid;
    }
    return min;
}
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         cin>>n>>m;
         for(int i=0;i<n;i++)
         for(int j=0;j<m;j++)
         cin>>a[i][j];
         int ans=findMedian();
         cout<<ans<<"\n";
     }
	//code
	return 0;
}
*/
