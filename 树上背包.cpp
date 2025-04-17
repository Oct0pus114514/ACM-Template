#include<bits/stdc++.h>
using namespace std;
const int L=310;
int f[L][L],a[L];
vector<int> e[L];
int n,m;
inline void dfs(int u){
	f[u][1]=a[u];
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i];
		dfs(v);
		for(int j=m+1;j>=1;j--)
			for(int k=0;k<j;k++)
				f[u][j]=max(f[u][j],f[v][k]+f[u][j-k]);
	}
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].push_back(i);
		a[i]=y;
	}
	dfs(0);
	printf("%d",f[0][m+1]);
	return 0;
}