#include<iostream>
#include<iomanip>
using namespace std;
int a[10],b[10],n;
bool vis[10];
inline void dfs(int p){
	for(int i=1;i<=n;i++)
		if(!vis[i]){
			vis[i]=true;
			a[p]=i;
			dfs(p+1);
			vis[i]=false;
		}
	if(p==n){
		for(int i=1;i<=n;i++)cout<<fixed<<setw(5)<<a[i];
		cout<<endl;
		return ;
	}
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)b[i]=i;
	dfs(1);
	return 0;
}