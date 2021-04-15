//BFS
//queue, visited
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//vector<vector<int>> g;
vector<int> g[10];
bool vis[10]={false};
queue <int> q;
void bfs(int h){
	q.push(h);
	vis[h]=true;
	cout << h << " ";
	while(!q.empty()){
		int v=q.front();
		//cout << v <<" ###\t ";
		q.pop();
		for(int i=0;i<g[v].size();i++)
		{
			if(vis[g[v][i]] == false )
			{
				q.push(g[v][i]);
				vis[g[v][i]] = true;
				cout << g[v][i] <<" ";
			}	
		}
	}
}
int main()
{
	int n,e; cin >> n >> e;
	int u,v;
	//Creating the garph
	for(int i=1;i<=e;i++)
	{
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	//Displaying the list
	for(int i=1;i<=n;i++)
	{
		cout << i <<"\t";
		for(int j=0;j<g[i].size();j++)
			cout <<g[i][j] <<" ";
		cout <<"\n";
	}
	int h; cin >> h;
	bfs(h);
	return 0;
}

