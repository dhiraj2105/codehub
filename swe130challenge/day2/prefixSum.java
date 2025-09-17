package swe130challenge.day2;

public class prefixSum {
    public static void main(String[] args) {
        int[] nums = { 1, 2, 3, 4, 5 };

        int[] prefixSum = new int[nums.length];

        prefixSum[0] = nums[0];
        for (int i = 1; i < nums.length; i++) {
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }
    }
}
