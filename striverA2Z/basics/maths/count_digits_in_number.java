public class count_digits_in_number {

    static int bruteForce(int num) {
        // use loop to increase counter
        int counter = 0;
        while (num > 0) {
            counter++;
            num = num / 10;
        }

        return counter;
    }

    static int optimised(int num) {
        int res = (int) Math.floor(Math.log10(num)) + 1;
        return res;
    }

    public static void main(String[] arg) {
        // Count total number of digits in a number
        int num = 12345;

        System.out.println(
            "Total number of digit using brute force method : " +
                bruteForce(num)
        );

        System.out.println(
            "Total number of digit using optimised method : " + optimised(num)
        );
    }
}
