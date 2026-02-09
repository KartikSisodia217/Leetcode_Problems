// This is my solution to Leetcode Problem #242: Valid Anagram

/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.


Example 1:
Input: s = "anagram", t = "nagaram"
Output: true


Example 2:
Input: s = "rat", t = "car"
Output: false
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
  bool isAnagram(string s, string t){
    bool ans = false;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    if (s == t){
      ans = true;
    }
    return ans;
  }
};

int main(){
  Solution sol;
  string s = "anagram";
  string t = "naagram";
  cout<<"The strings are anagrams: "<<sol.isAnagram(s,t)<<endl;
  return 0;
}