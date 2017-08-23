#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N=25;
int T,A,B,C;
long long s[N][N][N];
void expand(int f,int &x,int &y,int &z){
	x=f&1;f>>=1;
	y=f&1;f>>=1;
	z=f&1;
}
int sgn(int x,int y,int z){
	return (x+y+z)%2==1?1:-1;
}
long long sum(int x1,int x2,int y1,int y2,int z1,int z2){
	int dx=x2-x1+1,dy=y2-y1+1,dz=z2-z1+1;
	long long tmp=0ll;
	for(int i=0;i<=7;++i){
		int x,y,z;
		expand(i,x,y,z);
		tmp-=s[x2-x*dx][y2-y*dy][z2-z*dz]*sgn(x,y,z);
	}
	return tmp;
}
int main(){
	scanf("%d",&T);
	while(T--){
		memset(s,0,sizeof(s));
		scanf("%d%d%d",&A,&B,&C);
		for(int i=1;i<=A;++i)
			for(int j=1;j<=B;++j)
				for(int k=1;k<=C;++k)
					scanf("%lld",&s[i][j][k]);
		int x,y,z;
		for(int i=1;i<=A;++i)
			for(int j=1;j<=B;++j)
				for(int k=1;k<=C;++k)
					for(int f=1;f<=7;++f){
						expand(f,x,y,z);
						s[i][j][k]+=s[i-x][j-y][k-z]*sgn(x,y,z);
					}
		long long ans=-(1ll<<60);
		for(int x1=1;x1<=A;++x1)
			for(int x2=x1;x2<=A;++x2)
				for(int y1=1;y1<=B;++y1)
					for(int y2=y1;y2<=B;++y2){
						long long M=0ll;
						for(int z=1;z<=C;++z){
							long long s=sum(x1,x2,y1,y2,1,z);
							ans=max(ans,s-M);
							M=min(M,s);
						}
					}
		printf("%lld\n",ans);
		if(T)	printf("\n");
	}
	return 0;
}
