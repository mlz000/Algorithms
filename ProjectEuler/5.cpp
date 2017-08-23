#include<bits/stdc++.h>//232792560
using namespace std;
int cnt[20];
int p[8]={2,3,5,7,11,13,17,19};
int main(){
	for(int i=2;i<=20;++i){
		int t=i;
		for(int j=0;j<8;++j){
			int now=0;
			while(t && t%p[j]==0)	now++,t/=p[j];
			cnt[j]=max(now,cnt[j]);
		}
	}
	int ans=1;
	for(int i=0;i<8;++i)
		for(int j=1;j<=cnt[i];++j)
			ans*=p[i];
	cout<<ans<<endl;
	return 0;
}
