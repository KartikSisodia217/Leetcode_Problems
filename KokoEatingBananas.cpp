// This is my solution to Leetcode Problem #875: Koko Eating Bananas

/*
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.
Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
Return the minimum integer k such that she can eat all the bananas within h hours.

 

Example 1:
Input: piles = [3,6,7,11], h = 8
Output: 4


Example 2:
Input: piles = [30,11,23,4,20], h = 5
Output: 30


Example 3:
Input: piles = [30,11,23,4,20], h = 6
Output: 23
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std; 

class Solution
{
public:
  int minEatingSpeed(vector<int> &bananas, int hoursLimit)
  {

    int left = 1;
    int right = *max_element(bananas.begin(), bananas.end());
    int bestSpeed = right;

    while (left <= right)
    {
      int speed = left + (right - left) / 2;
      long long timeNeeded = 0;

      for (int pile : bananas)
      {
        timeNeeded += (pile + speed - 1) / speed;
        if (timeNeeded > hoursLimit)
          break;
      }

      if (timeNeeded <= hoursLimit)
      {
        bestSpeed = speed;
        right = speed - 1;
      }
      else
      {
        left = speed + 1;
      }
    }

    return bestSpeed;
  }
};

int main()
{
  int n;
  cin >> n;

  vector<int> bananas(n);
  for (int i = 0; i < n; i++)
  {
    cin >> bananas[i];
  }

  int hoursLimit;
  cin >> hoursLimit;

  Solution obj;
  cout << obj.minEatingSpeed(bananas, hoursLimit);

  return 0;
}
