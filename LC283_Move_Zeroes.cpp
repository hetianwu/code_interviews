/*

Problem is taken from:
https://leetcode.com/problems/move-zeroes/

Leet Code 283.Move Zeros
Problem Statement:

Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].

Note:
You must do this in-place without making a copy of the array.
Minimize the total number of operations.

*/

void moveZeroes(vector<int>& nums) {
    int size = nums.size();
    int next_index = 0;
    int num_int = 0;
    for(int i = 0; i<nums.size();i++){
        if(nums[i] != 0){
            nums[next_index] = nums[i];
            next_index++;
        }else{
            num_int++;
        }
    }
    for(int i = 0; i<num_int;i++){
        nums[size-1-i] = 0;
    }
}