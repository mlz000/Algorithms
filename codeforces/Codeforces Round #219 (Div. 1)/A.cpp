#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int N=500005;
int n,a[N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)	scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int l=1,r=n/2+1;
	int tot=0;
	while(l<=n/2 && r<=n){
		while(r<=n && a[l]*2>a[r])	r++;
		if(r<=n)	tot++,r++;
		l++;
	}
	printf("%d\n",n-tot);
	return 0;
}
