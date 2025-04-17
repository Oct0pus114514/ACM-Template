#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int L=1000010;
const ll mod=998244353;
ll fac[L],a[L],t[L],ans;
int n;
inline int lowbit(int x){return x&(-x);}
inline void add(int pos,ll x){
	for(;pos<=n;pos+=lowbit(pos))t[pos]+=x;
}
inline ll query(int pos){
	ll ret=0;
	for(;pos;pos-=lowbit(pos))ret+=t[pos];
	return ret;
}
int main(){
	scanf("%d",&n);
	fac[0]=fac[1]=1;
	for(register int i=2;i<=n;i++)fac[i]=fac[i-1]*i%mod;
	for(register int i=1;i<=n;i++){scanf("%lld",&a[i]);add(i,1);}
	for(register int i=1;i<=n;i++){
		ans=(ans+fac[n-i]*query(a[i]-1)%mod)%mod;
		add(a[i],-1);
	}
	printf("%lld",(ans+1+mod)%mod);
	return 0;
}