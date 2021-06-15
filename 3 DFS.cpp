#include<bits/stdc++.h>
using namespace std;


class Solution {
    void dfs(int node, vector<int> &vis, vector<int> adj[], vector<int> &Dfs) {
        Dfs.push_back(node); 
        vis[node] = 1; 
        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs(it, vis, adj, Dfs); 
            }
        }
    }
public:
	vector<int>dfsOfGraph(int V, vector<int> adj[]){
	    vector<int> Dfs; 
	    vector<int> vis(V, 0); 
      for(int i = 1;i<=V;i++) {
        if(!vis[i]) dfs(i, vis, adj, Dfs); 
      }
	    return Dfs; 
	}
};

// { Driver Code Starts.
int main(){
	
		int V, E;
    	cin >> V >> E;

    	vector<int> adj[V+1];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
 Solution obj;
        vector<int>ans=obj.dfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	
	return 0;
}
/*
4 6
0 1
0 2
1 2
2 0
2 3
3 3



8
7
1 3
3 4
2 3
5 6
5 8
6 7
7 8
*/
