/*
300. Longest Increasing Subsequence

https://leetcode.com/problems/longest-increasing-subsequence/

Given an unsorted array of integers, find the length of longest increasing subsequence.

For example,
Given [10, 9, 2, 5, 3, 7, 101, 18],
The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.

Your algorithm should run in O(n2) complexity.

Follow up: Could you improve it to O(n log n) time complexity?
*/
// First solution, O(N2) time complexity
int lengthOfLIS(vector<int>& nums) {
    // edge case when nums.size() = 0 
    if(nums.size() == 0){
        return 0;
    }
    // dp[i] means the longest increasing  subsequence 
    // that ends with i.
    vector<int> dp(nums.size(),1);
    int ret = 1;
    for(int i = 0; i<nums.size();i++){
        for(int j =0; j<i;j++){
            if(nums[i]>nums[j]){
                // if nums[i] > nums[j]
                // then the longest increasing subsequence
                // ends at j with i, will form a new increasing
                // subsquence,  we iterate through all possible
                // js to find the longest one
                dp[i] = max(dp[i],dp[j]+1);
            }
        }
        // check if the longest increasing subsequence ends at i
        // is the longest so far. if it's longer than the previous
        // longest one, then we update ret to be this value.
        ret = max(ret,dp[i]);
    }
    return ret;
        
}