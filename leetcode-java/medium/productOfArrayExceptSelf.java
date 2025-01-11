import java.util.Arrays;

public class productOfArrayExceptSelf {
    // Function to calculate the product of array elements except self
    public static int[] productExceptSelf(int[] nums) {
        // Get the size of the input array
        int n = nums.length;

        // Create a new array to store the products, initialized with 1's
        int[] product = new int[n];
        Arrays.fill(product, 1);

        // Calculate the prefix products
        for (int i = 1; i < n; i++) {
            product[i] = product[i - 1] * nums[i - 1];
        }

        // Initialize a variable to store the suffix product
        int right = 1;

        // Calculate the suffix products and multiply with the prefix products
        for (int i = n - 1; i >= 0; i--) {
            product[i] = product[i] * right;
            right = right * nums[i];
        }

        // Return the array of products
        return product;
    }

    public static void main(String[] args) {
        int[] nums = { 1, 2, 3, 4 };
        int[] result = productExceptSelf(nums);

        // Print the result
        for (int i = 0; i < result.length; i++) {
            System.out.print(result[i] + " ");
        }
    }
}