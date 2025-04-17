#include<bits/stdc++.h>
using namespace std;
const int L=1e4+10;
struct edge{int from,to;}a[L*10];
stack<int> st;
queue<int> q;
vector<int> e[L],e1[L];
int low[L],dfn[L],sd[L],val[L],ind[L],f[L];
bool vis[L];
int n,m,cnt;
inline void tarjan(int u){
    dfn[u]=low[u]=++cnt;
    st.push(u);vis[u]=true;
    for(int i=0;i<e[u].size();i++){
        int v=e[u][i];
        if(!dfn[v]){
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        else if(vis[v])low[u]=min(low[u],low[v]);
    }
    if(low[u]==dfn[u]){
        while(!st.empty()){
            int v=st.top();
            st.pop();
            sd[v]=u;
            vis[v]=false;
            if(v==u)break;
            val[u]+=val[v];
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&val[i]);
    for(int i=1;i<=m;i++){
        int u,v;
        scanf("%d%d",&u,&v);
        a[i].from=u;a[i].to=v;
        e[u].push_back(v);
    }
    for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i);
    for(int i=1;i<=m;i++){
        int u=sd[a[i].from],v=sd[a[i].to];
        if(u!=v){
            ind[v]++;
            e1[u].push_back(v);
        }
    }
    for(int i=1;i<=n;i++)if(sd[i]==i && !ind[i]){q.push(i);f[i]=val[i];}
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=0;i<e1[u].size();i++){
            int v=e1[u][i];
            f[v]=max(f[v],f[u]+val[v]);
            ind[v]--;
            if(!ind[v])q.push(v);
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++)ans=max(ans,f[i]);printf("%d",ans);
    return 0;
}