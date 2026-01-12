// This is my solution to Leetcode Problem #1390: Four Divisors

/*

Given an integer array nums, return the sum of divisors of the integers in that array that have exactly four divisors. If there is no such integer in the array, return 0.

 

Example 1:
Input: nums = [21,4,7]
Output: 32
Explanation: 
21 has 4 divisors: 1, 3, 7, 21
4 has 3 divisors: 1, 2, 4
7 has 2 divisors: 1, 7
The answer is the sum of divisors of 21 only.


Example 2:
Input: nums = [21,21]
Output: 64


Example 3:
Input: nums = [1,2,3,4,5]
Output: 0

*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        
        int sum=0;
        for(int i=0; i<=nums.size()-1; i++){
            int divisors=0;
            int d=0;
            for(int j=1; j*j<=nums[i]; j++){
                
                if(nums[i]%j==0){
                    divisors++;
                    d+=j;
                    if((nums[i]/j)!=j){
                        divisors++;
                        d= d+(nums[i]/j);
                    }
                }
            }
            if(divisors==4){
                sum+=d;
            }
        }
        return sum;
    }
};



int main(){
  Solution sol;
  vector<int> nums = {21,4,7};
  cout<<"The sum of divisors of the integers that have exactly four divisors is: "<<sol.sumFourDivisors(nums)<<endl;
  return 0;
}