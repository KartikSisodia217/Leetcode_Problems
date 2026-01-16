//This is my solution to Leetcode Problem #62: Unique Paths

/*

There is a robot on an m x n grid. The robot is initially located at the top-left corner 
(i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). 
The robot can only move either down or right at any point in time.
Given the two integers m and n, return the number of possible unique paths that the robot can take 
to reach the bottom-right corner.
The test cases are generated so that the answer will be less than or equal to 2 * 109.


Example 1:
Input: m = 3, n = 7
Output: 28


Example 2:
Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down

*/


#include<iostream>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        long long res = 1;
        int k = min(m - 1, n - 1);

        for (int i = 1; i <= k; i++) {
            res = res * (m + n - 2 - (i - 1)) / i;
        }
        return (int)res;
    }
};

int main(){
  Solution sol;
  int m=3,n=7;
  cout<<"The number of unique paths that can be followed in this case is : "<<sol.uniquePaths(m,n)<<endl;
  return 0;
}