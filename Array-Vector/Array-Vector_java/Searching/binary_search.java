import java.util.Arrays;
import java.util.Scanner;

public class binary_search {
    public static void main(String[] args) {
        // Initialize the sorted array
        int[] nums = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

        // Create a Scanner object for user input
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the target number: ");
        int target = scanner.nextInt();

        // Sort the array (not necessary here since it's already sorted)
        Arrays.sort(nums);

        // Initialize low and high pointers
        int low = 0;
        int high = nums.length - 1;
        boolean found = false;

        // Perform binary search
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (target == nums[mid]) {
                System.out.println("Target found at index " + mid);
                found = true;
                break;
            } else if (target > nums[mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        // Check if the target was found
        if (!found) {
            System.out.println("Target not found");
        }

        // Close the scanner
        scanner.close();
    }
}