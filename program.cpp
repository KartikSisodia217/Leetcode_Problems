//These are my solutions to Leetcode Problem #1390: Four Divisors

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


class Solution1 {
public:
    int sumFourDivisors(vector<int>& nums) {
        int result = 0;
        int currSum = 0;
        int divisors = 0;
        for (int i=0; i<nums.size();i++){
            int num = nums[i];
            for (int j=1; j<=num; j++){
                
                if(divisors>4){
                    break;
                }
                if(num % j  == 0){
                    currSum += j;
                    divisors +=1;
                }
            }
            if(divisors == 4){
                result += currSum;
            }
            currSum = 0;
            divisors = 0;
        };
        return result;
    }
};
class Solution2 {
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
  Solution1 sol1;
  Solution2 sol2;
  vector<int> nums = {21, 4, 7};
  cout<<"Output from solution 1: "<<sol1.sumFourDivisors(nums)<<endl;
  cout<<"Output from solution 2: "<<sol2.sumFourDivisors(nums)<<endl;
  return 0;
}

