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
}

public class hashSetProblems {
    public static void main(String[] args) {
        int[] nums = { 4, 4, 5, 6, 6, 2 };

        Result result = Problems.uniqueElement(nums);

        System.out.println("Unique element count : " + result.count);
        System.out.println("Unique elements : " + result.elements);
    }
}
