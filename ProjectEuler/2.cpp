#include<bits/stdc++.h>//4613732
using namespace std;
int f[50005];
int main(){
	f[0]=f[1]=1;
	long long ans=0ll;
	for(int i=2;;++i){
		f[i]=f[i-1]+f[i-2];
		if(f[i]>4000000)	break;
		if(f[i]%2==0)	ans+=f[i];
	}
	cout<<ans<<endl;
	return 0;
}
