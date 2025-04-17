#include<cstdio>
#include<algorithm>
using namespace std;
const int L=1e6+10;
int n,m,a[L];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	while(m--){
		int k;
		scanf("%d",&k);
		int left=1,right=n;
		while(left<right){
			int mid=left+right>>1;
			if(k>a[mid])left=mid+1;
			else right=mid;
		}
		printf("%d ",a[left]==k?left:-1);
	}
	return 0;
}