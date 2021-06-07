//Check for cycle in an Undirected Graph.
#include<bits/stdc++.h>
using namespace std;

bool isCycle(int s, int n, vector<int> adj[], vector<int> &vis)
{
	queue<pair<int,int>> q;
	q.push({s, -1});
	vis[s]=1;
	while(!q.empty()){
		int node = q.front().first;
		int parent = q.front().second;
		q.pop();
		for(auto it: adj[node])
		{
			if(!vis[it])
			{
				q.push({it, node});
				vis[it]=1;
			}
			else if(it!=parent)
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
		adj[v].push_back(u);
	}
	vector<int> vis(n+1,0);
	for(int i=1;i<=n;i++){
		if(vis[i]==0)
		{
			if (isCycle(i,n,adj,vis))
				cnt++;
		}
	}
	if(cnt==0)
		cout<<"False";
	else
		cout<<"True";

}
