//﹎惧蝴(S0454028)
//氮薄75/100
import java.util.*;

public class Q1 {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        String str = scanner.nextLine();

        StringTokenizer st = new StringTokenizer(str);
        int t = st.countTokens();
        int arr[] = new int[t];
        int i = 0;
        while (st.hasMoreTokens()) {
            arr[i] = Integer.parseInt(st.nextToken());
            i++;
        }

        int m = 0, n = 0;
        if (arr.length == 2 && (1 <= arr[0] && arr[0] <= 4)) {
            m = arr[0];
        	n = arr[1];
        }

        if (m == 1) {
            if (0 < n && n < 100) {
        		long Fm[] = new long[1000];
        		Fm[0] = 0;
        		Fm[1] = 1;

        		for (i = 2; i <= n; i++)
        			Fm[i] = Fm[i - 1] + Fm[i - 2];
        		System.out.print(Fm[n]); // output
            }
        }

        /*if (m == 2) {
        	for (i = n; ; i++) {
        	    String str = Integer.toString(i);
        	    int len = str.length(), k = 0, j = 0;
        	    boolean memory = true, palindrome = true;

        	    if (len % 2 == 1) { // 计
		            for (k = 0, j = len - 1; k < len / 2, j > len / 2; k++, j--) {
			            if (str.charAt(k) == str.charAt(j))
				            memory = true;
			            else
				            break;
		            }
		            if (memory == true)
			            palindrome = true;
	             	else
			            palindrome = false;
            	} else { // 案计
	            	for (k = 0, j = len - 1; k < len / 2, j > len / 2 - 1; k++, j--) {
		            	if (str.charAt(k) == str.charAt(j))
				            memory = true;
			            else
				            break;
		            }
		            if (memory == true)
		        	    palindrome = true;
		            else
			            palindrome = false;
	            }
	            return palindrome;

	            if (palindrome == true) { // 琌ゅ

	            	System.out.print(str); // output
	            	break;
	            }
        	}
        }*/

        if (m == 3) {
        	for (i = n; ; i++) {
                double num = Math.sqrt(i);
                int Num = (int)num;

                if (Num == num) { // 琌Чキよ计
        		    System.out.print(i); // output
        		    break;
        	    }
            }
        }

        if (m == 4) {
        	for (i = n; ; i++) {
        		int l = 0;
                for (int j = 2; j <= Math.sqrt(i); j++) {
                    if ((i % j) == 0) { // 琌计
                        int k = i / j;
                        if (k == j)
                            l = l + j;
                        else
                            l = l + j + k;
                    }
                }
                l++;
                if (l > i) { // 琌计
                	System.out.print(i); // output
        		    break;
                }
        	}
        }
    }
}