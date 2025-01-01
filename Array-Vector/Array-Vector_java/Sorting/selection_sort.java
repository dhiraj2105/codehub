public class selection_sort {
    public static void main(String[] args) {

        int[] nums = { 2, 1, 6, 3, 7, 8, 9, 4, 5 };
        int n = nums.length;

        int min, temp; // temp is used to swap elements
        for (int i = 0; i < n - 1; i++) {
            min = i;
            for (int j = i + 1; j < n; j++) {
                if (nums[j] < nums[min]) {
                    min = j;
                }
            }
            temp = nums[i];
            nums[i] = nums[min];
            nums[min] = temp;
        }

        // print array
        for (int i = 0; i < n; i++) {
            System.out.println(nums[i] + " ");
        }
    }
}
