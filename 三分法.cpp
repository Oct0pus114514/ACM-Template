#include<bits/stdc++.h>
using namespace std;
const double eps=1e-15;
int n;
double ll,rr,a[15];
double f(double x){
	double ret=0;
	for(int i=0;i<=n;i++)ret+=a[i]*pow(x,i);
	return ret;
}
signed main(){
	scanf("%d%lf%lf",&n,&ll,&rr);
	for(int i=n;i>=0;i--)scanf("%lf",&a[i]);
	double l=ll,r=rr;
	while(abs(r-l)>eps){
		double m1=l+(r-l)/3,m2=l+(r-l)*2/3;
		if(f(m1)<f(m2))l=m1;
		else r=m2;
	}
	printf("%.8lf",l);
	return 0;
}
