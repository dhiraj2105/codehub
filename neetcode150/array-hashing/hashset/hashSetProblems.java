// import java.util.HashSet;

// class Problems {
//     public static int uniqueElement(int[] nums) {

//         HashSet<Integer> set = new HashSet<>();
//         for (int num : nums) {
//             set.add(num);
//         }

//         return set.size();
//     }
// }

// public class hashSetProblems {
//     public static void main(String[] args) {
//         int[] nums = { 4, 4, 6, 6, 2 };

//         System.out.println("Unique element count : " + Problems.uniqueElement(nums));
//     }
// }

import java.util.ArrayList;
import java.util.HashSet;

class Result {
    int count;
    ArrayList<Integer> elements;

    Result(int count, ArrayList<Integer> elements) {
        this.count = count;
        this.elements = elements;
    }
}

class Problems {
    public static Result uniqueElement(int[] nums) {

        HashSet<Integer> set = new HashSet<>();

        for (int num : nums) {
            set.add(num);
        }

        return new Result(set.size(), new ArrayList<>(set));
    }

    public static Result intersectionOfArrays(int[] num1, int[] num2) {
        HashSet<Integer> set = new HashSet<>();
        HashSet<Integer> intersectionSet = new HashSet<>();

        for (int num : num1) {
            set.add(num);
        }

        for (int num : num2) {
            if (set.contains(num)) {
                intersectionSet.add(num);
            }
        }

        return new Result(intersectionSet.size(), new ArrayList<>(intersectionSet));
    }
}

public class hashSetProblems {
    public static void main(String[] args) {
        int[] nums = { 4, 4, 5, 6, 6, 2 };
        int[] nums2 = { 4, 5, 3, 6 };

        // Unique elements
        Result result = Problems.uniqueElement(nums);

        System.out.println("Unique element count : " + result.count);
        System.out.println("Unique elements : " + result.elements);

        // Intersection of two arrays
        Result result2 = Problems.intersectionOfArrays(nums, nums2);

        System.out.println("Intersection element count : " + result2.count);
        System.out.println("Intersection elements : " + result2.elements);
    }
}
