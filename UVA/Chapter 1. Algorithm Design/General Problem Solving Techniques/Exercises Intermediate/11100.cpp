#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=10005;
int n,a[N],b[N*10];
int main(){
	while(scanf("%d",&n)&&n){
		memset(b,0,sizeof(b));
		int tot=0;
		for(int i=1;i<=n;++i)	scanf("%d",&a[i]),b[a[i]]++,tot=max(tot,b[a[i]]);
		printf("%d\n",tot);
		sort(a+1,a+1+n);
		int now=1;
		for(int i=1;i<=tot;++i){
			for(int j=i;j<=n;j+=tot){
				printf("%d",a[j]);
				if(j+tot<=n)	printf(" ");
			}
			printf("\n");
		}
 	}
	return 0;
}
