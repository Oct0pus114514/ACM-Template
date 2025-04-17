#include<cstdio>
#include<queue>
using namespace std;
const int L=1e6+10;
struct node{
	int num,idx;
}a[L];
deque<node> q;
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){scanf("%d",&a[i].num);a[i].idx=i;}
	for(int i=1;i<=n;i++){
		while(!q.empty() && q.front().num>=a[i].num)q.pop_front();
		q.push_front(a[i]);
		while(q.back().idx<=i-m)q.pop_back();
		if(i>=m)printf("%d ",q.back().num);
	}q.clear();puts("");
	for(int i=1;i<=n;i++){
		while(!q.empty() && q.front().num<=a[i].num)q.pop_front();
		q.push_front(a[i]);
		while(q.back().idx<=i-m)q.pop_back();
		if(i>=m)printf("%d ",q.back().num);
	}
	return 0;
}