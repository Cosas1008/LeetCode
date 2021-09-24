
class Solution {
public:
    // Time Complexity : O(n)
    string tictactoe(vector<vector<int>>& moves) {
        vector<int> rows(3), cols(3);
        int diag = 0;
        int antidiag = 0;
        int player = 1;
        int n = 3;
        for(auto move : moves){
            int row = move[0];
            int col = move[1];
            
            rows[row] += player;
            cols[col] += player;
            if(row == col)
                diag += player;
            if(row + col == 2)
                antidiag += player;
            
            if(abs(rows[row]) == n ||
               abs(cols[col]) == n ||
               abs(diag)      == n ||
               abs(antidiag)  == n)
                return player == 1 ? "A" : "B";
            
            player *= -1;
        }
        return moves.size()==n*n? "Draw" : "Pending";
    }
};