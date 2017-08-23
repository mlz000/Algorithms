#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1000005;
char s[N];
int main(){
	scanf("%s",s);
	int l=strlen(s);
	int pos;
	long long le=0ll,ri=0ll;
	for(int i=0;i<l;++i)	if(s[i]=='^')	{pos=i;break;}
	for(int i=0;i<pos;++i)	if(s[i]>='1' && s[i]<='9')	le+=(s[i]-'0')*(pos-i);
	for(int i=pos+1;i<l;++i)	if(s[i]>='1' && s[i]<='9')	ri+=(s[i]-'0')*(i-pos);
	if(le==ri)	printf("balance\n");
	else if(le>ri)	printf("left\n");
	else printf("right\n");
	return 0;
}
