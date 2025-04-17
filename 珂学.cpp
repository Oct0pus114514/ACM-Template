#include<cstdio>
#include<set>
#include<algorithm>
#include<vector>
using namespace std;
typedef unsigned long long ull;
const int L=1e5+10;
struct node{
	ull l,r;
	mutable ull v;
	node(ull l,ull r=0,ull v=0):l(l),r(r),v(v){}
	inline bool operator<(const node &o)const{return l<o.l;}
};
typedef set<node>::iterator iter;
set<node> s;
ull a[L];
ull n,m,seed,vmax;
inline void swap(int &x,int &y){x^=y^=x^=y;}
inline ull rnd(void){
	ull ret=seed;
	seed=(seed*7+13)%1000000007ll;
	return ret;
}
inline iter split(ull pos){
	iter it=s.lower_bound(node(pos));
	if(it!=s.end() && it->l==pos)return it;
	it--;
	if(it->r<pos)return s.end();
	ull l=it->l,r=it->r,v=it->v;
	s.erase(it);
	s.insert(node(l,pos-1,v));
	return s.insert(node(pos,r,v)).first;
}
inline void add(ull l,ull r,ull v){
	iter itr=split(r+1),itl=split(l);
	for(iter it=itl;it!=itr;it++)
		it->v+=v;
}
inline void assign(ull l,ull r,ull v){
	iter itr=split(r+1),itl=split(l);
	s.erase(itl,itr);
	s.insert(node(l,r,v));
}
inline ull kth(ull l,ull r,ull x){
	struct sm{
		ull num,cnt;
		sm(ull num,ull cnt):num(num),cnt(cnt){}
		inline bool operator<(const sm &o)const{return num<o.num;}
	};
	vector<sm> v;
	iter itr=split(r+1),itl=split(l);
	for(iter it=itl;it!=itr;it++)
		v.push_back(sm(it->v,it->r-it->l+1));
	sort(v.begin(),v.end());
	int i;
	for(i=0;i<v.size();i++){
		if(v[i].cnt<x)x-=v[i].cnt;
		else break;
	}
	return v[i].num;
}
inline ull pow(ull a,ull b,ull mod){
	ull ans=1,base=a%mod;
	while(b){
		if(b&1)ans=ans*base%mod;
		base=base*base%mod;
		b>>=1;
	}
	return ans;
}
inline ull query(ull l,ull r,ull x,ull y){
	iter itr=split(r+1),itl=split(l);
	ull ans=0;
	for(iter it=itl;it!=itr;it++)
		ans=(ans+(it->r-it->l+1)%y*pow(it->v,x,y))%y;
	return ans;
}
int main(){
	scanf("%lld%lld%lld%lld",&n,&m,&seed,&vmax);
	for(register int i=1;i<=n;i++){
		a[i]=rnd()%vmax+1;
		s.insert(node(i,i,a[i]));
	}
	for(register int i=1;i<=m;i++){
		ull op=rnd()%4+1,l=rnd()%n+1,r=rnd()%n+1,x=0,y=0;
		if(l>r)swap(l,r);
		if(op==3)x=rnd()%(r-l+1)+1;
		else x=rnd()%vmax+1;
		if(op==4)y=rnd()%vmax+1;
//		printf("%lld %lld %lld",&l,&r,&x,&y);
		switch(op){
			case 1:add(l,r,x);break;
			case 2:assign(l,r,x);break;
			case 3:printf("%lld\n",kth(l,r,x));break;
			case 4:printf("%lld\n",query(l,r,x,y));break;	
		}
	}
	return 0;

}