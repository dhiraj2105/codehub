public class StringBuilderVSBuffer {

    public static void main(String[] args) {
        // Explained difference between string ,stringbuilder and stringbuffer

        // String is immutable, every time we modify a string it creates a new object ,
        // string memory is stored in string pool
        String str = "Hello";
        str = str + " World"; // Creates a new string object
        System.out.println("String: " + str);

        // IT is a default array size of 16, when it exceeds the limit it creates a new
        // array of size (old capacity*2)+2 and copies the old array to new array and
        // adds the new element and deletes the old array and points to the new array
        // StringBuilder and StringBuffer are mutable, they modify the existing object
        // StringBuilder memory is stored in heap memory
        // StringBuffer memory is also stored in heap memory
        StringBuilder stringBuilder = new StringBuilder("Hello");
        stringBuilder.append(" World"); // Modifies the existing object
        System.out.println("StringBuilder: " + stringBuilder.toString());

        StringBuffer stringBuffer = new StringBuffer("Hello");
        stringBuffer.append(" World"); // Modifies the existing object
        System.out.println("StringBuffer: " + stringBuffer.toString());

        // Difference between StringBuilder and StringBuffer
        // StringBuilder is not synchronized (not thread-safe) but faster
        // StringBuffer is synchronized (thread-safe) but slower

        // Example to show the difference with threads safety
        StringBuffer sb1 = new StringBuffer();

        Task t1 = new Task(sb1);
        Task t2 = new Task(sb1);

        t1.start();
        t2.start();

        try {
            // wait for both threads to finish
            t1.join();
            t2.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println(
            "Final length of thread safe StringBuffer: " + sb1.length()
        );
        // Above code will always print 20000 as StringBuffer is thread-safe
        // If we use StringBuilder instead of StringBuffer above code may print less
        // than 20000 as StringBuilder is not thread-safe
    }
}

class Task extends Thread {

    private StringBuffer sb;

    public Task(StringBuffer sb) {
        this.sb = sb;
    }

    @Override
    public void run() {
        for (int i = 0; i < 10000; i++) {
            sb.append("a");
        }
    }
}
