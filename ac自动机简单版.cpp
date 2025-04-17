#include<bits/stdc++.h>
using namespace std;
const int L=1e6+10;
int tr[L][26],e[L],fail[L];
int n,tot;
char str[L];
inline void insert(char *s){
	int p=0,l=strlen(s);
	for(int i=0;i<l;i++){
		int c=s[i]-'a';
		if(!tr[p][c])tr[p][c]=++tot;
		p=tr[p][c];
	}
	e[p]++;
}
inline void build(void){
	queue<int> q;
	for(int i=0;i<26;i++)
		if(tr[0][i])q.push(tr[0][i]);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=0;i<26;i++){
			if(tr[u][i]){fail[tr[u][i]]=tr[fail[u]][i];q.push(tr[u][i]);}
			else tr[u][i]=tr[fail[u]][i];
		}
	}
}
inline int query(char *s){
	int p=0,l=strlen(s),ret=0;
	for(int i=0;i<l;i++){
		p=tr[p][s[i]-'a'];
		for(int j=p;j && e[j]!=-1;j=fail[j]){
			ret+=e[j];e[j]=-1;
		}
	}
	return ret;
}
int main(){
	scanf("%d",&n);
	while(n--){
		scanf("%s",str);
		insert(str);
	}
	build();
	scanf("%s",str);
	printf("%d",query(str));
	return 0;
}