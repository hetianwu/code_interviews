/*
This problem is taken from:
https://leetcode.com/problems/paint-house-ii/

LeetCode 265. Paint House II
Problem Statement:

There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain color is different. You have to paint all the houses such that no two adjacent houses have the same color.

The cost of painting each house with a certain color is represented by a n x k cost matrix. For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on... Find the minimum cost to paint all houses.

Note:
All costs are positive integers.

Follow up:
Could you solve it in O(nk) runtime?

*/
int minCostII(vector<vector<int>>& costs) {
    // corner case
    if(costs.size() ==0){
        return 0;
    }
    if(costs[0].size() ==0){
        return 0;
    }
    // create a matrix for dynamic programming
    // dp[i][j] will be the minimum total cost up to (i+1) th house if (i+1)th house
    // is painted with color j+1. 
    // (0th row represent the cost for the first house)
    vector<vector<int> > dp(costs.size(),vector<int>(costs[0].size(),0));

    // create variables for find the smallest cost for the first house as
    // well as the second smallest cost for the first house

    int min = numeric_limits<int>::max();
    int secmin = numeric_limits<int>::max();
    int min_index = -1;
    int secmin_index = -1;
    for(int j = 0; j<costs[0].size();j++){
        if(costs[0][j]<min)
        {
            secmin = min;
            secmin_index = min_index;
            min = costs[0][j];
            min_index = j;

        }
        else if(costs[0][j]<secmin)
        {
            secmin = costs[0][j];
            secmin_index = j;
        }
        dp[0][j] = costs[0][j];

    }

    int prev_row_min_index = min_index;
    int prev_row_secmin_index = secmin_index;

    // the update formula is
    // dp[i][j] = cost[i][j]+ min(dp[i-1][j']) where j' is not j.
    // min(dp[i-1][j']) is the smallest one on i-1 th row if dp[i-1][j] is not the smallest one in i-1th row. 
    // min(dp[i-1)[j']) is the second smallest one if dp[i-1][j] is  the smallest one in i-1th row. 

    for(int i = 1; i<costs.size(); i++){
        int min = numeric_limits<int>::max();
        int secmin = numeric_limits<int>::max();

        for(int j = 0; j<costs[0].size();j++){

            if(j == prev_row_min_index){
                dp[i][j] = costs[i][j]+ dp[i-1][prev_row_secmin_index];
            }else{
                dp[i][j] = costs[i][j]+ dp[i-1][prev_row_min_index];  
            }

            if(dp[i][j]<min){
                secmin = min;
                secmin_index = min_index;
                min = dp[i][j];
                min_index = j;
            }
            else if(dp[i][j]<secmin){
                secmin = dp[i][j];
                secmin_index = j;

            }


         } 
         prev_row_min_index = min_index;
         prev_row_secmin_index = secmin_index;

    }

    return dp[costs.size()-1][min_index];
} 