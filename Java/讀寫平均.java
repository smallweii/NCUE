import java.util.*;
import java.io.*;
public class S0454028
{
	public static void main(String[] args) throws IOException
    {
    	FileReader fr = new FileReader("C:\\file_practice.txt"); // Ū��
        BufferedReader bfr = new BufferedReader(fr);

        FileWriter fw = new FileWriter("C:\\out.txt"); // �g��
        BufferedWriter bfw = new BufferedWriter(fw);

        String str;
        while ((str = bfr.readLine()) != null) // �C��Ū�@��A�����ɮ׵���
        {
        	StringTokenizer st = new StringTokenizer(str);
			int n = st.countTokens(); // �p��Token��(�h�Ӫťդ��|�����h�Ӱ}�C����)
			int arr[] = new int[n];
			int i = 0;
			while (st.hasMoreTokens())
			{
  				arr[i] = Integer.parseInt(st.nextToken());
  				i++;
			}

        	double sum = 0;
        	for (int j = 0; j < n; j++)
        		sum += arr[j];

        	double ave = sum / n;
        	bfw.write(Double.toString(ave)); // �g�J�r���w�İ�
        	bfw.newLine(); // �g�J����Ÿ�
        }

    	bfw.flush(); // �N�w�İϤ�����Ƽg���ɮ׸�
    	fr.close(); // ����
    	fw.close(); // ����
    }
}