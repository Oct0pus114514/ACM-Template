#include<bits/stdc++.h>
using namespace std;
const int L=25;
int n,m,a[L],ans;
bitset<2010> bcnt;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	for(int i=0;i<(1<<n);i++)
		if(bitset <L>(i).count()==n-m){
			bcnt&=0;bcnt|=1;
			for(int j=0;j<n;j++)if(i&(1<<j))bcnt|=bcnt<<a[j];
			ans=max(ans,(int)bcnt.count());
		}
	printf("%d",ans-1);
	return 0;
}