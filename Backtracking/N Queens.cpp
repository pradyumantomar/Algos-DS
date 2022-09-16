https://leetcode.com/problems/n-queens/
class Solution {
public:

    bool isValid(int row, int col, vector<string> &board , int n){
        if(row >= n  or row < 0  or col <0  or col >=n) return false;

        int tempRow = row;
        int tempCol = col;

        while(tempCol >= 0){
            if(board[tempRow][tempCol] == 'Q')return false;
            tempCol--;
        }

        tempRow = row;
        tempCol = col;

        while(tempCol >= 0 and tempRow >= 0){
            if(board[tempRow][tempCol] == 'Q')return false;
            tempCol--;
            tempRow--;
        }

        tempRow = row;
        tempCol = col;

        while(tempCol >= 0 and tempRow < n){
            if(board[tempRow][tempCol] == 'Q')return false;
            tempCol--;
            tempRow++;
        }

        return true;


    }

    void solve(vector<string> &board , vector<vector<string>> &ans , int col , int n){

        if(col == n){
            ans.push_back(board);
            return;
        }

        for(int row = 0 ; row < n ; row++){
            if(isValid(row,col,board,n)){
                board[row][col] = 'Q';
                solve(board , ans , col + 1 , n );

                // backtrack
                board[row][col] = '.';
            }
        }

    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;

        vector<string> board(n);
        string s(n,'.');

        for(int i = 0 ; i<n; i++){
            board[i] = s;
        }

        int col = 0;
        solve(board , ans, col,n);
        return ans;
    }
};
