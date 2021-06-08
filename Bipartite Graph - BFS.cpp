//CHECK FOR BIPARTITE GRAPH - BFS
#include<bits/stdc++.h>
using namespace std;

bool bipartite(int s, vector<int> adj[], int color[])
{
	queue<int> q;
	q.push(s);
	color[s]=1;
	while(!q.empty()){
		int node=q.front();
		q.pop();
		for(auto it: adj[node])
		{
			if(color[it]==-1){
				color[it]=1-color[node];
				q.push(it);
			}
			else if(color[it]==color[node])
				return false;
		}
	}
	return true;
}

bool check_bipartite(vector<int> adj[], int n)
{
	int color[n+1];
	memset(color,-1,sizeof color);

	for(int i=1;i<=n;i++)
	{
		if(color[i]==-1)
		{
			if(!bipartite(i,adj,color))
				return false;
		}
	}
	return true;
}

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	int n,e;
	int u,v;
	int cnt=0;
	cin>>n>>e;
	vector<int> adj[n+1];
	for(int i=0;i<e;i++)
	{
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	cout << check_bipartite(adj,n);

}


