import java.util.Scanner;
public class S0454028 {

    public static void main(String[] args) {

        Scanner scn = new Scanner(System.in);
        int num2 = 0, num4 = 0, num6 = 0, num8 = 0, n;
        String str;
        char ch;

        //int num1 = scanner.nextInt();
        //int num2 = scanner.nextInt();//整數(以空白字元區隔)
        //String s1= scanner.next();//字串(不含空白字元)
        //String s1= scanner.nextLine();//整行字串(含空白字元)
        //String s[]=s1.split(" ");//將字串切割成陣列

        System.out.println("請輸入字串：");
        str = scn.nextLine(); // user輸入字串
        n = str.length(); // 字串長度

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
        System.out.println("2 : "+num2+"次");
        System.out.println("4 : "+num4+"次");
        System.out.println("6 : "+num6+"次");
        System.out.println("8 : "+num8+"次");
    }
}