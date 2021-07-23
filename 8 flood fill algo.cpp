#include <bits/stdc++.h>
using namespace std;

//Time Complexity: O(x * y), Space Complexity: O(x * y) //x =no. of rows , y= no. of column

void solve(int i, int j, vector<vector<int>> &vis, vector<vector<int>> &image, int newColor, int x, int y, int oldclr)
{
    if (i >= x or i < 0 or j < 0 or j >= y)
        return;
    if (vis[i][j] == 1 or image[i][j] != oldclr)
        return;

    vis[i][j] = 1;
    image[i][j] = newColor;

    solve(i + 1, j, vis, image, newColor, x, y, oldclr);
    solve(i - 1, j, vis, image, newColor, x, y, oldclr);
    solve(i, j + 1, vis, image, newColor, x, y, oldclr);
    solve(i, j - 1, vis, image, newColor, x, y, oldclr);
}

vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
{
    int x = image.size();
    int y = image[0].size();
    vector<vector<int>> vis(x, vector<int>(y, 0));
    int oldclr = image[sr][sc];
    solve(sr, sc, vis, image, newColor, x, y, oldclr);
    return image;
}
int main()
{
    vector<vector<int>> screen = {
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 0, 0},
        {1, 0, 0, 1, 1, 0, 1, 1},
        {1, 2, 2, 2, 2, 0, 1, 0},
        {1, 1, 1, 2, 2, 0, 1, 0},
        {1, 1, 1, 2, 2, 2, 2, 0},
        {1, 1, 1, 1, 1, 2, 1, 1},
        {1, 1, 1, 1, 1, 2, 2, 1},
    };
    int x = 4, y = 4, newC = 3;
    floodFill(screen, x, y, newC);

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
            cout << screen[i][j] << " ";
        cout << endl;
    }
}
