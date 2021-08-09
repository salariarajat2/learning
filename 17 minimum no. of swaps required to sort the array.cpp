#include<bits/stdc++.h>
using namespace std;

//Time Complexity: O(nlogn), Space Complexity: O(n)

int aa(vector<int> &nums)
{
    int n = nums.size();
    vector<pair<int, int>> v(n);
    int cnt = 0;
    for (int i = 0; i < n; i++)
        v[i] = {nums[i], i};
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        if (v[i].second == i)
        {
            continue;
        }
        else
        {
            cnt++;
            swap(v[i], v[v[i].second]);
            i--;
        }
    }
    return cnt;
}

int main()
{

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << aa(a) << endl;
}





/*
int minSwaps(int a[], int n)
{
    int c = 0, i, t;
    int temp[n];
    for (i = 0; i < n; i++)
        temp[i] = a[i];
    sort(temp, temp + n);
    for (i = 0; i < n; i++)
    {
        a[i] = lower_bound(temp, temp + n, a[i]) - temp;
    }
    // for(i=0;i<n;i++)
    //     cout<<a[i]<<" ";
    for (i = 0; i < n - 1; i++)
    {

        while (i != a[i])
        {
            t = a[a[i]];
            a[a[i]] = a[i];
            a[i] = t;
            c += 1;
        }
    }
    return c;
}
*/


/*
int minSwaps(int a[], int n){

    int total=0;
    for(int i=0;i<n-1;i++)
    {
        int j,k;
        for(j=k=i;j<n;j++)
        {
            if(a[j]<a[k])
            {
                k=j;
            }
        }
         if(k!=i)
            {
                swap(a[i],a[k]);
                total++;
            }
    }
    return total;
} 
*/


/*void merge(int a[],int l,int mid,int h,int &c){
    int p=l,q=h;
    vector<int>vec;
    while(p<=mid && q<=h){
        if(a[p]>a[q]){
            c+=1;
            vec.push_back(a[p++]);
        }
        else{
            vec.push_back(a[q++]);
        }
    }
    while(p<=mid){
        vec.push_back(a[p++]);
    }
    while(q<=h){
        vec.push_back(a[q++]);
    }
    for(int i=h;i>=l;i--){
        a[i]=vec.back();
        vec.pop_back();
    }
}

void mergesort(int a[],int l,int h,int &c){
    if(l<h){
        int mid=(l+h)/2;
        mergesort(a,l,mid,c);
        mergesort(a,mid+1,h,c);
        merge(a,l,mid,h,c);
    }
}

int minSwaps(int a[], int N){
    int c=0,i,j,pos,t;
    // mergesort(A,0,N-1,c);
    for(i=0;i<N-1;i++){
        pos=i;
        for(j=i+1;j<N;j++){
            if(a[pos]>a[j]){
                pos=j;
            }
            
        }
        t=a[i];
        a[i]=a[pos];
        a[pos]=t;
        if(pos!=i)  
            c++;
    }
    return c;
}*/
