#include<bits/stdc++.h>
using namespace std;
const int L=60;
typedef long long ll;
vector<int> e[L];
vector<ll> pr,sol[L];
ll f[L],g[L],sz[L];
bool vis[(int)(1e5+10)];
int T,n,ans[L];
inline void euler(int l){
	pr.push_back(0);
	for(int i=2;i<=l;i++){
		if(!vis[i])pr.push_back(i);
		for(int j=1;j<pr.size();j++){
			if(i*pr[j]>l)break;
			vis[i*pr[j]]=true;
			if(i%pr[j]==0)break;
		}
	}
}
inline void init(void){
	for(int i=1;i<=n;i++)e[i].clear();
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	memset(sz,0,sizeof(sz));
}
inline void dfs(int u,int fa){
	sz[u]=f[u]=1;
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i];
		if(v!=fa){
			dfs(v,u);
			sz[u]+=sz[v];
			f[u]+=f[v]*pr[sz[v]];
		}
	}
}
inline void dfs1(int u,int fa){
	g[u]=pr[sz[1]-sz[u]]*(g[fa]-f[u]*pr[sz[u]])+f[u];
	for(int i=0;i<e[u].size();i++)if(e[u][i]!=fa)dfs1(e[u][i],u);
}
inline bool isequal(int i,int j){
	if(sol[i].size()!=sol[j].size())return false;
	for(int k=0;k<sol[i].size();k++)
		if(sol[i][k]!=sol[j][k])return false;
	return true;
}
int main(){
	euler(5e4);
	scanf("%d",&T);
	for(int k=1;k<=T;k++){
		scanf("%d",&n);
		init();
		for(int i=1;i<=n;i++){
			int x;scanf("%d",&x);
			if(x){e[i].push_back(x);e[x].push_back(i);}
		}
		dfs(1,0);
		dfs1(1,0);
		sort(g+1,g+n+1);
		for(int i=1;i<=n;i++)sol[k].push_back(g[i]);
		for(int j=1;j<k;j++)
			if(isequal(j,k)){printf("%d\n",j);goto nxt;}
		printf("%d\n",k);
		nxt:;
	}
	return 0;
}