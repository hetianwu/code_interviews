/*
https://leetcode.com/problems/two-sum/

Given an array of integers, return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution.
*/

vector<int> twoSum(vector<int>& nums, int target) {
  map<int,int> mymap;
  int size = nums.size();
  for(int i = 0; i<size;i++){
    int reminder = target-nums[i];
    if(mymap.find(reminder) != mymap.end()){
      vector<int> ret = {mymap[reminder],i};
      return ret;         
    }else{
      mymap[nums[i]] = i;
    }
  }      
}
