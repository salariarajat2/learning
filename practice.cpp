#include<bits/stdc++.h>
using namespace std;

vector<int> func(int V,vector<int> adj[])
{
	queue<int> q;
	vector<int> indegree(V,0);
	for(int i=0;i<V;i++)
	{
		for(auto it: adj[i])
		{
			indegree[it]++;
		}
	}
	for(int i=0;i<V;i++){
		if(indegree[i]==0)
		{
			q.push(i);
		}
	}
	vector<int> topo;
	for(int i=0;i<V;i++)
	{
		int node=q.front();
		topo.emplace_back(node);
		q.pop();
		for(auto it: adj[node])
		{
			indegree[it]--;
			if(indegree[it]==0)
			{
				q.push(it);
			}
			
		}
		
	}
return topo;	
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}
        vector <int> res = func(V, adj);
       
        	for(int i=0;i<res.size();i++) cout<<res[i]<<"  ";
    }

    return 0;
}

/*
int main()
{

	int t;
	cin>>t;
	while(t--)
	{
	int n,k;
	cin>>n>>k;
	set<int> m;
   for(int i=0;i<n;i++)
	{
		int s;
		cin>>s;
	    m.insert(s);
	
	}
	for(auto a: m)
	{
		cout<<a<<" ";
	}
	cout<<endl;

	int sum=0;
	set<int> ::iterator it =m.begin();
        for(int i=0;i<k;i++)
        {
        	 sum=sum+(*it);
        	 it++;
		}
        
	
cout<<sum;
		
	}
	
	return 0;
}
5 
10 3
5 5 4 4 3 3 2 1 0 2 
*/

