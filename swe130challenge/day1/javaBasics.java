package swe130challenge.day1;

public class javaBasics {
    public static void main(String[] args) {
        System.out.println("Hello 130 days swe challenge!");

        System.out.println("Comments in Java");
        // Single line comment
        /*
         * Multi line comment
         * This is a multi-line comment
         * It can span multiple lines
         */

        // Variables and Data Types

        // Syntax to declare a variable: dataType variableName = value;
        int variable1 = 10;

        // Different data types in Java

        // 1. Primitive Data Types
        byte myByte = 100; // Byte
        short myShort = 10000; // Short
        int myNumber = 10; // Integer
        long myLong = 150000L; // Long
        float myFloat = 5.75f; // Floating point number
        double myDouble = 5.99; // Floating point number
        char myChar = 'A'; // Character
        String myString = "Hello"; // String
        boolean myBoolean = true; // Boolean

        // 2. Non-Primitive Data Types
        // Arrays, Classes, Interfaces, etc.
        int[] myArray = { 1, 2, 3, 4, 5 }; // Array

        // Printing variables
        System.out.println("Integer: " + variable1);
        System.out.println("Byte: " + myByte);
        System.out.println("Short: " + myShort);
        System.out.println("Integer: " + myNumber);
        System.out.println("Long: " + myLong);
        System.out.println("Float: " + myFloat);
        System.out.println("Double: " + myDouble);
        System.out.println("Character: " + myChar);
        System.out.println("String: " + myString);
        System.out.println("Boolean: " + myBoolean);
        System.out.println("Array element at index 0: " + myArray[0]);

        // LOOPS in java
        System.out.println("Loops in Java");

        // 1. For Loop
        System.out.println("For Loop:");
        for (int i = 0; i < 5; i++) {
            System.out.println("Iteration: " + i);
        }

        // 2. While Loop
        System.out.println("While Loop:");
        int j = 0;
        while (j < 5) {
            System.out.println("Iteration: " + j);
            j++;
        }

        // 3. Do-While Loop
        System.out.println("Do-While Loop:");
        int k = 0;
        do {
            System.out.println("Iteration: " + k);
            k++;
        } while (k < 5);

        // 4. For-Each Loop
        System.out.println("For-Each Loop:");
        int[] numbers = { 1, 2, 3, 4, 5 };
        for (int number : numbers) {
            System.out.println("Number: " + number);
        }
    }
}
