// Online Java Compiler
// Use this editor to write, compile and run your Java code online
import java.util.*;  

/*Given 2 integer values, a and b , return their sum. However, "teen" values in the range 13..19 inclusive, are extra lucky. So if either value is a teen, just return 19. (aravind)
*/


class LuckyAge {
    public static void main(String[] args) {
        // System.out.println("Hello, World!");
        Scanner input = new Scanner(System.in);
        
        //varible declaration and taking input
        int firstNum, secondNum;
        System.out.print("Enter 1st value ");
        firstNum = input.nextInt();
        System.out.print("Enter second value ");
        secondNum = input.nextInt();
        
        //logic and output
        if((firstNum>=13 && firstNum<=19) || (secondNum>=13 && secondNum<=19))
        {
            System.out.print("19");
        }
        else{
            System.out.print(firstNum+secondNum);
        }
        
        
    }
}