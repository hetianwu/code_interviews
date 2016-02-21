// https://github.com/hetianwu/InterviewQuestions-.git

/*

https://leetcode.com/problems/increasing-triplet-subsequence/

Given an unsorted array return whether an increasing subsequence of length 3 exists or not in the array.
Formally the function should:
Return true if there exists i, j, k 
such that arr[i] < arr[j] < arr[k] given 0 ≤ i < j < k ≤ n-1 else return false.
Your algorithm should run in O(n) time complexity and O(1) space complexity.

*/

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