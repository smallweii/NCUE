import java.util.*;
public class S0454028 {
    public static void main(String[] args) {
        while(true) {
        	Scanner scn = new Scanner(System.in);
        	System.out.print("請輸入一串數字: ");
        	String str = scn.nextLine();
        	char check = str.charAt(0);

        	if (check != 'q') {
                //String arr[]=str.split(" ");// 將字串切割成陣列(多個空白會切成多個陣列元素)
                StringTokenizer st = new StringTokenizer(str);
                int n = st.countTokens(); // 計算Token數(多個空白不會切成多個陣列元素)
                int arr[] = new int[n];
                int i = 0;
                while (st.hasMoreTokens()) {
                    arr[i] = Integer.parseInt(st.nextToken());
                    i++;
                }

                System.out.println(""); // 換行
                System.out.print("排序前: ");
                System.out.print(arr[0]);
                for (i = 1; i < arr.length; i++)
            	    System.out.print(","+arr[i]);

                System.out.println("");
                int min = arr[0], max = arr[0];
                for (i = 0; i < arr.length; i++) {
            	    if (arr[i] < min)
            		    min = arr[i];
            	    if (arr[i] > max)
            		    max = arr[i];
                }
                System.out.print("最小值="+min+",最大值="+max);

                System.out.println("");
                System.out.print("排序後: ");
                Arrays.sort(arr); // 排序(從小到大)
                System.out.print(arr[0]);
                for (i = 1; i < arr.length; i++)
            	    System.out.print(","+arr[i]);

                System.out.println("");
                System.out.println("");
        	}
        	else
        		break;
        }
    }
}

