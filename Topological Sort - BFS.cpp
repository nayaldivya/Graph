//KAHN'S ALGORITHM 
#include<bits/stdc++.h>
using namespace std;

vector<int> topo_sort(int n, vector<int> adj[])
{
	vector<int> indegree(n,0);
	vector<int> topo;
	queue<int> q;
	for(int i=0; i<n ;i++)
	{
		for(auto it: adj[i])
			indegree[it]++;
	}
	for(int i=0;i<n;i++)
	{
		if(indegree[i]==0)
			q.push(i);
	}
	while(!q.empty())
	{
		int node=q.front();
		topo.push_back(node);
		q.pop();
		for(auto it: adj[node])
		{
			indegree[it]--;
			if(indegree[it]==0)
				q.push(it);
		}
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
	for(int i=0;i<n;i++)
		cout<< topo[i]<<" ";
	

}


