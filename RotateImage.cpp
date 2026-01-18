//This is my solution to Leetcode Problem #48: Rotate Image 


/* 
You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
You have to rotate the image in-place, which means you have to modify the input 2D matrix directly.
DO NOT allocate another 2D matrix and do the rotation. 


  Example 1: 
  Input: matrix = [[1,2,3],[4,5,6],[7,8,9]] 
  Output: [[7,4,1],[8,5,2],[9,6,3]] 
  Example 2: 


  Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]] 
  Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]] 
  */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// This solution does NOT follow the constraint "DO NOT allocate another 2D matrix and do the rotation."
class Solution1 {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> result = matrix;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int x = j;
                int y = n - 1 - i;
                result[x][y] = matrix[i][j];
            }
        }

        matrix = result;
    }
};


// This solution follows all constraints 
class Solution2 {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};


int main() {
    Solution1 sol1;
    Solution2 sol2;

    vector<vector<int>> matrix1 = {
        {5, 1, 9, 11},
        {2, 4, 8, 10},
        {13, 3, 6, 7},
        {15, 14, 12, 16}
    };

    vector<vector<int>> matrix2 = {
        {0, 1, 2, 3, 4},
        {5, 6, 7, 8, 9},
        {9, 8, 7, 6, 5},
        {4, 3, 2, 1, 0},
        {1, 2, 3, 4, 5}
    };

    cout << "This is the input for solution 1:\n";
    for (int i = 0; i < matrix1.size(); i++) {
        cout << "[ ";
        for (int j = 0; j < matrix1[i].size(); j++) {
            cout << matrix1[i][j];
            if (j != matrix1[i].size() - 1) cout << ", ";
        }
        cout << " ]\n";
    }

    sol1.rotate(matrix1);

    cout << "This is the output for input 1:\n";
    for (int i = 0; i < matrix1.size(); i++) {
        cout << "[ ";
        for (int j = 0; j < matrix1[i].size(); j++) {
            cout << matrix1[i][j];
            if (j != matrix1[i].size() - 1) cout << ", ";
        }
        cout << " ]\n";
    }

    cout << "This is the input for solution 2:\n";
    for (int i = 0; i < matrix2.size(); i++) {
        cout << "[ ";
        for (int j = 0; j < matrix2[i].size(); j++) {
            cout << matrix2[i][j];
            if (j != matrix2[i].size() - 1) cout << ", ";
        }
        cout << " ]\n";
    }

    sol2.rotate(matrix2);

    cout << "This is the output for input 2:\n";
    for (int i = 0; i < matrix2.size(); i++) {
        cout << "[ ";
        for (int j = 0; j < matrix2[i].size(); j++) {
            cout << matrix2[i][j];
            if (j != matrix2[i].size() - 1) cout << ", ";
        }
        cout << " ]\n";
    }

    return 0;
}
