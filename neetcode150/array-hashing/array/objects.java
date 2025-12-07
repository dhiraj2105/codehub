class myClass {
    void show() {
        System.out.println("This is my custom class stored in array");
    }
}

public class objects {
    public static void main(String[] args) {
        Object[] arrOfAnyType = new Object[3];

        arrOfAnyType[0] = 10;
        arrOfAnyType[1] = "Hii";
        arrOfAnyType[2] = new myClass();

        for (int i = 0; i < arrOfAnyType.length; i++) {
            System.out.println(arrOfAnyType[i] + " : " + arrOfAnyType[i].getClass());
        }

        // Type casting and using elements
        int num = (int) arrOfAnyType[0];
        myClass obj = (myClass) arrOfAnyType[2];

        System.out.println("\nAfter Casting...");

        System.out.println("Number + 5 = " + (num + 5));

        obj.show();

    }
}

/*
 * ------------------- EXPLAINATION ----------------------------
 * 
 * 1. Object is the parent of all classes
 * So anything can be saved on object[]
 * 
 * We can store data of anytype in object
 * 
 * 2. Why is casting needed?
 * Because Object does NOT have methods of String or Integer.
 * After casting, Java knows the exact type and allows methods.
 * 
 */