/*
128. Longest Consecutive Sequence 
https://leetcode.com/problems/longest-consecutive-sequence/

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/


int longestConsecutive(vector<int>& nums) {
    unordered_set<int> myset;
    if(nums.size() ==1){
        return 1;
    }
    for(int i = 0; i<nums.size();i++){
        myset.insert(nums[i]);
    }
    int ret = 1;
    while(myset.size()>0){ 
        int number = *myset.begin();
        int count = 1;
        myset.erase(number);
        int small = number-1;
        int big = number+1;
        while(myset.count(small)>0){
            myset.erase(small);
            small--;
            count++;
        }
        while(myset.count(big)>0){
            myset.erase(big);
            big++;
            count++;   
        }
        ret = max(count,ret);
            
    }
    return ret;
}