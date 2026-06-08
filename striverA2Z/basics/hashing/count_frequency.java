import java.util.HashMap;

public class count_frequency {

    static HashMap<Integer, Integer> Count(int[] nums) {
        HashMap<Integer, Integer> map = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            if (map.containsKey(nums[i])) {
                int val = map.get(nums[i]);
                map.put(nums[i], val + 1);
            } else {
                map.put(nums[i], 1);
            }
        }

        return map;
    }

    public static void main(String[] args) {
        // count frequency of each elements in an array
        int[] nums = { 1, 2, 2, 3, 4, 2, 5, 4 };

        System.out.println("Hashmap : " + Count(nums));
    }
}
