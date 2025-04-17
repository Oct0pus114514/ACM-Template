/*
10
1 2 2 3 3 3 4 4 4 4
*/
#include<bits/stdc++.h>
using namespace std;
const int L=1e5+10;
struct node{
	int l,r,cnt;
}t[L];
int n,m,a[L],b[L],buc[L];
inline void build(int i,int l,int r){
	t[i].l=l;t[i].r=r;
	if(l==r){t[i].cnt=buc[l];return ;}
	int mid=l+r>>1;
	build(i<<1,l,mid);
	build(i<<1|1,mid+1,r);
	t[i].cnt=t[i<<1].cnt+t[i<<1|1].cnt;
}
inline int kth_max(int i,int l,int r,int k){
	if(l==r)return l;
	int mid=l+r>>1,right=t[i<<1|1].cnt;
	if(k<=right)return kth_max(i<<1|1,mid+1,r,k);
	else return kth_max(i<<1,l,mid,k-right);
}
inline int kth_min(int i,int l,int r,int k){
	if(l==r)return l;
	int mid=l+r>>1,left=t[i<<1].cnt;
	if(k<=left)return kth_max(i<<1,l,mid,k);
	else return kth_max(i<<1|1,mid+1,r,k-left);
}
void add(int i,int l,int r,int v){
	if(l==r){t[v].cnt++;return ;}
	int mid=l+r>>1;
	if(v<=mid)add(i<<1,l,mid,v);
	else add(i<<1|1,mid+1,r,v);
	t[i].cnt=t[i<<1].cnt+t[i<<1|1].cnt;
}
int find(int i,int l,int r,int v){
	if(l==r)return t[v].cnt;
	int mid=l+r>>1;
	if(v<=mid)return find(i<<1,l,mid,v);
	else return find(i<<1|1,mid+1,r,v);
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){scanf("%d",&a[i]);b[i]=a[i];}
	sort(b+1,b+n+1);
	int len=unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=n;i++){
		int pos=lower_bound(b+1,b+len+1,a[i])-b;
		a[i]=pos;
	}
//	for(int i=1;i<=n;i++)printf("%d ",b[i]);
	for(int i=1;i<=n;i++)buc[a[i]]++;
	build(1,1,n);
//	while(m--){
//		int l,r,v;
//		scanf("%d%d%d",&l,&r,&v);
//		printf("%d\n",b[kth_min(1,l,r,v)]);
//	}
//	printf("%d",kth_max);
	return 0;
}