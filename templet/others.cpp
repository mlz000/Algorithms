//表达式计算
string s,l,w;
const int N=105;
char ch[N];
int num[N];
int cnt1[10],cnt2[10];//栈外 栈内 
int get(char a){
    if (a=='+') return 1;
    if (a=='-') return 2;
    if (a=='*') return 3;
    if (a=='/') return 4;
    if (a=='^') return 5;
    if (a=='(') return 6;
    if (a==')') return 0;
}
void solve(){
     int i,j,t,in,out;
     char now;
     int t1,t2;
	 t1=t2=0;
     memset(ch,0,sizeof(ch));
     memset(num,0,sizeof(num));
     s=w;
     s+=")";
     ch[++t2]='(';
     int len=s.length();
     for(i=0;i<len;++i)
        if(s[i]>='0' && s[i]<='9'){
	     j=i;
		 t=0;
		 while(j<len && s[j]>='0' && s[j]<='9'){
		   t=t*10;
		   t+=s[j]-'0';
		   j++;
		 } 
		 i=j-1;
		 num[++t1]=t;
	  }
	  else{
	      in=get(ch[t2]);
	      out=get(s[i]);
	      if(out==0){//右括号 
	         while(t2>0 && (ch[t2]!='(')){ //寻找左括号
			    now=ch[t2--];
				int b=num[t1--];
				int a=num[t1--];
				if(now=='+') a+=b;
				if(now=='-') a-=b;
				if(now=='*') a*=b;
				if(now=='/') a/=b;
				if(now=='^'){
				  t=1;
				  for(j=1;j<=b;++j)
				   t=t*a;
				  a=t;
				} 
				num[++t1]=a;
			 }
			 t2--; 
		  }  
	      else if(cnt1[out]<=cnt2[in]){
			while(t2>0 && cnt1[out]<=cnt2[in]){ //栈外比栈内优先级低 
			    now=ch[t2--];
				int b=num[t1--];
				int a=num[t1--];
				if(now=='+') a+=b;
				if(now=='-') a-=b;
				if(now=='*') a*=b;
				if(now=='/') a/=b;
				if(now=='^'){
				  t=1;
				  for(j=1;j<=b;++j)
				   t=t*a;
				  a=t;
				} 
				num[++t1]=a;
				in=get(ch[t2]); 
			 }
		    ch[++t2]=s[i];
		  }
	      else if(cnt1[out]>cnt2[in]) ch[++t2]=s[i];//入栈 
	  }
      printf("%d",num[1]);
}
int main(){ 
	 int i,len;
	 cin>>s;
	 l="0";//正负号前加前导0 
	 len=s.length();
	 for(i=0;i<len;++i){
	   if(((i==0)&&((s[i]=='+')||(s[i]=='-')))||((i>=1)&&(s[i-1]=='(')&&((s[i]=='+')||(s[i]=='-')))){
	      w+=l;
	      w+=s[i];
	   }
	   else w+=s[i];
	 } 
	 cnt1[1]=cnt2[1]=cnt1[2]=cnt2[2]=1;
	 cnt1[3]=cnt2[3]=cnt1[4]=cnt2[4]=2;
	 cnt1[5]=4;cnt2[5]=3;//^特殊，先算栈内 
	 cnt1[6]=5;cnt2[6]=0;//无条件加入左括号 
	 solve();
	 return 0; 
} 
//maxflow
const int N=205;
int f[N][N];
int h[N],d[N],dis[N],v[N],p[N];
int map[N][N];
int nn,n,P,t;
int i,j,k;
bool flag;
struct data{
      int u;
      int v;
      int w;
}edge[N*N];
int isap(){
	  memset(h,0,sizeof(h));
	  memset(dis,0,sizeof(dis));
	  memset(v,0,sizeof(v));
	  memset(p,0,sizeof(p));
	  int flow=0;
      for(i=0;i<n;++i)
	   d[i]=0;
	   i=0;
	   v[0]=n;//gap优化 
	  int aug=INT_MAX;
	  while(dis[0]<n){
	     flag=false;
	     h[i]=aug;
	     for(j=d[i];j<n;++j){
		   if(map[i][j]>0 && dis[j]+1==dis[i]){
		       flag=true;
		       d[i]=j;
		       if(map[i][j]<aug) aug=map[i][j];
               p[j]=i;
		       i=j;
		       if(i==n-1){
			      flow+=aug;
				  for(i=n-1;i!=0;i=p[i]){
				    map[p[i]][i]-=aug;
				    map[i][p[i]]+=aug;
				  }
				  aug=INT_MAX;
			   }
			   break;
		   }
		 }
	     if(flag) continue;
	     int MIN=n-1;
	     for(j=0;j<n;++j)
            if(map[i][j]>0 && dis[j]<MIN){
               MIN=dis[j];
               k=j;
             }
         d[i]=k;
		 v[dis[i]]--;
		 if(v[dis[i]]==0) break;
		 dis[i]=MIN+1;//gap 
		 v[dis[i]]++;
	     if(i!=0) {i=p[i];aug=h[i];}
	  }
      return flow;
}
void init(int x){
    memset(map,0,sizeof(map));
     for(i=1;i<=P;++i)
       if(edge[i].w<=x){
			map[edge[i].u][edge[i].v]++;
			map[edge[i].v][edge[i].u]++;
	  }
	  map[0][1]=10000;
	  map[nn][nn+1]=10000;
}
int main(){
	  n=nn+2;//共n个点
      Isap();
      printf("%d\n",best);
     return 0;
}
//mincost
struct edge{
    int u,v,next,f,w;
}e[40010];
int n,m;
int mincost=0;
int p[2000],d[2000];
int num=0;
int first[2000];
int i,j,s,t,x;
bool ok[2000];
void add(int u,int v,int f,int w){
     e[num].u=u;
     e[num].v=v;
     e[num].f=f;
     e[num].w=w;
     e[num].next=first[u];
     first[u]=num++;
}
void addedge(int u,int v,int f,int w){
    add(u,v,f,w);
    add(v,u,0,-w);
}
int spfa(){
     queue<int>q;
     for(i=0;i<=n+1;++i)
     d[i]=INT_MAX;
     q.push(s);
     d[s]=0;
     p[s]=-1;
     while(!q.empty()){
          i=q.front();
          q.pop();
          ok[i]=false;
          for(j=first[i];j!=-1;j=e[j].next){
               if(e[j].f>0 && d[i]+e[j].w<d[e[j].v]){
                  d[e[j].v]=d[i]+e[j].w;
                  p[e[j].v]=j;
                  if(!ok[e[j].v])
                  {
                      q.push(e[j].v);
                      ok[e[j].v]=true;
                  }
              }
           }
    }
    if(d[t]<INT_MAX)
     return 1;
     else return 0;
}
void solve(){
    int flow=INT_MAX;
    for(i=p[t];i!=-1;i=p[e[i].u]){
        if(flow>e[i].f) flow=e[i].f;
    }
    for(i=p[t];i!=-1;i=p[e[i].u]){
        e[i].f-=flow;
        e[i^1].f+=flow;
    }
    mincost+=d[t]*flow;
}
int main(){
    memset(first,-1,sizeof(first));
    int a,b,w;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;++i){
       scanf("%d%d%d",&a,&b,&w);
       addedge(a,b,1,w);
       addedge(b,a,1,w);
    }
       s=0;t=n+1;
       addedge(s,1,2,0);
       addedge(n,t,2,0);
       while(spfa()) solve();
       printf("%d\n",mincost);
    return 0;
}




