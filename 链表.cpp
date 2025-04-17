#include<iostream>
using namespace std;
const int L=1e5+10;
struct link{
	int pre,nxt;
}a[L];
bool vis[L];
int n,m,sz;
inline void add(int idx,int pre,bool pos){
	if(pos){//idx at the right of pre
		a[idx].pre=pre;
		a[idx].nxt=a[pre].nxt;
		a[a[pre].nxt].pre=idx;
		a[pre].nxt=idx;
	}else{
		a[idx].nxt=pre;
		a[idx].pre=a[pre].pre;
		a[a[pre].pre].nxt=idx;
		a[pre].pre=idx;
	}
}
inline void del(int idx){
	a[a[idx].pre].nxt=a[idx].nxt;
	a[a[idx].nxt].pre=a[idx].pre;
	a[idx].pre=a[idx].nxt=0;
}
inline void view(void){
	for(int i=a[0].nxt;i;i=a[i].nxt)
		cout<<i<<" ";
}
int main(){
	cin>>n;
	add(1,0,1);
	for(int i=2;i<=n;i++){
		int a,b;
		cin>>a>>b;
		add(i,a,b);
	}
	cin>>m;
	while(m--){
		int a;
		cin>>a;
		if(!vis[a]){del(a);vis[a]=true;}
	}
//	add(2,1,0);
//	cout<<a[0].nxt;
	view();
	return 0;
}