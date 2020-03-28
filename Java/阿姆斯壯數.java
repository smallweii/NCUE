import java.util.*;
public class S0454028 {
    public static void main(String[] args) {
        while(true) {
        	Scanner scn = new Scanner(System.in);
        	System.out.print("輸入: ");
        	String str = scn.nextLine();

            StringTokenizer st = new StringTokenizer(str);
            int t = st.countTokens(); // 計算Token數(多個空白不會切成多個陣列元素)
            int arr[] = new int[t];
            int i = 0;
            while (st.hasMoreTokens()) {
                arr[i] = Integer.parseInt(st.nextToken());
                i++;
            }

        	if (arr.length == 2 && arr[0] < arr[1]) { // 讓使用者輸入兩個數字n, m(n<m, 數字間以空白隔開)
        	    System.out.println("輸出: ");
        	    int n, m;
        	    n = arr[0];
        	    m = arr[1];
        	    int num[] = new int[40];
        		boolean yesno = false;

        		for (i = n; i <= m; i++) {
        			int j = 0, k = 0, top, N, arm = 0;

        			j = i;
        			while (j / 10 != 0) {
        				num[k] = j % 10;
                        j /= 10;
                        k++;
        			}
        			num[k] = j % 10;
        			top = k + 1;
        			for (k = 0; k < top; k++) {
        				N = num[k];
        				arm += pow(N, top);
        			}
        		    if (i == arm) { // 是阿姆斯壯數
        			    System.out.print(i+" ");
        			    yesno = true;
        		    }
        		}
        		if (yesno == true) // 完全世界有阿樹
        		    System.out.println("");
        		if (yesno == false) // 完全世界沒阿樹
        			System.out.println("none");
        	}
        }
    }
    public static int pow(int N, int top) {
    	int sum = 1;

    	for (int a = 1; a <= top; a++)
    		sum *= N;
    	return sum;
    }
}