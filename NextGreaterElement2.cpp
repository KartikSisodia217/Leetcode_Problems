//This is my solution to Leetcode Problem #503: Next Greater Element II

/*
Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), 
return the next greater number for every element in nums.
The next greater number of a number x is the first greater number to its traversing-order next in the 
array, which means you could search circularly to find its next greater number. If it doesn't exist, 
return -1 for this number.

 

Example 1:
Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number. 
The second 1's next greater number needs to search circularly, which is also 2.


Example 2:
Input: nums = [1,2,3,4,3]
Output: [2,3,4,-1,4]
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
  vector<int> nextGreaterElements(vector<int>& nums) {
    vector<int> ans(nums.size());
    for(int i =0; i<nums.size(); i++){
        ans[i]= -1;
    }
    bool found;
    for(int i=0; i<nums.size(); i++){
      found = false;
      for(int j = i; j<nums.size(); j++){
        if(nums[j]>nums[i] ){
          ans[i] = nums[j];
          found = true;
          break;
        }
      }
      if(!found){
        for(int j=0; j<i;j++){
          if(nums[j]>nums[i]){
            ans[i] = nums[j];
            break;
          }
        }
      }
    }
      return ans;
  }
};

int main() {
  Solution sol;
  vector<int> nums = {1, 2, 3, 4, 3};

  cout << "input: [";
  for (int i = 0; i < nums.size(); i++) {
    cout << nums[i];
    if (i != nums.size() - 1) cout << ",";
  }
  cout << "]" << endl;

  vector<int> result = sol.nextGreaterElements(nums);

  cout << "output: [";
  for (int i = 0; i < result.size(); i++) {
    cout << result[i];
    if (i != result.size() - 1) cout << ",";
  }
  cout << "]" << endl;

  return 0;
}
