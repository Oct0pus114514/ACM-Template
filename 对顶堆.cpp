#include<bits/stdc++.h>
using namespace std;
const int L=2e5+10;
int n,m,k;
int a[L],q[L];
priority_queue<int,vector<int>,greater<int> > q1;//xiao
priority_queue<int> q2;//da
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=m;i++){int x;scanf("%d",&x);q[x]++;}
	for(int i=1;i<=n;i++){
		if(!q2.empty() && a[i]<q2.top()){
			q2.push(a[i]);
			while(q2.size()>k){q1.push(q2.top());q2.pop();}
		}
		else {
			q1.push(a[i]);
			while(!q1.empty() && q2.size()<k){q2.push(q1.top());q1.pop();}
		}
		while(q[i]--){
			k++;
			while(!q1.empty() && q2.size()<k){q2.push(q1.top());q1.pop();}
			printf("%d\n",q2.top());
		}
	}
	return 0;
}