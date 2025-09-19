package swe130challenge.day4;

public class PerformanceDiff {
    public static void main(String[] args) {
        // start and end time
        long startTime, endTime;

        // Using String
        startTime = System.currentTimeMillis();
        String str = "Dhiraj";
        for (int i = 0; i < 100000; i++) {
            str += " Kumar";
        }
        endTime = System.currentTimeMillis();
        System.out.println("Time taken using String: " + (endTime - startTime) + "ms");

        // Using StringBuilder
        startTime = System.currentTimeMillis();
        StringBuilder stringBuilder = new StringBuilder("Dhiraj");
        for (int i = 0; i < 100000; i++) {
            stringBuilder.append(" Kumar");
        }
        endTime = System.currentTimeMillis();
        System.out.println("Time taken using StringBuilder: " + (endTime - startTime) + "ms");

        // Using StringBuffer
        startTime = System.currentTimeMillis();
        StringBuffer stringBuffer = new StringBuffer("Dhiraj");
        for (int i = 0; i < 100000; i++) {
            stringBuffer.append(" Kumar");
        }
        endTime = System.currentTimeMillis();
        System.out.println("Time taken using StringBuffer: " + (endTime - startTime) + "ms");
    }
}
