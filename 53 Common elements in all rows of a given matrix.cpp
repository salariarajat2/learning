#include <bits/stdc++.h>
using namespace std;
#define M 4
#define N 5
 
void printCommonElements(int mat[M][N])
{
    unordered_map<int, int> mp;
 
    for (int j = 0; j < N; j++)
        mp[mat[0][j]] = 1; // initalize 1st row elements with value 1
 
 
	
    for (int i = 1; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
   
            if (mp[mat[i][j]] == i)  // If element is present in the map and is not duplicated in current row.
            {
                mp[mat[i][j]] = i + 1;    // we increment count of the element in map by 1
                
                if (i==M-1 && mp[mat[i][j]]==M) // If this is last row or        if(i==M-1)
                  cout << mat[i][j] << " ";
            }
        }
    }
     
}

int main()
{
    int mat[M][N] =
    {
        {1, 2, 1, 4, 8},
        {3, 7, 8, 5, 1},
        {8, 7, 7, 3, 1},
        {8, 1, 2, 7, 9},
    };
 
    printCommonElements(mat);
 
    return 0;
}
