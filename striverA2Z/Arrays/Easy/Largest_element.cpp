#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int bruteForce(int nums[], int size) {
  // compare each element with current maximum element
  int maxElement = nums[0];

  for (int i = 1; i < size; i++) {
    if (nums[i] > maxElement) {
      maxElement = nums[i];
    }
  }

  return maxElement;
}

int bruteForce2(int nums[], int size) {
  // sort in ascending order and return last element
  // SORTING
  sort(nums, nums + size);
  return nums[size-1];
}

int best(int nums[], int size) { return 0; }

int main() {
  // Find the largest element from the array
  int arr[] = {2, 5, 1, 3, 0};
  int size = sizeof(arr) / sizeof(arr[0]);

  cout << "Largest Element from the array : " << bruteForce(arr, size) << endl;
  cout << "Largest Element from the array : " << bruteForce2(arr, size) << endl;
  cout << "Largest Element from the array : " << best(arr, size) << endl;
}
