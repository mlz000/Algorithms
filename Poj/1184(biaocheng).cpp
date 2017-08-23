# include <stdio.h>
# include <stdbool.h>
typedef struct
{
        int data;
        int last;
        int step;
        bool find;
}node;
node q[100000];
int h=0,r=0,st,e,std[7];
int max(int x,int y)
{
    return x>y?x:y;
}
int min(int x,int y)
{
    return x<y?x:y;
}
bool empty()
{
     return h==r?1:0;
}
node pop()
{
     h=(++h)%100000;
     return q[h];
}
void push(node pos)
{
     r=(++r)%100000;
     q[r]=pos;
}
bool used[10000000];
void change1(node *pos)
{
     int s[7];
     int i,num=pos->data/10;
     for(i=6;i>=1;i--)
     {
        s[i]=num%10;
        num/=10;
     }
     int temp=s[1];
     s[1]=s[pos->data%10];
     s[pos->data%10]=temp;
     num=0;
     for(i=1;i<=6;i++)
        num=num*10+s[i];
     pos->data=num*10+pos->data%10;
}
void change2(node *pos)
{
     int s[7];
     int i,num=pos->data/10;
     for(i=6;i>=1;i--)
     {
        s[i]=num%10;
        num/=10;
     }
     int temp=s[6];
     s[6]=s[pos->data%10];
     s[pos->data%10]=temp;
     num=0;
     for(i=1;i<=6;i++)
        num=num*10+s[i];
     pos->data=num*10+pos->data%10;
     pos->find=1;
}
int cal(node pos)
{
    int s[7],total=0;
     int i,num=pos.data/10;
     for(i=6;i>=1;i--)
     {
        s[i]=num%10;
        num/=10;
     }
     if(!pos.find)
     {
        for(i=1;i<=6;i++)
          if(s[i]!=std[i])
            {
               if(i>pos.last) return 999999;
               total+=abs(s[i]-std[i]);
            }
        return total;
     }
     else
     {
         for(i=1;i<6;i++)
          if(s[i]!=std[i])
            {
               if(i>pos.last) return 999999;
               total+=abs(s[i]-std[i]);
            }
        total+=abs(s[6]-std[6]);
        return total;
     }
}
int main()
{
    int i;
    scanf("%d %d",&st,&e);
    for(i=6;i>=1;i--) 
           std[i]=e%10,e/=10;
    node now,pos;
    int up=9999999;
    now.data=st*10+1;
    now.find=0;
    now.last=1;
    now.step=0;
    used[now.data]=1;
    push(now);
    up=min(cal(now),up);
    while(!empty())
    {
      pos=pop();
      if(pos.step>=up) break;
      int p=pos.data%10;
      if(p!=1)
      {
          now=pos;
          now.step++;
          now.data--;
          if(!used[now.data]) 
          {
              push(now);
              used[now.data]=1;
          }
          now=pos;
          now.step++;
          change1(&now);
          if(!used[now.data]) 
          {
              push(now);
              used[now.data]=1;
              up=min(cal(now)+now.step,up);
          }
      }
      if(p!=6)
      {
          now=pos;
          now.step++;
          now.data++;
          now.last=max(now.last,now.data%10);
          if(!used[now.data]) 
          {
              push(now);
              used[now.data]=1;
              up=min(cal(now)+now.step,up);
          }
          now=pos;
          now.step++;
          change2(&now);
          if(!used[now.data]) 
          {
              push(now);
              used[now.data]=1;
              up=min(cal(now)+now.step,up);
          }
      }
    }
    printf("%d\n",up);
    
}
