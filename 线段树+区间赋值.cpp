#include<bits/stdc++.h>//update the maxinum of the section
using namespace std;
typedef long long ll;
const int L=2e6+10;
const ll nt=LLONG_MIN;
struct node{
	int l,r;
	ll val,lp,la;
}t[L<<2];
ll a[L];
int n,m;
inline void build(int i,int l,int r){
	t[i].l=l;t[i].r=r;t[i].la=nt;
	if(l==r){t[i].val=a[l];return ;}
	int mid=l+r>>1;
	build(i<<1,l,mid);
	build(i<<1|1,mid+1,r);
	t[i].val=max(t[i<<1].val,t[i<<1|1].val);
}
inline void pushassign(int i){
	if(t[i].la!=nt){
		t[i<<1].val=t[i].la;
		t[i<<1|1].val=t[i].la;
		t[i<<1].lp=t[i<<1|1].lp=0;
		t[i<<1].la=t[i].la;
		t[i<<1|1].la=t[i].la;
		t[i].la=nt;
	}
}
inline void pushplus(int i){
	if(t[i].lp){
		pushassign(i);
		t[i<<1].val+=t[i].lp;
		t[i<<1|1].val+=t[i].lp;
		t[i<<1].lp+=t[i].lp;
		t[i<<1|1].lp+=t[i].lp;
		t[i].lp=0;
	}
}
inline void add(int i,int l,int r,ll v){
	if(t[i].l>=l && t[i].r<=r){
		pushassign(i);
		t[i].val+=v;
		t[i].lp+=v;
		return ;
	}
	if(t[i].l>r || t[i].r<l)return ;
	pushassign(i);
	pushplus(i);
	add(i<<1,l,r,v);
	add(i<<1|1,l,r,v);
	t[i].val=max(t[i<<1].val,t[i<<1|1].val);
}
inline void assign(int i,int l,int r,ll v){
	if(t[i].l>=l && t[i].r<=r){
		t[i].val=v;
		t[i].la=v;
		t[i].lp=0;
		return ;
	}
	if(t[i].l>r || t[i].r<l)return ;
	pushassign(i);
	pushplus(i);
	assign(i<<1,l,r,v);
	assign(i<<1|1,l,r,v);
	t[i].val=max(t[i<<1].val,t[i<<1|1].val);
}
inline ll query(int i,int l,int r){
	if(t[i].l>=l && t[i].r<=r)return t[i].val;
	if(t[i].l>r || t[i].r<l)return nt;
	pushassign(i);
	pushplus(i);
	return max(query(i<<1,l,r),query(i<<1|1,l,r));
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	build(1,1,n);
	while(m--){
		int op,l,r;ll x;
		scanf("%d%d%d",&op,&l,&r);
		switch(op){
			case 1:scanf("%lld",&x);assign(1,l,r,x);break;
			case 2:scanf("%lld",&x);add(1,l,r,x);break;
			case 3:printf("%lld\n",query(1,l,r));break;
		}
	}
	return 0;
}