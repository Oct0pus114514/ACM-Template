#include<bits/stdc++.h>
using namespace std;
const int L=1e5+10;
vector<int> e[L];
stack<int> st;
int n,m,beg,cnt1,cnt2;
int ind[L],oud[L],del[L];
void dfs(int u){
	for(int i=del[u];i<e[u].size();i=del[u]){
		del[u]=i+1;
		dfs(e[u][i]);
	}
	st.push(u);
}
int main(){
	scanf("%d%d",&n,&m);
	while(m--){
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		ind[v]++;oud[u]++;
	}
	for(int i=1;i<=n;i++){
		if(abs(ind[i]-oud[i])>1){puts("No");return 0;}
		if(oud[i]-ind[i]==1){cnt1++;beg=i;}
		else if(ind[i]-oud[i]==1)cnt2++;
	}
	for(int i=1;i<=n;i++)sort(e[i].begin(),e[i].end());
	dfs(beg);
	while(!st.empty()){printf("%d ",st.top());st.pop();}
	return 0;
}