
public class repeatedNumTriangle {

    public static void main(String[] args) {
        // Example
        // 1
        // 2 2
        // 3 3 3
        // 4 4 4 4

        int n = 5;

        for (int row = 1; row <= n; row++) {
            for (int col = 1; col <= row; col++) {
                System.out.print(row + " ");
            }
            System.out.println(" ");
        }
    }
}
