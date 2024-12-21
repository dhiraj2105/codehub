public class triangle {
    public static void main(String[] args) {
        // Also known as Half pyramid
        // Example
        // *
        // * *
        // * * *
        // * * * *

        int n = 5;

        for (int row = 1; row <= n; row++) {
            for (int col = 1; col <= row; col++) {
                System.out.print("* ");
            }
            System.out.println();
        }
    }
}
