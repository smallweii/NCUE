import java.util.*;
public class S0454028 {
    public static void main(String[] args) {
        while(true) {
        	Scanner scn = new Scanner(System.in);
        	System.out.print("¿é¤J: ");
        	int n = scn.nextInt();

        	if (0 <= n && n <= 70) {
        		long F[] = new long[80];
        		F[0] = 0;
        		F[1] = 1;

        		for (int i = 2; i <= n; i++)
        			F[i] = F[i - 1] + F[i - 2];

        	    System.out.print("¿é¥X: "+F[n]);
        	    System.out.println("");
        	}
        }
    }
}

