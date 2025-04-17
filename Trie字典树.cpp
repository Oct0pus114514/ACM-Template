#include<bits/stdc++.h>
using namespace std;
const int L=3e6+10;
int nxt[L][128],cnt[L];
int T,n,m,idx;
char str[L];
inline void add(char *s,int l){
	int p=0;
	for(int i=0;i<l;i++){
		int c=(char)s[i];
		if(!nxt[p][c])nxt[p][c]=++idx;
		p=nxt[p][c];
		cnt[p]++;
	}
}
inline int query(char *s,int l){
	int p=0;
	for(int i=0;i<l;i++){
		int c=(char)s[i];
		if(!nxt[p][c])return 0;
		p=nxt[p][c];
	}
	return cnt[p];
}
int main(){
	scanf("%d",&T);
	while(T--){
		for(int i=0;i<=idx;i++)
			for(int j=0;j<128;j++)nxt[i][j]=0;
		for(int i=0;i<=idx;i++)cnt[i]=0;
		idx=0;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%s",str);
			add(str,strlen(str));
		}
		for(int i=1;i<=m;i++){
			scanf("%s",str);
			printf("%d\n",query(str,strlen(str)));
		}
	}
	return 0;
}