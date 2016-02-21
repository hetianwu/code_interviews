/*
https://leetcode.com/problems/subsets/
Given a set of distinct integers, nums, return all possible subsets.
(also known as the power set)
*/

vector<vector<int>> subsets(vector<int>& nums) {
    /*first sort all numbers, since the problem
    asks us to make elements in a susbet in NON-DESCENDING order
    */
    sort(nums.begin(),nums.end());

    int size = nums.size();

    vector<vector<int>> ret;
    /* corner case */
    if(size == 0){
        return ret;
    }
    /* if nums is not empty,
       we first insert any empty set
       and a set that only has the first element of 
       nums into the collection of subset ret.

    */
    vector<int> a = {};
    vector<int> b = {nums[0]};
    ret.push_back(a);
    ret.push_back(b);
    long long int power_set = 2;

    /*
    suppose we have a set [1,2] all possible subsets of this set are
    { []
      [1]
      [2]
      [1,2]
    }

    we first have all possible subsets of [1]:
    { []
      [1]
    }
    and make copy of this
    { []
      [1]
    }
    =>
    { []
      [1]
      []
      [1]
    }
    and append "2" to the subsets in new copy
    { []
      [1]
      [] <=2
      [1] <=2
    }
    =>
    { []
      [1]
      [2] 
      [1,2] 
    }
    */



    for(int i = 1;i<size;i++){
        /*
        the function copy will append a copy
        of current ret to ret.

        { []
          [1]
        }
        =>
        { []
          [1]
          []
          [1]
        }

        */
        copy(ret,set_size);
        /*
        this loop will append nums[i] to the subsets in the new copy.
        */
        for(long long int j = set_size; j<set_size*2;j++){
            ret[j].push_back(nums[i]);
        }
        set_size *=2;
    }
    return ret;
        
}

void copy(vector<vector<int>>&sub,long long int size){
    for(long long int i = 0; i<size; i++){
        sub.push_back(sub[i]);
    }
        
}