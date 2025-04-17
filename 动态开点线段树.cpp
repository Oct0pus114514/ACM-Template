#include<cstdio>
using namespace std;
const int L=1e5+10;
typedef long long ll;
struct node{
	int ls,rs,len;
	ll sum,lazy;
}t[L<<2];
int n,m,cnt,root;
ll a[L];
inline int build(int l,int r){
	t[++cnt].len=r-l+1;
	return cnt;
}
inline void push(int i){
	int l=t[i].ls,r=t[i].rs;
	if(t[i].lazy){
		t[l].sum+=t[i].lazy*t[l].len;
		t[r].sum+=t[i].lazy*t[r].len;
		t[l].lazy+=t[i].lazy;
		t[r].lazy+=t[i].lazy;
		t[i].lazy=0;
	}
}
inline void add(int &p,int pl,int pr,int l,int r,ll val){
	if(!p)p=build(pl,pr);
	if(l<=pl && pr<=r){
		t[p].sum+=val*t[p].len;
		t[p].lazy+=val;
		return ;
	}
	push(p);
	int mid=pl+pr>>1;
	if(l<=mid)add(t[p].ls,pl,mid,l,r,val);
	if(r>mid)add(t[p].rs,mid+1,pr,l,r,val);
	t[p].sum=t[t[p].ls].sum+t[t[p].rs].sum;
}
inline ll query(int &p,int pl,int pr,int l,int r){
	if(!p)return 0;
	if(l<=pl && pr<=r)return t[p].sum;
	push(p);
	int mid=pl+pr>>1;
	ll sum=0;
	if(l<=mid)sum+=query(t[p].ls,pl,mid,l,r);
	if(r>mid)sum+=query(t[p].rs,mid+1,pr,l,r);
	return sum;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		add(root,1,n,i,i,a[i]);
	}
	while(m--){
		int op,x,y;ll k;
		scanf("%d%d%d",&op,&x,&y);
		if(op==1){scanf("%lld",&k);add(root,1,n,x,y,k);}
		else printf("%lld\n",query(root,1,n,x,y));
	}
	return 0;
}