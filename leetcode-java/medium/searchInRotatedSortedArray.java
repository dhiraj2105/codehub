
public class searchInRotatedSortedArray {

    // Function to search for the target in a rotated sorted array
    public static int search(int[] nums, int target) {
        int low = 0;
        int high = nums.length - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // If the target is found at mid, return the index
            if (nums[mid] == target) {
                return mid;
            }

            // Check if the left half is sorted
            if (nums[low] <= nums[mid]) {
                // If the target is within the sorted left half, search in the left half
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    // Otherwise, search in the right half
                    low = mid + 1;
                }
            } else {
                // If the right half is sorted, check if the target is within the sorted right
                // half
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    // Otherwise, search in the left half
                    high = mid - 1;
                }
            }
        }

        // If the target is not found, return -1
        return -1;
    }

    public static void main(String[] args) {
        int[] nums = { 4, 5, 6, 7, 0, 1, 2 };
        int target = 0;
        int result = search(nums, target);
        System.out.println("The index of the target is: " + result);
    }
}