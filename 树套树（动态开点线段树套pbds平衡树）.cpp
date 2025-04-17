#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
const int maxx=1e8,L=5e4+10;
struct node{
	int ls,rs;
	tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> tr;
}t[L*30];
int n,m,a[L],top,rt;
inline int read(void){
	int f=1,x=0;
	char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f*x;
}
inline void insert(int &i,int l,int r,int k,int pos,bool op){
	if(!i)i=++top;
	if(op)t[i].tr.insert(pos);
	else t[i].tr.erase(pos);
	if(l==r)return ;
	int mid=l+r>>1;
	if(k<=mid)insert(t[i].ls,l,mid,k,pos,op);
	else insert(t[i].rs,mid+1,r,k,pos,op);
}
inline int rnk(int &i,int l,int r,int k,int ql,int qr){
	if(!i)i=++top;
	if(r<=k)return t[i].tr.order_of_key(qr+1)-t[i].tr.order_of_key(ql);
	int mid=l+r>>1,ans=rnk(t[i].ls,l,mid,k,ql,qr);
	if(k>mid)ans+=rnk(t[i].rs,mid+1,r,k,ql,qr);
	return ans;
}
inline int kth(int &i,int l,int r,int k,int ql,int qr){
	if(!i)i=++top;
	if(l==r)return l;
	int mid=l+r>>1,left=t[t[i].ls].tr.order_of_key(qr+1)-t[t[i].ls].tr.order_of_key(ql);
	if(k<=left)return kth(t[i].ls,l,mid,k,ql,qr);
	else return kth(t[i].rs,mid+1,r,k-left,ql,qr);
}
int main(){
	n=read();m=read();
	for(int i=1;i<=n;i++){a[i]=read();insert(rt,0,maxx,a[i],i,1);}
	while(m--){
		int op=read(),l,r,pos,k,rk;
		if(op==3)pos=read();
		else {l=read();r=read();}
		k=read();
		switch(op){
			case 1:printf("%d\n",rnk(rt,0,maxx,k-1,l,r)+1);break;
			case 2:printf("%d\n",kth(rt,0,maxx,k,l,r));break;
			case 3:insert(rt,0,maxx,a[pos],pos,0);insert(rt,0,maxx,a[pos]=k,pos,1);break;
			case 4:rk=rnk(rt,0,maxx,k-1,l,r)+1;printf("%d\n",rk==1?-INT_MAX:kth(rt,0,maxx,rk-1,l,r));break;
			case 5:rk=rnk(rt,0,maxx,k,l,r)+1;printf("%d\n",rk>r-l+1?INT_MAX:kth(rt,0,maxx,rk,l,r));break;
		}
	}
	return 0;
}
