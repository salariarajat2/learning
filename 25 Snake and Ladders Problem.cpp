#include <bits/stdc++.h>
using namespace std;

//Time Complexity: O(N), Space Complexity: O(N)

struct node
{
    int v;    // Vertex number
    int dist; // Distance of this vertex from source
};

int getMinDiceThrows(vector<int> move, int N)
{
    vector<bool> visited(N, false);
    queue<node> q;
    visited[0] = true;
    node s = {0, 0};
    q.push(s);

    node qe;
    while (!q.empty())
    {
        qe = q.front();
        int v = qe.v;

        if (v == N - 1)
            break;

        q.pop();
        for (int j = v + 1; j <= (v + 6) && j < N; ++j)
        {
            if (!visited[j])
            {
                node a;
                a.dist = (qe.dist + 1);
                visited[j] = true;
                if (move[j] != -1)
                    a.v = move[j];
                else
                    a.v = j;
                q.push(a);
            }
        }
    }
    return qe.dist;
}

int main()
{
    int N = 30;
    vector<int> moves(N, -1);

    moves[2] = 21;
    moves[4] = 7;
    moves[10] = 25;
    moves[19] = 28;

    moves[26] = 0;
    moves[20] = 8;
    moves[16] = 3;
    moves[18] = 6;

    cout << "Min Dice throws required is " << getMinDiceThrows(moves, N);
    return 0;
}

/*#include <bits/stdc++.h>
using namespace std;

int snakesAndLadders(int board[][6])
{
    int n = 6;
    int steps = 0;
    queue<int> q;
    bool visited[n][n];
    q.push(1);
    visited[n - 1][0] = true;
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            int x = q.front();
            q.pop();
            if (x == n * n)
                return steps;
            for (int k = 1; k <= 6; k++)
            {
                if (k + x > n * n)
                    break;

                int r = n - ((k + x) - 1) / n - 1;
                int c = ((k + x) - 1) % n;
                if (r % 2 == n % 2)
                {
                    c = n - 1 - c;
                }
                if (visited[r][c] == true)
                    continue;
                visited[r][c] = true;
                if (board[r][c] == -1)
                {
                    q.push(k + x);
                }
                else
                {
                    q.push(board[r][c]);
                }
            }
        }

        steps++;
    }
    return steps;
}

int main()
{
    int board[6][6] = {{-1, -1, -1, -1, -1, -1},
                       {-1, -1, -1, -1, -1, -1},
                       {-1, -1, -1, -1, -1, -1},
                       {-1, 35, -1, -1, 13, -1},
                       {-1, -1, -1, -1, -1, -1},
                       {-1, 15, -1, -1, -1, -1}};

    cout << snakesAndLadders(board);
}
*/
/*
5 6
0 1
1 3
2 3
0 2
2 4
1 4

5 7
0 1
1 3
2 3
0 2
2 4
1 4
0 4
*/
