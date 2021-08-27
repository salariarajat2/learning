#include <bits/stdc++.h>
using namespace std;
#define V 4

int travllingSalesmanProblem(int graph[][V], int s)
{
    vector<int> vertex;
    for (int i = 0; i < V; i++)
        if (i != s)
            vertex.push_back(i);

    int min_path = INT_MAX;
    do
    {
        int current_pathweight = 0;
        int k = s;
        for (int i = 0; i < vertex.size(); i++)
        {
            current_pathweight += graph[k][vertex[i]];
            k = vertex[i];
        }
        current_pathweight += graph[k][s];
        min_path = min(min_path, current_pathweight);

    } while (next_permutation(vertex.begin(), vertex.end()));

    return min_path;
}

int main()
{
    int graph[][V] = {{-1, 10, 15, 20},
                      {10, -1, 35, 25},
                      {15, 35, -1, 30},
                      {20, 25, 30, -1}};
    int s = 0;
    cout << travllingSalesmanProblem(graph, s) << endl;
    return 0;
}

/*
// backtracking 

void tsp(int graph[][V], vector<bool> &v, int currPos, int n, int count, int cost, int &ans)
{
    if (count == n && graph[currPos][0])
    {
        ans = min(ans, cost + graph[currPos][0]);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!v[i] && graph[currPos][i])
        {
            v[i] = true;
            tsp(graph, v, i, n, count + 1,cost + graph[currPos][i], ans);
            v[i] = false; //backtracking
        }
    }
};

int main()
{
    int n = 4;
    int graph[][V] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}};

    vector<bool> v(n, false);
    v[0] = true;
    int ans = INT_MAX;
    tsp(graph, v, 0, n, 1, 0, ans);
    cout << ans;

    return 0;
}
*/
/*

#include <bits/stdc++.h>
using namespace std;

void findMinRoute(vector<vector<int>> tsp)
{
    int sum = 0;
    int counter = 0;
    int j = 0, i = 0;
    int min = INT_MAX;
    map<int, int> visitedRouteList;
    visitedRouteList[0] = 1;
    int route[tsp.size()];

    while (i < tsp.size() && j < tsp[i].size())
    {
        if (counter >= tsp[i].size() - 1) // Corner of the Matrix
        {
            break;
        }

        if (j != i && (!visitedRouteList[j]))
        {
            if (tsp[i][j] < min)
            {
                min = tsp[i][j];
                route[counter] = j + 1;
            }
        }
        j++;

        if (j == tsp[i].size())
        {
            sum += min;
            min = INT_MAX;
            visitedRouteList[route[counter] - 1] = 1;
            j = 0;
            i = route[counter] - 1;
            counter++;
        }
    }

    i = route[counter - 1] - 1;

    for (j = 0; j < tsp.size(); j++)
    {

        if ((i != j) && tsp[i][j] < min)
        {
            min = tsp[i][j];
            route[counter] = j + 1;
        }
    }
    sum += min;
    cout << ("Minimum Cost is : ");
    cout << (sum);
}

int main()
{
    vector<vector<int>> tsp = {{-1, 10, 15, 20},
                               {10, -1, 35, 25},
                               {15, 35, -1, 30},
                               {20, 25, 30, -1}};

    findMinRoute(tsp);
}*/

/*
#include <bits/stdc++.h>
#define MAX_N 15
const int INF = 987654321;
using namespace std;

int ShortestTSP(vector<vector<int>> graph)
{
    int ans = INF;
    int n = graph.size();      //size of graph
    int dp[1 << MAX_N][MAX_N]; //dp[i][j]=min distance of path ending at city-j using only cities in bitmask of int
                               //bitmask of 7 represent set of cities {1,2,8} since binary(7)=1011
    memset(dp, INF, sizeof(dp));

    //base case
    for (int i = 0; i < n; i++)
        dp[1 << i][i] = 0;

    //dp
    for (int i = 0; i < mask; i++)
    {
        for (int last = 0; last < n; last++)
        { //we see all paths ending at city-last
            if (mask & (1 << last) == 0)
                continue; //present mask, doesn't has city-last
            for (int cur = 0; cur < n; cur++)
            {
                if (mask & (1 << cur) == 0)
                    continue;
                int prev_mask = mask ^ (1 << cur);
                dp[mask][cur] = min(dp[mask][cur], dp[prev_mask][last] + dist[last][cur]);
            }
        }
    }

    for (int i = 0; i < n; i++)
        ans = min(ans, dp[(1 << n) - 1][i]);

    return ans;
}

int main()
{
    return 0;
}
*/
