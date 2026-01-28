// This is my solution to Leetcode Problem #42: Trapping Rainwater

/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 

Example 1:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.


Example 2:
Input: height = [4,2,0,3,2,5]
Output: 9
*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;

        int LMax = 0;
        int RMax = 0;

        int water = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                LMax = max(LMax, height[left]);
                water += LMax - height[left];
                left++;
            } else {
                RMax = max(RMax, height[right]);
                water += RMax - height[right];
                right--;
            }
        }

        return water;
    }
};

int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

    Solution obj;
    int result = obj.trap(height);

    cout << result << endl;

    return 0;
}
