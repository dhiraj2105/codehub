import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class intersectionofTwoArrays {
    public static List<Integer> intersect(int[] arr1, int[] arr2) {

        List<Integer> result = new ArrayList<>();
        HashMap<Integer, Integer> map = new HashMap<>();

        for (int num : arr1) {
            map.put(num, map.getOrDefault(num, 0) + 1);
        }

        for (int num : arr2) {
            if (map.containsKey(num) && map.get(num) > 0) {
                result.add(num);
                map.put(num, map.get(num) - 1);// decrement the count
            }
        }

        return result;
    }

    public static void main(String[] args) {
        /*
         * Given two integer arrays nums1 and nums2, return an array of their
         * intersection. Each element in the result must appear as many times as it
         * shows in both arrays and you may return the result in any order.
         */
        int[] nums1 = { 4, 9, 5 };
        int[] nums2 = { 9, 4, 9, 8, 4 };

        List<Integer> result = intersect(nums1, nums2);
        for (int i : result) {
            System.out.print(i + " ");
        }
    }
}
