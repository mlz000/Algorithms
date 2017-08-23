#include<vector>  
#include<cstdio>  
#include<cstring>  
#include<iostream>  
#include<algorithm>  
using namespace std;  
  
const int MAXN = 30010;  
  
int n , m;  
int num[MAXN];  
  
void solve(){  
    vector<int>v;  
    vector<int>::iterator it;  
    v.clear();  
    int x , pos = 0;  
    int index = 0;  
    while(m--){  
         scanf("%d" , &x);   
         while(v.size() != x){  
              it = lower_bound(v.begin() , v.end() , num[pos]);   
              v.insert(it , num[pos++]);  
         }   
         printf("%d\n" , v[index++]);  
    }  
}  
  
int main(){  
    int Case;  
    bool first = true;  
    scanf("%d" , &Case);  
    while(Case--){  
        scanf("%d%d" , &n , &m);      
        if(first)   
            first = false;  
        else  
            puts("");  
        for(int i = 0 ; i < n ; i++)  
            scanf("%d" , &num[i]);  
        solve();  
    }  
    return 0;  
}  

