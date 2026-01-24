// This is my solution to Leetcode problem #136: Single Number

/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single
one. 

 

Example 1:
Input: nums = [2,2,1]
Output: 1


Example 2:
Input: nums = [4,1,2,1,2]
Output: 4


Example 3:
Input: nums = [1]
Output: 1
*/


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
  int singleNumber(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int ans = 0;

    if (nums.size() == 1) {
      ans = nums[0];
    }
    else if (nums[nums.size() - 1] != nums[nums.size() - 2]) {
      ans = nums[nums.size() - 1];
    }
    else if (nums[0] != nums[1]) {
      ans = nums[0];
    }
    else {
      for (int i = 1; i < nums.size() - 1; i++) {
        if (nums[i] != nums[i - 1] && nums[i] != nums[i + 1]) {
          ans = nums[i];
        }
      }
    }
    return ans;
  }
};


int main(){
  Solution sol;
  vector<int> nums = {1,3,1,4,3,4,5,6,6};
  int ans = sol.singleNumber(nums);
  cout<<"The answer is: "<<ans<<endl;
  return 0;
}