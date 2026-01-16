#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                }
            }
        }
    }
};

int main() {
    Solution sol;

    vector<int> nums = {2, 0, 2, 1, 1, 0};

    cout<<"input: ";
    for (int x : nums) {
        cout << x << " ";
    }
    cout<<endl;

    sol.sortColors(nums);
    cout<<"output: ";
    for (int x : nums) {
        cout << x << " ";
    }
    cout<<endl;

    return 0;
}
