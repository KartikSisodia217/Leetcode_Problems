//This is my solution to Leetcode Problem #152: Maximum product subarray

/*
Given an integer array nums, find a subarray that has the largest product, and return the product.
The test cases are generated so that the answer will fit in a 32-bit integer.
Note that the product of an array with a single element is the value of that element.

 
Example 1:
Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.


Example 2:
Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
  int maxProduct(vector<int>& nums) {
    int maximum = nums[0];
    int minimum = nums[0];
    int ans = nums[0];

    for (int i = 1; i < nums.size(); i++) {
      if (nums[i] < 0) {
        swap(maximum, minimum);
      }

      maximum = max(nums[i], maximum * nums[i]);
      minimum = min(nums[i], minimum * nums[i]);

      ans = max(ans, maximum);
    }

    return ans;
  }
};

int main() {
  vector<int> nums = {2, 3, -2, 4};

  Solution obj;
  cout << "output: "<<obj.maxProduct(nums) << endl;

  return 0;
}
