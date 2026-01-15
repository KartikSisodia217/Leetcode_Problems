// This is my solution to Leetcode Problem #1493 

/*

Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array. 
Return 0 if there is no such subarray.

 
Example 1:
Input: nums = [1,1,0,1]
Output: 3
Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.


Example 2:
Input: nums = [0,1,1,1,0,1,1,0,1]
Output: 5
Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].


Example 3:
Input: nums = [1,1,1]
Output: 2
Explanation: You must delete one element.

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int curr = 0;
            int zeroes = 0;

            for (int j = i; j < n; j++) {
                if (nums[j] == 0) {
                    zeroes++;
                }
                if (zeroes > 1) {
                    break;
                }
                curr++;
            }

            ans = max(ans, curr - 1);
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = {0,1,1,1,0,1,1,0,1};
    cout <<"The solution to this problem is: "<< s.longestSubarray(nums)<<endl;
    return 0;
}
