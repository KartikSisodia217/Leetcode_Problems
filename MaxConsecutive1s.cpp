// This is my solution to Leetcode Problem #485: Max Consecutive Ones

/*
Given a binary array nums, return the maximum number of consecutive 1's in the array.


Example 1:
Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.


Example 2:
Input: nums = [1,0,1,1,0,1]
Output: 2
*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution
{
public:
  int findMaxConsecutiveOnes(vector<int> &nums){
    int curr = 0, ans = 0;
    for (int i = 0; i < nums.size(); i++){
      if (nums[i] == 1){
        curr++;
        ans = max(ans, curr);
      }
      else{
        curr = 0;
      }
    }
    return ans;
  }
};

int main(){
  Solution sol;
  vector <int> nums = {1,1,0,1,1,1,0,1};
  cout<<"The number of consecutive 1s in this case are: "<<sol.findMaxConsecutiveOnes(nums)<<endl;
  return 0;
}