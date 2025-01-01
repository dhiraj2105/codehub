public class merge_sort {

    public static void conquer(int[] arr, int si, int mid, int ei) {
        // Create a temporary array to hold the merged subarray
        int[] merged = new int[ei - si + 1];

        // Pointers for the left and right halves
        int left = si; // Start of the left half
        int right = mid + 1; // Start of the right half
        int idx = 0; // Index for the merged array

        // Merge the two halves by comparing their elements
        while (left <= mid && right <= ei) {
            if (arr[left] <= arr[right]) {
                merged[idx++] = arr[left++]; // Copy smaller element from the left half
            } else {
                merged[idx++] = arr[right++]; // Copy smaller element from the right half
            }
        }

        // Copy any remaining elements from the left half
        while (left <= mid) {
            merged[idx++] = arr[left++];
        }

        // Copy any remaining elements from the right half
        while (right <= ei) {
            merged[idx++] = arr[right++];
        }

        // Copy the merged array back into the original array
        for (int i = 0; i < merged.length; i++) {
            arr[si + i] = merged[i]; // Place merged elements in the correct position
        }
    }

    public static void divide(int[] arr, int si, int ei) {

        if (si >= ei) {
            return;
        }

        int mid = si + (ei - si) / 2;

        // for left subArray
        divide(arr, si, mid);
        // for right subArray
        divide(arr, mid + 1, ei);

        conquer(arr, si, mid, ei);
    }

    public static void main(String[] args) {
        int arr[] = { 5, 2, 8, 1, 9 };
        int n = arr.length;

        divide(arr, 0, n - 1);

        // print array
        for (int i = 0; i < n; i++) {
            System.out.print(arr[i] + " ");
        }
    }
}