//Check for cycle in an Undirected Graph. - DFS
#include<bits/stdc++.h>
using namespace std;

bool isCycle(int s, int parent, vector<int> adj[], vector<int> &vis)
{
	vis[s]=1;
	for(auto it: adj[s]){
		if(vis[it]==0)
		{
			if(isCycle(it, s, adj, vis)) return True;
		}
		else if(it!=parent)
			return true;
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
		adj[v].push_back(u);
	}
	vector<int> vis(n+1,0);
	for(int i=1;i<=n;i++){
		if(vis[i]==0)
		{
			if (isCycle(i,-1,adj,vis))
				cnt++;
		}
	}
	if(cnt==0)
		cout<<"False";
	else
		cout<<"True";

}


