import java.util.*;
public class S0454028 {
    public static void main(String[] args) {
        while(true) {
        	Scanner scn = new Scanner(System.in);
        	System.out.print("¿é¤J: ");
        	int n = scn.nextInt();

        	if (0 <= n && n <= 70) {
        	    System.out.print("¿é¥X: "+F(n));
        	    System.out.println("");
        	}
        }
    }
    public static long F(long n) {
    	if (n == 0)
        	return 0;
        if (n == 1)
        	return 1;
        else
        	return F(n - 1) + F(n - 2);
    }
}

