/*
221. Maximal Square
https://leetcode.com/problems/maximal-square/

Given a 2D binary matrix filled with 0's and 1's, find the largest square containing all 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4.
*/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if(row == 0){
            return 0;
        }
        int col = matrix[0].size();
        if(col == 0){
            return 0;
        }
        vector<vector<int> >dp(row,vector<int>(col,0));
        if(matrix[0][0] == '1'){
            dp[0][0] = 1;
        }
        int max_side = 0;
        for(int i = 0; i < row;i++){
            for(int j = 0; j <col;j++){
                if(matrix[i][j] == '1'){
                    int min_prev = INT_MAX;
                    if(i-1>=0){
                        if(dp[i-1][j]< min_prev){
                            min_prev = dp[i-1][j];
                        }
                    }else{
                        min_prev = 0;
                    }
                    if(j-1>=0){
                        if(dp[i][j-1]< min_prev){
                            min_prev = dp[i][j-1];
                        }
                    }else{
                         min_prev = 0;
                    }
                    if(i-1>=0 && j-1>=0){
                        if(dp[i-1][j-1]< min_prev){
                            min_prev = dp[i-1][j-1];
                        }
                    }
                    if(dp[i][j] == 0){
                        dp[i][j] = 1+min_prev;
                    }
                    if(dp[i][j]>max_side){
                        max_side = dp[i][j];
                    }
                }else{
                    dp[i][j] = 0; 
                }
            }
        }
        return max_side*max_side;
    }
};