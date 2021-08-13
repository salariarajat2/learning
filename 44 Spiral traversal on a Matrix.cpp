#include<bits/stdc++.h>
using namespace std;


void print(int arr[R][C], int i, int j, int m, int n)
{
    // If i or j lies outside the matrix
    if (i >= m or j >= n)
        return;

    // Print First Row
    for (int p = j; p < n; p++)
        cout << arr[i][p] << " ";

    // Print Last Column
    for (int p = i + 1; p < m; p++)
        cout << arr[p][n - 1] << " ";

    // Print Last Row, if Last and
    // First Row are not same
    if ((m - 1) != i)
        for (int p = n - 2; p >= j; p--)
            cout << arr[m - 1][p] << " ";

    // Print First Column,  if Last and
    // First Column are not same
    if ((n - 1) != j)
        for (int p = m - 2; p > i; p--)
            cout << arr[p][j] << " ";

    print(arr, i + 1, j + 1, m - 1, n - 1);
}

// Driver Code
int main()
{

    int a[R][C] = { { 1, 2, 3, 4 },
                    { 5, 6, 7, 8 },
                    { 9, 10, 11, 12 },
                    { 13, 14, 15, 16 } };

    // Function Call
    print(a, 0, 0, 4, 4);
    return 0;
}



/*


void print(vector<vector<int>> &A)
{
    int n=4;
    int k=0,l=n-1,m=0,z=n-1;
    while(k<l && m<z)
    {
        for(int i = m;i<=z;i++)
            cout << A[k][i] << " ";
        k++;
        for(int i=k;i<=l;i++)
            cout << A[i][z] <<  " ";
        z--;
        if(k<=l){
        for(int i=z;i>=m;i--)
            cout << A[l][i] << " ";
        l--;}
        if(m<=z){
        for(int i=l;i>=k;i--)
            cout << A[i][m] << " ";
        m++;}
    }
    cout << endl;
}

int main() {
    
    int t;
    cin >> t;
    while(t--)
    {
        vector<vector<int>> A(4, vector<int>(4));
        for(int i = 0;i<4;i++)
        {
            for(int j = 0;j<4;j++)
            {
                cin >> A[i][j]; 
            }
        }
        
        print(A);
    }
	return 0;
}

*/


/*


int main()
{
    long long t,n,i,j,k,l,m;
    cin>>t;
    while(t--)
    {
       cin>>m>>n;
       long long a[m][n];
       for(i=0;i<m;i++)
       {
           for(j=0;j<n;j++)
           {
               cin>>a[i][j];
           }
       }
       k=0,l=0;
       while(k<m && l<n)
       {
           for(i=l;i<n;i++)
           {
               cout<<a[k][i]<<" ";
           }
           k++;
           for(i=k;i<m;i++)
           {
               cout<<a[i][n-1]<<" ";
           }
           n--;
           if(k<m)
           {
               for(i=n-1;i>=l;i--)
               {
                   cout<<a[m-1][i]<<" ";
               }
               m--;
           }
           if(l<n)
           {
                for(i=m-1;i>=k;i--)
               {
                   cout<<a[i][l]<<" ";
               }
               l++;
           }
       }
       cout<<"\n";
    }
}





*/













