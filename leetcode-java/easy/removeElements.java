import java.util.Arrays;

public class removeElements {

    // Function to remove all occurrences of 'val' from the array 'nums'
    public static int removElements(int[] nums, int val) {
        int k = 0; // Pointer to track the position of elements not equal to 'val'
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != val) {
                nums[k] = nums[i]; // Move the element to the front of the array
                k++; // Increment the pointer
            }
        }
        return k; // Return the count of elements not equal to 'val'
    }

    public static void main(String[] args) {
        /*
         * Given an integer array nums and an integer val, remove all occurrences of val
         * in nums in-place.
         * The order of the elements may be changed. Then return the number of elements
         * in nums which are not equal to val.
         * 
         * Consider the number of elements in nums which are not equal to val be k, to
         * get accepted, you need to do the following things:
         * 
         * Change the array nums such that the first k elements of nums contain the
         * elements which are not equal to val.
         * The remaining elements of nums are not important as well as the size of nums.
         * Return k.
         */

        int[] nums = { 0, 1, 2, 2, 3, 0, 4, 2 }; // Input array
        int val = 2; // Value to remove

        int result = removElements(nums, val); // Call the function
        System.out.println(result); // Print the result

        // Optional: Print the modified array to verify the result
        System.out.println(Arrays.toString(Arrays.copyOfRange(nums, 0, result)));
    }
}