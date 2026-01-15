// This is my solution to Leetcode Problem #50: Pow(x,n)

/*
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).

 
Example 1:
Input: x = 2.00000, n = 10
Output: 1024.00000


Example 2:
Input: x = 2.10000, n = 3
Output: 9.26100


Example 3:
Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
*/

#include<iostream>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;     
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        double ans = 1;

        while (N > 0) {
            if (N % 2 == 1) {
                ans *= x;
            }
            x *= x;
            N /= 2;
        }

        return ans;
    }
};


int main(){
  Solution sol;
  double x;
  int n;
  cout<<"Enter the value of x (can have decimal places): ";
  cin>>x;
  cout<<"Enter value of integer n: ";
  cin>>n;
  cout<<"The value of "<<x<<" to the power "<<n<<" is: "<<sol.myPow(x,n)<<endl;
  return 0;
}