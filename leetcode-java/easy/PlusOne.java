import java.util.ArrayList;
import java.util.List;

public class PlusOne {

    public static List<Integer> plus_one(List<Integer> digits) {
        int n = digits.size();

        // Reverse loop
        for (int i = n - 1; i >= 0; i--) {
            // When digit is less than 9, increment by 1
            if (digits.get(i) < 9) {
                digits.set(i, digits.get(i) + 1);
                return digits;
            }
            // When digit is 9, update it to 0
            else {
                digits.set(i, 0);
            }
        }

        // This will only work when the upper loop exits without returning,
        // which means the array has all 9s. We then insert 1 at the beginning.
        digits.add(0, 1);

        return digits;
    }

    public static void main(String[] args) {
        /*
         * You are given a large integer represented as an integer array digits, where
         * each digits[i] is the ith digit of the integer. The digits are ordered from
         * most significant to least significant in left-to-right order. The large
         * integer does not contain any leading 0's.
         * 
         * Increment the large integer by one and return the resulting array of digits.
         */
        List<Integer> digits = new ArrayList<>();
        digits.add(1);
        digits.add(9);

        List<Integer> result = plus_one(digits);
        for (int i = 0; i < result.size(); i++) {
            System.out.print(result.get(i) + " ");
        }
    }
}