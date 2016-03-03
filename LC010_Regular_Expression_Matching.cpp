/*
10. Regular Expression Matching

https://leetcode.com/problems/regular-expression-matching/

Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*/
    bool isMatch(string s, string p) {
        // dynamic programming
        int m=s.length(), n = p.length();
        vector<vector<bool>> dp (m+1, vector<bool> (n+1, false));
        // initial state
        dp[0][0] = true;
        for(int i = 0; i < m+1; i++) {
            for(int j = 1; j < n+1; j++) {
                if(p[j-1] != '*') {
                    dp[i][j] = i > 0 && dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
                }
                else {
                    dp[i][j] = dp[i][j-2] || (i > 0 && dp[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.')); 
                }
            }
        }
        return dp[m][n];
    }
