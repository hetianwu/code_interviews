void search(string& s, unordered_set<string>& res_set, string& temp, int curr, int open, int s_sz, int& max_valid_len, bool left_deleted){
    // dfs
    if(s_sz-curr<open) return;
    if(curr == s_sz){
        if(temp.length()>=max_valid_len && res_set.find(temp) == res_set.end()){
            max_valid_len = temp.length();
            res_set.insert(temp);
        }
        return;
    }    
    if(s[curr] != '(' && s[curr] != ')'){
        temp += s[curr];
        search(s, res_set, temp, curr+1, open, s_sz, max_valid_len, left_deleted);
        temp.pop_back();
        return;
    }
    if(s[curr] == '('){
        temp += "(";
        search(s, res_set, temp, curr+1, open+1, s_sz, max_valid_len, left_deleted);
        temp.pop_back();
        search(s, res_set, temp, curr+1, open, s_sz, max_valid_len, true);
    }
    else{
        if(!(s[curr] == ')' && open==0)){
            temp += ')';
            search(s, res_set, temp, curr+1, open-1, s_sz, max_valid_len, left_deleted);
            temp.pop_back();
        }
        if(!left_deleted){
            search(s, res_set, temp, curr+1, open, s_sz, max_valid_len, left_deleted);
        }
    }
}

vector<string> removeInvalidParentheses(string s) {
    vector<string> res;
    int sz = s.length();
    unordered_set<string> res_set;
    string temp = "";
    int max_valid_len = 0;
    search(s, res_set, temp, 0, 0, sz, max_valid_len, false);
    for(string a:res_set) res.push_back(a);
    return res;
}