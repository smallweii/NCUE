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

        int factor[] = new int[10];
        if (arr.length <= 10) {
        	for (i = 0; i < arr.length; i++) { // arr[i]
        		for (int j = 2; j < arr[i]; j++) {
        		    if (arr[i] % j == 0) { // j是arr[i]的因數
        		        factor[i] = 1; // arr[i]是合數
        		        break;
        		    }
        		    else
        		    	factor[i] = 0; // arr[i]是質數
        		}
        	}
        	for (i = 0; i < arr.length; i++)
        	    if (factor[i] == 0)
        	    	System.out.print(arr[i]+" ");
        }
    }
}