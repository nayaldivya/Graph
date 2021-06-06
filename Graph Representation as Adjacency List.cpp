//Graph Representation as Adjacency List

#include<bits/stdc++.h>
using namespace std;

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
	for(int i=1;i<n+1;i++)
	{
		cout<< i <<"-\t";
		for(auto it:adj[i])
			cout<<it<<" ";
		cout<<endl;
	}
}


