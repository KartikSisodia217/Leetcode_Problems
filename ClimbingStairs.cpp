//This is my solution to Leetcode problem #70. Climbing Stairs

/*

You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

 

Example 1:
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps


Example 2:
Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

*/

#include<iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        
        if (n == 1) return 1;
        if (n == 2) return 2;

        int prev1 = 2;
        int prev2 = 1;  
        
        for (int i = 3; i <= n; i++) {
            int curr = prev1 + prev2; 
            prev2 = prev1;            
            prev1 = curr;
        }

        
        return prev1;
    }
};

int main(){
  Solution sol; 
  int input;
  cout<<"Enter n : ";
  cin>>input;
  cout<<"Number of ways to reach stair number "<<input<<" is "<<sol.climbStairs(input)<<endl;
  return 0;
}