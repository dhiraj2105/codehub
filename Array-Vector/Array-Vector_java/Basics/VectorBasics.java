import java.util.Vector; // Importing the Vector class from the java.util package

public class VectorBasics {
    public static void main(String[] args) {
        // Creating a Vector to hold Integer elements
        Vector<Integer> v = new Vector<>();

        // Adding elements to the Vector
        v.add(10); // Adds 10 to the Vector
        v.add(20); // Adds 20 to the Vector
        v.add(30); // Adds 30 to the Vector

        // Displaying the Vector
        System.out.println("Initial Vector: " + v);

        // Accessing elements from the Vector
        int firstElement = v.get(0); // Gets the first element (index 0)
        System.out.println("First Element: " + firstElement);

        // Modifying an element in the Vector
        v.set(1, 25); // Changes the element at index 1 to 25
        System.out.println("Vector after modification: " + v);

        // Removing an element from the Vector
        v.remove(2); // Removes the element at index 2
        System.out.println("Vector after removal: " + v);

        // Checking the size of the Vector
        int size = v.size(); // Gets the current size of the Vector
        System.out.println("Size of Vector: " + size);

        // Checking if the Vector contains a specific element
        boolean contains20 = v.contains(20); // Checks if 20 is in the Vector
        System.out.println("Vector contains 20: " + contains20);

        // Iterating over the elements of the Vector
        for (int i = 0; i < v.size(); i++) {
            System.out.println(v.get((i)));
        }

        // Clearing all elements from the Vector
        v.clear(); // Removes all elements from the Vector
        System.out.println("Vector after clearing: " + v);
    }
}