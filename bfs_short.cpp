//BFS
//queue, visited
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
//#include<bits/stdc++.h>
using namespace std;
//vector<vector<int>> g;
int n;
vector<int> g[10];
bool vis[10]={false};
queue <int> q;
vector <int> d(10), p(10);   // p--> store parents, d--> store the path length 
void bfs(int h){
	cout << " BFS TRAVERSAL : ";
	q.push(h);
	vis[h]=true;
	cout << h <<" ";
	p[h]=-1;
	d[h]=0;
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
				cout << g[v][i] << " ";
				p[g[v][i]]=v;
				d[g[v][i]]=d[v]+1;
			}	
		}
	}
}
void shortestPath(int v)
{
	if(!vis[v])
		cout <<"NO PATH\n";
	else
	{
		vector<int> path;
		for(int i=v;i!=-1;i=p[i])
			path.push_back(i);
		reverse(path.begin(),path.end());
		cout << "PATH LENGTH = "<<d[v]<<"\n";
		cout << "PATH : ";
		for(int i=0;i<path.size();i++)
			cout<<path[i]<<" ";
	}
}
void levelCount(int v)
{
	int cnt=0;
	for(int i=1;i<=n;i++)
	{
		if(v==d[i])
			cnt++;
	} cout << cnt << "\n";
}
int main()
{
	int e; cin >> n >> e;
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
	int h; 
	cout << "\nEnter the head node to bfs"; cin >> h;
	bfs(h);
	//To find shortest path b/w source and vertex sp
	cout << "\nShortest path from head node to ?? " ;
	int sp;
	cin >> sp;
	shortestPath(sp);
	//To count the no. of nodes at level l;
	int l; 
	cout << "\nEnter the level no. for which you want to know the count of nodes";
	cin >> l;
	levelCount(l);
	return 0;
}


