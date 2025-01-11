import java.util.Arrays;

public class sortColors {

    public static void SortColors(int[] nums) {
        if (nums.length <= 1) {
            return;
        }
        int mid = nums.length / 2;
        int[] leftArr = Arrays.copyOfRange(nums, 0, mid);
        int[] rightArr = Arrays.copyOfRange(nums, mid, nums.length);

        SortColors(leftArr);
        SortColors(rightArr);
        merger(nums, leftArr, rightArr);
    }

    public static void merger(int[] nums, int[] leftArr, int[] rightArr) {
        int i = 0, l = 0, r = 0;

        while (l < leftArr.length && r < rightArr.length) {
            if (leftArr[l] < rightArr[r]) {
                nums[i++] = leftArr[l++];
            } else {
                nums[i++] = rightArr[r++];
            }
        }
        while (l < leftArr.length) {
            nums[i++] = leftArr[l++];
        }
        while (r < rightArr.length) {
            nums[i++] = rightArr[r++];
        }
    }

    public static void main(String[] args) {
        /*
         * Given an array nums with n objects colored red, white, or blue, sort them
         * in-place so that objects of the same color are adjacent, with the colors in
         * the order red, white, and blue.
         * 
         * We will use the integers 0, 1, and 2 to represent the color red, white, and
         * blue, respectively.
         * 
         * You must solve this problem without using the library's sort function.
         */
        int[] nums = { 2, 0, 2, 1, 1, 0 };

        SortColors(nums);

        for (int i = 0; i < nums.length; i++) {
            System.out.print(nums[i] + " ");
        }
    }
}