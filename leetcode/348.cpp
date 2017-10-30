#define pb push_back
class TicTacToe {
public:
    /** Initialize your data structure here. */
    vector<vector<int> > a;
    vector<int> sumr, sumc, cntr, cntc;
    int n, sumd1, cntd1, sumd2, cntd2;
    TicTacToe(int n) {
        this -> n = n;
        a.resize(n), sumr.resize(n), sumc.resize(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j)
                a[i].pb(-1);
            sumr.pb(0), sumc.pb(0);
            cntr.pb(0), cntc.pb(0);
        }
        sumd1 = cntd1 = sumd2 = cntd2 = 0;
    }

    int move(int row, int col, int player) {
        a[row][col] = player;
        sumr[row] += player, sumc[col] += player;
        ++cntr[row], ++cntc[col];
        if (row == col) sumd1 += player, ++cntd1;
        if (row + col == n - 1)    sumd2 += player, ++cntd2;
        if ((cntr[row] == n && sumr[row] == n * player) || (cntc[col] == n && sumc[col] == n * player)|| (cntd1 == n && sumd1 == n * player) || (cntd2 == n && sumd2 == n * player))   return player;
        else return 0;
    }
};