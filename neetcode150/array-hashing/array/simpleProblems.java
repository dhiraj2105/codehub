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

}

class SortingAlgorithms {
    int[] bubbleSort(int nums[]) {
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
            System.out.println(nums[i] + " ");
        }
    }

    public static void main(String[] args) {
        int nums[] = { 10, 20, 40, 20, 50 };
        int target = 40;

        // Searching Algorithms
        int linearIDX = SearchingAlgorithms.linearSearch(nums, target);

        System.out.println("The target : " + target + " founded by linear search at index : " + linearIDX);
    }
}