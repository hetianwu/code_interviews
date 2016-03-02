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

bool increasingTriplet(vector<int>& nums) {
        int a1,a2,a3;
        if(nums.size()<3){
            return false;
        }
        a1 = INT_MAX;
        a2 = INT_MAX;
        for(int i = 0;i<nums.size();i++){
            if(nums[i]<a1){
                a2 = INT_MAX;
                a1 = nums[i];
                
            }else if(nums[i]<a2&& nums[i]>a1){
                a2 = nums[i];
            }
            if(nums[i]>a2){
                cout << nums[i] << a1 << a2;
                return true;
                
            }
        }
        return false;
        
    }