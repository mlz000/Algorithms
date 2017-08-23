#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1005;
int n,a[N],b[N];
int main(){
	while(scanf("%d",&n)&&n){
		for(int i=1;i<=n;++i)	scanf("%d",&a[i]);
		for(int i=1;i<=n;++i)	scanf("%d",&b[i]);
		sort(a+1,a+n+1);
		sort(b+1,b+n+1);
		int l1=1,r1=n,l2=1,r2=n;
		int win=0,lose=0;
		while(l1<=r1 && l2<=r2){
			if(a[l1]<b[l2])	++lose,++l1,--r2;
			else if(a[l1]>b[l2])	++win,++l1,++l2;
			else{
				if(a[r1]>b[r2])	++win,--r1,--r2;
				else if(a[r1]<b[r2])	++lose,++l1,--r2;
				else{
					if(a[l1]<b[r2])	++lose;
					++l1,--r2;
				}
			}
		}
		printf("%d\n",(win-lose)*200);
	}
	return 0;
}
				
