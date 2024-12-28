import java.util.Vector;

public class linear_search {

    public static void main(String[] args) {
        // Initialize a Vector and add some integers
        Vector<Integer> nums = new Vector<>();
        nums.add(1);
        nums.add(2);
        nums.add(3);
        nums.add(4);
        nums.add(5);

        // Define the target value to search for
        int target = 4;

        // Call the linear search method
        int index = linearSearch(nums, target);

        // Output the result
        if (index != -1) {
            System.out.println("Element found at index: " + index);
        } else {
            System.out.println("Element not found.");
        }
    }

    // Method to perform linear search
    public static int linearSearch(Vector<Integer> nums, int target) {
        // Iterate through the Vector
        for (int i = 0; i < nums.size(); i++) {
            // Check if the current element matches the target
            if (nums.get(i) == target) {
                return i; // Return the index if found
            }
        }
        return -1; // Return -1 if the target is not found
    }
}