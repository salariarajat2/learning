#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m,source;
	cin >> n >> m;
	vector<pair<int,int> > adj[n+1]; 	// 1-indexed adjacency list for of graph

	int a,b,wt;
	for(int i = 0; i<m ; i++){
		cin >> a >> b >> wt;
		adj[a].push_back(make_pair(b,wt));//adj[a].push_back({b,wt});
		adj[b].push_back(make_pair(a,wt));//adj[b].push_back({a,wt});
	}	
	
	cin >> source;
	
	// Dijkstra's algorithm begins from here
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;// min-heap ; In pair => (dist,from)
	vector<int> distTo(n+1,INT_MAX); 	// 1-indexed array for calculating shortest paths; 
	
	distTo[source] = 0;
	pq.push(make_pair(0,source));	// (dist,from)
	
	while( !pq.empty() ){
		int dist = pq.top().first;
		int prev = pq.top().second;
		pq.pop();
		
		//vector<pair<int,int> >::iterator it;
		for(auto it:adj[prev])//for( it = adj[prev].begin() ; it != adj[prev].end() ; it++)
		{
			int next = it.first;//int next = it->first;
			int nextDist = it.second;//int nextDist = it->second;
			if( distTo[next] > distTo[prev] + nextDist){
				distTo[next] = distTo[prev] + nextDist;
				pq.push(make_pair(distTo[next], next));
			}
		}
		
	}
	
	cout << "The distances from source, " << source << ", are : \n";
	for(int i = 1 ; i<=n ; i++)	cout << distTo[i] << " ";
	cout << "\n";
	
	return 0;
}



/*
5 12
1 2 2
1 4 1
2 1 2
2 3 4
2 5 5
3 2 4
3 4 3
3 5 1
4 1 1
4 3 3
5 2 5
5 3 1
1


ans-  0 2 4 1 5
*/









