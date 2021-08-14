
#include <bits/stdc++.h>
using namespace std;
 
#define N 4
 
void print(int arr[N][N])
{
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
            cout << arr[i][j] << " ";
             
        cout << '\n';
    }
}
 
void rotate(int arr[N][N])
{
     
    // First rotation
    // with respect to main diagonal
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < i; ++j)
        {
            swap(arr[i][j],arr[j][i]);
            //make
            /*2
              3  7
              4  8  12*/
        }
    }

   
    // Second rotation
    // with respect to middle column
    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N / 2; ++j)
        {
           swap(arr[i][j],arr[i][N - j- 1]);
        }
    }
      
}
 
// Driver code
int main()
{
    int arr[N][N] = { { 1, 2, 3, 4 },
                      { 5, 6, 7, 8 },
                      { 9, 10, 11, 12 },
                      { 13, 14, 15, 16 } };
    
	//int t;
	//cin>>t;
	//while(t--) 
	rotate(arr);
    print(arr);
    return 0;
}
/*

#include <bits/stdc++.h>
using namespace std;
 
#define N 4

void rotate90Clockwise(int arr[N][N])
{
    for (int j = 0; j < N; j++)
    {
        for (int i = N - 1; i >= 0; i--)
            cout << arr[i][j] << " ";
        cout << '\n';
    }
}

int main()
{
    int arr[N][N] = { { 1, 2, 3, 4 },
                      { 5, 6, 7, 8 },
                      { 9, 10, 11, 12 },
                      { 13, 14, 15, 16 } };
    rotate90Clockwise(arr);
    return 0;
}*/
