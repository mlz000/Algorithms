#include<iostream>
#include<cstring>
#include<cstdio>
#include<bitset>
#include<algorithm>
using namespace std;
const int N=805;
bitset<N>h[3][N],r[3][N];
int main(){
	int n;
	while(~scanf("%d",&n)){
		int x;
		for(int i=1;i<3;++i)
			for(int j=0;j<n;++j)
				for(int k=0;k<n;++k)
					h[i][j].reset(k),r[i][k].reset(j);
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j){
				scanf("%d",&x);
				x%=3;
				h[x][i].set(j);
			}
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j){
				scanf("%d",&x);
				x%=3;
				r[x][j].set(i);
			}
		for(int i=0;i<n;++i)
			for(int j=0;j<n;++j){
				int sum=0;
				sum+=(h[1][i]&r[1][j]).count();
				sum+=(h[2][i]&r[1][j]).count()*2;
				sum+=(h[1][i]&r[2][j]).count()*2;
				sum+=(h[2][i]&r[2][j]).count();
				sum%=3;
				if(j==n-1)	printf("%d\n",sum);
				else printf("%d ",sum);
			}
	}
	return 0;
}
