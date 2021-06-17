#include<bits/stdc++.h>
using namespace std;


void BFS(vector<int> adj[], int N, int src) 
{ 
//	int dist[N];
//	for(int i = 0;i<N;i++) dist[i] = INT_MAX; 
    vector<int> dist(N,INT_MAX);
	queue<int>  q;
	
	dist[src] = 0;
	q.push(src); 

	while(!q.empty()) 
	{ 
		int node = q.front(); 
		q.pop();
		 
		for(auto it:adj[node]){
		    if(dist[node] + 1 < dist[it]){
		        dist[it]=dist[node]+1;
		        q.push(it);
		    }
		} 
	} 
	for(int i = 0;i<N;i++) cout << dist[i] << " "; 
	
}

int main(){
	
		int V, E;
    	cin >> V >> E;

    	vector<int> adj[V+1];
int src; cout<<"enter the source "; cin>>src;
    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
        	adj[v].push_back(u); // uncomment this for undirected graoh 
    }
       
       BFS(adj,V,src);
    
    	return 0;
} 
/*
9 19
0
0 1
0 3
1 0
1 2
1 3
2 1
2 6
3 0
3 4
4 3
4 5
5 4
5 6
6 2
6 5 
6 8
7 6
7 8
8 6
8 7

ans-   0 1 2 1 2 3 3 4 4

*/







