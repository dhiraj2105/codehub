class ArrayProblems {

    int maxElement(int[] nums) {
        int max = nums[0];
        for (int num : nums) {
            if (num > max) {
                max = num;
            }
        }
        return max;
    }

    int[] findSubArrayWithSum(int[] arr, int target) {
        int start = 0;
        int currentSum = 0;

        for (int end = 0; end < arr.length; end++) {
            currentSum += arr[end];

            while (currentSum > target && start <= end) {
                currentSum -= arr[start];
                start++;
            }

            if (currentSum == target) {
                return new int[] { start, end };
            }
        }

        return new int[] { -1, -1 }; // Not found
    }
}

class StringProblems {}

public class stringAndArrayProblems {

    /*
     * Arrays Problems
     * Easy
     *
     * Find the maximum element in an array
     * Given an integer array, return the maximum element.
     *
     * Medium
     *
     * Find the subarray with the given sum
     * Given an array of positive integers and a target sum, find a continuous
     * subarray that sums to the target. Return the start and end indices.
     *
     * Find the longest subarray with equal number of 0s and 1s
     * Given a binary array, find the length of the longest contiguous subarray with
     * equal number of 0s and 1s.
     *
     * Hard
     *
     * Median of two sorted arrays
     * Given two sorted arrays of size m and n, find the median of the combined
     * sorted array in O(log(m+n)) time.
     *
     * Strings Problems
     * Easy
     *
     * Check if a string is a palindrome
     * Given a string, check if it reads the same forwards and backwards.
     *
     * Medium
     *
     * Find the length of the longest substring without repeating characters
     * (Sliding Window)
     * Given a string, find the length of the longest substring without repeating
     * characters.
     *
     * Find all anagrams of a pattern in a string (Sliding Window)
     * Given a string and a pattern, find all start indices of the pattern’s
     * anagrams in the string.
     *
     * Hard
     *
     * Minimum window substring (Sliding Window)
     * Given two strings s and t, find the minimum window substring in s which
     * contains all characters of t.
     */
    public static void main(String[] args) {
        ArrayProblems ap = new ArrayProblems();

        int[] nums = { 2, 1, 3, 5, 4 }; // original array (NOT sorted)

        // ✅ Find max element
        System.out.println("The max element in array: " + ap.maxElement(nums));

        // ✅ Find subarray with given sum
        int[] subArrayWithSumRESULT = ap.findSubArrayWithSum(nums, 8);
        if (subArrayWithSumRESULT[0] != -1) {
            System.out.println(
                "Subarray found between indices: " +
                    subArrayWithSumRESULT[0] +
                    " and " +
                    subArrayWithSumRESULT[1]
            );
        } else {
            System.out.println("Subarray with sum not found");
        }
    }
}
