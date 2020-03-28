import java.util.Scanner;
public class S0454028 {
    public static void main(String[] args) {
        while (true) {
        	Scanner scn = new Scanner(System.in);
            int num, n, k;
            String str;

            System.out.print("請輸入一整數：");
            if (scn.hasNextInt()) {
                num = scn.nextInt();
                n = num;
                for (int i = 0; i < num; i++) { // 第幾行
                    for (int j = 0; j < n; j++) // 每行有幾*
                	    System.out.print("*");
                    System.out.println(""); // 換行
                    n--;
    	        }
	            k = 2;
	            for (int i = 0; i < num - 1; i++) {
	    	        for (int j = 0; j < k; j++)
		                System.out.print("*");
	                System.out.println("");
	                k++;
	            }
            }
            else {
            	str = scn.nextLine();
            	if (str.charAt(0) == 'q')
            		break;
            }
        }
    }
}