https://leetcode.com/problems/sudoku-solver/

class Solution {
public:

    bool isSafe(vector<vector<char>> &board , int row , int col, char val){
        for(int i = 0 ; i<9 ; i++){
            if(board[row][i] == val)return false;             //checking in col
            if(board[i][col] == val)return false;            //checking in row

            // checking sub grid
            if(board[3*(row/3) + i/3][3 * (col/3) + i%3] == val)return false;
        }
        return true;
    }

    bool solve(vector<vector<char>> &board){

        int n = board.size();
        int m = board[0].size();

        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ;j<m ;j++){

                if(board[i][j] == '.'){
                    for(char k = '1' ;k <= '9' ; k++){
                        if(isSafe(board,i,j,k)){
                                 board[i][j] = k;
                                 if(solve(board)) return true;
                                 else board[i][j] = '.';
                        }
                    }
                    // if all char checked to end then return false as no Solution
                    // possible
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        solve(board);
    }
};



int main() {
    vector<vector<char>>board{
        {'9', '5', '7', '.', '1', '3', '.', '8', '4'},
        {'4', '8', '3', '.', '5', '7', '1', '.', '6'},
        {'.', '1', '2', '.', '4', '9', '5', '3', '7'},
        {'1', '7', '.', '3', '.', '4', '9', '.', '2'},
        {'5', '.', '4', '9', '7', '.', '3', '6', '.'},
        {'3', '.', '9', '5', '.', '8', '7', '.', '1'},
        {'8', '4', '5', '7', '9', '.', '6', '1', '3'},
        {'.', '9', '1', '.', '3', '6', '.', '7', '5'},
        {'7', '.', '6', '1', '8', '5', '4', '.', '9'}
    };

    solveSudoku(board);

    for(int i= 0; i< 9; i++){
        for(int j= 0; j< 9; j++)
            cout<<board[i][j]<<" ";
            cout<<"\n";
    }
    return 0;
}
