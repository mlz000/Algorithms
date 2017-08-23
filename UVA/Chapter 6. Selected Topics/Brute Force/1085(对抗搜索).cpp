#include<cstdio>//¶Ô¿¹ËÑË÷
#include<algorithm>
#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;
const int INF=1000000000,UP=0,FL=1,DO=2;
int n,deck[30];
struct State{
	int card[8],type[8],hold[2],pos,score;
	State child() const{
		State s;
		memcpy(&s,this,sizeof(s));
		s.pos=pos+1;
		return s;
	}
	State(){
		for(int i=0;i<8;++i){
			card[i]=deck[i];
			type[i]=i%2==0?UP:DO;
		}
		hold[0]=hold[1]=score=0;
		pos=8;
	}
	bool isfinal(){
		if(pos==2*n){
			score+=hold[0]+hold[1];
			hold[0]=hold[1]=0;
			return true;
		}
		return false;
	}
	int getscore(int x,int y,int z)	const{
		int tot=abs(x)+abs(y)+abs(z);
		int cnt=0;
		if(x>0)	cnt++;
		if(y>0)	cnt++;
		if(z>0)	cnt++;
		return cnt>=2?tot:-tot;
	}
	void expand(int player,vector<State>& ret)	const{
		int cur=deck[pos];
		if(hold[player]==0){	//1:hold
			State s=child();
			s.hold[player]=cur;
			ret.push_back(s);
		}
		for(int i=0;i<7;++i){	//2:make a floor
			if(type[i]==DO && type[i+1]==UP){//use cur
				State s=child();
				s.score+=getscore(card[i],card[i+1],cur);
				s.type[i]=s.type[i+1]=FL;
				s.card[i]=s.card[i+1]=cur;
				ret.push_back(s);
				if(hold[player]!=0){//use held card
					State s=child();
					s.score+=getscore(card[i],card[i+1],hold[player]);
					s.type[i]=s.type[i+1]=FL;
					s.card[i]=s.card[i+1]=hold[player];
					s.hold[player]=cur;
					ret.push_back(s);
				}
			}
		}
		if(hold[player]!=0){	//3:make a peak
			for(int i=0;i<7;++i){
				if(type[i]==FL && type[i+1]==FL && card[i]==card[i+1]){
					State s=child();
					s.score+=getscore(card[i],hold[player],cur);
					s.type[i]=UP,s.type[i+1]=DO;
					s.card[i]=cur,s.card[i+1]=hold[player];
					s.hold[player]=0;
					ret.push_back(s);
					swap(s.card[i],s.card[i+1]);
					ret.push_back(s);
				}
			}
		}
	}
};
int alphabeta(State& s,int player,int alpha,int beta){
	if(s.isfinal())	return s.score;
	vector<State> children;
	s.expand(player,children);
	int n=children.size();
	for(int i=0;i<n;++i){
		int v=alphabeta(children[i],player^1,alpha,beta);
		if(!player)	alpha=max(alpha,v);
		else beta=min(beta,v);
		if(beta<=alpha)	break;
	}
	return !player?alpha:beta;
}
int main(){
	char s[10];
	int tt=0;
	while(scanf("%s",s)==1 && s[0]!='E'){
		printf("Case %d: ", ++tt);
		scanf("%d",&n);
		for(int i=0;i<n*2;++i){
			char ch;
			scanf("%d%c",&deck[i],&ch);
			if(ch=='B')	deck[i]=-deck[i];
		}
		State init;
		int first=deck[0]>0?0:1;
		int score=alphabeta(init,first,-INF,INF);
		if(s[0]=='B')	score=-score;
		if(score==0)	printf("Axel and Birgit tie\n");
		else if(score>0)	printf("%s wins %d\n", s, score);	
		else printf("%s loses %d\n", s, -score);
	}
	return 0;
}
