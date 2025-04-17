#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int L = 2e4 + 10;
vector<int> e[L];
int low[L], dfn[L];
bool cut[L];
int n, m,cnt,ans;
inline void tarjan(int u, int rt) {
	int child = 0;
	low[u] = dfn[u] = ++cnt;
	for (int i = 0;i < e[u].size();i++) {
		int v = e[u][i];
		if (!dfn[v]) {
			tarjan(v, rt);
			low[u] = min(low[u], low[v]);
			if (dfn[u]<=low[v] && u!=rt)cut[u] = 1;
			if (u == rt)child++;
		}
		low[u] = min(low[u], dfn[v]);
	}
	if (child >= 2 && u == rt)cut[u] = 1;
}
int main() {
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 1;i <= m;i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for (int i = 1;i <= n;i++)if (!dfn[i])tarjan(i,i);
	for (int i = 1;i <= n;i++)if (cut[i])ans++;
	cout << ans << endl;
	for (int i = 1;i <= n;i++)if (cut[i])cout << i << " ";
	return 0;
}