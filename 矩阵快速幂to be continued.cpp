#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int n;ll k;
struct matrix{
	ll m[110][110];
	matrix(){memset(m,0,sizeof(m));}
	inline void build(void){
		for(int i=1;i<=n;i++)m[i][i]=1ll;
	}
	inline matrix operator*(const matrix &o)const{
		matrix ret;
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					ret.m[i][j]=(ret.m[i][j]+m[i][k]*o.m[k][j]%mod)%mod;
		return ret;
	}
	inline void disp(void){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)printf("%lld ",(m[i][j]+mod)%mod);
			puts("");
		}
	}
}a;
inline matrix pow(matrix a,ll b){
	matrix ans,base=a;
	ans.build();
	while(b){
		if(b&1)ans=ans*base;
		base=base*base;
		b>>=1;
	}
	return ans;
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)scanf("%d",&a.m[i][j]);
	pow(a,k).disp();
	return 0;
}