#include<bits/stdc++.h>
using namespace std;
int main(){

#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
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
	vector<int> bfs;
	queue<int> q;
	for(int i=1;i<=n;i++){
		if(vis[i]==0)
		{
			//bfs
			vis[i]=1;
			q.push(i);
			while(!q.empty()){
				int node=q.front();
				bfs.push_back(node);
				q.pop();
				for(auto it: adj[node])
				{
					if(!vis[it]){
						vis[it]=1;
						q.push(it);
				}
				}
			}
		}
	}
	for(int i=0;i<bfs.size();i++)
		cout<<bfs[i]<<" ";

}


