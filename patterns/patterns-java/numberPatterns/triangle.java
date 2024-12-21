public class triangle {
    public static void main(String[] args) {
        // Half pyramid
        // 1
        // 1 2
        // 1 2 3
        // 1 2 3 4

        int n = 5;

        for (int row = 1; row <= n; row++) {
            for (int col = 1; col <= row; col++) {
                System.out.print(col + " ");
            }
            System.out.println();
        }
    }
}
