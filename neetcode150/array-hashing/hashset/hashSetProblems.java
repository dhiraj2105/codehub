import java.util.HashSet;

class Problems {
    public static int uniqueElement(int[] nums) {

        HashSet<Integer> set = new HashSet<>();
        for (int num : nums) {
            set.add(num);
        }

        return set.size();
    }
}

public class hashSetProblems {
    public static void main(String[] args) {
        int[] nums = { 4, 4, 6, 6, 2 };

        System.out.println("Unique element count : " + Problems.uniqueElement(nums));
    }
}
