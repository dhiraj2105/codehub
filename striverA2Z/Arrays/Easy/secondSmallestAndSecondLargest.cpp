#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<int> bruteForce(vector<int> nums)
{
  vector<int> result;
  // Sort the array and return the size-2 for second largest and 1st index for
  sort(nums.begin(), nums.end());

  result.push_back(nums[1]);
  result.push_back(nums[nums.size() - 2]);

  return result;
}

vector<int> better(vector<int> nums)
{
  // Traverse the array and find smallest and largest,
  // then traverse the array again to find element just greater than smallest and just smaller than largest

  int largest = nums[0];
  int smallest = nums[0];
  int secondSmallest = INT_MAX;
  int secondLargest = INT_MIN;

  for (int i = 1; i < nums.size(); i++)
  {
    if (nums[i] > largest)
    {
      largest = nums[i];
    }
    if (nums[i] < smallest)
    {
      smallest = nums[i];
    }
  }

  for (int i = 0; i < nums.size(); i++)
  {
    if (nums[i] > smallest && nums[i] < secondSmallest)
    {
      secondSmallest = nums[i];
    }
    if (nums[i] < largest && nums[i] > secondLargest)
    {
      secondLargest = nums[i];
    }
  }

  return {secondSmallest, secondLargest};
}

int main()
{
  // Find the second largest and second smallest element from the array, Print
  // -1 if either of them is not exist.
  vector<int> nums = {1, 2, 4, 8, 7, 5};

  // USING BRUTE FORCE METHOD
  cout << "-> The second smallest and second largest element from the array are : ";
  for (int element : bruteForce(nums))
  {
    cout << element << " ";
  }

  cout << endl;

  // USING BETTER METHOD
  cout << "-> The second smallest and second largest element from the array are : ";
  for (int element : better(nums))
  {
    cout << element << " ";
  }

  cout << endl;

  return 0;
}
