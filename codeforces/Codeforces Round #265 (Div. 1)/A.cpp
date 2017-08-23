#include<bits/stdc++.h>
char s[1005];
int main(){
	int n,p;
	scanf("%d%d%s",&n,&p,s);
	int pos=n-1;
	++s[pos];
	while(pos>=0 && pos<n){
		if(s[pos]-'a'>=p){
			s[pos--]='a';
			if(pos>=0)	++s[pos];
		}
		else if(pos>0 && s[pos]==s[pos-1])	++s[pos];
		else if(pos>1 && s[pos]==s[pos-2])	++s[pos];
		else ++pos;
	}
	if(pos<0)	puts("NO");
	else printf("%s\n",s);
	return 0;
}
