#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1000005;
int n;
long long f[N];
int main(){
	for(long long x=4;x<=1000000;++x)	f[x]=f[x-1]+((x-1)*(x-2)/2-(x-1)/2)/2;
	while(cin>>n){
		if(n<3)	break;
		cout<<f[n]<<endl;
	}
	return 0;
}
