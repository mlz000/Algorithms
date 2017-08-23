#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N=100005;
int n,s,a[N];
int main(){
	while(scanf("%d%d",&n,&s)==2){
		for(int i=1;i<=n;++i){
			scanf("%d",&a[i]);
			if(a[i]>=s){
				printf("1\n");
				continue;
			}
		}
		int h=1,r=2;
		int ans=1000000;
		int now=a[1];
		while(h<r && r<=n){
			if(a[r]>0){
				now+=a[r];
				while(now>=s){
					ans=min(ans,r-h+1);
					now-=a[h];
					h++;
					if(h==r)	break;
				}
				r++;
				continue;
			}
			else{
				h=r+1,r=h+1,now=a[h];
			}
		}
		if(ans==1000000)	printf("0\n");
		else printf("%d\n",ans);
	}
	return 0;
}

