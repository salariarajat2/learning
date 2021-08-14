#include<bits/stdc++.h>
using namespace std;

int findMaxValue(vector<vector<int>> mat, int n) {
    int maxVal = INT_MIN;

    vector<vector<int>> dp(n, vector<int>(n));

    dp[0][0] = mat[0][0];

    for (int i =1;i<n; i++) {
        dp[i][0] = min(dp[i - 1][0], mat[i][0]);
    }
    /*	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<dp[i][j]<<"   ";
		}
		cout<<endl;
	 } 
	 cout<<endl;*/

    for (int j = 1; j < n; j++) {
        dp[0][j] = min(dp[0][j - 1], mat[0][j]);
    }
    
    

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            maxVal = max(maxVal, mat[i][j] - dp[i - 1][j - 1]);
            dp[i][j] = min(mat[i][j], min(dp[i - 1][j], dp[i][j - 1]));
        }
    }
    
    return maxVal;

}

int main()
{

                
    vector<vector<int> > mat(5,vector<int>(5));
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			cin>>mat[i][j];
		}
	 } 
    cout << "Maximum Value is "<< findMaxValue(mat,5);
 
    return 0;
}
                
/*		
1 2 -1 -4 -20 
-8 -3 4 2 1 
3 8 6 1 3 
-4 -1 1 7 -6 
0 -4 10 -5 1 


    Time complexity: O(N^2)
    Space complexity: O(N^2)

    Where N is the number of rows (or columns) of the square matrix.
    
    
    
    
    
    
// A Naive method to find maximum value of mat[d][e]
// - ma[a][b] such that d > a and e > b
#include <bits/stdc++.h>
using namespace std;
#define N 5
 
// The function returns maximum value A(d,e) - A(a,b)
// over all choices of indexes such that both d > a
// and e > b.
int findMaxValue(int mat[][N])
{
    // stores maximum value
    int maxValue = INT_MIN;
 
    // Consider all possible pairs mat[a][b] and
    // mat[d][e]
    for (int a = 0; a < N - 1; a++)
    for (int b = 0; b < N - 1; b++)
        for (int d = a + 1; d < N; d++)
        for (int e = b + 1; e < N; e++)
            if (maxValue < (mat[d][e] - mat[a][b]))
                maxValue = mat[d][e] - mat[a][b];
 
    return maxValue;
}
 
// Driver program to test above function
int main()
{
int mat[N][N] = {
                { 1, 2, -1, -4, -20 },
                { -8, -3, 4, 2, 1 },
                { 3, 8, 6, 1, 3 },
                { -4, -1, 1, 7, -6 },
                { 0, -4, 10, -5, 1 }
            };
    cout << "Maximum Value is "
        << findMaxValue(mat);
 
    return 0;
}
 */
 

/*
#include <bits/stdc++.h>
#define R 4
#define C 4

int maxHist(int row[])
{
    stack<int> result;
 
    int top_val; // Top of stack
 
    int max_area = 0; // Initialize max area in current row (or histogram)
    int area = 0; // Initialize area with current top
    int i = 0;
    while (i < C) {
        if (result.empty() || row[result.top()] <= row[i])
            result.push(i++);
 
        else {
            top_val = row[result.top()];
            result.pop();
            area = top_val * i;
 
            if (!result.empty())
                area = top_val * (i - result.top() - 1);
            max_area = max(area, max_area);
        }
    }
    while (!result.empty()) {
        top_val = row[result.top()];
        result.pop();
        area = top_val * i;
        if (!result.empty())
            area = top_val * (i - result.top() - 1);
 
        max_area = max(area, max_area);
    }
    return max_area;
}
int maxRectangle(int A[][C])
{
    int result = maxHist(A[0]);
    for (int i = 1; i < R; i++) {
 
        for (int j = 0; j < C; j++)
            if (A[i][j])  A[i][j] += A[i - 1][j];
        result = max(result, maxHist(A[i]));
    }
 
    return result;
}
int main()
{
    int A[][C] = {
        { 0, 1, 1, 0 },
        { 1, 1, 1, 1 },
        { 1, 1, 1, 1 },
        { 1, 1, 0, 0 },
    };
 
    cout << "Area of maximum rectangle is "<< maxRectangle(A);
 
    return 0;
}*/
