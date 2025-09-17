package swe130challenge.day2;

public class subarraySum {
    public static void main(String[] args) {
        int[] arr = { 1, 2, 3 };
        int n = arr.length;

        System.out.println("All Subarray Sums:");
        for (int start = 0; start < n; start++) {
            int sum = 0;
            for (int end = start; end < n; end++) {
                sum += arr[end];
                System.out.println("Sum of subarray [" + start + "..." + end + "] = " + sum);
            }
        }
    }

}
