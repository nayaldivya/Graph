#include<bits/stdc++.h>
using namespace std;

void findShortestDist(int s, int d, int n, vector<int> adj[])
{
	int dis[n];
	for(int i=0;i<n;i++)
	{
		dis[i]=INT_MAX;
	}
	queue<int> q;
	q.push(s);
	dis[s]=0;
	while(!q.empty())
	{
		int node=q.front();
		q.pop();
		for(auto it:adj[node])
		{
			if(dis[node]+1<dis[it])
			{	dis[it]=dis[node]+1;
				q.push(it);
			}
		}
	}
	cout << dis[d];
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
int n,e;
cin >> n >> e;
int u,v;
vector<int> adj[n];
for(int i=0;i<e;i++)
{
	cin >> u >> v;
	adj[u].push_back(v);
	adj[v].push_back(u);
}
int src,dest;
cin >> src >> dest;
findShortestDist(src,dest,n,adj);

}


