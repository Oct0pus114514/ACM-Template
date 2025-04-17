#include<bits/stdc++.h>
using namespace std;
#define L 5010
#define mod 80112002
vector<int> e[L];
queue<int> q;
int ind[L],oud[L],cnt[L];
int n,m,tot;
inline void add(int u,int v){e[u].push_back(v);}
inline void bfs(void){
	for(int i=1;i<=n;i++)if(!ind[i]){q.push(i);cnt[i]=1;}
	while(!q.empty()){
		int top=q.front();q.pop();
		for(int i=0;i<e[top].size();i++){
			int v=e[top][i];
			cnt[v]=(cnt[v]+cnt[top])%mod;
			ind[v]--;
			if(!ind[v])q.push(v);
		}
	}
}
int main(){
	cin>>n>>m;
	while(m--){
		int u,v;
		cin>>u>>v;
		add(u,v);
		ind[v]++;oud[u]++;
	}
	bfs();
	for(int i=1;i<=n;i++)
		if(!oud[i])tot=(tot+cnt[i])%mod;
	cout<<tot;
	return 0;
}