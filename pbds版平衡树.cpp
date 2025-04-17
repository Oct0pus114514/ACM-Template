#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
const int L=1e7+10;
int m,cnt[2*L];
tree<int,null_type,std::less<int>,rb_tree_tag,tree_order_statistics_node_update> rbt;//第三个参数可以使用splay_tree_tag 
int main(){
	scanf("%d",&m);
	while(m--){
		int op,x;
		scanf("%d%d",&op,&x);
		x+=(L-10);
		switch(op){
			case 1:rbt.insert(x);break;
			case 2:rbt.erase(x);break;//删一个等于全删 
			case 3:printf("%d\n",rbt.order_of_key(x)+1);break;
			case 4:printf("%d\n",*rbt.find_by_order(x-1));break; 
//			case 5:printf("%d\n",*(--rbt.lower_bound(x)));break;
//			case 6:printf("%d\n",*rbt.upper_bound(x));break;
		}
	}
	return 0;
}
