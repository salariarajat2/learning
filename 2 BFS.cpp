#include<bits/stdc++.h>
using namespace std;

void bfsOfGraph(int V, vector<int> adj[]){
	    vector<int> bfs; 
	    vector<int> vis(V+1, 0); 
	    queue<int> q; 
	    q.push(0); 
	    vis[0] = 1; 
	    while(!q.empty()) {
	        int node = q.front();
	        q.pop(); 
	        bfs.push_back(node); 
	        
	        for(auto it : adj[node]) {
	            if(!vis[it]) {
	                q.push(it); 
	                vis[it] = 1; 
	            }
	        }
	    }
	    for(int i=0;i<bfs.size();i++){
        	cout<<bfs[i]<<" ";
        }
	   
	}
		
	
int main(){
	
		int V, E;
    	cin >> V >> E;

    	vector<int> adj[V+1];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
        	adj[v].push_back(u); // uncomment this for undirected graoh 
    }
        // string s1;
        // cin>>s1;
       bfsOfGraph(V, adj);
    
    	return 0;
}  // } Driver Code Ends

/*
3
8 10
0 1
0 2
0 3
0 4
1 5
2 5
3 6
4 6
5 7
6 7

Output:
0 1 2 3 4 5 6 7

*/
