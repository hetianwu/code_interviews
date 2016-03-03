/*
32. Longest Valid Parentheses 
https://leetcode.com/problems/longest-valid-parentheses/
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/
int longestValidParentheses(string s) {
    vector<int> mys;
    vector<int> dp(s.size(), 0);
    //dp[i] is the longest valid parenthes ends at i;
    if (s.size() < 2) {
        return 0;
    }
    int ret = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            mys.push_back(i);
        } else {
            if (mys.size() > 0) {
                int rightmostLeft = mys[mys.size() - 1];
                mys.pop_back();
                dp[i] = i - rightmostLeft + 1 + dp[rightmostLeft - 1];
                //the subtring bewteen i and top is an valid parenthes
                ret = max(ret, dp[i]);
                // if dp[i] is longer the previously longest one, update the ret.
            }
        }

    }
    return ret;

}
