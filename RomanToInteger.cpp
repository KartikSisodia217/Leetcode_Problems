//These are my solutions of Leetcode problem #13: Roman to Integer
/*

Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII,
which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for
four is not IIII. Instead, the number four is written as IV. Because the one is before the five we 
subtract it making four. The same principle applies to the number nine, which is written as IX. 
There are six instances where subtraction is used:
-I can be placed before V (5) and X (10) to make 4 and 9. 
-X can be placed before L (50) and C (100) to make 40 and 90. 
-C can be placed before D (500) and M (1000) to make 400 and 900.




Given a roman numeral, convert it to an integer. 

Example 1:
Input: s = "III"
Output: 3
Explanation: III = 3.

Example 2:
Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.

Example 3:
Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 


*/

#include<iostream>
#include<string>
using namespace std;

//This was my first solution
class Solution1 {
public:
    int romanToInt(string s) {
        bool IX = false;
        bool IV = false;
        bool XL = false;
        bool XC = false;
        bool CD = false;
        bool CM = false;
        int output = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'I') {
                if (s[i + 1] == 'V') {
                    IV = true;
                    output = output + 4;
                }
                else if (s[i + 1] == 'X') {
                    IX = true;
                    output = output + 9;
                }
                else {
                    output = output + 1;
                }
            }

            else if (s[i] == 'X') {
                if (s[i + 1] == 'L') {
                    XL = true;
                    output = output + 40;
                }
                else if (s[i + 1] == 'C') {
                    XC = true;
                    output = output + 90;
                }
                else {
                    output = output + 10;
                }
            }

            else if (s[i] == 'C') {
                if (s[i + 1] == 'D') {
                    CD = true;
                    output = output + 400;
                }
                else if (s[i + 1] == 'M') {
                    CM = true;
                    output = output + 900;
                }
                else {
                    output = output + 100;
                }
            }

            else if (s[i] == 'V') {
                output = output + 5;
            }
            else if (s[i] == 'L') {
                output = output + 50;
            }
            else if (s[i] == 'D') {
                output = output + 500;
            }
            else if (s[i] == 'M') {
                output = output + 1000;
            }
        }

        if (IX == true) {
            output = output - 10;
        }
        if (IV == true) {
            output = output - 5;
        }
        if (XL == true) {
            output = output - 50;
        }
        if (XC == true) {
            output = output - 100;
        }
        if (CD == true) {
            output = output - 500;
        }
        if (CM == true) {
            output = output - 1000;
        }

        return output;
    }
};
//This was my second and more optimised solution
class Solution2 {
public:
    int func(char c){
        switch(c){
            case 'M': return 1000;  case 'D': return 500;
            case 'C': return 100;   case 'L': return 50;
            case 'X': return 10;    case 'V': return 5;
            case 'I': return 1;     default: return 53;
        }
    }
    int romanToInt(string s) {
        int size=s.length();
        int sum=0;
        for(int i=0;i<size;i++){
          if(i+1<size && func(s[i])<func(s[i+1])){
            sum-=func(s[i]);
          }else{
            sum+=func(s[i]);
          }
        }
        return sum;
    }
};

int main() {
    string s;
    cout << "Enter Roman numeral: ";
    cin >> s;

    Solution1 sol1;
    Solution2 sol2;

    cout << "Solution1 Output: " << sol1.romanToInt(s) << endl;
    cout << "Solution2 Output: " << sol2.romanToInt(s) << endl;

    return 0;
}

