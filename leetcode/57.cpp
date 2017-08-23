#define pb push_back
#define S start
#define E end
class Solution {
public:
    vector<Interval> ans;
    vector<Interval> insert(vector<Interval>& a, Interval b) {
        bool f = 0;
        if (a.size() == 0) {
            ans.pb(b);
            return ans;
        }
        for(auto x : a){
	    	if (f)  ans.pb(x);
	    	else if(b.E < x.S) {
	    	    f = 1;
	    	    ans.pb(b), ans.pb(x);
	    	}
	    	else if(b.S > x.E)  ans.pb(x); 
            else{
                b.S = min(b.S, x.S);
                b.E = max(b.E, x.E);
            }	
        }
        if (!f) ans.pb(b);
	    return ans;
     }
};