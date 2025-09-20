import java.util.ArrayList;

public class arrayList {
    public static void main(String[] args) {
        // creating array list
        ArrayList<String> fruits = new ArrayList<>();

        // add
        fruits.add("Apple");
        fruits.add("Banana");
        fruits.add("Pineapple");
        fruits.add("orange");
        fruits.add("Apple");

        System.out.println("List of fruits : ");
        for (String fruit : fruits) {
            System.out.println(fruit);
        }

        // update
        fruits.set(3, "Mango");

        // remove
        fruits.remove(0); // by index
        fruits.remove("Apple"); // by value

        System.out.println("List of fruits : ");
        for (String fruit : fruits) {
            System.out.println(fruit);
        }
    }
}
