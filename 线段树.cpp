#include<bits/stdc++.h>
using namespace std;
const int L=1e5+10;
typedef long long ll;
struct node{
	int l,r;
	ll sum,lazy;
}t[L<<2];
ll a[L];
int n,m;
inline void push(int i){
	if(t[i].lazy){
		t[i<<1].lazy+=t[i].lazy;
		t[i<<1|1].lazy+=t[i].lazy;
		t[i<<1].sum+=t[i].lazy*(t[i<<1].r-t[i<<1].l+1);
		t[i<<1|1].sum+=t[i].lazy*(t[i<<1|1].r-t[i<<1|1].l+1);
		t[i].lazy=0;
	}
}
inline void build(int i,int l,int r){
	t[i].l=l;t[i].r=r;
	if(l==r){t[i].sum=a[l];return ;}
	int mid=(l+r)>>1;
	build(i<<1,l,mid);
	build(i<<1|1,mid+1,r);
	t[i].sum=t[i<<1].sum+t[i<<1|1].sum;
}
inline void add(int i,int l,int r,ll v){
	if(t[i].l>=l && t[i].r<=r){t[i].sum+=v*(t[i].r-t[i].l+1);t[i].lazy+=v;return ;}
	if(t[i].r<l || t[i].l>r)return ;
	push(i);
	add(i<<1,l,r,v);
	add(i<<1|1,l,r,v);
	t[i].sum=t[i<<1].sum+t[i<<1|1].sum;
}
inline ll query(int i,int l,int r){
	if(t[i].l>=l && t[i].r<=r)return t[i].sum;
	if(t[i].r<l || t[i].l>r)return 0;
	push(i);
	ll s=0;
	return query(i<<1,l,r)+query(i<<1|1,l,r);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	build(1,1,n);
	while(m--){
		int p,l,r;ll v;
		scanf("%d%d%d",&p,&l,&r);
		if(p==1){scanf("%lld",&v);add(1,l,r,v);}
		else printf("%lld\n",query(1,l,r));
	}
	return 0;
}