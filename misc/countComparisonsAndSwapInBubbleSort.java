package misc;

public class countComparisonsAndSwapInBubbleSort {

    public static void BubbleSort(int[] nums) {
        int totalComparisions = 0;
        int totalSwap = 0;

        for (int i = 0; i < nums.length; i++) {
            for (int j = 0; j < nums.length - i - 1; j++) {
                totalComparisions++;
                if (nums[j] > nums[j + 1]) {
                    int temp = nums[j];
                    nums[j] = nums[j + 1];
                    nums[j + 1] = temp;
                    totalSwap++;
                }
            }
        }

        // print new array
        for (int i = 0; i < nums.length; i++) {
            System.out.print(nums[i] + " ");
        }

        System.out.println("Total number of comparisions " + totalComparisions);
        System.out.println("Total number of swaps " + totalSwap);
    }

    public static void main(String[] args) {
        int[] nums = { 5, 1, 4, 2, 8 };

        BubbleSort(nums);
    }
}
