
public class invertedTriangle {
    public static void main(String[] args) {
        // Inveted Half pyramid
        // 1 2 3 4
        // 1 2 3
        // 1 2
        // 1
        int n = 5;
        for (int row = 1; row <= n; row++) {
            for (int col = 1; col <= n - row + 1; col++) {
                System.out.print(col + " ");
            }
            System.out.println();
        }
    }
}