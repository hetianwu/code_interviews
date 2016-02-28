/*

30. Surrounded Regions

https://leetcode.com/problems/surrounded-regions/

Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X

*/
class Solution {
public:
    bool validLocation(int x, int y, int row,int col){
        if(x>=0 && x<row && y>=0 && y<col){
            return true;
        }
        return false;
    }
    void solve(vector<vector<char>>& board) {
        // check four edges 
        int row = board.size();
        if (row == 0){
            return;
        }
        int col = board[0].size();
        
        if(col == 0){
            return;
        }
    
        int i,j;
        for(j = 0; j<col;j++){
            for(i = 0; i<row;i++){
                if(i == 0 || i == row-1 || j == 0 || j == col-1){
                    if(board[i][j] == 'O'){
                        board[i][j] = '1';
                        queue<pair<int,int>> myq;
                        pair<int,int>loc; 
                        loc.first = i;
                        loc.second = j;
                        myq.push(loc);
                       
                        while(!myq.empty()){
                            int x = myq.front().first;
                            int y = myq.front().second;
                            if(validLocation(x+1,y,row,col)&& board[x+1][y] =='O'){
                                pair<int,int> loc; 
                                loc.first = x+1;
                                loc.second = y;
                                myq.push(loc);
                                board[x+1][y] = '1';
                            }
                            if(validLocation(x-1,y,row,col)&& board[x-1][y] =='O'){
                                pair<int,int> loc; 
                                loc.first = x-1;
                                loc.second = y;
                                myq.push(loc);
                                board[x-1][y] = '1';
                             }
                            if(validLocation(x,y+1,row,col)&& board[x][y+1] =='O'){
                                pair<int,int> loc; 
                                loc.first = x;
                                loc.second = y+1;
                                myq.push(loc);
                                board[x][y+1] = '1';
                            }
                            if(validLocation(x,y-1,row,col)&& board[x][y-1] =='O'){
                                pair<int,int> loc; 
                                loc.first = x;
                                loc.second = y-1;
                                myq.push(loc);
                                board[x][y-1] = '1';
                            }
                            myq.pop();
                        }
                    }
                    
                }
                
            }
        }
        
        // for all "untouched" 'O's, they are surrounded by 'X's.
        // convert them into 'X's.
        // for all '1's, they are the 'O' who are connected to edges
        // convert them back into 'O'
        for(int i = 0;i<row;i++){
            for(int j = 0; j<col;j++){
                if(board[i][j] == '1'){
                    board[i][j] = 'O';
                }else if (board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
        return;
        
        
    }
};
