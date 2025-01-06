
public class medianOfTwoSortedArrays {
    public static double median(int[] arr1, int[] arr2) {
        // Get the lengths of the input arrays
        int m = arr1.length;
        int n = arr2.length;

        // If the total length of the arrays is odd, the median is the middle element
        // If the total length is even, the median is the average of the two middle
        // elements
        // We use the formula (m + n + 1) / 2 to handle both cases
        int totalLength = m + n;
        int halfLength = (totalLength + 1) / 2;

        // Initialize variables to store the current index and the current median
        int i = 0, j = 0;
        int currentMedian = 0;

        // Loop through the arrays until we reach the middle element
        for (int k = 0; k < halfLength; k++) {
            // If we've reached the end of the first array, the current median is the next
            // element in the second array
            if (i == m) {
                currentMedian = arr2[j++];
            }
            // If we've reached the end of the second array, the current median is the next
            // element in the first array
            else if (j == n) {
                currentMedian = arr1[i++];
            }
            // If the current element in the first array is smaller than the current element
            // in the second array,
            // the current median is the current element in the first array
            else if (arr1[i] < arr2[j]) {
                currentMedian = arr1[i++];
            }
            // Otherwise, the current median is the current element in the second array
            else {
                currentMedian = arr2[j++];
            }
        }

        // If the total length of the arrays is even, we need to find the next element
        // and return the average
        if (totalLength % 2 == 0) {
            // Find the next element
            int nextMedian = 0;
            if (i == m) {
                nextMedian = arr2[j++];
            } else if (j == n) {
                nextMedian = arr1[i++];
            } else if (arr1[i] < arr2[j]) {
                nextMedian = arr1[i++];
            } else {
                nextMedian = arr2[j++];
            }

            // Return the average of the two middle elements
            return (currentMedian + nextMedian) / 2.0;
        }

        // If the total length of the arrays is odd, return the middle element
        return currentMedian;
    }

    public static void main(String[] args) {
        int[] nums1 = { 1, 3 };
        int[] nums2 = { 2, 4 };

        System.out.println(median(nums1, nums2));
    }
}
