#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
char s1[20],s2[20];
int T,cnt1[20],cnt2[20],s,d1,d2,t,f,l1,l2;
bool check(int tot){
	for(int i=1;i<=15;++i){
		if(cnt1[i]>=4 && (tot==4 || i>=f))	return true;
	}
	for(int i=1;i<=15;++i){
		if(cnt1[i] && (tot==1 || (i>=s && !f)))	return true;
		if(cnt1[i]>=2 && (tot==2 || (i>=d1 && !f)))	return true;
		if(cnt1[i]>=3 && (tot==3 || (i>=t && !f)))	return true;
		if(cnt1[i]>=3){
			if(tot==4)	return true;
			if(l2<4 && l1>=4)	return true;
			if(l1>=4 && i>=t && !f)	return true;
		}
		if(cnt1[i]>=3){
			for(int j=1;j<=15;++j){
				if(i==j)	continue;
				if(cnt1[j]>=2){
					if(tot==5)	return true;
					if(l1>=5 && l2<5 && !f)	return true;
					if(l1>=5 && (i>t || (i<t && !d2)) && !f)	return true;
				}
			}
		}
		if(cnt1[i]>=4){
			if(tot==6)	return true;
			if(l1>=6 && l2<6 && !f)	return true;
		}
	}
	return false;
}
int main(){
	scanf("%d",&T);
	while(T--){
		s=d1=d2=t=f=0;
		memset(cnt1,0,sizeof(cnt1));
		memset(cnt2,0,sizeof(cnt2));
		scanf("%s",s1);	
		scanf("%s",s2);
		l1=strlen(s1);
		l2=strlen(s2);
		for(int i=0;i<l1;++i){
			if(s1[i]=='T')	cnt1[8]++;
			else if(s1[i]=='J')	cnt1[9]++;
			else if(s1[i]=='Q')	cnt1[10]++;
			else if(s1[i]=='K')	cnt1[11]++;
			else if(s1[i]=='A')	cnt1[12]++;
			else if(s1[i]=='2')	cnt1[13]++;
			else if(s1[i]=='X')	cnt1[14]++;
			else if(s1[i]=='Y')	cnt1[15]++;
			else cnt1[s1[i]-'0'-2]++;
		}
		for(int i=0;i<l2;++i){
			if(s2[i]=='T')	cnt2[8]++;
			else if(s2[i]=='J')	cnt2[9]++;
			else if(s2[i]=='Q')	cnt2[10]++;
			else if(s2[i]=='K')	cnt2[11]++;
			else if(s2[i]=='A')	cnt2[12]++;
			else if(s2[i]=='2')	cnt2[13]++;
			else if(s2[i]=='X')	cnt2[14]++;
			else if(s2[i]=='Y')	cnt2[15]++;
			else cnt2[s2[i]-'0'-2]++;
		}
		for(int i=15;i>=1;--i){
			if(cnt2[i]>=4)	f=max(f,i);
			if(cnt2[i]>=3)	t=max(t,i);
			if(cnt2[i]>=2){
				d2=max(d2,i);
				if(d1<d2)	swap(d1,d2);
			}
			if(cnt2[i])	s=max(s,i);
		}
		if(d1==d2)	d2=0;
		if(cnt2[14]==1 && cnt2[15]==1){
			f=100;
		}
		if(cnt1[14]==1 && cnt1[15]==1){
			printf("Yes\n");
			continue;
		}
		if(check(l1))	printf("Yes\n");
		else printf("No\n");

	}
	return 0;
}
