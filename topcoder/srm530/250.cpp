#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii; 
class GogoXCake { 
public: 
   string solve( vector <string> cake, vector <string> cutter ) { 
     int m = cutter.size(), n = cutter[0].size(); 
     for (int i = 0; i + m <= cake.size(); ++i) {	 	
	 	for (int j = 0; j + n <= cake[0].size(); ++j) { 
        	bool canUse = true; 
         	for (int x = 0; x < m; ++x) 
           		for (int y = 0; y < n; ++y) 
            		 if (cutter[x][y] == '.' && cake[i + x][j + y] == 'X') 
               		 	canUse = false; 
         	if (canUse) { 
            	 for (int x = 0; x < m; ++x) 
             		for (int y = 0; y < n; ++y) 
              			if (cutter[x][y] == '.') 
                			cake[i + x][j + y] = 'X'; 
         	} 
       	}	 
     } 
     for (int i = 0; i < cake.size(); ++i) 
     	for (int j = 0; j < cake[0].size(); ++j) 
        	if (cake[i][j] == '.') 
           		return "NO"; 
     return "YES"; 
   } 
}; 

