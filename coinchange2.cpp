// https://github.com/hetianwu/InterviewQuestions-.git

int coinchange2(vector<int> &A, int B) {
    if (A.size() == 0) return 0;
    int m = A.size();
    sort(A.begin(),A.end());
    vector<long int> dp(B+1,0);
    dp[0] = 1;
    for(long int i = 0; i<m;i++){
        for(long int j = A[i];j<=B;j++){
            dp[j] += dp[j-A[i]];
            dp[j] = dp[j]%1000007;
        }
    }
    return dp[B];
}
int main(){
	return 0;
}