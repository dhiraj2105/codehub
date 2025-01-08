public class valid_mountain_arr {
    public static boolean validMountainArray(int[] arr) {
        int i = 0;
        int j = arr.length - 1;
        int n = arr.length - 1;

        while (i + 1 < n && arr[i] < arr[i + 1]) {
            i++;
        }
        while (j > 0 && arr[j] < arr[j - 1]) {
            j--;
        }

        return (i > 0 && i == j && j < n);
    }

    public static void main(String[] args) {
        /*
         * Given an array of integers arr, return true if it is a valid mountain array.
         */
        int[] arr = { 0, 3, 2, 1 };

        System.out.println(validMountainArray(arr));
    }
}