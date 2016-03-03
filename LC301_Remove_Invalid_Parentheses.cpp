/*
301. Remove Invalid Parentheses 

https://leetcode.com/problems/remove-invalid-parentheses/

Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.

Note: The input string may contain letters other than the parentheses ( and ).

Examples:
"()())()" -> ["()()()", "(())()"]
"(a)())()" -> ["(a)()()", "(a())()"]
")(" -> [""]
*/

vector<string> removeInvalidParentheses(string s) {
    vector<char> par;
    par.resize(2);
    par[0] = '(';
    par[1] = ')';
    vector<string> ret;
    dfsRemove(s,ret,0,0,par);
    return ret;
    
}
void dfsRemove(string s, vector<string>&ret,int last_break, int last_removal,vector<char>&par){

    int stack = 0;
    int break_index = last_break;
    for(int i = last_break;i<s.size();i++){
        if(s[i] == par[0]){
            stack++;
        }else if(s[i] == par[1]){
            stack--;
        }
        if(stack<0){
            break_index = i;
            break;
        }
    }

    if(stack<0){
        for(int j = last_removal;j<=break_index;j++){

            if(s[j] == par[1] && (j == last_removal || s[j-1] != par[1]) ){

                string sub = s.substr(0,j) + s.substr(j+1,s.size());

                dfsRemove(sub,ret,break_index,j,par);
            }
       
        }
        return;
    }

    string s_copy = s;

    reverse(s_copy.begin(),s_copy.end());

    if(par[0] == '('){
        cout << " need to reverse" <<endl;
        vector<char> parR = { ')','('};
        dfsRemove(s_copy,ret,0,0,parR);

        
    }else{
        ret.push_back(s_copy); 
    }

}
