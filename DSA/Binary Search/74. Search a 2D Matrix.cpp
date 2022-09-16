class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int n_row = matrix.size();
        int m_col = matrix[0].size();

        int row = 0 ;
        int col = m_col - 1 ;

        while((row>=0  and row<n_row)and (col>=0 and col<m_col)){
            if(matrix[row][col]==target){
                return true;
            }
            else if(matrix[row][col]>target){
                --col;
            }
            else{
                ++row;
            }
        }
        return false;

    }
};