#include<bits/stdc++.h>
using namespace std;

bool func(int N, vector<int> adj[]) {
        queue<int> q; 
	    vector<int> indegree(N, 0); 
	    for(int i = 0;i<N;i++) {
	        for(auto it: adj[i]) {
	            indegree[it]++; 
	        }
	    }
	
  for(int i = 0;i<N;i++) {
	        if(indegree[i] == 0) {
	            q.push(i); 
	        }
	    }

int cnt=0;
	    while(!q.empty()) {
	        int node = q.front(); 
	        q.pop(); 
	        cnt++;
	        for(auto it : adj[node]) {
	            indegree[it]--;
	            if(indegree[it] == 0) {
	                q.push(it); 
	            }
	        }
	    }
	    if(cnt==N) return true;
	    else return false;
	}

int main()
{
		int V, E;
    	cin >> V >> E;
	vector<int> adj[V+1];
	for(int i=0 ; i<E ; i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
	}
    if(func(V+1, adj)) cout<<"No there is no cycle";
    else cout<<"yes there is a cycle";
    return 0;
}

/*
9 9
1 2
2 3
3 4
3 6
4 5
6 5
7 8
8 9
9 7
yes


9 9
1 2
2 3
3 4
3 6
4 5
6 5
7 8
7 9
8 9
no

*/

