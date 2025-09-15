package swe130challenge.day1;

public class arrayBasics {
    public static void main(String[] args) {
        // Method 1 to Declare and initialize an array with array literal
        int[] numbers = { 10, 20, 30, 40, 50 };

        // Access and print elements of the array
        System.out.println("First element: " + numbers[0]);
        System.out.println("Second element: " + numbers[1]);

        // Modify an element in the array
        numbers[2] = 35;
        System.out.println("Modified third element: " + numbers[2]);

        // Iterate through the array and print all elements
        System.out.println("All elements in the array:");
        for (int i = 0; i < numbers.length; i++) {
            System.out.println(numbers[i]);
        }

        // Method 2 to Declare and initialize an array combining declaration and
        // initialization
        String[] fruits = new String[3];
        fruits[0] = "Apple";
        fruits[1] = "Banana";
        fruits[2] = "Cherry";
        System.out.println("Fruits in the array:");
        for (String fruit : fruits) {
            System.out.println(fruit);
        }

        // Method 3 to Declare and initialize an array two steps
        int[] moreNumbers;
        moreNumbers = new int[] { 60, 70, 80 };
        System.out.println("More numbers in the array:");
        for (int num : moreNumbers) {
            System.out.println(num);
        }

        // INSERTION in array at start

        int[] nums = { 1, 2, 3, 4, 5 };
        int newElement = 0;

        // creating new array of size of nums + 1
        int[] newNums = new int[nums.length + 1];

        // inserting new element at start
        newNums[0] = newElement;

        // copying rest of the elements
        for (int i = 0; i < nums.length; i++) {
            newNums[i + 1] = nums[i];
        }

        // INSERTION in array at middle

        int[] nums2 = { 1, 2, 4, 5 };
        int newElement2 = 3;
        int insertIndex = 2; // index where we want to insert the new element
        // creating new array of size of nums2 + 1
        int[] newNums2 = new int[nums2.length + 1];
        // copying elements before the insert index
        for (int i = 0; i < insertIndex; i++) {
            newNums2[i] = nums2[i];
        }

        // inserting the new element
        newNums2[insertIndex] = newElement2;

        // copying elements after the insert index
        for (int i = insertIndex; i < nums2.length; i++) {
            newNums2[i + 1] = nums2[i];
        }

        // INSERTION in array at end
        int[] nums3 = { 1, 2, 3, 4 };
        int newElement3 = 5;
        // creating new array of size of nums3 + 1
        int[] newNums3 = new int[nums3.length + 1];
        // copying all elements
        for (int i = 0; i < nums3.length; i++) {
            newNums3[i] = nums3[i];
        }
        // inserting the new element at the end
        newNums3[nums3.length] = newElement3;
    }
}
