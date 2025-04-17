#include<bits/stdc++.h>
using namespace std;
const int L=2e5+10;
struct node{
	int ls,rs,sum;
}t[L*25];
int n,m,top,a[L],b[L],root[L*25];
inline int read(void){
	int f=1,x=0;
	char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f*x;
}
inline int clone(int i){
	t[++top]=t[i];
	return top;
}
inline int build(int i,int l,int r){
	i=++top;
	if(l==r)return i;
	int mid=l+r>>1;
	t[i].ls=build(t[i].ls,l,mid);
	t[i].rs=build(t[i].rs,mid+1,r);
	return i;
}
inline int update(int i,int l,int r,int pos){
	i=clone(i);
	if(l==r){t[i].sum++;return i;}
	int mid=l+r>>1;
	if(pos<=mid)t[i].ls=update(t[i].ls,l,mid,pos);
	else t[i].rs=update(t[i].rs,mid+1,r,pos);
	t[i].sum=t[t[i].ls].sum+t[t[i].rs].sum;
	return i;
}
inline int query(int pl,int pr,int l,int r,int k){
	if(l==r)return l;
	int mid=l+r>>1,left=t[t[pr].ls].sum-t[t[pl].ls].sum;
	if(k<=left)return query(t[pl].ls,t[pr].ls,l,mid,k);
	return query(t[pl].rs,t[pr].rs,mid+1,r,k-left);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){a[i]=read();b[i]=a[i];}
	sort(b+1,b+n+1);
	int len=unique(b+1,b+n+1)-b-1;
	root[0]=build(0,1,n);
	for(int i=1;i<=n;i++){
		int pos=lower_bound(b+1,b+len+1,a[i])-b;
		a[i]=pos;
		root[i]=update(root[i-1],1,n,a[i]);
	}
//	printf("%d",t[root[5]].sum);
//	for(int i=1;i<=n;i++)printf("%d ",a[i]);
	while(m--){
		int l=read(),r=read(),k=read();
		printf("%d\n",b[query(root[l-1],root[r],1,n,k)]);
	}
	return 0;
}