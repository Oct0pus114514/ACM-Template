#include<cstdio>
using namespace std;
const int L=1e5+10;
typedef long long ll;
struct node{
	int l,r;
	ll sum,lp,lt;
}t[L<<2];
ll init[L],mod;
int n,m;
inline void build(int i,int l,int r){
	t[i].l=l;t[i].r=r;t[i].lt=1ll;
	if(l==r){t[i].sum=init[l]%mod;return ;}
	int mid=l+r>>1;
	build(i<<1,l,mid);
	build(i<<1|1,mid+1,r);
	t[i].sum=(t[i<<1].sum+t[i<<1|1].sum)%mod;
}
inline void push(int i){
	t[i<<1].sum=(t[i<<1].sum*t[i].lt%mod+t[i].lp*(t[i<<1].r-t[i<<1].l+1)%mod)%mod;
	t[i<<1|1].sum=(t[i<<1|1].sum*t[i].lt%mod+t[i].lp*(t[i<<1|1].r-t[i<<1|1].l+1)%mod)%mod;
	t[i<<1].lt=(t[i<<1].lt*t[i].lt)%mod;
	t[i<<1|1].lt=(t[i<<1|1].lt*t[i].lt)%mod;
	t[i<<1].lp=(t[i<<1].lp*t[i].lt%mod+t[i].lp)%mod;
	t[i<<1|1].lp=(t[i<<1|1].lp*t[i].lt%mod+t[i].lp)%mod;
	t[i].lp=0;
	t[i].lt=1;
}
inline void add(int i,int l,int r,ll val){
	if(t[i].l>=l && t[i].r<=r){
		t[i].sum=(t[i].sum+val*(t[i].r-t[i].l+1)%mod)%mod;
		t[i].lp=(t[i].lp+val)%mod;
		return ;
	}
	if(t[i].l>r || t[i].r<l)return ;
	push(i);
	add(i<<1,l,r,val);
	add(i<<1|1,l,r,val);
	t[i].sum=(t[i<<1].sum+t[i<<1|1].sum)%mod;
}
inline void time(int i,int l,int r,ll val){
	if(t[i].l>=l && t[i].r<=r){
		t[i].sum=(t[i].sum*val)%mod;
		t[i].lp=(t[i].lp*val)%mod;
		t[i].lt=(t[i].lt*val)%mod;
		return ;
	}
	if(t[i].l>r || t[i].r<l)return ;
	push(i);
	time(i<<1,l,r,val);
	time(i<<1|1,l,r,val);
	t[i].sum=(t[i<<1].sum+t[i<<1|1].sum)%mod;
}
inline ll query(int i,int l,int r){
	if(t[i].l>=l && t[i].r<=r)return t[i].sum;
	if(t[i].l>r || t[i].r<l)return 0ll;
	push(i);
	return (query(i<<1,l,r)+query(i<<1|1,l,r))%mod;
}
int main(){
	scanf("%d%lld",&n,&mod);
	for(int i=1;i<=n;i++)scanf("%lld",&init[i]);
	build(1,1,n);
	scanf("%d",&m);
	while(m--){
		int t,x,y;ll v;
		scanf("%d%d%d",&t,&x,&y);
		switch(t){
			case 1:scanf("%lld",&v);time(1,x,y,v);break;
			case 2:scanf("%lld",&v);add(1,x,y,v);break;
			case 3:printf("%lld\n",query(1,x,y));break;
			default:break;
		}
	}
	return 0;
}