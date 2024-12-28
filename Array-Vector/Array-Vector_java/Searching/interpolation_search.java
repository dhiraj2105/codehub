import java.util.Scanner;

public class interpolation_search {

    // Function to perform interpolation search
    public static int interpolationSearch(int[] nums, int target) {
        // Initialize low and high pointers
        int low = 0;
        int high = nums.length - 1; // Set high to the last index of the array

        int index; // Variable to store the calculated index
        // Continue searching while the target is within the bounds of the current range
        while (low <= high && target >= nums[low] && target <= nums[high]) {
            // Prevent division by zero if the values at low and high are the same
            if (nums[high] == nums[low]) {
                break;
            }

            // Calculate the estimated index using the interpolation formula
            index = low + (high - low) * (target - nums[low]) / (nums[high] - nums[low]);

            System.out.println("Guessed : " + index);

            // Ensure the calculated index is within the bounds of the array
            if (index < 0 || index >= nums.length) {
                break; // Exit if the index is out of bounds
            }

            // Check if the target is found at the calculated index
            if (target == nums[index]) {
                return index; // Return the index if the target is found
            }
            // If the target is less than the value at the calculated index, adjust the high
            // pointer
            else if (target < nums[index]) {
                high = index - 1; // Narrow the search to the left half
            }
            // If the target is greater than the value at the calculated index, adjust the
            // low pointer
            else {
                low = index + 1; // Narrow the search to the right half
            }
        }
        return -1; // Return -1 if the target is not found
    }

    public static void main(String[] args) {
        // Array must be sorted for interpolation search to work correctly
        int[] arr = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter target value: ");
        int target = scanner.nextInt(); // Input the target value from the user

        // Call the interpolation search function and store the result
        int res = interpolationSearch(arr, target);
        // Output the result
        System.out.println("Index of element is " + res);

        scanner.close(); // Close the scanner
    }
}