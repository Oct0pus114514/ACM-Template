#include<bits/stdc++.h>
using namespace std;
const int L=2e5+10;
int fa[L],n,m;
inline int find(int x){
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
inline void merge(int a,int b){
	a=find(a),b=find(b);
	if(a!=b)fa[a]=b;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)fa[i]=i;
	while(m--){
		int a,b,c;
		cin>>a>>b>>c;
		if(a==1)merge(b,c);
		else cout<<(find(b)==find(c)?"Y\n":"N\n");
	}
	return 0;
}