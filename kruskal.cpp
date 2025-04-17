#include<bits/stdc++.h>
using namespace std;
#define L 5010
struct edge{
	int from,to,val;
	inline bool operator<(const edge &o){
		return val<o.val;
	}
}a[L];
int fa[L];
int cnt,l;
int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
//struct e1{
//	int to,val;
//};
//vector<e1> e[L];
int n,m;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++)cin>>a[i].from>>a[i].to>>a[i].val;
	sort(a+1,a+m+1);
	for(int i=1;i<=m;i++){
		int x=find(a[i].from),y=find(a[i].to);
		if(x!=y){fa[x]=y;cnt+=a[i].val;}
	}
	for(int i=1;i<=n;i++)if(find(i)==i)l++;
	if(l>1)cout<<"orz";
	else cout<<cnt;
//	for(int i=1;i<=m;i++)cout<<a[i].val<<" ";
	return 0;
}