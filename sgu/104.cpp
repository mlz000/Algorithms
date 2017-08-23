#include <bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,a[N][N],f[N][N],p[N][N],ans[N];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)	
			cin>>a[i][j];
	memset(f,0x80,sizeof(f));
	f[0][0]=0;
	for(int i=1;i<=n;++i)
		for(int j=i;j<=m;++j)
			for(int k=i-1;k<j;++k)
				if(f[i-1][k]+a[i][j]>f[i][j]){
					f[i][j]=f[i-1][k]+a[i][j];
					p[i][j]=k;
				}
	int tot=INT_MIN,ed;
	for(int i=n;i<=m;++i)	
		if(f[n][i]>tot){
			tot=f[n][i];
			ed=i;
		}
	for(int i=n;i>=1;--i){
		ans[i]=ed;
		ed=p[i][ed];
	}
	cout<<tot<<endl;
	for(int i=1;i<=n;++i)	cout<<ans[i]<<' ';
	return 0;
}
