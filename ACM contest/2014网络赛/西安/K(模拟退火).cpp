#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const double INF=1e60,eps=1e-9,r=0.99;
double a,b,c,d,e,f;
int dx[]={1,1,1,0,0,-1,-1,-1};
int dy[]={1,0,-1,1,-1,1,0,-1};
double dis(double x,double y,double z){
	return x*x+y*y+z*z;
}
double work(double x,double y){
	double C=a*x*x+b*y*y+f*x*y-1.0;
	double A=c,B=d*y+e*x;
	double delta=B*B-4*A*C;
	if(delta<0)	return INF;
	double z1=(-B+sqrt(delta))/2.0/A;
	double z2=(-B-sqrt(delta))/2.0/A;
	return z1*z1<z2*z2?z1:z2;
}
double solve(){
	double step=1.0;
	double x=0.0,y=0.0,z;
	for(;step>eps;step*=r){
		z=work(x,y);
		for(int i=0;i<8;++i){
			double tx=x+step*dx[i];
			double ty=y+step*dy[i];
			double tz=work(tx,ty);
			if(tz>1e30)	continue;
			if(dis(tx,ty,tz)<dis(x,y,z)){
				x=tx;y=ty;z=tz;
			}
		}
	}
	return dis(x,y,z);
}
int main(){
	while(scanf("%lf%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e,&f)!=EOF){
		double ans;
		ans=solve();
		printf("%.8lf\n",sqrt(ans));
	}
	return 0;
}
