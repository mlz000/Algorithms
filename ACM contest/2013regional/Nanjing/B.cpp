#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const double eps=1e-5;
double a[15];
int main(){
	double x,y;
	while(scanf("%lf%lf",&x,&y)!=EOF){
		int ans=(int)(x-1);
		y-=x-1+eps;
		if(y<0)	{printf("-1\n");continue;}
		for(int i=1;i<=x;++i)	a[i]=x/i;
		for(int i=1;i<=x;++i){
			int n=(int)(y/a[i]);
			ans+=n;
			y-=n*a[i];
			if(y<1)	break;
		}
		printf("%d\n",ans);
	}
	return 0;
}
