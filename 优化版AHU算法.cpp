#include<bits/stdc++.h>
using namespace std;
int m,n,T;
int sz[55],f[55];
vector<int> e[55];
string seq[55];
inline void dfs(int u,int fa){
	sz[u]=1;
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i];
		if(v!=fa){
			dfs(v,u);
			sz[u]+=sz[v];
			f[u]=max(f[u],sz[v]);
		}
	}
	f[u]=max(f[u],n-sz[u]);
}
string ahu(int u,int fa){
	string ret="(",tmp[55];
	int cnt=0;
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i];
		if(v!=fa)tmp[++cnt]=ahu(v,u);
	}
	sort(tmp+1,tmp+cnt+1);
	for(int i=1;i<=cnt;i++)ret+=tmp[i];
	ret+=")";
	return ret;
}
int main(){
	scanf("%d",&T);
	for(int j=1;j<=T;j++){
		memset(sz,0,sizeof(sz));
		memset(f,0,sizeof(f));
		scanf("%d",&n);
		for(int i=1;i<=n;i++)e[i].clear();
		for(int i=1;i<=n;i++){
			int v;scanf("%d",&v);
			if(v){e[i].push_back(v);e[v].push_back(i);}
		}
		dfs(1,0);
		int minn=INT_MAX;seq[j]="z";
		for(int i=1;i<=n;i++)minn=min(minn,f[i]);
		for(int i=1;i<=n;i++)if(f[i]==minn)seq[j]=min(seq[j],ahu(i,0));
//		printf("%s\n",seq[j].c_str());
		for(int i=1;i<=j;i++)if(seq[i]==seq[j]){printf("%d\n",i);break;}
	}
	return 0;
}
