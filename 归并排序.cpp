#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll a[600000], b[600000], ans;
void mergee(ll l, ll r) {
	if (l >= r) {  //不能再分了，直接返回。
		return ;
	}
	ll mid = (l + r) / 2;//取一个中间值
	ll i = l, j = mid + 1, tot = l;  // i是第一个序列的开头，j是第二个序列的开头，tot是整个的大序列。
	while (i <= mid && j <= r) {  //合并
		if (a[i] <= a[j]) {  //谁小就把谁放到前面。
			b[tot++] = a[i]; 
			i++;
		} else {
			b[tot++] = a[j];
			j++;
		}
	}
	while (i <= mid) {  //可能还没有放完，就把剩下的放进来。
		b[tot++] = a[i];
		i++;
	}
	while (j <= r) {  // 同上
		b[tot++] = a[j];
		j++;
	}
	for (int i = l; i <= r; i++) {  // 给最终的答案数组赋值。
		a[i] = b[i];
	}
	return;
}
void mergesort(ll l, ll r) {
	if (l < r) {
		int mid = (l + r) / 2;
		mergesort(l, mid);  //  先给左子序列排序。
		mergesort(mid + 1, r); //再给右子序列排序。
		mergee(l, r);  // 最后把两个子序列合并。
	}
}
int main() {
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	ll n;
	cin>>n;
	for (int i = 1; i <= n; i++) {
		cin>>a[i];
	}
	mergesort(1, n);
	for (int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
	return 0;
}
