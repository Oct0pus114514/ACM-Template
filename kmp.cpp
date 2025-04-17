#include<bits/stdc++.h>
using namespace std;
const int L=2e6+10;
int pi[L];
string s,s1,s2;
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>s1>>s2;
	int l1=s1.size(),l2=s2.size();
	s=s2+"#"+s1;
	int j=0;
	for(int i=1;i<s.size();i++){
		while(j && s[i]!=s[j])j=pi[j];
		if(s[i]==s[j])j++;
		pi[i+1]=j;
	}
	for(int i=1;i<=s.size();i++)if(pi[i]==l2)cout<<i-2*l2<<endl;
	memset(pi,0,sizeof(pi));
	j=0;
	for(int i=1;i<s2.size();i++){
		while(j && s2[i]!=s2[j])j=pi[j];
		if(s2[i]==s2[j])j++;
		pi[i+1]=j;
	}
	for(int i=1;i<=s2.size();i++)cout<<pi[i]<<" ";
	return 0;
}