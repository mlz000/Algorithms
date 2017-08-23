#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int T, now;
unsigned X; // we assume that unsigned is a 32bit integer type
bool f[34];
void srand1(unsigned S){
  X = S;
}

unsigned nextInteger1(void){
  X = X * 1103515245 + 12345;
  return (X / 65536) % 32768;
}

int generator1(){
  return nextInteger1() % 2; 
}
struct Trie{
	int ch[N * 40][2];
	int w[N * 40];
	int sz;
	void clear()	{sz=1,memset(ch[0],0,sizeof(ch[0]));}
	int idx(char c)	{return c-'0';}
	void insert(char *s,int v){
		int u=0,n=strlen(s);
		for(int i=0;i<n;++i){
			int c=idx(s[i]);
			if(!ch[u][c]){
				memset(ch[sz],0,sizeof(ch[sz]));
				w[sz]=0;
				ch[u][c]=sz++;
			}
			u=ch[u][c];
		}
		w[u]=v;
	}
	void find(){
		int u=0;
		while (1){
			int c = generator1();
			if(!ch[u][c])	break;
			u=ch[u][c];
			if(w[u])	{f[w[u]] = 1, ++now;break;}
		}
	}
}trie;
char s[N];
int main() {
	trie.clear();
	scanf("%d", &T);
	for (int i = 1; i <= T; ++i) {
		scanf("%s", s);
		trie.insert(s, i);
	}
	for (long long i = 0; ; ++i) {
		srand1(i);
		trie.find();
		if (now == T)	break;
	}
	for (int i = 1; i <= T; ++i) {
		printf("%s\n", f[i] ? "LCG" : "Xorshift");
	}
	return 0;
}
