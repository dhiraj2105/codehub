import java.util.HashMap;

public class SubarraySumEqualsK {

    public static int subarraySum(int[] nums, int k) {
        // Step 1: Initialize a hashmap to store the frequency of each prefix sum
        HashMap<Integer, Integer> mpp = new HashMap<>();

        // Step 2: Initialize the map with a prefix sum of 0 having frequency 1
        mpp.put(0, 1);

        // Step 3: Initialize variables to track the current prefix sum and the result
        // count
        int prefixSum = 0, count = 0;

        // Step 4: Traverse through the array to calculate the prefix sum at each index
        for (int num : nums) {
            // Update the prefix sum by adding the current element
            prefixSum += num;

            // Step 5: Check if there exists a previous prefix sum such that (prefixSum - k)
            // has occurred
            // If it exists, it means we've found a subarray with sum = k
            if (mpp.containsKey(prefixSum - k)) {
                // Add the frequency of prefixSum - k to the result count
                count += mpp.get(prefixSum - k);
            }

            // Step 6: Update the hashmap with the current prefix sum
            mpp.put(prefixSum, mpp.getOrDefault(prefixSum, 0) + 1);
        }

        // Step 7: Return the total count of subarrays with sum = k
        return count;
    }

    public static void main(String[] args) {
        // Example input array
        int[] nums = { 1, 2, 3, -3, 1, 1, 1, 4, 2, -3 };
        int k = 3;

        // Call the subarraySum function and output the result
        System.out.println("Total subarrays with sum " + k + ": " + subarraySum(nums, k));
    }
}
