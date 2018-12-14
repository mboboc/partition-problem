import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.concurrent.ThreadLocalRandom;
import java.util.Scanner;
import java.io.BufferedWriter;

public class Main {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        ArrayList<Integer> numbers = new ArrayList<Integer>();
        int random;
        int testNumber = in.nextInt();
        int count = in.nextInt();
        String outputString = "test" + String.valueOf(testNumber) + ".in";
        try {
            File file = new  File("C:/Users/madalina.boboc/Documents/an2/aa/implementation/in/" + outputString);
            // if file doesnt exists, then create it
            if (!file.exists()) {   // checks whether the file is Exist or not
                file.createNewFile();   // here if file not exist new file created
            }
            FileWriter fw = new FileWriter(file.getAbsoluteFile(), false); // creating fileWriter object with the file
            BufferedWriter bw = new BufferedWriter(fw); // creating bufferWriter which is used to write the content into the file
            bw.write(String.valueOf(count) + " ");
            for(int i = 0; i < count; i++) {
                random = ThreadLocalRandom.current().nextInt(16777216, 33554432);
                //daca vreau numere unice
                /*while (numbers.contains(random)) {
                    random = ThreadLocalRandom.current().nextInt(1, 2147483647);
                }*/
                numbers.add(random);
                bw.write(String.valueOf(random) + " "); // write method is used to write the given content into the file
            }

            bw.close(); // Closes the stream, flushing it first. Once the stream has been closed, further write() or flush() invocations will cause an IOException to be thrown. Closing a previously closed stream has no effect.

            } catch (IOException e) { // if any exception occurs it will catch
                e.printStackTrace();
            }
        System.out.println("Done");
    }
}
