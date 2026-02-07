// This is my solution to Leetcode Problem #283: Move Zeroes

/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Note that you must do this in-place without making a copy of the array.


Example 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]


Example 2:
Input: nums = [0]
Output: [0]
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
  void moveZeroes(vector<int> &nums){
    int sorted = 0;

    for (int j = 0; j < nums.size(); j++){
      if (nums[j] != 0){
        swap(nums[sorted], nums[j]);
        sorted++;
      }
    }
  }
};

int main()
{
  Solution sol;
  vector<int> nums = {0,1,0,3,12};
  cout<<"input: { ";
  for(int el : nums){
    cout<<el<<" " ;
  }
  cout<<"}"<<endl;
  sol.moveZeroes(nums);
  cout<<"output: { ";
  for(int el : nums){
    cout<<el<<" " ;
  }
  cout<<"}"<<endl;
  return 0;
}