// This is my solution of leetcode problem #3: Longest Substring Without Repeating Characters

/*
Given a string s, find the length of the longest substring without duplicate characters.

 

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.


Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.


Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

*/


#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        int x=0;
        int y=0;
        int z = 0;
        int result = 0;
        bool found = false;
        for (int i = 0; i<len; i++){
            if(y==0 && i==0){
                x++;
                y++;
            }
            else{
                for(int j = z; j<i; j++){
                    if(s[i]==s[j]){
                        found = true;
                        z=j+1;
                        break;
                    }
                }
                if(found){
                    x=0;
                    y=i-z+1;
                    found = false;
                }
                else{
                    y++;
                    x++;
                }
            }
            if(y>=result){
                result = y;
            }
        }
        return result;
    }
};


int main() {
    Solution sol;
    string input = "abcabcbb"; 
    int result = sol.lengthOfLongestSubstring(input);
    cout << "Longest substring length: " << result << endl;
    return 0;
}
