//TOPOLOGICAL SORT - DFS

#include<bits/stdc++.h>
using namespace std;

void findTopoSort(int node, stack<int> &st, vector<int> &vis, vector<int> adj[])
{
	for(auto it: adj[node])
	{
		if(!vis[it])
		{
			findTopoSort(it,st,vis,adj);
		}
	}
	st.push(node);
}
vector<int> topo_sort(int n, vector<int> adj[])
{
	stack<int> st;
	vector<int> vis(n,0);
	for(int i=0;i<n;i++)
	{
		if(!vis[i]==0)
			findTopoSort(i,st,vis,adj);
	}
	vector<int> topo;
	while(!st.empty())
	{
		topo.push_back(st.top());
		st.pop();
	}
	return topo;
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
	vector<int> adj[n];
	vector<int> topo;
	for(int i=0;i<e;i++)
	{
		cin>>u>>v;
		adj[u].push_back(v);
		//adj[v].push_back(u);
	}
	
	topo=topo_sort(n,adj);
	for(auto it: topo)
		cout<<it<<" ";
	

}


