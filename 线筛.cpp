#include<bits/stdc++.h>
using namespace std;
const int L=1e8+10;
int n,T;
bool vis[L];
vector<int> pr;
void euler(void){
	for(int i=2;i<=n;i++){
		if(!vis[i])pr.push_back(i);
		for(int j=0;j<pr.size();j++){
			if(i*pr[j]>n)break;
			vis[i*pr[j]]=true;
			if(i%pr[j]==0)break;
		}
	}
}
int main(){
	scanf("%d%d",&n,&T);
	euler();
	while(T--){
		int x;
		scanf("%d",&x);
		printf("%d\n",pr[x-1]);
	}
	return 0;
}