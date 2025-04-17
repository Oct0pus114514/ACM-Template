#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
#define L 500010
vector<int> e[L];
int n,m,s;
int dis[L],p[L][21];
inline void dfs(int u,int fa){
	dis[u]=dis[fa]+1;
	p[u][0]=fa;
	for(int i=1;1<<i<=dis[u];i++)
		p[u][i]=p[p[u][i-1]][i-1];
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i];
		if(v!=fa)dfs(v,u);
	}
}
inline int lca(int a,int b){
	if(dis[a]>dis[b])swap(a,b);
	for(int i=log2(dis[b]);i>=0;i--)
		if(dis[a]<=dis[b]-(1<<i))b=p[b][i];
	if(a==b)return a;
	for(int i=log2(dis[b]);i>=0;i--)
		if(p[a][i]!=p[b][i])a=p[a][i],b=p[b][i];
	return p[a][0];
}
int main(){
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(s,0);
	while(m--){
		int a,b;
		scanf("%d%d",&a,&b);
		printf("%d\n",lca(a,b));
	}
	return 0;
}