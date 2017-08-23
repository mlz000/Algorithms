#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1000005;
long long a[N];
int main(){
	int T,n;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;++i)	scanf("%I64d",&a[i]);
		int l,r;
		l=1,r=n;
		bool flag=false;
		for(int i=0;i<=n-1;++i){
			while(l<r && !a[l])	++l;
			if(l<=1)	l=1;
			else --l;
			while(l<r && !a[r])	--r;
			if(r>=n-i)	r=n-i;
			else ++r;
			if(l>=r){
				flag=true;
				break;
			}
			int f1=0,f2=0;
			for(int j=l;j<r;++j){
				if(a[j+1]>a[j])	f1=1;
				if(a[j+1]<a[j])	f2=1;
			}
			if(f1 && f2 || (l!=1  && r!=n-i)){
				if(i==0)	printf("ugly series\n");
				else printf("%d\n",i-1);
				break;
			}
			for(int j=l;j<r;++j)	a[j]=a[j+1]-a[j];
			--r;
			if(i==n-1)	flag=true;
		}
		if(flag)	printf("nice series\n");
	}
	return 0;
}
