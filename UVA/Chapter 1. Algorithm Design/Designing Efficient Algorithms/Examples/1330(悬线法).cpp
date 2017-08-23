#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N=1005;
char s[N][N];
int T,n,m,up[N][N],l[N][N],r[N][N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j){
				char ch=getchar();
				while(ch!='R' && ch!='F')	ch=getchar();	
				s[i][j]=ch;
			}
		int ans=0;
		for(int i=0;i<n;++i){
			int lo=-1,ro=m;
			for(int j=0;j<m;++j){
				if(s[i][j]=='R')	up[i][j]=l[i][j]=0,lo=j;
				else{
					up[i][j]=(i==0)?1:up[i-1][j]+1;
					l[i][j]=(i==0)?lo+1:max(l[i-1][j],lo+1);
				}
			}
			for(int j=m-1;j>=0;--j){
				if(s[i][j]=='R')	r[i][j]=m,ro=j;
				else{
					r[i][j]=(i==0)?ro-1:min(r[i-1][j],ro-1);
					ans=max(ans,up[i][j]*(r[i][j]-l[i][j]+1));
				}
			}
		}
		printf("%d\n",ans*3);
	}
	return 0;
}
