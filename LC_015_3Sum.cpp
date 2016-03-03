/*
15. 3Sum
https://leetcode.com/problems/3sum/

Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)


*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums){
        vector<vector<int>> ret;
        sort(nums.begin(),nums.end());
        if(nums.size()<3){
            return ret;
        }
        int i = 0;
        while(i<nums.size()){
            int targetSum = -nums[i];
            int front = i+1;
            int back = nums.size()-1;
            while(front<back){
                int sum = nums[front]+nums[back];
                if(sum<targetSum){
                    front++;
                }else if (sum>targetSum){
                    back--;
                }else{
                    vector<int> triplet = {nums[i],nums[front],nums[back]};
                    ret.push_back(triplet);
                    int frontNum = nums[front];
                    int backNum = nums[back];
                    front++;
                    back--;
                    while(nums[front] == triplet[1]){
                        front++;
                    }
                    while(nums[back] == triplet[2]){
                        back--;
                    }
                }
                
            }
            
            i++;
            while(i+1<nums.size() &&nums[i] == -targetSum){
                  i++;
            }
            
            
        }
        return ret;
        
    }
    
};