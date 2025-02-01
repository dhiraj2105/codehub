public class trappingRainWater {
    public static int trap(int[] height) {
        // Handle edge case where there are less than 3 bars
        if (height.length < 3) {
            return 0;
        }

        // Declare two arrays to store the maximum height from the left and right
        int[] leftMax = new int[height.length];
        int[] rightMax = new int[height.length];

        // Initialize the first element of the 'leftMax' array to be the height of the
        // first bar
        leftMax[0] = height[0];

        // Loop through the rest of the 'height' array starting from index 1
        for (int i = 1; i < height.length; i++) {
            // For each bar, calculate the maximum height encountered so far from the left
            leftMax[i] = Math.max(leftMax[i - 1], height[i]);
        }

        // Set the last element of the 'rightMax' array to be the height of the last bar
        rightMax[height.length - 1] = height[height.length - 1];

        // Loop through the 'height' array from right to left, starting from the second
        // last element
        for (int i = height.length - 2; i >= 0; i--) {
            // For each bar, calculate the maximum height encountered so far from the right
            rightMax[i] = Math.max(rightMax[i + 1], height[i]);
        }

        // Initialize a variable 'ans' to accumulate the total amount of water trapped
        int ans = 0;

        // Calculate the trapped water for each bar
        for (int i = 0; i < height.length; i++) {
            ans += Math.min(leftMax[i], rightMax[i]) - height[i];
        }

        return ans;
    }

    public static void main(String[] args) {
        int[] height = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 3, 2, 1 };
        System.out.println(trap(height));
    }
}