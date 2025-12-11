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
        return 0;
    }

    int pivotIndex(int[] nums) {
        return 0;
    }

    int[] leftProduct(int[] nums) {
        return nums;
    }

    int[] rightProduct(int[] nums) {
        return nums;
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
        int[] nums = { 1, 2, 3, 4, 5 };

        // prefix sum array
        printArr("Prefix Sum Array Result :", PrefixArray.prefixArray(nums));
        // suffix sum array
        printArr("Suffix Sum Array Result :", SuffixArray.suffixArray(nums));
    }
}
