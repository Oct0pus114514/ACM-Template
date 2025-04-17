#include<bits/stdc++.h>
using namespace std;
const int L=1e6+10;
struct node{
	int ls,rs,val;
}t[L*25];
int a[L],n,m,top,root[L*25];
inline int clone(int i){//dongtaikaidian
	t[++top]=t[i];
	return top;
}
inline int build(int i,int l,int r){
	i=++top;
	if(l==r){t[i].val=a[l];return i;}
	int mid=l+r>>1;
	t[i].ls=build(t[i].ls,l,mid);
	t[i].rs=build(t[i].rs,mid+1,r);
	return i;
}
inline int update(int i,int l,int r,int pos,int v){
	i=clone(i);
	if(l==r){t[i].val=v;return i;}
	int mid=l+r>>1;
	if(pos<=mid)t[i].ls=update(t[i].ls,l,mid,pos,v);
	else t[i].rs=update(t[i].rs,mid+1,r,pos,v);
	return i;
}
inline int query(int i,int l,int r,int pos){
	if(l==r)return t[i].val;
	int mid=l+r>>1;
	if(pos<=mid)return query(t[i].ls,l,mid,pos);
	return query(t[i].rs,mid+1,r,pos);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	root[0]=build(0,1,n);
	for(int i=1;i<=m;i++){
		int v,op,loc,val;
		scanf("%d%d%d",&v,&op,&loc);
		if(op==1){
			scanf("%d",&val);
			root[i]=update(root[v],1,n,loc,val);
		}else{
			printf("%d\n",query(root[v],1,n,loc));
			root[i]=root[v];
		}
	}
	return 0;
}