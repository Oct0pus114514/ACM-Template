#include<bits/stdc++.h>
using namespace std;
const int L=15010;
int tr[L][26],fail[L],cnt[L],ans[L],val[L];
string str[160],t;
int n,tot,maxx;
unordered_map<int,int> mp;
inline void init(void){
	tot=maxx=0;mp.clear();
	memset(tr,0,sizeof(tr));
	memset(fail,0,sizeof(fail));
	memset(cnt,0,sizeof(cnt));
	memset(ans,0,sizeof(ans));
	memset(val,0,sizeof(val));
}
inline void insert(int i,string s){
	int p=0,l=s.size();
	for(int i=0;i<l;i++){
		int c=s[i]-'a';
		if(!tr[p][c])tr[p][c]=++tot;
		p=tr[p][c];
	}
	cnt[p]++;
	mp[p]=i;
}
inline void build(void){
	queue<int> q;
	for(int i=0;i<26;i++)if(tr[0][i])q.push(tr[0][i]);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=0;i<26;i++){
			if(tr[u][i]){fail[tr[u][i]]=tr[fail[u]][i];q.push(tr[u][i]);}
			else tr[u][i]=tr[fail[u]][i];
		}
	}
}
inline void query(string s){
	int p=0,l=s.size();
	for(int i=0;i<l;i++){
		p=tr[p][s[i]-'a'];
		for(int j=p;j;j=fail[j])val[j]++;
	}
	for(int i=1;i<=tot;i++)
		if(mp[i])ans[mp[i]]=val[i];
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	while(1){
		cin>>n;
		if(!n)return 0;
		init();
		for(int i=1;i<=n;i++){cin>>str[i];insert(i,str[i]);}
		build();
		cin>>t;
		query(t);
		for(int i=1;i<=n;i++)maxx=max(maxx,ans[i]);cout<<maxx<<endl;
		for(int i=1;i<=n;i++)if(ans[i]==maxx)cout<<str[i]<<endl;
	}
	return 0;
}