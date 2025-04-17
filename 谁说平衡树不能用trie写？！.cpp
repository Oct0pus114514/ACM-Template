#include<bits/stdc++.h>
using namespace std;
const int L=1e5*26+10,over=1e7+1;
int trie[L][2],cnt[L],sz,m;
inline void insert(int x){
	int p=0;
	for(int i=25;i>=0;i--){
		int b=(x>>i)&1;
		if(!trie[p][b])trie[p][b]=++sz;
		p=trie[p][b];
		cnt[p]++;
	}
}
inline void del(int x){
	int p=0;
	for(int i=25;i>=0;i--){
		int b=(x>>i)&1;
		p=trie[p][b];
		cnt[p]--;
	}
}
inline int rnk(int x){
	int ret=1,p=0;
	for(int i=25;i>=0;i--){
		int b=(x>>i)&1;
		if(b){
			ret+=cnt[trie[p][0]];
			p=trie[p][1];
		}else p=trie[p][0];
		if(!cnt[p])break;
	}
	return ret;
}
inline int kth(int x){
	int ret=0,p=0;
	for(int i=25;i>=0;i--){
//		printf("%d %d %d\n",i,x,cnt[trie[p][0]]);
		if(x>cnt[trie[p][0]]){	
			ret+=1<<i;
			x-=cnt[trie[p][0]];
			p=trie[p][1];
		}else p=trie[p][0];
	}
	return ret;
}
int main(){
	scanf("%d",&m);
	while(m--){
		int op,x;
		scanf("%d%d",&op,&x);
		switch(op){
			case 1:insert(x+over);break;
			case 2:del(x+over);break;
			case 3:printf("%d\n",rnk(x+over));break;
			case 4:printf("%d\n",kth(x)-over);break;
			case 5:printf("%d\n",kth(rnk(x+over)-1)-over);break;
			case 6:printf("%d\n",kth(rnk(x+over+1))-over);break;
		}
	}
	return 0;
}