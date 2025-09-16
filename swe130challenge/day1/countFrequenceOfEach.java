package swe130challenge.day1;

public class countFrequenceOfEach {
    public static void main(String[] args) {

        // Step 1: Define the array
        int[] arr = { 1, 2, 2, 3, 1, 4, 2, 3, 1 };

        // Step 2: Create a visited array to track counted elements
        boolean[] visited = new boolean[arr.length];

        System.out.println("Element Frequencies:");

        // Step 3: Outer loop to pick each element
        for (int i = 0; i < arr.length; i++) {
            // Skip this element if it's already counted
            if (visited[i])
                continue;

            int count = 1; // Start with 1 because we found arr[i] once

            // Step 4: Inner loop to count duplicates
            for (int j = i + 1; j < arr.length; j++) {
                if (arr[i] == arr[j]) {
                    count++;
                    visited[j] = true; // Mark as visited
                }
            }

            // Step 5: Print the frequency of current element
            System.out.println("Element " + arr[i] + ": " + count + " times");
        }
    }
}
