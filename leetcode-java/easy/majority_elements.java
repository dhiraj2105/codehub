import java.util.HashMap;
import java.util.Map;

public class majority_elements {
    // Function to find the majority element
    public static int majorityElement(int[] nums) {
        // Create a map to store the frequency of each element
        Map<Integer, Integer> numMap = new HashMap<>();

        // Iterate through the array to count the frequency of each element
        for (int num : nums) {
            numMap.put(num, numMap.getOrDefault(num, 0) + 1); // Increment the count for the current element
        }

        // Iterate through the map to find the element with frequency > n/2
        for (Map.Entry<Integer, Integer> entry : numMap.entrySet()) {
            if (entry.getValue() > nums.length / 2) {
                return entry.getKey(); // Return the majority element
            }
        }
        return -1; // Return -1 if no majority element is found (though the problem states it
                   // always exists)
    }

    public static void main(String[] args) {
        /*
         * Given an array nums of size n, return the majority element.
         * 
         * The majority element is the element that appears more than ⌊n / 2⌋ times. You
         * may assume that the majority element always exists in the array.
         */
        int[] nums = { 3, 2, 3, 3, 3, 2 };

        // Call the majorityElement function and print the result
        System.out.println(majorityElement(nums));
    }
}