import java.util.*;
public class S0454028 {
    public static void main(String[] args) {
        while(true) {
        	Scanner scn = new Scanner(System.in);
        	System.out.print("�п�J�@��Ʀr: ");
        	String str = scn.nextLine();
        	char check = str.charAt(0);

        	if (check != 'q') {
                //String arr[]=str.split(" ");// �N�r����Φ��}�C(�h�Ӫťշ|�����h�Ӱ}�C����)
                StringTokenizer st = new StringTokenizer(str);
                int n = st.countTokens(); // �p��Token��(�h�Ӫťդ��|�����h�Ӱ}�C����)
                int arr[] = new int[n];
                int i = 0;
                while (st.hasMoreTokens()) {
                    arr[i] = Integer.parseInt(st.nextToken());
                    i++;
                }

                System.out.println(""); // ����
                System.out.print("�Ƨǫe: ");
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
                System.out.print("�̤p��="+min+",�̤j��="+max);

                System.out.println("");
                System.out.print("�Ƨǫ�: ");
                Arrays.sort(arr); // �Ƨ�(�q�p��j)
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

