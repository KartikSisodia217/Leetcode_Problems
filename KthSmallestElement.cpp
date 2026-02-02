//This is my solution to Leetcode Problem #378: Kth Smallest Element in a Sorted Matrix

/*
Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.
Note that it is the kth smallest element in the sorted order, not the kth distinct element.



Example 1:
Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: The elements in the matrix are [1,5,9,10,11,12,13,13,15], and the 8th smallest number is 13


Example 2:
Input: matrix = [[-5]], k = 1
Output: -5
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    int total = matrix.size() * matrix[0].size();
    vector<int> temp(total);
    int index = 0;

    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[i].size(); j++) {
        temp[index] = matrix[i][j];
        index++;
      }
    }

    sort(temp.begin(), temp.end());
    return temp[k - 1];
  }
};

int main() {
  vector<vector<int>> matrix = {
    {1, 5, 9},
    {10, 11, 13},
    {12, 13, 15}
  };
  int k = 8;

  Solution s;
  cout <<"Solution: "<< s.kthSmallest(matrix, k)<<endl;
  return 0;
}


