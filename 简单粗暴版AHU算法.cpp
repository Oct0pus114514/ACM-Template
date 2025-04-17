#include<bits/stdc++.h>
using namespace std;
int m,n,T;
vector<int> e[55];
string seq[55];
string ahu(int u,int fa){
	string ret="(",tmp[55];
	int cnt=0;
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i];
		if(v!=fa)tmp[++cnt]=ahu(v,u);
	}
	sort(tmp+1,tmp+cnt+1);
	for(int i=1;i<=cnt;i++)ret+=tmp[i];
	ret+=")";
	return ret;
}
int main(){
	scanf("%d",&T);
	for(int j=1;j<=T;j++){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)e[i].clear();
		for(int i=1;i<=n;i++){
			int v;scanf("%d",&v);
			if(v){e[i].push_back(v);e[v].push_back(i);}
		}
		seq[j]=ahu(1,0);
		for(int i=2;i<=n;i++)seq[j]=min(seq[j],ahu(i,0));
//		printf("%s\n",seq[j].c_str());
		for(int k=1;k<=j;k++)if(seq[k]==seq[j]){
			printf("%d\n",k);break;
		}
	}
	return 0;
}
