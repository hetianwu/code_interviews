class Solution {
public:
vector<vector<int>> adj_list; 
void createAdjList(int numCourses, vector<pair<int, int>>& prerequisites){
    adj_list.resize(0);
    adj_list.resize(numCourses);
    for(int i = 0; i<prerequisites.size();i++){
        adj_list[prerequisites[i].first].push_back(prerequisites[i].second);
    }
}
void topoSortRecur(int v, vector<bool>& visited,stack<int>& mys){
    
    visited[v] = true;
 
    // Recur for all the vertices adjacent to this vertex
    
    for (int i = 1; i< adj_list[v].size();i++){
        int adj = adj_list[v][i];
        if (!visited[adj])
            topoSortRecur(adj, visited, mys);
        
    }
        
 
    // Push current vertex to stack which stores result
    mys.push(v);
}
vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
    stack<int> mys;
    vector<int> ret;
    if(numCourses<=2){
        return ret;
    }
    createAdjList(numCourses, prerequisites);
    vector<bool> visited = vector(numCourses,false);
    for(int i =0; i< numCourses; i++){
        if(visited[i] == false){
            topoSortRecur(i,visited,mys);
        }
    }
   
    while(!mys.empty()){
        ret.push_back(mys.top());
        mys.pop();
    }
    return ret;
}

};
