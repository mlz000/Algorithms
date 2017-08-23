#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5,M=1e9+7;
string s,q[N];
ll add[10],shift[10]; 
int main(){
	int n;
	cin>>s>>n;
	for(int i=0;i<10;++i){
		add[i]=i;
		shift[i]=10;
	}
	for(int i=0;i<n;++i)	cin>>q[i];
	for(int i=n-1;i>=0;--i){
		ll ta=0,ts=1;		
		for(int j=q[i].size()-1;j>=3;--j){
			ta=(ta+add[q[i][j]-'0']*ts)%M;
			ts=shift[q[i][j]-'0']*ts%M;
		}
		int x=q[i][0]-'0';
		add[x]=ta;
		shift[x]=ts;
	}
	ll ans=0ll;
	for(int i=0;i<s.size();++i)	ans=(ans*shift[s[i]-'0']+add[s[i]-'0'])%M;
	cout<<ans<<endl;
	return 0;
}
