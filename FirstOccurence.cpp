// This is my solution to Leetcode Problem #28

/*

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 
Example 1:
Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.


Example 2:
Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.

*/


#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) return 0;


        for (int i = 0; i + needle.size() <= haystack.size(); i++) {
            int counter = 0;
            if (haystack[i] == needle[0]) {
                for (int j = 0; j < needle.size(); j++) {
                    if (haystack[i + j] != needle[j]) break;
                    counter++;
                }
            }

            if (counter == needle.size()) return i;
        }
        
        return -1;
    }
};


int main(){
  Solution sol;
  string haystack = "sadbutsad";
  string needle = "sad";
  cout<<"The first occurence of needle in haystack is at index: "<<sol.strStr(haystack,needle)<<endl;
  return 0;
}