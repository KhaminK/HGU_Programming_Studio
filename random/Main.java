import java.io.PrintStream;
import java.util.Scanner;

/**
 * Hamin's java summary notes. 
 * @author Hamin Song 22400386
 */
class Main{
    public static void main(String[] args) {
        //Input
        Scanner s = new Scanner(System.in);
        //Get one line of input
        s.nextLine();
        //Get one intger
        s.nextInt();
        s.nextBoolean();
        s.nextFloat();

        Integer integer = 5;
        Double DDouble = 5.0;

        //math
        Math.abs(-50); //50
        Math.exp(0);
        Math.max(50d, 40d);
        Math.min(50, 100);;
        Math.sqrt(25);
        //unboxing
        int numofInteger = integer;
        double dDouble = DDouble;
        
        //trim
        String string1 = "  Hello World!  ";
        string1 = string1.trim();
        String[] string2 = string1.split(" ");
        //we will discuss regex later
        


    }
}
