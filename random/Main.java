import java.util.Scanner;

/**
 * Hamin's java summary notes. 
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

        Integer integer = 5;

        //math
        Math.abs(-50); //50
        Math.exp(0);
        Math.max(50d, 40d);
        Math.min(50, 100);;
        //unboxing
        int numofInteger = integer;
        
        //trim
        String string1 = "  Hello World!  ";
        string1 = string1.trim();
        String[] string2 = string1.split(" ");
        //we will discuss regex later


    }
}
