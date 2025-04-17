#include<cstdio>
#include<algorithm>
using namespace std;
const int L=1e6+10;
typedef long long ll;
int n;
ll m,a[L];
inline ll sum(ll x){
	ll ans=0;
	for(int i=1;i<=n;i++)
		if(a[i]>x)ans+=a[i]-x;
	return ans;
}
int main(){
	scanf("%d%lld",&n,&m);
	ll left=0,right=0,mid;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		right=max(right,a[i]);
	}
	while(left<right){
		mid=left+right+1>>1;
		if(sum(mid)>=m)left=mid;
		else right=mid-1;
	}
	printf("%lld",left);
	return 0;
}