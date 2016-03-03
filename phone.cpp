class Solution { public: vector letterCombinations(string digits) { vector result; if(digits.size()==0){ return result; } unordered_map<int,string> table; table.insert({0,""}); table.insert({1,""}); table.insert({2,"abc"}); table.insert({3,"def"}); table.insert({4,"ghi"}); table.insert({5,"jkl"}); table.insert({6,"mno"}); table.insert({7,"pqrs"}); table.insert({8,"tuv"}); table.insert({9,"wxyz"});

    string combo="";
    backtrackHelper(result,combo, digits,0, table);
    return result;
}

void backtrackHelper(vector<string>& result, string combo, string digits, int index,unordered_map<int,string> table){
    if(index>=digits.size()){
        result.push_back(combo);
        return;
    }

    unordered_map<int,string>::iterator pointer=table.find(digits[index]-'0');
    for(int i=0;i<pointer->second.size();i++){
        combo+=pointer->second[i];
        backtrackHelper(result,combo,digits,index+1, table);
        combo.erase(combo.end()-1);
    }


}
};