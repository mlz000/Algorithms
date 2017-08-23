#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int N=1<<11;
int n,top,ep2[15],lg2[N],a[20];
void init(){
     for(int i=0;i<15;++i){
         ep2[i] =  1 << i;
     }
     int t = 0;
     for(int i=0;i<N;++i){
         if (ep2[t + 1] <= i) t++;
         lg2[i] = t;
     }
}
bool dfs(int num,int tot){
	if(a[top]==num)	return true;
	if(top>=tot)	return false;
	int last=a[top];
	if((last<<(tot-top))<n)	return false;
	for(int i=0;i<=top;++i){
		top++;
		a[top]=a[top-1]+a[i];
		if(dfs(num,tot))	return true;
		a[top]=a[top-1]-a[i];
		if(a[top]>1 && dfs(num,tot))	return true;
		top--;
	}
	return false;
}
int main(){
	init();
	while(scanf("%d",&n)&&n){
		int step=lg2[n];
		while(step<=12){
			a[top=0]=1;
			if(dfs(n,step))	break;
			step++;
		}
		printf("%d\n",step);
	}
	return 0;
}
