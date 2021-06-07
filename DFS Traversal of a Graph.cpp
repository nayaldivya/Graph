#include<bits/stdc++.h>
using namespace std;
void dfs(int node, vector<int> &vis, vector<int> &storedfs, vector<int> adj[])
{
		storedfs.push_back(node);
		vis[node]=1;
		for(auto it:adj[node])
		{
			if(vis[it]==0)
				dfs(it, vis, storedfs, adj);
		}
}
int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	int n,e;
	int u,v;
	cin>>n>>e;
	vector<int> adj[n+1];
	for(int i=0;i<e;i++)
	{
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> vis(n+1,0);
	vector<int> storedfs;
	for(int i=1;i<=n;i++){
		if(vis[i]==0)
		{
			dfs(i,vis,storedfs,adj);
		}
	}
	for(int i=0;i<storedfs.size();i++)
		cout<<storedfs[i]<<" ";

}


