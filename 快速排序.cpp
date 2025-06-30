#include<bits/stdc++.h>
using namespace std;
const int L=1e5+10;
int n,a[L];
void sort(int l,int r){
	int i=l,j=r,mid=a[l+r>>1];
	do{
		while(a[i]<mid)i++;
		while(a[j]>mid)j--;
		if(i<=j){
			int t=a[i];a[i]=a[j];a[j]=t;
			i++;j--;
		}
	}while(i<=j);
	if(i<r)sort(i,r);
	if(l<j)sort(l,j);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(1,n);
	for(int i=1;i<=n;i++)printf("%d ",a[i]);
	return 0;
}
