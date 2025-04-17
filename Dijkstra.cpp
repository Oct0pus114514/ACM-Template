#include<iostream>
#include<climits>
#include<queue>
using namespace std;
const int L=1e5+10;
struct edge{
	int to,val;
};
vector<edge> e[L];
struct qnode{
	int v,w;
	inline bool operator<(const qnode &o)const{return o.w<w;}
};
int dis[L];
bool vis[L];
int n,m,s;
void Dijkstra(void){
	priority_queue<qnode> q;
	while(!q.empty())q.pop();
	dis[s]=0;q.push((qnode){s,0});
	while(!q.empty()){
		int u=q.top().v;q.pop();
		if(vis[u])continue;
		vis[u]=true;
		for(int i=0;i<e[u].size();i++){
			int v=e[u][i].to;
			if(dis[v]>dis[u]+e[u][i].val){
				dis[v]=dis[u]+e[u][i].val;
				q.push((qnode){v,dis[v]});
			}
		}
	}
}
int main(){
	cin>>n>>m>>s;
	for(int i=1;i<=n;i++)dis[i]=INT_MAX;
	while(m--){
		int from,to,val;
		cin>>from>>to>>val;
		e[from].push_back((edge){to,val});
	}
	Dijkstra();
	for(int i=1;i<=n;i++)cout<<dis[i]<<" ";
	return 0;
}