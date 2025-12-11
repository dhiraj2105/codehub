// both prefix and suffix has same logic
// prefix is from left to right
// suffix is right to left

class PrefixArray {
    public static int[] prefixArray(int[] nums) {

        int[] prefixSumArray = new int[nums.length];
        prefixSumArray[0] = nums[0];

        for (int i = 1; i < nums.length; i++) {
            prefixSumArray[i] = prefixSumArray[i - 1] + nums[i];
        }

        return prefixSumArray;
    }
}

class SuffixArray {
    public static int[] suffixArray(int[] nums) {
        int[] suffixSumArray = new int[nums.length];
        suffixSumArray[nums.length - 1] = nums[nums.length - 1];

        for (int i = nums.length - 2; i >= 0; i--) {
            suffixSumArray[i] = suffixSumArray[i + 1] + nums[i];
        }
        return suffixSumArray;
    }
}

class Problems {
    int rangeSum(int[] prefix, int l, int r) {
        if (l == 0) {
            return prefix[r];
        }
        return prefix[r] - prefix[l - 1];
    }

    int pivotIndex(int[] nums) {

        int leftSum = 0;
        int rightSum = 0;
        int val;

        for (int num : nums) {
            rightSum += num;
        }

        for (int i = 0; i < nums.length; i++) {
            val = nums[i];
            rightSum = rightSum - val;
            if (leftSum == rightSum) {
                return i;
            }
            leftSum = leftSum + val;
        }

        return -1;
    }
}

public class PrefixSuffixAndProblems {

    static void printArr(String msg, int[] nums) {
        System.out.print(" " + msg + " ");
        for (int i = 0; i < nums.length; i++) {
            System.out.print(nums[i] + " ");
        }
        System.out.println("\n");
    }

    public static void main(String[] args) {
        // int[] nums = { 1, 2, 3, 4, 5 };
        int[] nums = { 1, 7, 3, 6, 5, 6 };

        // prefix sum array
        printArr("Prefix Sum Array Result :", PrefixArray.prefixArray(nums));
        // suffix sum array
        printArr("Suffix Sum Array Result :", SuffixArray.suffixArray(nums));

        // Problems
        Problems p = new Problems();
        System.out.println("The range Sum : " +
                p.rangeSum(PrefixArray.prefixArray(nums), 1, 4));

        System.out.println("The pivot Index of given array is : " + p.pivotIndex(nums));
    }
}
