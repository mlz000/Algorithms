#include<cstdio>
#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;
const int N=505;
int n,p[N];
long long f[N][N];
int main(){
	while(cin>>n){
		for(int i=0;i<=n;++i)	cin>>p[i];
		for(int i=1;i<=n;++i)	f[i][i]=0;
		for(int l=2;l<=n;++l)
			for(int i=1;i<=n-l+1;++i){
				int j=i+l-1;
				f[i][j]=INT_MAX;
				for(int k=i;k<j;++k)	f[i][j]=min(f[i][j],f[i][k]+f[k+1][j]+p[i-1]*p[j]*p[k]);
			}
			cout<<f[1][n]<<endl;
	}
	return 0;
}
