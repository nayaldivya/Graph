//Creating a graph and dfs traversal
#include<iostream>
#include<vector>
using namespace std;
//vector<vector<int>> g;
vector<int> g[10];
bool vis[10]={false};
void dfs(int h){
	vis[h]=true;
	cout << h <<" ";
	for(int i=0;i<g[h].size();i++)
	{
		if(vis[g[h][i]]==false)
			dfs(g[h][i]);
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
	dfs(h);
	return 0;
}
