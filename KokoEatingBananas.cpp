// This is my solution to Leetcode Problem #875: Koko Eating Bananas

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
