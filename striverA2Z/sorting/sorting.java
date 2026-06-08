public class sorting {

    static void selectionSort(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            int min = i;
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[min] > nums[j]) {
                    min = j;
                }
            }
            int temp = nums[i];
            nums[i] = nums[min];
            nums[min] = temp;
        }

        print("Selection Sort", nums);
    }

    static void print(String name, int[] nums) {
        System.out.print(name);
        for (int i = 0; i < nums.length; i++) {
            System.out.print(" -> " + nums[i]);
        }
        System.out.println();
    }

    public static void main(String[] args) {
        int[] nums = { 2, 1, 5, 3, 4 };

        selectionSort(nums);
    }
}
