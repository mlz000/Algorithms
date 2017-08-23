#include<iostream>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e5+5;
double xx,xk,x[N],y;
inline double dis(double x,double y){
	return sqrt(x*x+y*y);
}
double calc1(int l,int r){
	return x[r]-x[l]+min(dis(xx-x[l],y),dis(xx-x[r],y));
}
double calc2(int l,int r){
	return x[r]-x[l]+min(fabs(xk-x[l])+dis(xx-x[r],y),fabs(x[r]-xk)+dis(xx-x[l],y));
}
int main(){
	int n,k,pos;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)	scanf("%lf",&x[i]);
	scanf("%lf",&xx);
	xk=x[k];
	sort(x+1,x+n+1);
	scanf("%lf",&y);
	double ans=1e15;
	if(k==n+1)	ans=min(ans,calc1(1,n));
	else{
		ans=calc2(1,n);
		for(int i=2;i<=n;++i){
			ans=min(ans,min(calc1(1,i-1)+calc2(i,n),calc2(1,i-1)+calc1(i,n)));
		}
	}
	printf("%.10lf\n",ans);
	return 0;
}
