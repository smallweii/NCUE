import java.util.Scanner;
public class S0454028 {

    public static void main(String[] args) {

        Scanner scn = new Scanner(System.in);
        int num2 = 0, num4 = 0, num6 = 0, num8 = 0, n;
        String str;
        char ch;

        //int num1 = scanner.nextInt();
        //int num2 = scanner.nextInt();//���(�H�ťզr���Ϲj)
        //String s1= scanner.next();//�r��(���t�ťզr��)
        //String s1= scanner.nextLine();//���r��(�t�ťզr��)
        //String s[]=s1.split(" ");//�N�r����Φ��}�C

        System.out.println("�п�J�r��G");
        str = scn.nextLine(); // user��J�r��
        n = str.length(); // �r�����

        for (int i = 0; i < n; i++) {
    	    ch = str.charAt(i);

    	    switch(ch) {
    	    	case '2' :
    	    		num2++;
    	    		break;
    	    	case '4' :
    	    		num4++;
    	    		break;
    	    	case '6' :
    	    		num6++;
    	    		break;
    	    	case '8' :
    	    		num8++;
    	    		break;
    	    	default :
    	    		break;
    	    }
        }
        System.out.println("2 : "+num2+"��");
        System.out.println("4 : "+num4+"��");
        System.out.println("6 : "+num6+"��");
        System.out.println("8 : "+num8+"��");
    }
}