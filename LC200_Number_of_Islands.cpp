class Union{
public:   
    vector<int>parent;
    vector<int>size;
    int counter;

    Union(int n){
        parent = vector<int>(n);
        size = vector<int>(n,1);
        for(int i =0;i< n;i++){
            parent[i] = i;
        }
        counter = n;
    }
    int count(){
        return counter;
    }

    void connect(int a,int b){
        int aa = find(a);
        int bb = find(b);
        if(aa == bb)
            return;
        if(size[aa] <= size[bb]){
            size[bb] +=size[aa];
            parent[aa] = bb;
        

        }else{
            size[aa] +=size[bb];
            parent[bb] = aa;
        }
        counter--;
    }

    bool isConnect(int a,int b){
        return find(a) == find (b);
    }

    int find(int m){
        if(parent[m] == m){
            return m;
        }
        parent[m] = find(parent[m]);
        return parent[m];
    }
};
class Solution {
public:

     bool validLocation(int x,int y,int row,int col){
        if( x>=0 && x<row && y>=0 && y<col){
            return true;
        }
        return false;
    }
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if(row == 0){
            return 0;
        }
        int col = grid[0].size();
        if(col == 0){
            return 0;
        }
        cout << "row" << row << endl;
        cout << "col" << col << endl;
        int num_zero = 0;
        int num_pixel = row*col;
        Union un =  Union(num_pixel);
        for(int i = 0; i<row; i++){
            for(int j = 0; j<col;j++){
                if(grid[i][j] == '1'){
              
                    if(validLocation(i+1,j,row,col) && grid[i+1][j] == '1' ){
                      
                        un.connect(i*col+j,(i+1)*col+j);
                    }
                    if(validLocation(i-1,j,row,col) && grid[i-1][j] == '1' ){
                      
                        un.connect(i*col+j,(i-1)*col+j);
                    }
                    if(validLocation(i,j-1,row,col) && grid[i][j-1] == '1'){
                     
                        un.connect(i*col+j,(i)*col+j-1);
                    }
                    if(validLocation(i,j+1,row,col) && grid[i][j+1] == '1'){
                    
                        un.connect(i*col+j,(i)*col+j+1);
                    
                    }
                 
                }else{
                    num_zero++;
                }
            }
        }
        // I treat each zero pixel as a single subset.
        // The number of islands is the number of subsets subtract the number
        // of the zeros.
        return un.count()-num_zero;
        
    }
  
};