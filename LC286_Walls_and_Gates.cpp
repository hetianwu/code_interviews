
/*

286. Walls and Gates

https://leetcode.com/problems/walls-and-gates/

You are given a m x n 2D grid initialized with these three possible values.

-1 - A wall or an obstacle.
0 - A gate.
INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

For example, given the 2D grid:
INF  -1  0  INF
INF INF INF  -1
INF  -1 INF  -1
  0  -1 INF INF
After running your function, the 2D grid should be:
  3  -1   0   1
  2   2   1  -1
  1  -1   2  -1
  0  -1   3   4

*/


void wallsAndGates(vector<vector<int>>& rooms) {
    queue<pair<int,int>> myq;
    
    for(int i = 0;i<rooms.size();i++){
        for(int j = 0; j< rooms[0].size();j++){
            if(rooms[i][j] == 0){
                pair <int,int> newpair;
                newpair.first = i;
                newpair.second = j;
                myq.push(newpair);
            }
        }
    }
    while(!myq.empty()){
        int x = myq.front().first;
        int y = myq.front().second;
        if(isValid(rooms,x+1,y)){
            rooms[x+1][y] = rooms[x][y]+1;
            pair <int,int> newpair;
            newpair.first = x+1;
            newpair.second = y;
            myq.push(newpair);
                
                
        }
        if(isValid(rooms,x-1,y)){
            rooms[x-1][y] = rooms[x][y]+1;
            pair <int,int> newpair;
            newpair.first = x-1;
            newpair.second = y;
            myq.push(newpair);
                
        }
        if(isValid(rooms,x,y+1)){
            rooms[x][y+1] = rooms[x][y]+1;
            pair <int,int> newpair;
            newpair.first = x;
            newpair.second = y+1;
            myq.push(newpair);
                
        }
        if(isValid(rooms,x,y-1)){
            rooms[x][y-1] = rooms[x][y]+1;
            pair <int,int> newpair;
            newpair.first = x;
            newpair.second = y-1;
            myq.push(newpair);
                
        }
        
        myq.pop();
        
    }
        
}
bool isValid(vector<vector<int>>& rooms,int x,int y){
    int INF = 2147483647;
    int row = rooms.size();
    int col = rooms[0].size();
    if(x<0 || x>= row){
        return false;
    }
    if(y<0 || y>= col){
        return false;
    }
    if(rooms[x][y] == -1){
        return false;
    }
    if(rooms[x][y] == INF){
        return true;
    }
    return false;
}