public class reverseAlphaPyramid {

    public static void main(String[] args) {
        // Example Output
        // D
        // C C
        // B B B
        // A A A A

        int n = 5;

        for (int row = 1; row <= n; row++) {
            for (int col = 1; col <= row; col++) {
                System.out.print((char) ('A' + n - row) + " ");
            }
            System.out.println();
        }
    }
}