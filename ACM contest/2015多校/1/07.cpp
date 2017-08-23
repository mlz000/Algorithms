#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define F first
#define S second
typedef long long LL;
const int inf = 1000000000;
const int N = 2005, M = 60005;
struct Edge{
	int v, f, nxt;
	Edge(){}
	Edge(int _v, int _f, int _nxt):v(_v), f(_f), nxt(_nxt){}
};
int n, m, id;
Edge e[M * 2 + 10];
int  ans, g[N + 10], val[N];
void add(int u, int v, int f){
      e[++id] = Edge(v, f ,g[u]);
      g[u] = id;
      e[++id] = Edge(u, 0, g[v]);
      g[v] = id;
}
queue <int> que;
bool vis[N + 10];
int  dist[N + 10];
void bfs(){
     memset(dist, 0, sizeof(dist)) ;
     while(!que.empty())	que.pop() ;
     que.push(1);
     vis[1] = 1;
     while(!que.empty()){
          int u = que.front();  que.pop();
          for(int i = g[u]; i; i = e[i].nxt){
               int v = e[i].v ;
               if (e[i].f && !vis[v]) {
                     que.push(v);
                     dist[v] = dist[u] + 1;
                     vis[v] = 1;
               }
          }
     }
}
int dfs(int u , int delta){
	if(u == n) return delta ;
	int ans = 0 ;
	for(int i = g[u] ; i && delta ; i = e[i].nxt){
		int  v = e[i].v ;
		if(e[i].f && dist[v] == dist[u] + 1){
			int d = dfs(v , min(delta , e[i].f)) ;
			e[i].f -= d ;
			e[i^1].f += d ;
			delta -= d ;
			ans += d ;
		}
	}
	return ans ;
}
int  maxflow(){
     int ans = 0 ;
     while(1){
         memset(vis , 0 , sizeof(vis)) ;
         bfs() ;
         if(!vis[n]) return ans  ;
         ans += dfs(1, inf) ;
     }
}
struct E{
       int v , w , c ;
       E(){}
       E(int _v , int _w , int _c):v(_v) , w(_w) , c(_c){}
};
vector<E> lis[N];
bool in[N];
int  mind[N];
void spfa(int s){
      memset(in, 0, sizeof(in)) ;
      memset(mind, 63, sizeof(mind)) ;
      queue<int> q;
      q.push(s);
      in[s] = 1;
      mind[s] = 0;
      while (!q.empty()){
           int u = q.front(); 
		   q.pop();
           in[u] = 0;
           for (int i = 0; i < lis[u].size(); ++i){
               int v = lis[u][i].v;
               int w = lis[u][i].w;
               if (mind[u] + w < mind[v]) {
                    mind[v] = mind[u] + w;
					val[v] = val[u] + 1;
                    if (!in[v]){
                         q.push(v);
						 in[v] = 1;
                    }
               }
			   else if (mind[u] + w == mind[v] && val[v] > val[u] + 1) {
			   		val[v] = val[u] + 1;
			   }
           }
      }
}
int main(){
    while(scanf("%d%d", &n, &m) != EOF){
         memset(g, 0, sizeof(g));
		 memset(val, 0, sizeof(val));
		 id = 1;
		 ans = 0;
         for (int i = 1; i <= n; ++i)	lis[i].clear() ;
		 for (int i = 1; i <= m; ++i) {
			 int u, v, w;
			 scanf("%d%d%d", &u, &v, &w) ;
			 lis[u].push_back(E(v, w, 1)) ;
			 lis[v].push_back(E(u, w, 1)) ;
		 }
         spfa(1);
         for(int u = 1; u <= n; ++u){
              for(int i = 0 ; i < lis[u].size(); ++i){
                 int v = lis[u][i].v ;
                 int w = lis[u][i].w ;
                 int c = lis[u][i].c ;
                 if(mind[u] + w == mind[v])	add(u, v, c);
              }
         }
         printf("%d %d\n", maxflow(), m - val[n]);
    }
    return 0 ;
}

