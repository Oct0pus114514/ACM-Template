#include<bits/stdc++.h>
using namespace std;
const int L=1e5+10;
#define int long long
int n,m,r,mod,cnt,w[L],wt[L],fa[L],sz[L],dep[L],son[L],idx[L],top[L];
struct node{
	int l,r,sum,lazy;
}t[L<<2];
vector<int> e[L];
inline int read(void){
	int f=1,x=0;
	char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f*x;
}
inline void build(int i,int l,int r){
	t[i].l=l;t[i].r=r;
	if(l==r){t[i].sum=wt[l]%mod;return ;}
	int mid=l+r>>1;
	build(i<<1,l,mid);
	build(i<<1|1,mid+1,r);
	t[i].sum=(t[i<<1].sum+t[i<<1|1].sum)%mod;
}
inline void pushdown(int i){
	if(t[i].lazy){
		t[i<<1].sum=(t[i<<1].sum+t[i].lazy*(t[i<<1].r-t[i<<1].l+1)%mod)%mod;
		t[i<<1|1].sum=(t[i<<1|1].sum+t[i].lazy*(t[i<<1|1].r-t[i<<1|1].l+1)%mod)%mod;
		t[i<<1].lazy=(t[i<<1].lazy+t[i].lazy)%mod;
		t[i<<1|1].lazy=(t[i<<1|1].lazy+t[i].lazy)%mod;
		t[i].lazy=0;
	}
}
inline void segadd(int i,int l,int r,int v){
	if(t[i].l>=l && t[i].r<=r){
		t[i].sum=(t[i].sum+v*(t[i].r-t[i].l+1)%mod)%mod;
		t[i].lazy=(t[i].lazy+v%mod)%mod;
		return ;
	}
	if(t[i].l>r || t[i].r<l)return ;
	pushdown(i);
	segadd(i<<1,l,r,v);
	segadd(i<<1|1,l,r,v);
	t[i].sum=(t[i<<1].sum+t[i<<1|1].sum)%mod;
}
inline int segsum(int i,int l,int r){
	if(t[i].l>=l && t[i].r<=r)return t[i].sum;
	if(t[i].l>r || t[i].r<l)return 0;
	pushdown(i);
	return (segsum(i<<1,l,r)+segsum(i<<1|1,l,r))%mod;
}
inline void treeadd(int x,int y,int v){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		segadd(1,idx[top[x]],idx[x],v);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	segadd(1,idx[x],idx[y],v);
}
inline int treesum(int x,int y){
	int sum=0;
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		sum=(sum+segsum(1,idx[top[x]],idx[x]))%mod;
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	sum=(sum+segsum(1,idx[x],idx[y]))%mod;
	return sum;
}
inline void dfs1(int u,int f){
	dep[u]=dep[f]+1;
	fa[u]=f;
	sz[u]=1;
	int t=0;
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i];
		if(v!=f){
			dfs1(v,u);
			sz[u]+=sz[v];
			if(sz[v]>t){
				t=sz[v];
				son[u]=v;
			}
		}
	}
}
inline void dfs2(int u,int f){
	idx[u]=++cnt;
	wt[cnt]=w[u];
	top[u]=f;
	if(!son[u])return ;
	dfs2(son[u],f);
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i];
		if(!idx[v])dfs2(v,v);
	}
}
signed main(){
	n=read();m=read();r=read();mod=read();
	for(int i=1;i<=n;i++)w[i]=read();
	for(int i=1;i<n;i++){
		int u=read(),v=read();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs1(r,0);
	dfs2(r,r);
	build(1,1,n);
	while(m--){
		int op=read(),x=read(),y,z;
		switch(op){
			case 1:y=read();z=read();treeadd(x,y,z);break; 
			case 2:y=read();printf("%lld\n",treesum(x,y));break;
			case 3:y=read();segadd(1,idx[x],idx[x]+sz[x]-1,y);break;
			default:printf("%lld\n",segsum(1,idx[x],idx[x]+sz[x]-1));break;
		}
	}
	return 0;
}
