int spfa(){
     queue<int> q;
     for (int i = 0; i <= n + 1; ++i)
     d[i] = INT_MAX;
     q.push(s);
     d[s] = 0;
     p[s] = -1;
     while(!q.empty()){
          i = q.front();
          q.pop();
          ok[i] = false;
          for(j = first[i]; j != -1; j = e[j].next){
               if(e[j].f > 0 && d[i] + e[j].w < d[e[j].v]){
                  d[e[j].v] = d[i] + e[j].w;
                  p[e[j].v] = j;
                  if(!ok[e[j].v]) {
                      q.push(e[j].v);
                      ok[e[j].v]=  true;
                  }
              }
           }
    }
    if(d[t] < INT_MAX)
    return 1;
     else return 0;
}
void solve(){
    int flow = INT_MAX;
    for (i = p[t]; i!=-1; i = p[e[i].u]){
        if(flow > e[i].f) flow = e[i].f;
    }
    for (i = p[t];i !=-1; i = p[e[i].u]){
        e[i].f -= flow;
        e[i^1].f += flow;
    }
    mincost += d[t] * flow;
}
