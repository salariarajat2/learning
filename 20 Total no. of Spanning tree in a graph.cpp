#include <bits/stdc++.h>
using namespace std;

int Spanning(int vertices)
{
    int result = 0;

    result = vertices;
    return result;
}

int main()
{
    int vertices = 4;

    cout << "Spanning tree = " << Spanning(vertices);
    return 0;
}



//Total number of Spanning trees in a Cycle Graph   ->    the number of spanning treess will always be equal to the number
//  of vertices in a cycle graph.



//If a graph is a complete graph with n vertices, then total number of spanning trees is n^(n-2) where n is the number of nodes 
// in the graph. Cayley�s formula.


//The number of spanning trees for a complete weighted graph with n vertices is n^(n-2).
