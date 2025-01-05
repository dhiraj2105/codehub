import java.util.Arrays;

public class ThreeSumClosest {

    public static int threeSumClosest(int[] nums, int target) {

        Arrays.sort(nums);
        int closestSum = Integer.MAX_VALUE;
        int res = 0;

        for (int i = 0; i < nums.length; i++) {
            int left = i + 1;
            int right = nums.length - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (Math.abs(sum - target) < closestSum) {
                    closestSum = Math.abs(sum - target);
                    res = sum;
                } else if (Math.abs(sum - target) == closestSum) {
                    res = Math.min(res, sum);
                }
                if (sum > target) {
                    right--;
                } else {
                    left++;
                }
            }
        }

        return res;
    }

    public static void main(String[] args) {
        /*
         * Given an integer array nums of length n and an integer target, find three
         * integers in nums such that the sum is closest to target.
         * 
         * Return the sum of the three integers.
         * 
         * You may assume that each input would have exactly one solution.
         */
        int[] nums = { -1, 2, 1, -4 };
        int target = 1;

        System.out.println(threeSumClosest(nums, target));
    }
}