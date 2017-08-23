#include<iostream>//Hidden Markov Model
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
using namespace std;
double p1[3][3]={
    {0.5 ,0.375,0.125},
    {0.25,0.125,0.625},
    {0.25,0.375,0.375}
};
double p2[3][4]={
    {0.6 ,0.2 ,0.15,0.05},
    {0.25,0.3,0.2,0.25},
    {0.05,0.10,0.35,0.50}
};
double f[50][5];
int pre[50][5];
map<string,int>mp;
char ans[3][10]={"Sunny","Cloudy","Rainy"};
void print(int i,int j){
	if(i==0)	return;
	print(i-1,pre[i][j]);
	printf("%s\n",ans[j]);
}
int main(){
	mp["Dry"]=0,mp["Dryish"]=1,mp["Damp"]=2,mp["Soggy"]=3;
	int T,n;
	string s;
	cin>>T;
	for(int tt=1;tt<=T;++tt){
		f[1][0]=0.63,f[1][1]=0.17,f[1][2]=0.20;
		printf("Case #%d:\n",tt);
		cin>>n;
		for(int i=1;i<=n;++i){
			cin>>s;
			int k=mp[s];
			for(int j=0;j<3;++j){
				if(i==1)	f[i][j]=log(f[i][j])+log(p2[j][k]);
				else{
					f[i][j]=-1000000.0;
					for(int l=0;l<3;++l){
						if(f[i][j]<f[i-1][l]+log(p1[l][j])+log(p2[j][k])){
							f[i][j]=f[i-1][l]+log(p1[l][j])+log(p2[j][k]);
							pre[i][j]=l;
						}
					}
				}
			}
		}
		int last=0;
		if(f[n][1]>f[n][last])	last=1;
		if(f[n][2]>f[n][last])	last=2;
		print(n,last);
	}
	return 0;
}
