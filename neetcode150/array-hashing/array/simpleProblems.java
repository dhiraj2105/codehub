/**
 * 1. Searching Algorithms : Linear and Binary
 * 2. Sorting Algorithms : Bubble Sort
 * 3. Simple problems : reverse array, find max element
 */

class SearchingAlgorithms {
    public static int linearSearch(int nums[], int target) {
        System.out.println("---> linear search");

        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == target) {
                return i;
            }
        }
        return 0;
    }

    public static int binarySearch(int nums[], int target) {
        // the array must be SORTED
        SortingAlgorithms.bubbleSort(nums);
        // logic
        int low = 0, high = nums.length - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (target == nums[mid]) {
                return mid;
            }
            if (target < nums[mid]) {
                high = mid - 1;
            }
            if (target > nums[mid]) {
                low = mid + 1;
            }
        }

        return 0;
    }
}

class SortingAlgorithms {
    public static int[] bubbleSort(int nums[]) {
        for (int i = 0; i < nums.length - 1; i++) {
            for (int j = 0; j < nums.length - 1 - i; j++) {
                if (nums[j] > nums[j + 1]) {
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                }
            }
        }
        return nums;
    }

}

public class simpleProblems {
    // print array
    static void printArray(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            System.out.print(nums[i] + " ");
        }
        System.out.println("\n");
    }

    public static void main(String[] args) {
        int nums[] = { 10, 30, 40, 20, 50 };
        int target = 40;

        // Searching Algorithms
        int linearIDX = SearchingAlgorithms.linearSearch(nums, target);
        int binaryIDX = SearchingAlgorithms.binarySearch(nums, target);

        System.out.println("The target : " + target + " founded by linear search at index : " + linearIDX);
        System.out.println("The target : " + target + " founded by binary search at index : " + binaryIDX);

        // Sorting Algorithm
        System.out.print("Array Sorted using bubble sort : ");
        printArray(SortingAlgorithms.bubbleSort(nums));
    }
}