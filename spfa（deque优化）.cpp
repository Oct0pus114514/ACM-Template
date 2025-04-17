#include<iostream>
#include<queue>
#include<climits>
using namespace std;
const int L=1e4+10;
struct edge{
	int to,val;
};
vector<edge> e[L];
int n,m,s;
int dis[L];
bool vis[L];
void spfa(void){
	deque<int> q;
	q.push_back(s);dis[s]=0;vis[s]=true;
	while(!q.empty()){
		int u=q.front();q.pop_front();vis[u]=false;
		for(int i=0;i<e[u].size();i++){
			int v=e[u][i].to;
			if(dis[v]>dis[u]+e[u][i].val){
				dis[v]=dis[u]+e[u][i].val;
				if(!vis[v]){
					vis[v]=true;
					if(q.size() && dis[v]<dis[q.front()])q.push_front(v);
					else q.push_back(v);
				}
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
	spfa();
	for(int i=1;i<=n;i++)cout<<dis[i]<<" ";
	return 0;
}