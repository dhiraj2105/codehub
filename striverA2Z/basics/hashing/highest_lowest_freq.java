import java.util.HashMap;
import java.util.Map;

public class highest_lowest_freq {

    static void HL(int[] nums) {
        HashMap<Integer, Integer> map = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            if (map.containsKey(nums[i])) {
                map.put(nums[i], map.get(nums[i]) + 1);
            } else {
                map.put(nums[i], 1);
            }
        }

        System.out.println("Hashmap : " + map);

        // find HL
        int highestElement = 0,
            lowestElement = 0;
        int highestFreq = Integer.MIN_VALUE,
            lowestFreq = Integer.MAX_VALUE;

        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            int element = entry.getKey();
            int freq = entry.getValue();

            if (freq > highestFreq) {
                highestFreq = freq;
                highestElement = element;
            }
            if (freq < lowestFreq) {
                lowestFreq = freq;
                lowestElement = element;
            }
        }
        System.out.println(
            "Highest Frequency Element : " +
                highestElement +
                " -> " +
                highestFreq
        );

        System.out.println(
            "Lowest Frequency Element : " + lowestElement + " -> " + lowestFreq
        );
    }

    public static void main(String[] args) {
        // count highest lowest frequency of elements in array
        int[] nums = { 1, 2, 2, 3, 4, 2, 5, 4 };

        HL(nums);
    }
}
