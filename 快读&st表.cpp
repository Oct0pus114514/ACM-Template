#include<cstdio>
#include<cmath>
using namespace std;
const int L=1e5+10;
#define max(a,b) ((a)>(b)?(a):(b))
int n,m;
int st[L][18];
inline int read(void){
	int f=1,x=0;
	char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' && ch<='9'){x=x*10+(ch-'0');ch=getchar();}
	return f*x;
}
inline int query(int l,int r){
	int sz=log2(r-l+1);
	return max(st[l][sz],st[r-(1<<sz)+1][sz]);
}
int main(){
	n=read();m=read();
	for(int i=1;i<=n;i++)st[i][0]=read();
	for(int j=1;j<18;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	while(m--){
		int l=read(),r=read();
		printf("%d\n",query(l,r));
	}
	return 0;
}