#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int Vrtx; // No. of vertices

    list<pair<int, int>> *adj;

public:
    Graph(int Vrtx) // Constructor function
    {
        this->Vrtx = Vrtx;
        adj = new list<pair<int, int>>[Vrtx];
    }

    void addEdges(int a, int b, int c) // Function that adds edge
    {
        adj[a].push_back(make_pair(b, c));
    }

    vector<int> shortestPath(int src) // Function to return shortest path
    {

        set<pair<int, int>> setds;

        vector<int> dist(Vrtx, INT_MAX); //Create vector and initialise as INT_MAXinite

        setds.insert(make_pair(0, src)); //Insert source
        dist[src] = 0;

        while (!setds.empty())
        {

            pair<int, int> tmp = *(setds.begin()); //Source vertex is min
            setds.erase(setds.begin());            //distance

            int a = tmp.second;

            // 'i' is used to get all adjacent vertices
            list<pair<int, int>>::iterator i;
            for (i = adj[a].begin(); i != adj[a].end(); ++i)
            {

                int b = (*i).first; // Get weight of current and adj vertex
                int weight = (*i).second;

                if (dist[b] > dist[a] + weight) //Check for shortest path
                {

                    if (dist[b] != INT_MAX)
                        setds.erase(setds.find(make_pair(dist[b], b)));

                    dist[b] = dist[a] + weight; // Updating distance
                    setds.insert(make_pair(dist[b], b));
                }
            }
        }
        return dist;
    }
};

//Function adds edge weight
Graph EdgeWeight(int edge[][2], int E, int Vrtx)
{
    Graph g(Vrtx);
    for (int i = 0; i < E; i++)
    {
        //  original edge - weight 0
        g.addEdges(edge[i][0], edge[i][1], 0);

        //  reverse edge - weight 1
        g.addEdges(edge[i][1], edge[i][0], 1);
    }
    return g;
}

int MinEdges(int edge[][2], int E, int Vrtx, int src, int dest)
{
    Graph g = EdgeWeight(edge, E, Vrtx); // Gives modified graph

    //  get shortes path vector
    vector<int> dist = g.shortestPath(src);

    if (dist[dest] == INT_MAX) // Not possible if INT_MAXinite
        return -1;
    else
        return dist[dest]; // min no of edges
}

int main() //Main Function
{
    int Vrtx = 7;
    int edge[][2] = {{0, 1}, {2, 1}, {2, 3}, {4, 1}, {5, 4}, {6, 5}, {6, 3}};
    int E = sizeof(edge) / sizeof(edge[0]);

    int minimum = MinEdges(edge, E, Vrtx, 0, 6);
    if (minimum != -1)
        cout << "Minimum number of edges to be reversed: " << minimum;
    else
        cout << "Not possible";
    return 0;
}
