import java.util.*;
import java.io.*;
public class S0454028
{
	public static void main(String[] args) throws IOException
    {
    	FileReader fr = new FileReader("C:\\file_practice_2.txt"); // Ū��
        BufferedReader bfr = new BufferedReader(fr);

        FileWriter fw = new FileWriter("C:\\out2.txt"); // �g��
        BufferedWriter bfw = new BufferedWriter(fw);

	    String str = bfr.readLine(); // �C��Ū�@��A���ɮץu���@��
        System.out.println("���g�u�媺�r����(�t�ť�)�@�� " + str.length());

        int space = 0, count = 0;
        for (int i = 0; i < str.length(); i++)
           	if (str.charAt(i) == ' ')
           	    space++;
        System.out.println("���t�ťժ��r���Ʀ@�� " + (str.length() - space));

        String s[] = str.split(" "); // �N�r����Φ��}�C(�h�Ӫťշ|�����h�Ӱ}�C����)
        for (int i = 0; i < s.length; i++)
        	if (s[i].equals("the") == true) // ���s[i]�̪��r��O�_�P " the " �ۦP
        		count++;
	    System.out.println("�@�� " + count + " �Ӧr��Q���N");

        String replacedstr = str.replaceAll("the", "THE"); // ��u�夺�Ҧ����r�� " the " �H " THE " ���N
        bfw.write(replacedstr); // �g�J�r���w�İ�

    	bfw.flush(); // �N�w�İϤ�����Ƽg���ɮ׸�
    	fr.close(); // ����
    	fw.close(); // ����
    }
}