https://leetcode.com/problems/n-queens-ii/

class Solution {
public:

    bool isValid(int row , int col , vector<string> &board, int n){
        int tRow = row;
        int tCol = col;

        while(tRow >= 0 and tCol >= 0){
            if(board[tRow][tCol] == '1')return false;
            tRow--;
            tCol--;
        }

        tRow = row;
        tCol = col;

        while(tRow <n and tCol >= 0){
            if(board[tRow][tCol] == '1')return false;
            tRow++;
            tCol--;
        }

        tRow = row;
        tCol = col;

        while(tCol >= 0){
            if(board[tRow][tCol] == '1')return false;
            tCol--;
        }

        return true;



    }

    void solve(vector<string> &board, int &ans, int col , int n){
        // bc
        if(col == n){
            ans++;
            return;
        }

        for(int row = 0; row<n; row++ ){
            if(isValid(row,col,board,n)){
                board[row][col] = '1';
                solve(board, ans, col + 1 , n);

                // backTracking

                board[row][col] = '0';
            }
        }

    }

    int totalNQueens(int n) {
        int ans = 0;
        vector<string> board(n);

        string s(n,'0');
        int col = 0;
        solve(board,ans, col, n);
        return ans;

    }
};
