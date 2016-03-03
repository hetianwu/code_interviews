
/*
79. Word Search

https://leetcode.com/problems/word-search/

Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/
bool exist(vector<vector<char>>& board, string word) {
  for (int i = 0; i < board.size(); i++) {
    for (int j = 0; j < board[0].size(); j++) {
      if (board[i][j] == word[0] && backtracking(board, word, 0, i, j)) return true;
    }
  }
  return false;
}
bool backtracking(vector<vector<char>>& board, string word, int index, int i, int j) {
  // check if i or j exceed the boundary of the board
  // check if the index-th char of word match the char at board[i][j]

  if ( i < 0 || i >= board.size() ||
       j < 0 || j >= board[0].size() ||
       board[i][j] != word[index]) {
    return false;
  }
  // if it passes the previous conditions
  // if this is the goal state we return ture;
  if (index == word.size() - 1) {
    return true;
  }
  char ch = board[i][j];
  board[i][j] = '&';
  if (backtracking(board, word, index + 1, i + 1, j) ||
      backtracking(board, word, index + 1, i - 1, j) ||
      backtracking(board, word, index + 1, i, j + 1) ||
      backtracking(board, word, index + 1, i, j - 1)) {
    return true;
  }
  board[i][j] = ch;
  return false;
}
