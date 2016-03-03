/*
Problem taken from
https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
Remove Duplicates from Sorted Array II:

Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
*/

int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if(size<3){
            return size;
        } 
        int next_index = 2;
        
        int prepre = nums[0];
        int pre = nums[1];
        for(int i = 2;i<size;i++){
            if(!(nums[i] == pre && nums[i] == prepre)){
                nums[next_index] = nums[i];
                pre = nums[next_index];
                prepre = nums[next_index-1];
                next_index++;
            }
            
        }
        return next_index--;
    }
