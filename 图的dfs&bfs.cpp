#include<bits/stdc++.h>
using namespace std;
const int L=1e5+10;
vector<int> edge[L];
queue<int> q;
bool vis[L];
int n,m;
inline void add(int a,int b){edge[a].push_back(b);}
void dfs(int node){
	if(!vis[node]){cout<<node<<" ";vis[node]=true;}
	for(int i=0;i<edge[node].size();i++)
		if(!vis[edge[node][i]]){dfs(edge[node][i]);vis[edge[node][i]]=true;}
}
void bfs(int x){
	memset(vis, false, sizeof(vis));
	vis[x] = true;
	q.push(x);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		cout << v << " ";
		for (int i=0; i<edge[v].size(); i++) 
			if (!vis[edge[v][i]]) {
				vis[edge[v][i]] = true;
				q.push(edge[v][i]);
			}
	}
}
int main(){
	cin>>n>>m;
	while(m--){
		int a,b;
		cin>>a>>b;
		add(a,b);
	}
	for(int i=1;i<=n;i++)sort(edge[i].begin(),edge[i].end());
	dfs(1);cout<<endl;
	bfs(1);
	return 0;
}