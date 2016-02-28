/*
88. Merge Sorted Array
https://leetcode.com/problems/merge-sorted-array/

Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.

*/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pt_nums1 = m-1;
        int pt_nums2 = n-1;
        int pt_merge = m+n-1;
        
        while(pt_nums1>=0 || pt_nums2 >=0){
            if(pt_nums1>=0 && pt_nums2>=0){
                if(nums1[pt_nums1]>nums2[pt_nums2]){
                    nums1[pt_merge] = nums1[pt_nums1];
                    pt_nums1--;
                }else{
                    nums1[pt_merge] = nums2[pt_nums2];
                    pt_nums2--;
                    
                }
            }else if(pt_nums1>=0){
                nums1[pt_merge] = nums1[pt_nums1];
                pt_nums1--;
                
            }else{
                nums1[pt_merge] = nums2[pt_nums2];
                pt_nums2--;
                
            }
            pt_merge--;
            
        }
        
    }
};