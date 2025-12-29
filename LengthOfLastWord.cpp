//This is my solution to Leetcode problem #58: Length of last word

/*

Given a string s consisting of words and spaces, return the length of the last word in the string.
A word is a maximal substring consisting of non-space characters only.

 

Example 1:
Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.


Example 2:
Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.


Example 3:
Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.


*/


#include<iostream>
#include<string>
using namespace std;


class Solution {
public:
    int lengthOfLastWord(string s) {
        bool wordstart = false;
        int len = s.size();
        int output = 0;
        for (int i = len-1;i>=0;i-- ){
            if(!wordstart){
               if(s[i]!=' '){
                output = output + 1;
                wordstart = true;
               } 
            }
            else{
                
                if(s[i] != ' '){
                    output = output + 1;
                }
                else{
                    break;
                }
                
            }
        }
        return output;
    }
};


int main() {
  Solution sol;
  string s;

  cout << "Enter a string: ";
  getline(cin, s);

  cout << "Length of last word: " << sol.lengthOfLastWord(s) << endl;

  return 0;
}
