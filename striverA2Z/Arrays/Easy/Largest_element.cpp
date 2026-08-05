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

int best(int nums[], int size) { return 0; }

int main() {
  // Find the largest element from the array
  int arr[] = {2, 5, 1, 3, 0};
  int size = sizeof(arr) / sizeof(arr[0]);

  cout << "Largest Element from the array : " << bruteForce(arr, size) << endl;
  cout << "Largest Element from the array : " << best(arr, size) << endl;
}
