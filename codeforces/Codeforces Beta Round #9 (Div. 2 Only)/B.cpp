#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int n,i,m;
double r,vb,vs,mt,t,x,y,a[100];
int main () 
{
	scanf("%d%lf%lf",&n,&vb,&vs);
	for (i=0; i<n; i++) scanf("%lf",&a[i]);
	scanf("%lf%lf",&x,&y);
	mt=2000000;
	for (i=1; i<n; i++){
		t=a[i]/vb+sqrt(pow(x-a[i],2)+pow(y,2))/vs;
		if (t<mt || (mt==t && r>sqrt(pow(x-a[i],2)+pow(y,2))/vs)) { 
			mt=t; 
			m=i;
			r=sqrt(pow(x-a[i],2)+pow(y,2))/vs;
		}
	}
	printf("%d\n",m+1);
	return 0;
}

