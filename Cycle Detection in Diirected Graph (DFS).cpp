//CHECK FOR CYCLE IN DIRECTED GRAPH - DFS
#include<bits/stdc++.h>
using namespace std;

bool cycle(int s, vector<int> adj[], vector<int> &vis[], vector<int> &dfs_vis)
{
	vis[s]=1;
	dfs_vis=1;
	for(auto it: adj[s])
	{
		if(vis[it]==0)
		{
			if(cycle(it,adj,vis,dfs_vis))
				return true;
		}
		else if(dfs_vis[it])
				return true;
	}
	dfs_vis[i]=0;
	return false;
}

bool check_cycle(vector<int> adj[], int n)
{

	vector<int> vis(n+1,0);
	vector<int> dfs_vis(n+1,0);
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			if(cycle(i,adj,vis,dfs_vis))
				return true;
		}
	}
	return false;
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
		//adj[v].push_back(u);
	}
	
	cout << check_cycle(adj,n);

}


