#include<iostream>
#include<vector>
using namespace std;
//vector<vector<int>> g;
vector<int> g[10];
int n;
int color[10]={0};        // 0--> not visited, 1--> visited, 2--> already exited
int time_in[10], time_out[10];
int timer=0;
void dfs(int h)
{
	time_in[h]=timer++;
	color[h]=1;
	for(int i=0;i<g[h].size();i++)
	{
		if(color[g[h][i]]==0)
			dfs(g[h][i]);
	}
	color[h]=2;
	time_out[h]=timer++;
}
//To check if i is ancestor of j
bool isancestor(int i,int j)
{
	if(time_in[i]<time_in[j] && time_out[i]<time_out[j])
		return true;
	return false;
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
	int h; cin >> h;
	dfs(h);
	int a,b; cin >> a >> b;
	int ans= isancestor(a,b);
	if(ans)
		cout << "YES";
	else
		cout<< "NO";
	return 0;
}
