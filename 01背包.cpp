#include<iostream>
#include<algorithm>
using namespace std;
int t,m;
int c[110],v[110],f[1010];
int main(){
	cin>>t>>m;
	for(int i=1;i<=m;i++)cin>>c[i]>>v[i];
	for(int i=1;i<=m;i++)
		for(int j=t;j>=c[i];j--)
			f[j]=max(f[j],f[j-c[i]]+v[i]);
	cout<<f[t];
	return 0;
}