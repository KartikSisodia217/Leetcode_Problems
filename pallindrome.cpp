//This is my solution to leetcode problem #9: Pallindrome number

/*

Given an integer x, return true if x is a palindrome, and false otherwise.


Example 1:
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.


Example 2:
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.


Example 3:
Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

*/


#include<iostream>
using namespace std;


class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0){
            return false;
        }
        long long ans=0, num=x;
        while(num>0){
            ans=(ans*10)+num%10;
            num/=10;
        }
        return ans==x;
    }
};


int main(){
  Solution s;

  int x;
  cout << "Enter an integer: ";
  cin >> x;

  bool result = s.isPalindrome(x);

  if (result){
    cout << "Palindrome" << endl;
  }
  else{
    cout << "Not a Palindrome" << endl;
  }      
  return 0;
}