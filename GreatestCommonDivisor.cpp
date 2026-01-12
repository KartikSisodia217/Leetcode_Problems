//This is my solution to Leetcode Problem #1979: Find Greatest Common Divisor of Array

/*

Given an integer array nums, return the greatest common divisor of the smallest number and largest 
number in nums. The greatest common divisor of two numbers is the largest positive integer that 
evenly divides both numbers.

 

Example 1:
Input: nums = [2,5,6,9,10]
Output: 2
Explanation:
The smallest number in nums is 2.
The largest number in nums is 10.
The greatest common divisor of 2 and 10 is 2.


Example 2:
Input: nums = [7,5,6,8,3]
Output: 1
Explanation:
The smallest number in nums is 3.
The largest number in nums is 8.
The greatest common divisor of 3 and 8 is 1.


Example 3:
Input: nums = [3,3]
Output: 3
Explanation:
The smallest number in nums is 3.
The largest number in nums is 3.
The greatest common divisor of 3 and 3 is 3.

*/

#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int findGCD(vector<int>& nums) {
        int smallest=nums[0];
        int largest=nums[0];
        int gcd=1;
        for (int i=0; i<nums.size(); i++){
            if(nums[i]<=smallest){
                smallest = nums[i];
            }
            else if(nums[i]>=largest){
                largest = nums[i];
            }
        
        }
        if(smallest==1){
            return 1;
        }
        else{
            for (int j=1; j<(smallest+1);j++){
                if (smallest % j==0 && largest%j ==0){
                    gcd = j;
                }
            }
        }
        
        return gcd;
    }
};


int main(){
  Solution sol;
  vector<int> nums = {2,5,6,8,10};
  cout<<"The GCD of the smallest and the largest number in the array is: "<<sol.findGCD(nums);
  return 0;
}